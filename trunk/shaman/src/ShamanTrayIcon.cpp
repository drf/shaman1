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

#include <QTimer>
#include <QSettings>
#include <QMovie>

ShamanTrayIcon::ShamanTrayIcon(MainWindow *mW, AlpmHandler *aH)
 : mainWin(mW),
   aHandle(aH)
{
	if(aHandle->getUpgradeablePackages().isEmpty())
		changeIconStatus(ShamanIcon::IdleIcon);
	else
		changeIconStatus(ShamanIcon::UpgradesAvailableIcon);
	
	show();

	systrayAct.clear();

	QMenu *systrayMenu = new QMenu();

	QAction *updateDBAction = systrayMenu->addAction(QIcon(":/Icons/icons/view-refresh.png"), tr("Update Database"));
	connect(updateDBAction, SIGNAL(triggered()), mainWin, SLOT(doDbUpdate()));
	systrayAct.append(updateDBAction);

	QAction *upgradeAction = systrayMenu->addAction(QIcon(":/Icons/icons/system-software-update.png"), tr("Upgrade System"));
	connect(upgradeAction, SIGNAL(triggered()), mainWin, SLOT(fullSysUpgrade()));
	systrayAct.append(upgradeAction);

	QAction *queueAction = systrayMenu->addAction(QIcon(":/Icons/icons/dialog-ok-apply.png"), tr("Process Queue"));
	connect(queueAction, SIGNAL(triggered()), mainWin, SLOT(widgetQueueToAlpmQueue()));
	systrayAct.append(queueAction);
	systrayMenu->addSeparator();

	QAction *settingsAction = systrayMenu->addAction(QIcon(":/Icons/icons/preferences-system.png"), tr("Settings"));
	connect(settingsAction, SIGNAL(triggered()), mainWin, SLOT(showSettings()));
	systrayAct.append(settingsAction);
	systrayMenu->addSeparator();

	QAction *closeAction = systrayMenu->addAction(QIcon(":/Icons/icons/application-exit.png"), tr("Quit"));
	connect(closeAction, SIGNAL(triggered()), mainWin, SLOT(quitApp()));
	systrayAct.append(closeAction);

	//Add actions here ;)
	setContextMenu(systrayMenu);

	connect(aHandle, SIGNAL(transactionStarted()), SLOT(transactionStarted()));
	connect(aHandle, SIGNAL(transactionReleased()), SLOT(transactionReleased()));
	
	connect(mainWin, SIGNAL(buildingStarted()), SLOT(transactionStarted()));
	connect(mainWin, SIGNAL(buildingFinished()), SLOT(transactionReleased()));

	QSettings *settings = new QSettings();

	if(settings->value("scheduledUpdate/enabled").toBool())
	{
		trayUpDb = new QTimer(this); /* Oh yeah :) */
		trayUpDb->setInterval(settings->value("scheduledUpdate/interval", 10).toInt() * 60000);

		connect(trayUpDb, SIGNAL(timeout()), SLOT(dbUpdateTray()));
	}
	else
		trayUpDb = NULL;

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
	
	if(aHandle->isTransaction())
		return;
	
	/* Ok, let's silently perform a Db Update.
	 */
	
	emit startDbUpdate();
}

void ShamanTrayIcon::changeIconStatus(ShamanIcon::IconStatus status)
{
	if(status == ShamanIcon::IdleIcon)
	{
		stopMovie();
		setIcon(QIcon(":/Icons/icons/shaman/shaman-32.png"));
		setToolTip(QString(tr("Shaman - Idle")));
	}
	else if(status == ShamanIcon::ProcessingIcon)
	{
		setMovie(new QMovie(":/Icons/icons/shaman/shaman-animation.mng"));
		startMovie();
		setToolTip(QString(tr("Shaman - Processing")));
	}
	else
	{
		QStringList upgrds = aHandle->getUpgradeablePackages();
		stopMovie();
		setIcon(QIcon(":/Icons/icons/shaman/shaman-updates-available-32.png"));
		setToolTip(QString(tr("Shaman - Idle (Upgrades Available)")));
		showMessage(QString(tr("System Upgrade")), QString(upgrds.size() == 1 ? tr("There is %1 upgradeable package.\n"
				"Click here to upgrade your System.") :	tr("There are %1 upgradeable packages.\nClick here to upgrade your System.")).
				arg(upgrds.size()));
		connect(this, SIGNAL(messageClicked()), mainWin, SLOT(fullSysUpgrade()));
	}
}

void ShamanTrayIcon::transactionStarted()
{
	disableTrayActions();
	
	changeIconStatus(ShamanIcon::ProcessingIcon);
}

void ShamanTrayIcon::transactionReleased()
{
	enableTrayActions();
	
	if(aHandle->getUpgradeablePackages().isEmpty())
		changeIconStatus(ShamanIcon::IdleIcon);
	else
		changeIconStatus(ShamanIcon::UpgradesAvailableIcon);
}

void ShamanTrayIcon::enableTrayActions()
{
	foreach(QAction *act, systrayAct)
		act->setEnabled(true);
}

void ShamanTrayIcon::disableTrayActions()
{
	foreach(QAction *act, systrayAct)
		act->setEnabled(false);
}

void ShamanTrayIcon::startTimer()
{
	QSettings *settings = new QSettings();
	
	if(settings->value("scheduledUpdate/enabled").toBool() == true)
		trayUpDb->start();
	
	settings->deleteLater();
}

void ShamanTrayIcon::stopTimer()
{
	QSettings *settings = new QSettings();
	
	if(settings->value("scheduledUpdate/enabled").toBool() == true)
		trayUpDb->stop();
	
	settings->deleteLater();
}


void ShamanTrayIcon::changeTimerInterval()
{
	QSettings *settings = new QSettings();

	if(settings->value("scheduledUpdate/enabled").toBool())
	{
		if(trayUpDb == NULL)
			trayUpDb = new QTimer(this);
		else
			disconnect(trayUpDb, 0, 0, 0);
		
		trayUpDb->setInterval(settings->value("scheduledUpdate/interval", 10).toInt() * 60000);

		connect(trayUpDb, SIGNAL(timeout()), SLOT(dbUpdateTray()));
	}
	else
	{
		if(trayUpDb != NULL)
		{
			trayUpDb->deleteLater();
			trayUpDb = NULL;
		}
	}
	
	settings->deleteLater();
}
