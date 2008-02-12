/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *   Copyright (C) 2008 by Lukas Appelhans				   *
 *   l.appelhans@gmx.de							   *
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
#include "MainWindow.h"
#include "callbacks.h"
#include "UpdateDbDialog.h"
#include "SysUpgradeDialog.h"
#include "QueueDialog.h"
#include "configDialog.h"
#include "../ui_reviewQueueDialog.h"
#include "../ui_aboutDialog.h"

#include <iostream>
#include <QMenu>
#include <QString>
#include <QListWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <alpm.h>

extern CallBacks CbackReference;


MainWindow::MainWindow(AlpmHandler *handler, QMainWindow *parent) 
: QMainWindow(parent),
  currentpkgs(0),
  aHandle(handler),
  upActive(false),
  revActive(false)
{
	setupUi(this);
	pkgsViewWG->setContextMenuPolicy(Qt::CustomContextMenu);
        repoList->setContextMenuPolicy(Qt::CustomContextMenu);

	setupSystray();

	connect(actionUpdate_Database, SIGNAL(triggered()), SLOT(doDbUpdate()));
	connect(pkgsViewWG, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(showPkgsViewContextMenu()));
        connect(repoList, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(showRepoViewContextMenu()));
	connect(actionProcess_Queue, SIGNAL(triggered()), SLOT(widgetQueueToAlpmQueue()));
	connect(switchToRepo, SIGNAL(clicked()), SLOT(populateRepoColumn()));
	connect(switchToGrps, SIGNAL(clicked()), SLOT(populateGrpsColumn()));
	connect(installButton, SIGNAL(clicked()), SLOT(installPackage()));
	connect(removeButton, SIGNAL(clicked()), SLOT(removePackage()));
	connect(completeRemoveButton, SIGNAL(clicked()), SLOT(completeRemovePackage()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(cancelAction()));
	connect(actionUpgrade_System, SIGNAL(triggered()), SLOT(fullSysUpgrade()));
	connect(packageSwitchCombo, SIGNAL(currentIndexChanged(int)), SLOT(refinePkgView()));
	connect(searchLine, SIGNAL(textChanged(const QString&)), SLOT(refinePkgView()));
	connect(actionPacman_Preferences, SIGNAL(triggered()), SLOT(showSettings()));
	connect(systray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(systrayActivated(QSystemTrayIcon::ActivationReason)));
	connect(actionQuit, SIGNAL(triggered()), SLOT(quitApp()));
	connect(actionAbout, SIGNAL(triggered()), SLOT(showAboutDialog()));

	return;
}

MainWindow::~MainWindow()
{
	return;
}

void MainWindow::setupSystray()
{
	systray = new QSystemTrayIcon(this);
	systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
	systray->show();
	QMenu *systrayMenu = new QMenu(this);
	QAction *updateDBAction = systrayMenu->addAction(QIcon(":/Icons/icons/view-refresh.png"), tr("Update Database"));
	connect(updateDBAction, SIGNAL(triggered()), SLOT(doDbUpdate()));
	QAction *upgradeAction = systrayMenu->addAction(QIcon(":/Icons/icons/edit-redo.png"), tr("Upgrade System"));
	connect(upgradeAction, SIGNAL(triggered()), SLOT(fullSysUpgrade()));
	QAction *queueAction = systrayMenu->addAction(QIcon(":/Icons/icons/dialog-ok-apply.png"), tr("Process Queue"));
	connect(queueAction, SIGNAL(triggered()), SLOT(widgetQueueToAlpmQueue()));
	systrayMenu->addSeparator();
	QAction *settingsAction = systrayMenu->addAction(QIcon(":/Icons/icons/preferences-system.png"), tr("Settings"));
	connect(settingsAction, SIGNAL(triggered()), SLOT(showSettings()));
	systrayMenu->addSeparator();
	QAction *closeAction = systrayMenu->addAction(QIcon(":/Icons/icons/application-exit.png"), tr("Quit"));
	connect(closeAction, SIGNAL(triggered()), SLOT(quitApp()));
	//Add actions here ;)
	systray->setContextMenu(systrayMenu);
}

void MainWindow::quitApp()
{
	emit aboutToQuit();
}

void MainWindow::removePackagesView()
{
	QTreeWidgetItem *itm;

	while((itm = pkgsViewWG->takeTopLevelItem(0)) != NULL)
		delete(itm);

}

void MainWindow::removeRepoColumn()
{
	QListWidgetItem *itm;

	while((itm = repoList->takeItem(0)) != 0)
		delete(itm);

	disconnect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), 0, 0);
}

