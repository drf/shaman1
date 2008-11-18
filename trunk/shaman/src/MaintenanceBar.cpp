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

#include "MaintenanceBar.h"

#include <aqpm/Backend.h>

#include "configDialog.h"

#include <QComboBox>
#include <QAction>
#include <QDebug>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

MaintenanceBar::MaintenanceBar( QWidget *parent )
        : QToolBar( parent ),
        ath( new Authenticator( this ) )
{
    setObjectName( "MaintenanceBar" );

    setWindowTitle( QString( tr( "Maintenance Actions" ) ) );

    QComboBox *box = new QComboBox();
    box->addItems( QStringList() <<
                   QString( tr( "Please choose an action to start maintenance..." ) ) <<
                   QString() <<
                   QString( tr( "Clean Unused Databases" ) ) <<
                   QString( tr( "Clean Cache" ) ) <<
                   QString( tr( "Empty Cache" ) ) <<
                   QString( tr( "Optimize Pacman Database" ) ) <<
                   QString( tr( "Clean All Building Environments" ) ) );

    box->setCurrentIndex( 0 );

    connect( box, SIGNAL( currentIndexChanged( int ) ), SLOT( performAction() ) );

    m_comboBox = addWidget( box );
}

MaintenanceBar::~MaintenanceBar()
{
}

void MaintenanceBar::performAction()
{
    QComboBox *box = qobject_cast<QComboBox*>( widgetForAction( m_comboBox ) );

    if ( box == 0 )
        return;

    switch ( qobject_cast<QComboBox*>( widgetForAction( m_comboBox ) )->currentIndex() ) {
    case 0:
    case 1:
        box->setCurrentIndex( 0 );
        break;

    case 2:
        openDialog();

        cTh = new CleanThread( 0 );

        statusLabel->setText( QString( tr( "Cleaning up unused Databases..." ) ) );
        mantDetails->append( QString( tr( "Cleaning up unused Databases..." ) ) );

        connect( cTh, SIGNAL( success( int ) ), SLOT( showSuccess( int ) ) );
        connect( cTh, SIGNAL( failure( int ) ), SLOT( showFailure( int ) ) );
        connect( cTh, SIGNAL( finished() ), cTh, SLOT( deleteLater() ) );
        cTh->start();
        break;

    case 3:
        openDialog();

        cTh = new CleanThread( 1 );

        statusLabel->setText( QString( tr( "Cleaning up Cache..." ) ) );
        mantDetails->append( QString( tr( "Cleaning up Cache..." ) ) );

        connect( cTh, SIGNAL( success( int ) ), SLOT( showSuccess( int ) ) );
        connect( cTh, SIGNAL( failure( int ) ), SLOT( showFailure( int ) ) );
        connect( cTh, SIGNAL( finished() ), cTh, SLOT( deleteLater() ) );
        cTh->start();
        break;

    case 4:
        openDialog();

        cTh = new CleanThread( 2 );

        statusLabel->setText( QString( tr( "Deleting Cache..." ) ) );
        mantDetails->append( QString( tr( "Deleting Cache..." ) ) );

        connect( cTh, SIGNAL( success( int ) ), SLOT( showSuccess( int ) ) );
        connect( cTh, SIGNAL( failure( int ) ), SLOT( showFailure( int ) ) );
        connect( cTh, SIGNAL( finished() ), cTh, SLOT( deleteLater() ) );
        cTh->start();
        break;

    case 5:
        openDialog();

        mantProc = new RootProcess();

        connect( mantProc, SIGNAL( readyReadStandardError() ), SLOT( mantProgress() ) );
        connect( mantProc, SIGNAL( finished( int, QProcess::ExitStatus ) ), SLOT( cleanProc( int, QProcess::ExitStatus ) ) );

        statusLabel->setText( QString( tr( "Optimizing Pacman Database..." ) ) );
        mantDetails->append( QString( tr( "Optimizing Pacman Database..." ) ) );

        qDebug() << "Starting the process";

        ath->switchToRoot();

        mantProc->start( "pacman-optimize" );

        ath->switchToStdUsr();
        break;

    case 6:
        openDialog();

        cTh = new CleanThread( 3 );

        statusLabel->setText( QString( tr( "Cleaning up building Environments..." ) ) );
        mantDetails->append( QString( tr( "Cleaning up building Environments..." ) ) );

        connect( cTh, SIGNAL( success( int ) ), SLOT( showSuccess( int ) ) );
        connect( cTh, SIGNAL( failure( int ) ), SLOT( showFailure( int ) ) );
        connect( cTh, SIGNAL( finished() ), cTh, SLOT( deleteLater() ) );
        cTh->start();
        break;

    default:
        break;
    }
}

