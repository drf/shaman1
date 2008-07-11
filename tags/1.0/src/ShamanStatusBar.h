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
 **************************************************************************/

#ifndef SHAMANSTATUSBAR_H
#define SHAMANSTATUSBAR_H

#include <QStatusBar>
#include <QPointer>
#include <QLabel>
#include <QProgressBar>
#include <QWidget>

#include "AlpmHandler.h"
#include "MainWindow.h"

class ShamanStatusBar : public QStatusBar
{
	Q_OBJECT
	
public:
	explicit ShamanStatusBar(AlpmHandler *aH, MainWindow *parent = 0);
	virtual ~ShamanStatusBar();
	
public Q_SLOTS:
	void showStBarAction(const QString &text, const QPixmap &pixmap, int timeout = 10);
	void clearStBarAction();
	void updateStatusBar();
	void startProgressBar();
	void stopProgressBar();
	void updateProgressBar(int percentage);
	
private:
	void setUpStatusBar();
	
private:
	AlpmHandler *aHandle;
	MainWindow *mWin;
	
	QPointer<QLabel> stBarImage;
	QPointer<QLabel> stBarText;
	QPointer<QProgressBar> stBarProg;
};

#endif /*SHAMANSTATUSBAR_H*/