bool MainWindow::populatePackagesView()
{
	alpm_list_t *databases;
	int count = 0;

	disconnect(pkgsViewWG, SIGNAL(itemSelectionChanged()), 0, 0);

	removePackagesView();

	databases = aHandle->getAvailableRepos();

	databases = alpm_list_first(databases);

	while(databases != NULL)
	{
		pmdb_t *dbcrnt = (pmdb_t *)alpm_list_getdata(databases);

		currentpkgs = alpm_db_getpkgcache(dbcrnt);
		count = 0;

		while(currentpkgs != NULL)
		{
			pmpkg_t *pkg = (pmpkg_t *)alpm_list_getdata(currentpkgs);
			QTreeWidgetItem *item = new QTreeWidgetItem(pkgsViewWG);
			alpm_list_t *grps = (alpm_list_t *)alpm_pkg_get_groups(pkg);
			QString grStr("");

			/* TODO: show icons instead of text here *///Comment: IMO we should show text and icon here (more usable) (boom1992)
			if(aHandle->isInstalled(pkg))
				item->setText(0, tr("Installed"));
			else
				item->setText(0, tr("Not Installed"));

			item->setText(2, alpm_pkg_get_name(pkg));
			item->setText(3, alpm_pkg_get_version(pkg));
			item->setText(4, alpm_pkg_get_desc(pkg));
			item->setText(5, alpm_db_get_name(dbcrnt));

			while(grps != NULL)
			{
				grStr.append(" ");

				grStr.append((char *)alpm_list_getdata(grps));
				grps = alpm_list_next(grps);
			}
			grStr.append(" ");

			item->setText(6, grStr);

			currentpkgs = alpm_list_next(currentpkgs);

			count++;
		}

		databases = alpm_list_next(databases);
	}

	databases = alpm_list_first(databases);

	pkgsViewWG->sortItems(2, Qt::AscendingOrder);
	pkgsViewWG->setSortingEnabled(true);//Enable sorting *after* inserting :D

	connect(pkgsViewWG, SIGNAL(itemSelectionChanged()), this, 
			SLOT(itemChanged()));

	return true;
}

void MainWindow::populateRepoColumn()
{
	alpm_list_t *list = aHandle->getAvailableRepos();

	removeRepoColumn();

	list = alpm_list_first(list);

	QListWidgetItem *item = new QListWidgetItem(repoList);

	item->setText(tr("All Repositories"));
	item->setSelected(true);

	while(list != NULL)
	{
		QListWidgetItem *item = new QListWidgetItem(repoList);

		item->setText(alpm_db_get_name((pmdb_t *)alpm_list_getdata(list)));

		list = alpm_list_next(list);
	}

	list = alpm_list_first(list);

	connect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), this, 
			SLOT(refinePkgView()));
}

void MainWindow::populateGrpsColumn()
{
	alpm_list_t *grps = alpm_list_first(aHandle->getPackageGroups());

	removeRepoColumn();

	while(grps != NULL)
	{
		QListWidgetItem *item = new QListWidgetItem(repoList);

		item->setText((char *)alpm_list_getdata(grps));

		grps = alpm_list_next(grps);
	}

	repoList->sortItems(Qt::AscendingOrder);

	QListWidgetItem *item = new QListWidgetItem();

	item->setText(tr("All Groups"));
	item->setSelected(true);
	repoList->insertItem(0, item);

	alpm_list_free(grps);

	connect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), this, 
			SLOT(refinePkgView()));
}