void MaintenanceBar::openDialog()
{
    if ( m_dialog )
        m_dialog->deleteLater();

    m_dialog = new QDialog( parentWidget() );
    statusLabel = new QLabel();
    mantDetails = new QTextEdit();
    QVBoxLayout *lay = new QVBoxLayout();
    QHBoxLayout *hlay = new QHBoxLayout();
    m_button = new QPushButton();

    mantDetails->setReadOnly( true );
    m_button->setText( QString( tr( "Abort" ) ) );
    m_button->setIcon( QPixmap( ":/Icons/icons/dialog-cancel.png" ) );

    lay->addWidget( statusLabel );
    lay->addWidget( mantDetails );

    hlay->addStretch();
    hlay->addWidget( m_button );

    lay->addLayout( hlay );

    m_dialog->setLayout( lay );
    m_dialog->setModal( true );
    m_dialog->setWindowTitle( QString( tr( "System Maintenance" ) ) );
    m_dialog->show();
}

void MaintenanceBar::showSuccess( int act )
{
    switch ( act ) {
    case 0:
        statusLabel->setText( QString( tr( "Unused Databases Cleaned up successfully!" ) ) );
        mantDetails->append( QString( tr( "Unused Databases Cleaned up successfully!" ) ) );
        alpm_logaction( QString( tr( "Unused Databases Cleaned up successfully!" ) + QChar( '\n' ) ).toUtf8().data() );
        break;

    case 1:
        statusLabel->setText( QString( tr( "Cache Cleaned Up Successfully!" ) ) );
        mantDetails->append( QString( tr( "Cache Cleaned Up Successfully!" ) ) );
        alpm_logaction( QString( tr( "Cache Cleaned Up Successfully!" ) + QChar( '\n' ) ).toUtf8().data() );
        break;

    case 2:
        statusLabel->setText( QString( tr( "Cache Successfully Deleted!" ) ) );
        mantDetails->append( QString( tr( "Cache Successfully Deleted!" ) ) );
        alpm_logaction( QString( tr( "Cache Successfully Deleted!" ) + QChar( '\n' ) ).toUtf8().data() );
        break;

    case 3:
        statusLabel->setText( QString( tr( "Build Environments Successfully Cleaned!" ) ) );
        mantDetails->append( QString( tr( "Build Environments Successfully Cleaned!" ) ) );
        alpm_logaction( QString( tr( "Build Environments Successfully Cleaned!" ) + QChar( '\n' ) ).toUtf8().data() );
        break;
    }

    mantDetails->moveCursor( QTextCursor::End );

    m_button->setText( QString( tr( "Close" ) ) );
    m_button->setIcon( QPixmap( ":/Icons/icons/dialog-ok-apply.png" ) );

    connect( m_button, SIGNAL( clicked() ), m_dialog, SLOT( deleteLater() ) );

    QComboBox *box = qobject_cast<QComboBox*>( widgetForAction( m_comboBox ) );

    if ( box == 0 )
        return;

    box->setCurrentIndex( 0 );
}

