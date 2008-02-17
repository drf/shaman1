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
#include <QDir>
#include "../ui_buildingDialog.h"

#include "BuildingDialog.h"

BuildingDialog::BuildingDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
aHandle(hnd)
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
	QSettings *settings = new QSettings();

	QString path(settings->value("absbuilding/buildpath").toString());

	settings->deleteLater();

	if(!path.endsWith("/"))
		path.append("/");
	
	path.append(package);
	
	QDir pathDir(path);
	if(pathDir.exists())
		cleanBuildingEnvironment(package);
	
	if(!pathDir.mkpath(path))
		return false;
	
	QDir absDir("/var/abs");
	absDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
	
	int found = 0;
	QString absSource;
	
	QFileInfoList list = absDir.entryInfoList();
	
	for (int i = 0; i < list.size(); ++i) 
	{
		QDir subAbsDir(list.at(i).absoluteFilePath());
		subAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
		QFileInfoList subList = subAbsDir.entryInfoList();
		for (int j = 0; j < list.size(); ++j) 
		{
			if(subList.at(j).baseName().compare(package))
			{
				found = 1;
				absSource = subList.at(j).absoluteFilePath();
				break;
			}
		}
		if(found == 1)
			break;
	}
	
	if(!found)
		return false;
	
	QDir absPDir(absSource);
	absPDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot | QDir::NoSymLinks);
	
	QFileInfoList Plist = absPDir.entryInfoList();

	for (int i = 0; i < Plist.size(); ++i) 
	{
		QString dest(path);
		if(!dest.endsWith("/"))
			dest.append("/");
		dest.append(Plist.at(i).fileName());
		
		if(!QFile::copy(Plist.at(i).absoluteFilePath(), dest))
			return false;
	}
	
	return true;
}

bool BuildingDialog::cleanBuildingEnvironment(const QString &package)
{
	QSettings *settings = new QSettings();

	QString path(settings->value("absbuilding/buildpath").toString());

	settings->deleteLater();

	if(!path.endsWith("/"))
		path.append("/");

	path.append(package);
	
	aHandle->rmrf(path.toAscii().data());
	
	return true;
}