void MainWindow::refinePkgView()
{
	qDebug() << "refinePkgView";
	//First we hide all items
	for(int i = 0; i < pkgsViewWG->topLevelItemCount(); ++i)
	{

		pkgsViewWG->topLevelItem(i)->setHidden(true);
	}

	QList<QTreeWidgetItem*> list = pkgsViewWG->findItems(QString(), Qt::MatchRegExp | Qt::MatchWildcard);

	// Now first: What do we need to refine in the right column?

	if((repoList->selectedItems().at(0)->text().compare(tr("All Repositories")) &&
			repoList->selectedItems().at(0)->text().compare(tr("All Groups"))) &&
			!repoList->selectedItems().isEmpty())
	{
		if(!repoList->findItems(QString(tr("All Repositories")),
				(Qt::MatchFlags)Qt::MatchExactly).isEmpty())
			// First time, so don't check anything.
			list = pkgsViewWG->findItems(repoList->selectedItems().at(0)->text(), 
					(Qt::MatchFlags)Qt::MatchExactly, 5);
		else
		{
			list = pkgsViewWG->findItems(repoList->selectedItems().at(0)->text(), 
					(Qt::MatchFlags)Qt::MatchExactly, 6);
			QString tmp = repoList->selectedItems().at(0)->text();
			tmp.append(" ");
			tmp.prepend(" ");
			list += pkgsViewWG->findItems(tmp, 
					(Qt::MatchFlags)Qt::MatchContains, 6);
		}
	}
	else
	{
		for(int i = 0; i < pkgsViewWG->topLevelItemCount(); ++i)
		{

			list += pkgsViewWG->topLevelItem(i);
		}
	}
	qDebug() << "The left TextBox is over, let's do the ComboBox";
	if(!packageSwitchCombo->currentIndex() == 0)
	{
		qDebug() << "Hehe, we should not show all Packages";
		if (packageSwitchCombo->currentText() == tr("Installed packages"))
		{
			//qDebug() << "We should only show the installed packages";
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (!item->text(0).compare(tr("Not Installed")))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Not installed packages"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (!item->text(0).compare(tr("Installed")))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Upgradeable packages"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (!item->text(0).compare(tr("Upgradeable")))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Packages in Queue"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (item->text(1).isEmpty())
					list.removeAt(list.indexOf(item));
			}
		}
	}
	else
		qDebug() << "Show all packages";

	if (!searchLine->text().isEmpty())
	{
		foreach (QTreeWidgetItem *item, list)
		{
			if (!item->text(2).contains(searchLine->text(), Qt::CaseInsensitive))
			{
				list.removeAt(list.indexOf(item));
			}
		}
	}


	/* When we are here, we have a list that contains the packages refined
	 * by all of our three components. And then we set that list to be
	 * visible. */


	foreach (QTreeWidgetItem *item, list)
	{
		item->setHidden(false);
	}

}

void MainWindow::itemChanged()
{
	if (pkgsViewWG->selectedItems().first()->text(0) == tr("Installed"))
	{
		removeButton->setEnabled(true);
		installButton->setDisabled(true);
		completeRemoveButton->setEnabled(true);
	}
	if (pkgsViewWG->selectedItems().first()->text(0) == tr("Not Installed"))
	{
		removeButton->setDisabled(true);
		installButton->setEnabled(true);
		completeRemoveButton->setDisabled(true);
	}
	//if (pkgsViewWG->selectedItems().first()->text(1) == tr("Upgradeable"))
	showPkgInfo();
}

