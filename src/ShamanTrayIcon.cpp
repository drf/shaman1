/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#include "ShamanTrayIcon.h"

#include <aqpm/Backend.h>

#include <QTimer>
#include <QSettings>
#include <QMovie>
#include <QTime>
#include <QDebug>

#include "config.h"

#ifdef KDE4_INTEGRATION
#include <knotification.h>
#endif

using namespace Aqpm;

ShamanTrayIcon::ShamanTrayIcon( MainWindow *mW )
        : KAnimatedSystemTrayIcon( mW ),
        mainWin( mW )
{
    if ( Backend::instance()->getUpgradeablePackages().isEmpty() ) {
        changeIconStatus( ShamanIcon::IdleIcon );
    } else {
        changeIconStatus( ShamanIcon::UpgradesAvailableIcon );
    }

    show();

    systrayAct.clear();

    QMenu *systrayMenu = new QMenu();

    QAction *updateDBAction = systrayMenu->addAction( QIcon( ":/Icons/icons/view-refresh.png" ), tr( "Update Database" ) );
    connect( updateDBAction, SIGNAL( triggered() ), mainWin, SLOT( doDbUpdate() ) );
    systrayAct.append( updateDBAction );

    QAction *upgradeAction = systrayMenu->addAction( QIcon( ":/Icons/icons/system-software-update.png" ), tr( "Upgrade System" ) );
    connect( upgradeAction, SIGNAL( triggered() ), mainWin, SLOT( fullSysUpgrade() ) );
    systrayAct.append( upgradeAction );

    QAction *queueAction = systrayMenu->addAction( QIcon( ":/Icons/icons/dialog-ok-apply.png" ), tr( "Process Queue" ) );
    connect( queueAction, SIGNAL( triggered() ), mainWin, SLOT( widgetQueueToAlpmQueue() ) );
    systrayAct.append( queueAction );
    systrayMenu->addSeparator();

    QAction *settingsAction = systrayMenu->addAction( QIcon( ":/Icons/icons/preferences-system.png" ), tr( "Settings" ) );
    connect( settingsAction, SIGNAL( triggered() ), mainWin, SLOT( showSettings() ) );
    systrayAct.append( settingsAction );
    systrayMenu->addSeparator();

    QAction *closeAction = systrayMenu->addAction( QIcon( ":/Icons/icons/application-exit.png" ), tr( "Quit" ) );
    connect( closeAction, SIGNAL( triggered() ), mainWin, SLOT( quitApp() ) );
    systrayAct.append( closeAction );

    //Add actions here ;)
    setContextMenu( systrayMenu );

    connect( Backend::instance(), SIGNAL( transactionStarted() ), SLOT( transactionStarted() ) );
    connect( Backend::instance(), SIGNAL( transactionReleased() ), SLOT( transactionReleased() ) );

    connect( mainWin, SIGNAL( buildingStarted() ), SLOT( transactionStarted() ) );
    connect( mainWin, SIGNAL( buildingFinished() ), SLOT( transactionReleased() ) );

    QSettings *settings = new QSettings();

    enableTimer();
    resetTimerAt();

    settings->deleteLater();
}

ShamanTrayIcon::~ShamanTrayIcon()
{
}

void ShamanTrayIcon::dbUpdateTray()
{
    /* Are there some transactions in progress? If so, we simply skip
     * this cycle, and see you next time.
     */

    if ( Backend::instance()->isOnTransaction() )
        return;

    /* Ok, let's silently perform a Db Update.
     */

    emit startDbUpdate();
}

