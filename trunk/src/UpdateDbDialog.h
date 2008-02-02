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

#ifndef UPDATEDBDIALOG_H_
#define UPDATEDBDIALOG_H_

#include <iostream>
#include "../ui_dbUpdateDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

class UpDbThread : public QThread
{
public:
	UpDbThread(AlpmHandler *aH);
	void run();
private:
	AlpmHandler *aHandle;
};

class UpdateDbDialog : public QDialog, private Ui::dbUpdateDialog
{
	Q_OBJECT
	
public:
	UpdateDbDialog(AlpmHandler *hnd, QWidget *parent = 0);
	virtual ~UpdateDbDialog();
	
	bool dbHasBeenUpdated();

public slots:
	void doAction();
	
private slots:
	void updateLabel(char *repo, int action);
	//void updateDlProg(float bytetotal, float bytedled, float speed);
	void updateTotalProg();
	void setPBarRange(int range);
	void setUpdated();
	void scopeEnded();
	void updateDlBar(char *c, int bytedone, int bytetotal, int speed,
			int i, int j, int k);
	
signals:
	void killMe();
	
private:
	int currentAction;
	char *currentRepo;
	int actionDone;
	bool updated;
	AlpmHandler *aHandle;
	UpDbThread *dbth;
	
};

#endif /*UPDATEDBDIALOG_H_*/
