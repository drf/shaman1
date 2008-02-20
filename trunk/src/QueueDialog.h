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

#ifndef QUEUEDIALOG_H_
#define QUEUEDIALOG_H_

#include <iostream>
#include "../ui_transactionDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include "AlpmHandler.h"

#include <QThread>

class TrCommitThread : public QThread
{
public:
	TrCommitThread(AlpmHandler *aH);
	void run();
private:
	AlpmHandler *aHandle;
};


class QueueDialog : public QDialog, private Ui::transactionDialog
{
	Q_OBJECT
	
public:
	explicit QueueDialog(AlpmHandler *hnd, QWidget *parent = 0);
	~QueueDialog();
	void startProcessing();
	
public slots:
	void changeStatus(pmtransevt_t event, void *data1, void *data2);
	void updateProgressBar(char *c, int bytedone, int bytetotal, int speed,
			int listdone, int listtotal, int speedtotal);
	void updateProgressBar(pmtransprog_t event, char *pkgname, int percent,
	        int howmany, int remain);
	void startDownload();
	void startProcess();
	void cleanup();
	
signals:
	void terminated(bool errors);
	
private:
	AlpmHandler *aHandle;
	TrCommitThread *cTh;
	int status;
};

#endif /*QUEUEDIALOG_H_*/