void ShamanTrayIcon::changeIconStatus( ShamanIcon::IconStatus status )
{
    if ( status == ShamanIcon::IdleIcon ) {
        stopMovie();
        setIcon( QIcon( ":/Icons/icons/shaman/shaman-32.png" ) );
        setToolTip( QString( tr( "Shaman - Idle" ) ) );
    } else if ( status == ShamanIcon::ProcessingIcon ) {
        QSettings *settings = new QSettings();

        if ( settings->value( "trayicon/useanimatedicon", true ).toBool() ) {
            setMovie( new QMovie( ":/Icons/icons/shaman/shaman-animation.mng" ) );
            startMovie();
        } else
            setIcon( QIcon( ":/Icons/icons/shaman/shaman-yellow-icon-32.png" ) );

        settings->deleteLater();

        setToolTip( QString( tr( "Shaman - Processing" ) ) );
    } else {
        Package::List upgrds = Backend::instance()->getUpgradeablePackages();
        stopMovie();
        setIcon( QIcon( ":/Icons/icons/shaman/shaman-updates-available-32.png" ) );
        setToolTip( QString( tr( "Shaman - Idle (Upgrades Available)" ) ) );

        QSettings *settings = new QSettings();
        if ( settings->value( "scheduledUpdate/updateDbShowNotify" ).toBool() ) {
            showMessage( QString( tr( "System Upgrade" ) ), QString( tr( "Upgradeable package(s): %n.\n"
                         "Click here to upgrade your System.", "", upgrds.size() ) ) );
            disconnect( this, SIGNAL( messageClicked() ), 0, 0 );
            connect( this, SIGNAL( messageClicked() ), SIGNAL( upgradePkgs() ) );
            QTimer::singleShot( 10000, this, SLOT( disconnectBaloon() ) );
        }
        if ( settings->value( "scheduledUpdate/addupgradestoqueue" ).toBool() )
            mainWin->addUpgradeableToQueue();

        settings->deleteLater();
    }
}

void ShamanTrayIcon::transactionStarted()
{
    disableTrayActions();

    changeIconStatus( ShamanIcon::ProcessingIcon );
}

void ShamanTrayIcon::transactionReleased()
{
    enableTrayActions();

    if ( Backend::instance()->getUpgradeablePackages().isEmpty() ) {
        changeIconStatus( ShamanIcon::IdleIcon );
    } else {
        changeIconStatus( ShamanIcon::UpgradesAvailableIcon );
    }
}

void ShamanTrayIcon::enableTrayActions()
{
    foreach( QAction *act, systrayAct )
    act->setEnabled( true );
}

void ShamanTrayIcon::disableTrayActions()
{
    foreach( QAction *act, systrayAct )
    act->setEnabled( false );
}

void ShamanTrayIcon::startTimer()
{
    enableTimer();

    if ( !trayUpDb )
        return;

    QSettings *settings = new QSettings();

    if ( settings->value( "scheduledUpdate/enabled" ).toBool() == true )
        trayUpDb->start();

    settings->deleteLater();
}

void ShamanTrayIcon::stopTimer()
{
    enableTimer();

    if ( !trayUpDb )
        return;

    QSettings *settings = new QSettings();

    if ( settings->value( "scheduledUpdate/enabled" ).toBool() == true )
        trayUpDb->stop();

    settings->deleteLater();
}


void ShamanTrayIcon::changeTimerInterval()
{
    enableTimer();

    if ( !trayUpDb )
        return;

    QSettings *settings = new QSettings();

    if ( settings->value( "scheduledUpdate/enabled" ).toBool() ) {
        if ( trayUpDb == NULL )
            trayUpDb = new QTimer( this );
        else
            disconnect( trayUpDb, 0, 0, 0 );

        trayUpDb->setInterval( settings->value( "scheduledUpdate/interval", 10 ).toInt() * 60000 );

        connect( trayUpDb, SIGNAL( timeout() ), SLOT( dbUpdateTray() ) );
    } else {
        if ( trayUpDb != NULL ) {
            trayUpDb->deleteLater();
            trayUpDb = NULL;
        }
    }

    settings->deleteLater();
}

