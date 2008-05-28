/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                                                    *
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

#ifndef REVIEWQUEUEDIALOG_H
#define REVIEWQUEUEDIALOG_H

#include "ui_reviewQueueDialog.h"
#include "AlpmHandler.h"
#include "MainWindow.h"

class ReviewQueueDialog : public QDialog, private Ui::QueueReadyDialog
{
	Q_OBJECT
	
public:
	ReviewQueueDialog(AlpmHandler *hnd, MainWindow *parent);
	virtual ~ReviewQueueDialog();
	bool isInTray();
	bool isTurnOff();
	bool force();
	
public slots:
	void processQueue();
	
private slots:
	void adjust(bool tgld);
	
signals:
	void goProcess();
	
private:
	AlpmHandler *aHandle;

};

#endif /*REVIEWQUEUEDIALOG_H*/
