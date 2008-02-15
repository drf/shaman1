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

extern CallBacks CbackReference;

using namespace std;

UpdateDbDialog::UpdateDbDialog(AlpmHandler *hnd, QWidget *parent) 
 : QDialog(parent),
   actionDone(0),
   updated(false),
   aHandle(hnd),
   errorsOccourred(false)
{	
	setupUi(this);
        setWindowModality(Qt::ApplicationModal);
	
	connect(aHandle, SIGNAL(streamDbUpdatingStatus(char*,int)),
				SLOT(updateLabel(char*, int)));
	connect(aHandle, SIGNAL(dbQty(const QStringList&)), SLOT(createWidgets(const QStringList&)));
	connect(aHandle, SIGNAL(dbUpdated()), SLOT(setUpdated()));
	connect(aHandle, SIGNAL(dbUpdatePerformed()), SLOT(updateTotalProg()));
	connect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 
			SLOT(updateDlBar(char*,int,int,int,int,int,int)));
}

UpdateDbDialog::~UpdateDbDialog()
{
	disconnect(aHandle, SIGNAL(streamDbUpdatingStatus(char*,int)), 0, 0);
	disconnect(aHandle, SIGNAL(dbQty(const QStringList&)), 0, 0);
	disconnect(aHandle, SIGNAL(dbUpdated()), 0, 0);
	disconnect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 0, 0);
}

void UpdateDbDialog::updateLabel(char *repo, int action)
{
	Q_UNUSED(repo);
	
	QLabel *toInsert = labelList.at(actionDone);
	
	switch(action)
	{
	case 0:
		toInsert->setPixmap(QIcon(":/Icons/icons/edit-redo.png").pixmap(22));
		break;
	case 1:
		toInsert->setPixmap(QIcon(":/Icons/icons/view-refresh.png").pixmap(22));
		break;
	case 2:
		toInsert->setPixmap(QIcon(":/Icons/icons/edit-redo.png").pixmap(22));
		break;
	case 3:
		toInsert->setPixmap(QIcon(":/Icons/icons/dialog-ok-apply.png").pixmap(22));
		break;
	case 4:
		toInsert->setPixmap(QIcon(":/Icons/icons/edit-delete.png").pixmap(22));
		errorsOccourred = true;
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

bool UpdateDbDialog::anyErrors()
{
	return errorsOccourred;
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
	Q_UNUSED(speed);
	Q_UNUSED(bytedone);
	Q_UNUSED(bytetotal);
	
	QLabel *toInsert = labelList.at(actionDone);

	toInsert->setPixmap(QIcon(":/Icons/icons/view-refresh.png").pixmap(22));
}

void UpdateDbDialog::doAction()
{
	dbth = new UpDbThread(aHandle);
	dbth->start();
	connect(dbth, SIGNAL(finished()), this, SLOT(scopeEnded()));
}

void UpdateDbDialog::scopeEnded()
{
	for(int i = 0; i < labelList.size(); ++i)
		delete(labelList.at(i));
	
	delete(dbth);
	
	emit killMe();
}

UpDbThread::UpDbThread(AlpmHandler *aH)
{
	aHandle = aH;
}

void UpDbThread::run()
{
	result = aHandle->updateDatabase();
}

bool UpDbThread::getResult()
{
	return result;
}

void UpdateDbDialog::createWidgets(const QStringList &list)
{
	for (int i = 0; i < list.size(); ++i)
	{
		QLabel *labelDb = new QLabel(this);
		QLabel *labelStatus = new QLabel(this);
		labelStatus->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
		labelDb->setText(QString("<b>%1</b>").arg(list.at(i)));
		labelStatus->setPixmap(QIcon(":/Icons/icons/view-history.png").pixmap(22));
		
		gridLayout->addWidget(labelDb, i+1, 0);
		gridLayout->addWidget(labelStatus, i+1, 1);
		
		labelList.append(labelStatus);
		
	}
}