void MainWindow::showPkgInfo()
{
	QString description;
	pmpkg_t *pkg;
	alpm_list_t *databases;
	pmdb_t *curdb = NULL;

	databases = aHandle->getAvailableRepos();

	databases = alpm_list_first(databases);

	while(databases != NULL)
	{
		if(!strcmp(pkgsViewWG->currentItem()->text(5).toAscii().data(),
				alpm_db_get_name((pmdb_t *)alpm_list_getdata(databases))))
		{
			curdb = (pmdb_t *)alpm_list_getdata(databases);
			break;
		}
		databases = alpm_list_next(databases);
	}

	pkg = alpm_db_get_pkg(curdb, pkgsViewWG->currentItem()->text(2).toAscii().data());

	databases = alpm_list_first(databases);

	description.append("<b>");
	description.append(alpm_pkg_get_name(pkg));
	description.append(" (");
	description.append(alpm_pkg_get_version(pkg));
	description.append(")</b><br><br>");
	description.append(alpm_pkg_get_desc(pkg));

	pkgInfo->setHtml(description);

	dependenciesWidget->clear(); //First clear the widget
	foreach (QString dep, aHandle->getPackageDependencies(alpm_pkg_get_name(pkg) , pkgsViewWG->currentItem()->text(5)))
	{
		dependenciesWidget->addItem(dep);
	}

	filesWidget->clear();
	filesWidget->header()->hide();
	QStringList files = aHandle->getPackageFiles(pkgsViewWG->selectedItems().first()->text(2));
	foreach (QString file, files)
	{
		QStringList splitted = file.split("/");
		QTreeWidgetItem *parentItem = 0;
		foreach (QString spl, splitted)
		{
			if (spl.isEmpty())
				continue;
			if (parentItem)
			{
				qDebug() << "Yay, we have a parentItem";
				bool there = false;
				int j = parentItem->childCount();
				for (int i = 0;i != j; i++)
				{
					if (parentItem->child(i)->text(0) == spl)
					{
						there = true;
						parentItem = parentItem->child(i);
						continue;
					}
				}
				if (!there)
					parentItem->addChild(new QTreeWidgetItem(parentItem, (QStringList) spl));
			}
			else
			{
				QList<QTreeWidgetItem*> list = filesWidget->findItems(spl, Qt::MatchExactly);
				if (!list.isEmpty())
				{
					qDebug() << "Hehe we have the same item already found";
					parentItem = list.first();
				}
				else
				{
					filesWidget->insertTopLevelItem(0, new QTreeWidgetItem(filesWidget, (QStringList) spl));
				}
			}
		}
	}
}

void MainWindow::doDbUpdate()
{
	dbdialog = new UpdateDbDialog(aHandle, this);

	dbdialog->show();

	connect(dbdialog, SIGNAL(killMe()), this, SLOT(finishDbUpdate()));

	dbdialog->doAction();
}

void MainWindow::finishDbUpdate()
{
	disconnect(dbdialog, 0,0,0);

	if(dbdialog->dbHasBeenUpdated())
	{
		pkgsViewWG->setSortingEnabled(false);
		populatePackagesView();
	}

	dbdialog->deleteLater();

}

void MainWindow::showPkgsViewContextMenu()
{
	if(pkgsViewWG->selectedItems().isEmpty())
		return;
	
	qDebug() << "Let's show a context menu";
	QTreeWidgetItem *item = pkgsViewWG->selectedItems().first();
	QMenu *menu = new QMenu(this);
	QAction *installAction = menu->addAction(QIcon(":/Icons/icons/list-add.png"), tr("Mark for Installation"));
	connect(installAction, SIGNAL(triggered()), SLOT(installPackage()));
	QAction *removeAction = menu->addAction(QIcon(":/Icons/icons/list-remove.png"), tr("Mark for Removal"));
	connect(removeAction, SIGNAL(triggered()), SLOT(removePackage()));
	QAction *upgradeAction = menu->addAction(QIcon(":/Icons/icons/edit-redo.png"), tr("Mark for Upgrade"));
	connect(upgradeAction, SIGNAL(triggered()), SLOT(upgradePackage()));
	QAction *cancelAction = menu->addAction(QIcon(":/Icons/icons/edit-delete.png"), tr("Cancel Action"));
	connect(cancelAction, SIGNAL(triggered()), SLOT(cancelAction()));

	if (item->text(0) == tr("Installed"))
	{
		installAction->setDisabled(true);
		upgradeAction->setDisabled(true);
	}
	else if (item->text(0) == tr("Not Installed"))
	{
		removeAction->setDisabled(true);
		upgradeAction->setDisabled(true);
	}
	else//Package is marked as upgradeable
	{
		installAction->setDisabled(true);
		removeAction->setDisabled(true);
	}//FIXME: Add completeRemove-action

	if (item->text(1).isEmpty())
		cancelAction->setDisabled(true);

	if (item->text(1) == tr("Install"))
		installAction->setDisabled(true);
	else if (item->text(1) == tr("Uninstall"))
		removeAction->setDisabled(true);
	else //Upgrade
		upgradeAction->setDisabled(true);


	menu->popup(QCursor::pos());
}

