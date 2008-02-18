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
#include <QDebug>
#include <QMessageBox>
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

	processingLabel->setText(QString(tr("Updating ABS Tree...")));
	buildingLabel->setText(QString());

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
	progressEdit->append(QString(tr("<br><br><b>ABS Tree Was Successfully Updated!</b>")));

	QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("ABS Update"), QString(tr("Your ABS Tree was updated!")),
			QMessageBox::Ok);

	message->exec();

	message->deleteLater();
	return;

	this->close();
}

void BuildingDialog::finishedBuildingAction(int ecode, QProcess::ExitStatus estat)
{
	Q_UNUSED(estat);
	
	if(ecode != 0)
	{
		failed = true;
		progressEdit->append(QString(tr("<b>Building %1 failed!!</b><br><br>")).arg(buildQueue.at(currentItem)));
		progressEdit->append(ABSProc->readAllStandardError());
	}
	else
	{
		progressEdit->append(QString(tr("<b>%1 was built successfully!!</b><br><br>")).arg(buildQueue.at(currentItem)));
		allFailed = false;

		QSettings *settings = new QSettings();

		QString path(settings->value("absbuilding/buildpath").toString());

		settings->deleteLater();

		if(!path.endsWith("/"))
			path.append("/");

		path.append(buildQueue.at(currentItem));
		
		QDir dir(path);

		dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

		QFileInfoList list = dir.entryInfoList();
		
		for (int i = 0; i < list.size(); ++i) 
		{
			if(list.at(i).absoluteFilePath().endsWith("pkg.tar.gz"))
			{
				builtPaths.append(list.at(i).absoluteFilePath());
				qDebug() << "In queue: " << list.at(i).absoluteFilePath();
			}
		}
		
	}
	
	currentItem++;
	
	if(currentItem == buildQueue.size())
	{
		if(allFailed)
			emit finishedBuilding(2, builtPaths);
		else if(failed)
			emit finishedBuilding(1, builtPaths);
		else
			emit finishedBuilding(0, builtPaths);
		
		return;
	}
	
	processCurrentQueueItem();
	
}

void BuildingDialog::processCurrentQueueItem()
{
	ABSProc->deleteLater();
	
	ABSProc = new QProcess();
	
	processingLabel->setText(QString(tr("Processing Package %1 of %2...")).arg(currentItem + 1).arg(buildQueue.size()));
	buildingLabel->setText(QString(tr("Building %1...")).arg(buildQueue.at(currentItem)));

	/* Let's build the path we need */
	
	if(!setUpBuildingEnvironment(buildQueue.at(currentItem)))
		finishedBuildingAction(1, QProcess::CrashExit);
		
	QSettings *settings = new QSettings();

	QString path(settings->value("absbuilding/buildpath").toString());

	settings->deleteLater();

	if(!path.endsWith("/"))
		path.append("/");

	path.append(buildQueue.at(currentItem));
	
	ABSProc->setWorkingDirectory(path);

	connect(ABSProc, SIGNAL(readyReadStandardOutput()), SLOT(writeLineProgress()));
	connect(ABSProc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(finishedBuildingAction(int,QProcess::ExitStatus)));
	
	progressEdit->append(QString(tr("<b>Building %1...</b><br><br>")).arg(buildQueue.at(currentItem)));
		
	ABSProc->start("makepkg", QStringList("--asroot"));

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
		qDebug() << list.at(i).absoluteFilePath();
		QDir subAbsDir(list.at(i).absoluteFilePath());
		subAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
		QFileInfoList subList = subAbsDir.entryInfoList();
		for (int k = 0; k < subList.size(); ++k) 
		{
			qDebug() << subList.at(k).absoluteFilePath();
			QDir subUbAbsDir(subList.at(k).absoluteFilePath());
			subUbAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
			QFileInfoList subUbList = subUbAbsDir.entryInfoList();
			for (int j = 0; j < subUbList.size(); ++j) 
			{
				qDebug() << subUbList.at(j).baseName();
				if(!subUbList.at(j).baseName().compare(package))
				{
					found = 1;
					absSource = subUbList.at(j).absoluteFilePath();
					break;
				}
			}
		}
		if(found == 1)
			break;
	}
	
	if(!found)
		return false;
	
	qDebug() << "ABS Dir is " << absSource;
	
	QDir absPDir(absSource);
	absPDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot | QDir::NoSymLinks);
	
	QFileInfoList Plist = absPDir.entryInfoList();

	for (int i = 0; i < Plist.size(); ++i) 
	{
		QString dest(path);
		if(!dest.endsWith("/"))
			dest.append("/");
		dest.append(Plist.at(i).fileName());
		
		qDebug() << "Copying " << Plist.at(i).absoluteFilePath() << " to " << dest;
		
		if(!QFile::copy(Plist.at(i).absoluteFilePath(), dest))
		{
			return false;
		}
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

void BuildingDialog::initBuildingQueue()
{
	currentItem = 0;
	buildQueue.clear();
	failed = false;
	allFailed = true;
	waitProcessing = false;
}

void BuildingDialog::addBuildingQueueItem(const QString &item)
{
	buildQueue.append(item);
}

void BuildingDialog::processBuildingQueue()
{
	if(buildQueue.isEmpty())
		return;
	
	progressEdit->append(QString(tr("<b>Building operation has started.</b><br><br>")));
	
	processCurrentQueueItem();
}

void BuildingDialog::waitBeforeProcess(bool yn)
{
	waitProcessing = yn;
}

bool BuildingDialog::reviewOutputFirst()
{
	return waitProcessing;
}
