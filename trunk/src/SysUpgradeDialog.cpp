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
#include "../ui_upgradeDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <QSettings>
#include <AlpmHandler.h>

#include "SysUpgradeDialog.h"

SysUpgradeDialog::SysUpgradeDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
aHandle(hnd)
{
	QSettings *settings = new QSettings(QSettings::SystemScope, "qtPacman", "qtPacman");

	if(settings->value("gui/actionupgrade").toString() == "add")
		addPkg();
	else if(settings->value("gui/actionupgrade").toString() == "upgrade")
		initSysUpgrade();
	else
	{

		alpm_list_t *data;

		setupUi(this);
		setWindowModality(Qt::ApplicationModal);

		data = aHandle->getUpgradeablePackages();

		upgradeMessage->setText(QString("There are <b>%1 upgradeable "
				"packages</b>. You can either<br> upgrade "
				"immediately or add them to the current Queue"
				"<br> and process them later.").arg(
						alpm_list_count(data)));

		connect(abortButton, SIGNAL(clicked()), SLOT(abort()));
		connect(addToQueue, SIGNAL(clicked()), SLOT(addPkg()));
		connect(goUpgrading, SIGNAL(clicked()), SLOT(initSysUpgrade()));
	}
}

SysUpgradeDialog::~SysUpgradeDialog()
{
	disconnect(abortButton, 0, 0, 0);
	disconnect(addToQueue, 0, 0, 0);
	disconnect(goUpgrading, 0, 0, 0);
}

void SysUpgradeDialog::abort()
{
	emit aborted();
}

void SysUpgradeDialog::addPkg()
{
	QSettings *settings = new QSettings(QSettings::SystemScope, "qtPacman", "qtPacman");
	
	if(checkBox->isChecked())
		settings->setValue("gui/actionupgrade", "add");
	
	emit addToPkgQueue();
}

void SysUpgradeDialog::initSysUpgrade()
{
	QSettings *settings = new QSettings(QSettings::SystemScope, "qtPacman", "qtPacman");
		
	if(checkBox->isChecked())
		settings->setValue("gui/actionupgrade", "upgrade");
		
	emit addToPkgQueue();
	
	aHandle->fullSystemUpgrade();

	emit upgradeNow();
}