void MaintenanceBar::showFailure( int act )
{
    switch ( act ) {
    case 0:
        statusLabel->setText( QString( tr( "Cleaning up Unused Databases Failed!" ) ) );
        mantDetails->append( QString( tr( "Cleaning up Unused Databases Failed!" ) ) );
        break;

    case 1:
        statusLabel->setText( QString( tr( "Cleaning up Cache Failed!" ) ) );
        mantDetails->append( QString( tr( "Cleaning up Cache Failed!" ) ) );
        break;

    case 2:
        statusLabel->setText( QString( tr( "Deleting Cache Failed!" ) ) );
        mantDetails->append( QString( tr( "Deleting Cache Failed!" ) ) );
        break;

    case 3:
        statusLabel->setText( QString( tr( "Could not clean Build Environments!!" ) ) );
        mantDetails->append( QString( tr( "Could not clean Build Environments!!" ) ) );
        break;
    }

    mantDetails->moveCursor( QTextCursor::End );

    m_button->setText( QString( tr( "Close" ) ) );
    m_button->setIcon( QPixmap( ":/Icons/icons/dialog-ok-apply.png" ) );

    connect( m_button, SIGNAL( clicked() ), m_dialog, SLOT( deleteLater() ) );

    QComboBox *box = qobject_cast<QComboBox*>( widgetForAction( m_comboBox ) );

    if ( box == 0 )
        return;

    box->setCurrentIndex( 0 );
}

void MaintenanceBar::cleanProc( int eC, QProcess::ExitStatus eS )
{
    Q_UNUSED( eS );

    if ( eC == 0 ) {
        statusLabel->setText( QString( tr( "Pacman Database Optimized Successfully!" ) ) );
        mantDetails->append( QString( tr( "Pacman Database Optimized Successfully!" ) ) );
        alpm_logaction( QString( tr( "Pacman Database Optimized Successfully!" ) + QChar( '\n' ) ).toUtf8().data() );
    } else {
        statusLabel->setText( QString( tr( "Could not Optimize Pacman Database!" ) ) );
        mantDetails->append( QString( tr( "Could not Optimize Pacman Database!" ) ) );
        alpm_logaction( QString( tr( "Could not Optimize Pacman Database!" ) + QChar( '\n' ) ).toUtf8().data() );
    }

    mantProc->deleteLater();

    mantDetails->moveCursor( QTextCursor::End );

    statusLabel->setText( QString( tr( "Running sync...", "sync is a command, so it should not be translated" ) ) );
    mantDetails->append( QString( tr( "Running sync...", "sync is a command, so it should not be translated" ) ) );

    mantProc = new RootProcess();

    ath->switchToRoot();

    if ( mantProc->execute( "sync" ) == 0 ) {
        statusLabel->setText( QString( tr( "Operation Completed Successfully!" ) ) );
        mantDetails->append( QString( tr( "Sync was successfully executed!!", "Sync is always the command" ) ) );
        mantDetails->append( QString( tr( "Operation Completed Successfully!" ) ) );
    } else {
        statusLabel->setText( QString( tr( "Sync could not be executed!", "Sync is always the command" ) ) );
        mantDetails->append( QString( tr( "Sync could not be executed!!", "Sync is always the command" ) ) );
    }

    ath->switchToStdUsr();

    mantDetails->moveCursor( QTextCursor::End );

    mantProc->deleteLater();

    m_button->setText( QString( tr( "Close" ) ) );
    m_button->setIcon( QPixmap( ":/Icons/icons/dialog-ok-apply.png" ) );

    connect( m_button, SIGNAL( clicked() ), m_dialog, SLOT( deleteLater() ) );

    QComboBox *box = qobject_cast<QComboBox*>( widgetForAction( m_comboBox ) );

    if ( box == 0 )
        return;

    box->setCurrentIndex( 0 );
}

void MaintenanceBar::mantProgress()
{
    mantProc->setReadChannel( QProcess::StandardError );
    QString str = QString::fromLocal8Bit( mantProc->readLine( 1024 ) );
    mantDetails->append( QString( "<b><i>" + str + "</b></i>" ) );
    qDebug() << str;
    mantDetails->moveCursor( QTextCursor::End );
}
