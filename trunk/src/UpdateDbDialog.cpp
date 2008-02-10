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

#include "UpdateDbDialog.h"
#include <AlpmHandler.h>
#include <sstream>
#include "callbacks.h"
#include <QtGui>

extern CallBacks CbackReference;

using namespace std;

UpdateDbDialog::UpdateDbDialog(AlpmHandler *hnd, QWidget *parent) 
 : QDialog(parent),
   actionDone(0),
   updated(false),
   aHandle(hnd)
{	
	setupUi(this);
        setWindowModality(Qt::ApplicationModal);
	
	connect(aHandle, SIGNAL(streamDbUpdatingStatus(char*,int)), this,
				SLOT(updateLabel(char*, int)));
	connect(aHandle, SIGNAL(dbQty(QStringList)), this, SLOT(createWidgets(QStringList)));
	connect(aHandle, SIGNAL(dbUpdated()), this, SLOT(setUpdated()));
	connect(aHandle, SIGNAL(dbUpdatePerformed()), this, SLOT(updateTotalProg()));
	connect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 
			this, SLOT(updateDlBar(char*,int,int,int,int,int,int)));
}

UpdateDbDialog::~UpdateDbDialog()
{
	disconnect(aHandle, SIGNAL(streamDbUpdatingStatus(char*,int)), 0, 0);
	disconnect(aHandle, SIGNAL(dbQty(int)), 0, 0);
	disconnect(aHandle, SIGNAL(dbUpdated()), 0, 0);
	disconnect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 0, 0);
}

void UpdateDbDialog::updateLabel(char *repo, int action)
{
	QLabel *toInsert = labelList.at(actionDone);
	
	switch(action)
	{
	case 0:
		toInsert->setText("<i>Checking...</i>");
		break;
	case 1:
		toInsert->setText("<i>Downloading...</i>");
		break;
	case 2:
		toInsert->setText("<i>Installing...</i>");
		break;
	case 3:
		toInsert->setText("<i>Up to Date</i>");
		//dlProgress->setFormat(toInsert);
		break;
	default:
		break;
	}
}

void UpdateDbDialog::setUpdated()
{
	updated = true;
}

bool UpdateDbDialog::dbHasBeenUpdated()
{
	return updated;
}

void UpdateDbDialog::updateTotalProg()
{
	actionDone++;
}

void UpdateDbDialog::updateDlBar(char *c, int bytedone, int bytetotal, int speed,
		int i, int j, int k)
{
        Q_UNUSED(c)
        Q_UNUSED(i)
        Q_UNUSED(j)
        Q_UNUSED(k)
	QString toInsert, spd;
	
	spd.setNum(speed);
	toInsert.append("%p% at ");
	toInsert.append(spd);
	toInsert.append(" KB/s");
}

void UpdateDbDialog::doAction()
{
	dbth = new UpDbThread(aHandle);
	dbth->start();
	connect(dbth, SIGNAL(finished()), this, SLOT(scopeEnded()));
}

void UpdateDbDialog::scopeEnded()
{
	delete(dbth);
	
	emit killMe();
}

UpDbThread::UpDbThread(AlpmHandler *aH)
{
	aHandle = aH;
}

void UpDbThread::run()
{
	aHandle->updateDatabase();
}

void UpdateDbDialog::createWidgets(QStringList list)
{
	//QGridLayout *layout = new QGridLayout(this);
	
	for (int i = 0; i < list.size(); ++i)
	{
		QLabel *labelDb = new QLabel(this);
		QLabel *labelStatus = new QLabel(this);
		
		labelDb->setText(QString("<b>%1</b>").arg(list.at(i)));
		labelStatus->setText(QString("<i>Waiting...</i>"));
		
		printf("here\n");
		gridLayout->addWidget(labelDb, i+1, 0);
		printf("here\n");
		gridLayout->addWidget(labelStatus, i+1, 1);
		
		printf("here\n");
		
		labelList.append(labelStatus);
		
	}
}