void MainWindow::showRepoViewContextMenu()
{
	if (repoList->selectedItems().isEmpty())
		return;

	QListWidgetItem *item = repoList->selectedItems().first();
	QMenu *menu = new QMenu(this);
	QAction *installAction = menu->addAction(QIcon(":/Icons/icons/list-add.png"), tr("Mark all for installation"));
	connect(installAction, SIGNAL(triggered()), SLOT(installAllPackages()));
	QAction *removeAction = menu->addAction(QIcon(":/Icons/icons/list-remove.png"), tr("Mark all for removal"));
	connect(removeAction, SIGNAL(triggered()), SLOT(removeAllPackages()));
	QAction *cancelAction = menu->addAction(QIcon(":/Icons/icons/edit-delete.png"), tr("Cancel all actions"));
	connect(cancelAction, SIGNAL(triggered()), SLOT(cancelAllActions()));

	menu->popup(QCursor::pos());
}

void MainWindow::installAllPackages()
{
	if (repoList->selectedItems().isEmpty())
		return;

	QListWidgetItem *item = repoList->selectedItems().first();
	foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(item->text(), Qt::MatchExactly, 5))
	{
		installPackage(item->text(2));
	}
}

void MainWindow::removeAllPackages()
{
	if (repoList->selectedItems().isEmpty())
		return;

	QListWidgetItem *item = repoList->selectedItems().first();
	foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(item->text(), Qt::MatchExactly, 5))
	{
		removePackage(item->text(2));
	}
}

void MainWindow::cancelAllActions()
{
	if (repoList->selectedItems().isEmpty())
		return;

	QListWidgetItem *item = repoList->selectedItems().first();
	foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(item->text(), Qt::MatchExactly, 5))
	{
		cancelAction(item->text(2));
	}
}

void MainWindow::installPackage()
{
	qDebug() << "Install Package";
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
		installPackage(item->text(2));
}

void MainWindow::installPackage(const QString &package)
{
	qDebug() << "Install package: " + package;
	if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 2).isEmpty())
	{
		qDebug() << "Can't find package: " + package;
		//QStringList providers = aHandle->getProviders(package, item->text(5));
		//if (!providers.isEmpty())
		//	installPackage(providers.first());
		return;
	}
	QTreeWidgetItem *item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 2).first();

	qDebug() << item->text(1);
	if(aHandle->isProviderInstalled(package))
		return;
	
	if (item->text(0) == tr("Installed") || item->text(1) == tr("Install"))
		return;
	else
	{
		item->setText(1, tr("Install"));
		item->setIcon(1, QIcon(":/Icons/icons/list-add.png"));
	}
	qDebug() << item->text(5);

	foreach (QString dep, aHandle->getPackageDependencies(package, item->text(5)))
	{
		installPackage(dep);
	}
}

void MainWindow::removePackage()
{
	qDebug() << "Remove Package";
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
		removePackage(item->text(2));
}

