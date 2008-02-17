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

#include <iostream>
#include <QProcess>
#include <QString>
#include <QSettings>
#include "../ui_buildingDialog.h"

#include "BuildingDialog.h"

BuildingDialog::BuildingDialog(QWidget *parent)
: QDialog(parent)
{
	setupUi(this);
	setWindowModality(Qt::ApplicationModal);
}

BuildingDialog::~BuildingDialog()
{
}

void BuildingDialog::updateABSTree()
{
	ABSProc = new QProcess(this);
	connect(ABSProc, SIGNAL(readyReadStandardOutput()), SLOT(writeLineProgress()));
	connect(ABSProc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(finishedUpdateABSTree()));
	
	progressEdit->append(QString(tr("<b>Starting ABS Tree Update...</b><br><br>")));
	ABSProc->start("abs");
}

void BuildingDialog::writeLineProgress()
{
	progressEdit->append(ABSProc->readLine(1024));
}

void BuildingDialog::finishedUpdateABSTree()
{
	ABSProc->deleteLater();
	progressEdit->append(QString(tr("<br><br><b>ABS Tree Was Successfully Updated</b>")));
}

void BuildingDialog::finishedBuildingAction(int ecode, QProcess::ExitStatus estat)
{
	Q_UNUSED(estat);
	
	if(ecode != 0)
		failed = true;
	else
		allFailed = false;
	
	currentItem++;
	
	if(!(currentItem < buildQueue.size()))
	{
		if(allFailed)
			emit finishedBuilding(2);
		else if(failed)
			emit finishedBuilding(1);
		else
			emit finishedBuilding(0);
		
		return;
	}
	
	processCurrentQueueItem();
	
}

void BuildingDialog::processCurrentQueueItem()
{
	delete(ABSProc);

	ABSProc = new QProcess();

	/* Let's build the path we need */
	
	if(!setUpBuildingEnvironment(buildQueue.at(currentItem)))
		finishedBuildingAction(1, QProcess::CrashExit);

	QSettings *settings = new QSettings();

	QString path(settings->value("absbuilding/buildpath").toString());

	settings->deleteLater();

	if(!path.endsWith("/"))
		path.append("/");

}

bool BuildingDialog::setUpBuildingEnvironment(const QString &package)
{
	
}
