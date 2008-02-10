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
#include "../ui_mantDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <QSettings>
#include <AlpmHandler.h>


#include "ManteinanceDialog.h"

ManteinanceDialog::ManteinanceDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
aHandle(hnd)
{
	setupUi(this);
	setWindowModality(Qt::ApplicationModal);

	connect(cleanDbButton, SIGNAL(clicked()), SLOT(cleanUnused()));
	connect(cleanCacheButton, SIGNAL(clicked()), SLOT(cleanCache()));
	connect(emptyCacheButton, SIGNAL(clicked()), SLOT(clearCache()));
}

ManteinanceDialog::~ManteinanceDialog()
{
}

CleanThread::CleanThread(AlpmHandler *aH, int act)
: aHandle(aH),
action(act)
{

}

void CleanThread::run()
{
	switch(action)
	{
	case 0:
		if(aHandle->cleanUnusedDb())
			emit success(action);
		else
			emit failure(action);
		break;

	case 1:
		if(aHandle->cleanCache())
			emit success(action);
		else
			emit failure(action);
		break;
	case 2:
		if(aHandle->cleanCache(true))
			emit success(action);
		else
			emit failure(action);
		break;

	}
}

void ManteinanceDialog::cleanUnused()
{
	cTh = new CleanThread(aHandle, 0);

	cleanDbButton->setEnabled(false);
	cleanCacheButton->setEnabled(false);
	emptyCacheButton->setEnabled(false);

	statusLabel->setText(QString(tr("Cleaning up unused Databases...")));

	cTh->start();
	connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
	connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
	connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
}

void ManteinanceDialog::cleanCache()
{
	cTh = new CleanThread(aHandle, 1);

	cleanDbButton->setEnabled(false);
	cleanCacheButton->setEnabled(false);
	emptyCacheButton->setEnabled(false);

	statusLabel->setText(QString(tr("Cleaning up Cache...")));

	cTh->start();
	connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
	connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
	connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
}

void ManteinanceDialog::clearCache()
{
	cTh = new CleanThread(aHandle, 2);

	cleanDbButton->setEnabled(false);
	cleanCacheButton->setEnabled(false);
	emptyCacheButton->setEnabled(false);

	statusLabel->setText(QString(tr("Deleting Cache...")));

	cTh->start();
	connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
	connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
	connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
}

void ManteinanceDialog::showFailure(int act)
{
	switch(act)
	{
	case 0:
		statusLabel->setText(QString(tr("Cleaning up Unused Databases Failed!")));
		break;

	case 1:
		statusLabel->setText(QString(tr("Cleaning up Cache Failed!")));
		break;

	case 2:
		statusLabel->setText(QString(tr("Deleting Cache Failed!")));
		break;
	}

	cleanDbButton->setEnabled(true);
	cleanCacheButton->setEnabled(true);
	emptyCacheButton->setEnabled(true);
}

void ManteinanceDialog::showSuccess(int act)
{
	switch(act)
	{
	case 0:
		statusLabel->setText(QString(tr("Unused Databases Cleaned up successfully!")));
		break;

	case 1:
		statusLabel->setText(QString(tr("Cache Cleaned Up Successfully!")));
		break;

	case 2:
		statusLabel->setText(QString(tr("Cache Successfully Deleted!")));
		break;
	}

	cleanDbButton->setEnabled(true);
	cleanCacheButton->setEnabled(true);
	emptyCacheButton->setEnabled(true);
}

void ManteinanceDialog::cleanThread()
{
	cTh->deleteLater();
}