void ShamanTrayIcon::newNewsAvailable()
{
    QSettings *settings = new QSettings();

    if ( !settings->value( "newsreader/userss" ).toBool() || !settings->value( "newsreader/notifynew" ).toBool() ) {
        settings->deleteLater();
        return;
    }

    showMessage( QString( tr( "New News Available" ) ), QString( tr( "There are new news available.\n"
                 "Click here to review them." ) ) );
    disconnect( this, SIGNAL( messageClicked() ), 0, 0 );
    connect( this, SIGNAL( messageClicked() ), mainWin, SLOT( openNewsDialog() ) );
    QTimer::singleShot( 10000, this, SLOT( disconnectBaloon() ) );
}

void ShamanTrayIcon::newsFetchingFailed()
{
    QSettings *settings = new QSettings();

    if ( !settings->value( "newsreader/userss" ).toBool() ) {
        settings->deleteLater();
        return;
    }

    showMessage( QString( tr( "Failed Fetching News" ) ), QString( tr( "An error occourred while fetching news!\n"
                 "Click here to open the News Dialog for more details." ) ) );
    disconnect( this, SIGNAL( messageClicked() ), 0, 0 );
    connect( this, SIGNAL( messageClicked() ), mainWin, SLOT( openNewsDialog() ) );
    QTimer::singleShot( 10000, this, SLOT( disconnectBaloon() ) );
}

void ShamanTrayIcon::disconnectBaloon()
{
    disconnect( this, SIGNAL( messageClicked() ), 0, 0 );
}

void ShamanTrayIcon::enableTimer()
{
    QSettings *settings = new QSettings();

    if ( settings->value( "scheduledUpdate/enabled" ).toBool() ) {
        if ( trayUpDb )
            return;

        trayUpDb = new QTimer( this ); /* Oh yeah :) */
        trayUpDb->setInterval( settings->value( "scheduledUpdate/interval", 10 ).toInt() * 60000 );

        connect( trayUpDb, SIGNAL( timeout() ), SLOT( dbUpdateTray() ) );
    } else {
        if ( trayUpDb )
            trayUpDb->deleteLater();
    }

    settings->deleteLater();
}

void ShamanTrayIcon::enableTimerAt()
{
    QSettings *settings = new QSettings();

    if ( settings->value( "scheduledUpdate/enabledat" ).toBool() ) {
        if ( trayUpDbAt )
            return;

        trayUpDbAt = new QTimer( this ); /* Oh yeah :) */

        connect( trayUpDb, SIGNAL( timeout() ), SLOT( timerAtElapsed() ) );
    } else {
        if ( trayUpDbAt )
            trayUpDbAt->deleteLater();
    }

    settings->deleteLater();
}

void ShamanTrayIcon::resetTimerAt()
{
    enableTimerAt();

    if ( !trayUpDbAt )
        return;

    trayUpDbAt->stop();

    QSettings *settings = new QSettings();

    QTime time = settings->value( "scheduledUpdate/updatetime" ).toTime();

    int interval;

    if ( QTime::currentTime().msecsTo( time ) < 0 )
        interval = 86400000 + QTime::currentTime().msecsTo( time );
    else
        interval = QTime::currentTime().msecsTo( time );

    qDebug() << interval << "to elapse";

    trayUpDbAt->setInterval( interval );

    trayUpDbAt->start();

    settings->deleteLater();
}

void ShamanTrayIcon::timerAtElapsed()
{
    /* Are there some transactions in progress? If so, we simply skip
     * this cycle, and see you next time.
     */

    if ( Backend::instance()->isOnTransaction() )
        return;

    /* Set back the timer */

    trayUpDbAt->stop();

    trayUpDbAt->setInterval( 86400000 );

    trayUpDbAt->start();

    /* Ok, let's silently perform a Db Update.
     */

    emit startDbUpdate();
}

void ShamanTrayIcon::showMessage(const QString &title, const QString &message, MessageIcon icon, int millisecondsTimeoutHint)
{
#ifndef KDE4_INTEGRATION
    KAnimatedSystemTrayIcon::showMessage(title, message, icon, millisecondsTimeoutHint);
#else
    KNotification::event(KNotification::Notification, message);
#endif
}
