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

#ifndef SHAMANTRAYICON_H_
#define SHAMANTRAYICON_H_

#include "kanimatedsystemtrayicon.h"
#include "MainWindow.h"
#include "AlpmHandler.h"

namespace ShamanIcon {

	enum IconStatus {
		IdleIcon,
		UpgradesAvailableIcon,
		ProcessingIcon
	};

}  // namespace ShamanIcon


class ShamanTrayIcon : public KAnimatedSystemTrayIcon
{
	Q_OBJECT
	
public:
	explicit ShamanTrayIcon(MainWindow *mW, AlpmHandler *aH);
	virtual ~ShamanTrayIcon();
	
public slots:
	void changeIconStatus(ShamanIcon::IconStatus status);
	void dbUpdateTray();
	void startTimer();
	void stopTimer();
	void changeTimerInterval();
	
private slots:
	void transactionStarted();
	void transactionReleased();
	void enableTrayActions();
	void disableTrayActions();
	
signals:
	void startDbUpdate();
	
private:
	MainWindow *mainWin;
	AlpmHandler *aHandle;
	QTimer *trayUpDb;
	QList<QAction *> systrayAct;
	
};

#endif /*SHAMANTRAYICON_H_*/
