/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                                                    *
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

#include "ReviewQueueDialog.h"

#include "PackageProperties.h"

#include <QSettings>

ReviewQueueDialog::ReviewQueueDialog(AlpmHandler *hnd, MainWindow *parent)
: QDialog(parent),
aHandle(hnd)
{
	int totalSize = 0;
	int removeSize = 0;
	int addSize = 0;
	
	setupUi(this);

	if(!parent->pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 8).isEmpty())
	{
		QTreeWidgetItem *itm = new QTreeWidgetItem(treeWidget, QStringList(tr("To be Installed")));
		treeWidget->addTopLevelItem(itm);
	}
	if(!parent->pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 8).isEmpty())
	{
		QTreeWidgetItem *itm = new QTreeWidgetItem(treeWidget, QStringList(tr("To be Upgraded")));
		treeWidget->addTopLevelItem(itm);
	}
	if(!parent->pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 8).isEmpty())
	{
		QTreeWidgetItem *itm = new QTreeWidgetItem(treeWidget, QStringList(tr("To be Removed")));
		treeWidget->addTopLevelItem(itm);
	}


	foreach(QTreeWidgetItem *itm, parent->pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 8))
	{
		aHandle->addSyncToQueue(itm->text(1));
		addSize += aHandle->getPackageSize(itm->text(1), itm->text(5));
		QTreeWidgetItem *itmL = treeWidget->findItems(tr("To be Installed"), Qt::MatchExactly, 0).first();
		new QTreeWidgetItem(itmL, QStringList(itm->text(1)));
		itmL->setExpanded(true);
	}

	foreach(QTreeWidgetItem *itm, parent->pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 8))
	{
		aHandle->addSyncToQueue(itm->text(1));
		addSize += aHandle->getPackageSize(itm->text(1), itm->text(5));
		QTreeWidgetItem *itmL = treeWidget->findItems(tr("To be Upgraded"), Qt::MatchExactly, 0).first();
		new QTreeWidgetItem(itmL, QStringList(itm->text(1)));
		itmL->setExpanded(true);
	}

	foreach(QTreeWidgetItem *itm, parent->pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 8))
	{
		aHandle->addRemoveToQueue(itm->text(1));
		removeSize += aHandle->getPackageSize(itm->text(1), itm->text(5));
		QTreeWidgetItem *itmL = treeWidget->findItems(tr("To be Removed"), Qt::MatchExactly, 0).first();
		new QTreeWidgetItem(itmL, QStringList(itm->text(1)));
		itmL->setExpanded(true);
	}

	foreach(QTreeWidgetItem *itm, parent->pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 8))
	{
		aHandle->addRemoveToQueue(itm->text(1));
		removeSize += aHandle->getPackageSize(itm->text(1), itm->text(5));
		QTreeWidgetItem *itmL = treeWidget->findItems(tr("To be Removed"), Qt::MatchExactly, 0).first();
		new QTreeWidgetItem(itmL, QStringList(itm->text(1)));
		itmL->setExpanded(true);
	}
	
	bool spaceToDo;
	
	if(addSize > removeSize)
	{
		spaceToDo = true;
		totalSize = addSize - removeSize;
	}
	else
	{
		spaceToDo = false;
		totalSize = removeSize - addSize;
	}
	
	QString sizeToShow(PackageProperties::formatSize(totalSize));

	QString toShow;
	toShow.append(QString(tr("Your Queue is about to be processed. "
			"You are going to:<br />")));
	int n = aHandle->getNumberOfTargets(1);
	toShow.append(QString(n == 1 ? tr("Remove <b>%1 package</b><br />") : tr("Remove <b>%1 packages</b><br />")).arg(n));
	int k = aHandle->getNumberOfTargets(0);
	toShow.append(QString(k == 1 ? tr("Install/Upgrade <b>%1 package</b><br />") : tr("Install/Upgrade <b>%1 packages</b><br />")).arg(k));
	toShow.append(QString(spaceToDo == true ? tr("<b>%1</b> will be used").arg(sizeToShow)
			: tr("<b>%1</b> will be freed").arg(sizeToShow)) + "<br />");
	toShow.append(tr("Do you wish to continue?"));

	queueInfo->setText(toShow);

	setWindowModality(Qt::ApplicationModal);
	treeWidget->hide();
	adjustSize();

	QSettings *settings = new QSettings();

	if(settings->value("gui/keepqueuedialogopen", true).toBool())
		keepOpenBox->setChecked(true);

	settings->deleteLater();

	connect(processButton, SIGNAL(clicked()), SLOT(processQueue()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(deleteLater()));
	connect(showPackages, SIGNAL(toggled(bool)), SLOT(adjust(bool)));
}

ReviewQueueDialog::~ReviewQueueDialog()
{
}

void ReviewQueueDialog::processQueue()
{
	QSettings *settings = new QSettings();

	if(keepOpenBox->isChecked())
		settings->setValue("gui/keepqueuedialogopen", true);
	else
		settings->setValue("gui/keepqueuedialogopen", false);
	
	settings->deleteLater();
	
	emit goProcess();
}

bool ReviewQueueDialog::isInTray()
{
	return trayBox->isChecked();
}

bool ReviewQueueDialog::isTurnOff()
{
	return turnoffBox->isChecked();
}

void ReviewQueueDialog::adjust(bool tgld)
{
	if(tgld)
		treeWidget->show();
	else
	{
		treeWidget->hide();
		resize(minimumSize());
	}
	
	adjustSize();
}
