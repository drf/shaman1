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
#include "BuildingDialog.h"

#include <iostream>
#include <QProcess>
#include <QString>
#include <QSettings>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include "ABSHandler.h"

BuildingDialog::BuildingDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
aHandle(hnd)
{
	setupUi(this);
	setWindowModality(Qt::ApplicationModal);
	connect(abortButton, SIGNAL(clicked()), this, SLOT(abortProcess()));
}

BuildingDialog::~BuildingDialog()
{
}

void BuildingDialog::abortProcess()
{
	QMessageBox *msgBox = new QMessageBox(this);

	msgBox->setIcon(QMessageBox::Question);
	msgBox->setWindowTitle(QString(tr("Error")));

	msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

	msgBox->setWindowModality(Qt::ApplicationModal);

	msgBox->setText(QString(tr("Would you like to abort building?.\nAll Process will be lost.")));

	switch (msgBox->exec()) {
	case QMessageBox::Yes:
		disconnect(ABSProc, SIGNAL(readyReadStandardOutput()), this, SLOT(writeLineProgress()));
		disconnect(ABSProc, SIGNAL(readyReadStandardError()), this, SLOT(writeLineProgressErr()));
		disconnect(ABSProc, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(finishedBuildingAction(int,QProcess::ExitStatus)));
		ABSProc->kill();
		progressEdit->append(QString(tr("<br><br><b>Building Process Aborted by the User. Building Failed.</b>")));
		emit finishedBuilding(2, builtPaths);
		break;
	case QMessageBox::No:
		break;
	default:
		// should never be reached
		break;
	}

	msgBox->deleteLater();
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
	
	progressEdit->moveCursor(QTextCursor::End);
}

void BuildingDialog::writeLineProgress()
{
	if(ABSProc->readChannel() == QProcess::StandardError)
		progressEdit->append(QString());
	
	ABSProc->setReadChannel(QProcess::StandardOutput);
	
	QString view(ABSProc->readLine(1024));
	
	view.replace(QChar('\n'), "<br>");

	QString tmp(view);
	tmp.remove(QChar('.'));

	if(tmp.isEmpty())
		return;

	progressEdit->insertHtml(view);
	
	progressEdit->moveCursor(QTextCursor::End);
}

void BuildingDialog::writeLineProgressErr()
{
	if(ABSProc->readChannel() == QProcess::StandardOutput)
		progressEdit->append(QString());
	
	ABSProc->setReadChannel(QProcess::StandardError);

	QString view(ABSProc->readLine(1024));

	view.replace(QChar('\n'), "<br>");
	
	QString tmp(view);
	tmp.remove(QChar('.'));
	
	if(tmp.isEmpty())
		return;
	
	progressEdit->insertHtml("<b><i>" + view + "</i></b>");
	
	progressEdit->moveCursor(QTextCursor::End);
}

void BuildingDialog::finishedUpdateABSTree()
{
	ABSProc->deleteLater();
	progressEdit->append(QString(tr("<br><br><b>ABS Tree Was Successfully Updated!</b>")));

	QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("ABS Update"), QString(tr("Your ABS Tree was updated!")),
			QMessageBox::Ok, this);

	message->exec();

	message->deleteLater();

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

		if(!path.endsWith(QChar('/')))
			path.append(QChar('/'));

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

	if(!path.endsWith(QChar('/')))
		path.append(QChar('/'));

	path.append(buildQueue.at(currentItem));
	
	ABSProc->setWorkingDirectory(path);

	connect(ABSProc, SIGNAL(readyReadStandardOutput()), SLOT(writeLineProgress()));
	connect(ABSProc, SIGNAL(readyReadStandardError()), SLOT(writeLineProgressErr()));
	connect(ABSProc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(finishedBuildingAction(int,QProcess::ExitStatus)));
	
	progressEdit->append(QString(tr("<b>Building %1...</b><br><br>")).arg(buildQueue.at(currentItem)));
		
	ABSProc->start("makepkg", QStringList("--asroot"));

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

void BuildingDialog::closeEvent(QCloseEvent *evt)
{
	emit nullifyPointer();
	evt->accept();
}