void MainWindow::removePackage(const QString &package)
{
	qDebug() << "Uninstall package: " + package;
	if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 2).isEmpty())
	{
		qDebug() << "Can't find package: " + package;
		return;
	}
	QTreeWidgetItem *item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 2).first();

	qDebug() << item->text(1);
	if (item->text(0) == tr("Not Installed") || item->text(1) == tr("Remove"))
		return;
	else
	{
		item->setText(1, tr("Uninstall"));
		item->setIcon(1, QIcon(":/Icons/icons/list-remove.png"));
	}
	qDebug() << item->text(5);

	foreach (QString dep, aHandle->getDependenciesOnPackage(package, item->text(5)))
	{
		removePackage(dep);
	}
}

void MainWindow::completeRemovePackage()
{
	qDebug() << "Complete Remove Package";
	QTreeWidgetItem *item = pkgsViewWG->selectedItems().first();

	qDebug() << item->text(1);
	if (item->text(0) == tr("Not Installed"))
		return;
	else
	{
		item->setText(1, tr("Complete Uninstall"));
		item->setIcon(1, QIcon(":/Icons/icons/edit-delete.png"));
	}
	qDebug() << item->text(5);

	//Now we remove the on-package-dependencies and the dependencies...
	
	foreach (QString onDep, aHandle->getDependenciesOnPackage(item->text(2), item->text(5)))
	{
		removePackage(onDep);
	}
	foreach (QString dep, aHandle->getPackageDependencies(item->text(2), item->text(5)))
	{
		removePackage(dep);
	}
}

void MainWindow::cancelAction()
{
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
		cancelAction(item->text(2));
}

void MainWindow::cancelAction(const QString &package)
{
	qDebug() << "cancel action for: " + package;
	if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 2).isEmpty())
	{
		qDebug() << "Can't find package: " + package;
		return;
	}
	QTreeWidgetItem *item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 2).first();
	if (item->text(1).isEmpty())
		return;

	item->setText(1, QString());
	item->setIcon(1, QIcon());
	
	foreach (QString onDep, aHandle->getDependenciesOnPackage(item->text(2), item->text(5)))
	{
		cancelAction(onDep);
	}
	foreach (QString dep, aHandle->getPackageDependencies(item->text(2), item->text(5)))
	{
		cancelAction(dep);
	}

}

void MainWindow::startUpgrading()
{
	disconnect(dbdialog, 0,0,0);

	dbdialog->deleteLater();

	if(!aHandle->getUpgradeablePackages())
	{
		/* Display a simple popup saying the system is up-to-date. */
		QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("System-Update"), tr("Your system is up to date!"), QMessageBox::Ok, this);
		message->show();
		qDebug() << "System is up to date";
	}
	else
	{
		/* Something to upgrade! Cool! Let's show our user the
		 * upgrade dialog */
		/* Preferences are handled in SysUpgradeDialog, there's
		 * a reason for that :)
		 */

		upDl = new SysUpgradeDialog(aHandle, this);

		upDl->show();
		
		upActive = true;

		connect(upDl, SIGNAL(aborted()), SLOT(upgradeAborted()));
		connect(upDl, SIGNAL(upgradeNow()), SLOT(processQueue()));
		connect(upDl, SIGNAL(addToPkgQueue()), SLOT(addUpgradeableToQueue()));
	}

}

void MainWindow::upgradeAborted()
{
	upDl->deleteLater();
	upActive = false;
}

void MainWindow::addUpgradeableToQueue()
{
	//FIXME: do sth like foreach (pkg, pkgs) item->setText("upgradable")... look in installPackage-function for more information
	upDl->deleteLater();
	upActive = false;
	return;
}

void MainWindow::fullSysUpgrade()
{
	dbdialog = new UpdateDbDialog(aHandle, this);

	dbdialog->show();

	connect(dbdialog, SIGNAL(killMe()), this, SLOT(startUpgrading()));

	dbdialog->doAction();
}

void MainWindow::upgradePackage()
{
	qDebug() << "Upgrade Package";
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
	{
		item->setText(1, tr("Upgrade"));//Look if there are dependencies for the upgrade
	}
}

