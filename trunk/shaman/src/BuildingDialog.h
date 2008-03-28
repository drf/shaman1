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

#ifndef BUILDINGDIALOG_H_
#define BUILDINGDIALOG_H_

#include <iostream>
#include "AlpmHandler.h"
#include "ABSHandler.h"
#include "ui_buildingDialog.h"

#include <QProcess>

class ABSHandler;

class BuildingDialog : public QDialog, public Ui::buildingDialog, private ABSHandler
{
	Q_OBJECT
	
public:
	explicit BuildingDialog(AlpmHandler *hnd, QWidget *parent = 0);
	virtual ~BuildingDialog();
	
	void initBuildingQueue();
	void addBuildingQueueItem(const QString &item);
	void processBuildingQueue();
	void waitBeforeProcess(bool yn);
	bool reviewOutputFirst();
	
public slots:
	void updateABSTree();
	void writeLineProgress();
	void writeLineProgressErr();
	void writeLineProgressMk();
	void writeLineProgressErrMk();
	void finishedUpdateABSTree();
	void finishedBuildingAction(int ecode, QProcess::ExitStatus estat);
	void abortProcess();
	
protected:
	void closeEvent(QCloseEvent *evt);
	
private:
	void processCurrentQueueItem();
	
signals:
	void finishedBuilding(int failurelevel, const QStringList &bp);
	void nullifyPointer();
	
private:
	RootProcess *ABSProc;
	QProcess *MakePkgProc;
	QStringList buildQueue;
	QStringList builtPaths;
	int currentItem;
	bool failed;
	bool allFailed;
	bool waitProcessing;
	AlpmHandler *aHandle;
	Authenticator ath;
	
};

#endif /*BUILDINGDIALOG_H_*/