void MainWindow::processQueue()
{
	qDebug() << "Process Queue";

	/* This Function will only do the processing stuff. We'd better
	 * keep things modular as possible due to libalpm's design.
	 * So the "Process Queue" button does not point here, but
	 * to a function that reads the queue and prepares libalpm's
	 * transaction. 
	 */

	if(upActive)
		upDl->deleteLater();
	if(revActive)
		reviewQueue->deleteLater();
	
	upActive = false;
	revActive = false;

	/* Now, everything will be done inside our Queue Dialog.
	 * So, just create it and let him handle the job.
	 */

	queueDl = new QueueDialog(aHandle, this);

	queueDl->show();

	connect(queueDl, SIGNAL(terminated(bool)), SLOT(queueProcessingEnded(bool)));

	queueDl->startProcessing();

}

void MainWindow::queueProcessingEnded(bool errors)
{
	if(errors)
	{
		// TODO: popup a message if there were errors
		qDebug() << "Errors Occourred";
	}

	queueDl->deleteLater();

	qDebug() << "Transaction Completed Successfully";

	pkgsViewWG->setSortingEnabled(false);
	populatePackagesView();
	refinePkgView();
	
	QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("Queue Processed"), tr("Your Queue was successfully processed!"), QMessageBox::Ok);

	message->show();
}

void MainWindow::widgetQueueToAlpmQueue()
{
	/* This function takes the queue the user defined in the
	 * GUI and "translates" it to a libalpm transaction queue.
	 * So THIS is the function that the "Process Queue" buttons 
	 * should call. processQueue() processes a libalpm queue,
	 * so you need to "translate" it first.
	 * 
	 * First of all, we need to know what kind of actions we
	 * need.
	 */

	if(pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 1).isEmpty() &&
			pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 1).isEmpty() &&
			pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 1).isEmpty())
		return;
	else if(pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 1).isEmpty() &&
			pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 1).isEmpty())
		aHandle->initQueue(false, true);
	else if(pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 1).isEmpty())
		aHandle->initQueue(true, false);
	else
		aHandle->initQueue(true, true);

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 1))
		aHandle->addSyncToQueue(itm->text(2));

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 1))
		aHandle->addRemoveToQueue(itm->text(2));

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 1))
		aHandle->addRemoveToQueue(itm->text(2));

	
	revActive = true;
	
	reviewQueue = new QDialog(this);
	Ui::QueueReadyDialog qUi;
	qUi.setupUi(reviewQueue);
	
	reviewQueue->setWindowModality(Qt::ApplicationModal);
	reviewQueue->show();
	
	connect(qUi.processButton, SIGNAL(clicked()), SLOT(processQueue()));
	connect(qUi.cancelButton, SIGNAL(clicked()), SLOT(destroyReviewQueue()));
	
	qUi.queueInfo->setText(QString(tr("Your Queue is about to be processed. "
			"You are going to:<br />Remove <b>%1 packages</b><br />Install/Upgrade"
			" <b>%2 packages</b><br />Do you wish to continue?")).arg(aHandle->getNumberOfTargets(1)).
			arg(aHandle->getNumberOfTargets(0)));

}

void MainWindow::destroyReviewQueue()
{
	revActive = false;
	reviewQueue->deleteLater();
}

void MainWindow::showSettings()
{
	configDialog = new ConfigDialog(aHandle, this);
	configDialog->exec();
	if(configDialog->doDbUpdate())
		doDbUpdate();
	
	configDialog->deleteLater();
}

void MainWindow::systrayActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::Trigger)
	{
		if (isHidden())
			show();
		else
			hide();
	}
}

void MainWindow::showAboutDialog()
{
	QDialog *about = new QDialog(this);
	Ui::aboutDialog ui;
	
	ui.setupUi(about);
	
	about->setWindowModality(Qt::ApplicationModal);
	
	about->exec();
	
	about->deleteLater();
}
