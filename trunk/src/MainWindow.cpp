/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *   Copyright (C) 2008 by Lukas Appelhans				   				   *
 *   l.appelhans@gmx.de							   						   *
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
#include "BuildingDialog.h"
#include "EditPBuild.h"
#include "../ui_reviewQueueDialog.h"
#include "../ui_aboutDialog.h"

#include <iostream>
#include <QMenu>
#include <QString>
#include <QListWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <QFileDialog>
#include <QTimer>
#include <QCloseEvent>
#include <QSettings>
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
	addDockWidget(Qt::LeftDockWidgetArea, dockWidget_2);
	addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
	pkgsViewWG->setContextMenuPolicy(Qt::CustomContextMenu);
        repoList->setContextMenuPolicy(Qt::CustomContextMenu);
	pkgsViewWG->hideColumn(6);
	pkgsViewWG->hideColumn(7);
	resize(500, size().height());

	setupSystray();
	
	nameDescBox->addItem(tr("Name"));
	nameDescBox->addItem(tr("Description"));

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
	connect(nameDescBox, SIGNAL(currentIndexChanged(int)), SLOT(refinePkgView()));
	connect(searchLine, SIGNAL(textChanged(const QString&)), SLOT(refinePkgView()));
	connect(actionPacman_Preferences, SIGNAL(triggered()), SLOT(showSettings()));
	connect(systray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(systrayActivated(QSystemTrayIcon::ActivationReason)));
	connect(actionQuit, SIGNAL(triggered()), SLOT(quitApp()));
	connect(actionAbout, SIGNAL(triggered()), SLOT(showAboutDialog()));
	connect(actionInstall_Package_From_File, SIGNAL(triggered()), SLOT(getPackageFromFile()));
	connect(actionUpdate_ABS_Tree, SIGNAL(triggered()), SLOT(updateABSTree()));
	connect(actionBuild_and_Install_Selected, SIGNAL(triggered()), SLOT(validateSourceQueue()));

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
	systray->setToolTip(QString(tr("qtPacman - Idle")));
		
	QSettings *settings = new QSettings();
		
	if(settings->value("scheduledUpdate/enabled").toBool())
	{
		trayUpDb = new QTimer(this); /* Oh yeah :) */
		trayUpDb->setInterval(settings->value("scheduledUpdate/interval", 10).toInt() * 60000);

		connect(trayUpDb, SIGNAL(timeout()), SLOT(dbUpdateTray()));
	}
	
	settings->deleteLater();
}

void MainWindow::quitApp()
{
	emit aboutToQuit();
}

void MainWindow::closeEvent(QCloseEvent *evt)
{
	QSettings *settings = new QSettings();
	
	if(settings->value("scheduledUpdate/enabled").toBool() == true)
		trayUpDb->start();
	
	if(!settings->value("gui/confirmquit").toBool())
	{
		QDialog *dlog = new QDialog(this);
		QLabel *lbl = new QLabel(dlog);
		QCheckBox *cbx = new QCheckBox(dlog);
		QDialogButtonBox *but = new QDialogButtonBox(dlog);
		QVBoxLayout *lay = new QVBoxLayout();
		
		lbl->setText(QString(tr("qtPacman will keep running in the system tray.\nTo close it, click Quit in the file menu "
				"or in the tray icon context menu.\nWhile in the System Tray, qtPacman will update your Databases\nat a regular"
				" interval and notify you about available upgrades.\nYou can change this behaviour in Settings.")));
		cbx->setText(QString(tr("Don't show this Again")));
		cbx->setChecked(false);
		but->addButton(QDialogButtonBox::Ok);
		lay->addWidget(lbl);
		lay->addWidget(cbx);
		lay->addWidget(but);
		dlog->setLayout(lay);
		dlog->setWindowTitle(QString(tr("qtPacman")));
		dlog->setWindowModality(Qt::ApplicationModal);
		connect(but, SIGNAL(accepted()), dlog, SLOT(accept()));
		
		dlog->exec();
		
		if(cbx->isChecked())
			settings->setValue("gui/confirmquit", true);
	}
	
	settings->deleteLater();

	evt->accept();
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

			if(aHandle->isInstalled(pkg))
			{
				//item->setText(0, tr("Installed"));
				item->setIcon(0, QIcon(":/Icons/icons/dialog-ok-apply.png"));
			}
			else
			{
				//item->setText(0, tr("Not Installed"));
				item->setIcon(0, QIcon(":/Icons/icons/dialog-cancel.png"));
			}

			item->setText(1, alpm_pkg_get_name(pkg));
			item->setText(3, alpm_pkg_get_version(pkg));
			item->setText(6, alpm_pkg_get_desc(pkg));
			item->setText(4, alpm_db_get_name(dbcrnt));

			while(grps != NULL)
			{
				grStr.append(" ");

				grStr.append((char *)alpm_list_getdata(grps));
				grps = alpm_list_next(grps);
			}
			grStr.append(" ");

			item->setText(5, grStr);

			currentpkgs = alpm_list_next(currentpkgs);

			count++;
		}

		databases = alpm_list_next(databases);
	}

	databases = alpm_list_first(databases);
	
	alpm_list_t *locPkg = aHandle->getInstalledPackages();
	
	while(locPkg != NULL)
	{
		pmpkg_t *pkg = (pmpkg_t *)alpm_list_getdata(locPkg);
		QList<QTreeWidgetItem*> list = pkgsViewWG->findItems(alpm_pkg_get_name(pkg), Qt::MatchExactly, 1);
		if (list.isEmpty())
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(pkgsViewWG);
			item->setIcon(0, QIcon(":/Icons/icons/dialog-ok-apply.png"));
			item->setText(1, alpm_pkg_get_name(pkg));
			item->setText(3, alpm_pkg_get_version(pkg));
			item->setText(6, alpm_pkg_get_desc(pkg));
			item->setText(4, "local");
		}
		else
			list.first()->setText(3, alpm_pkg_get_version(aHandle->getPackageFromName(list.first()->text(1), "local")));
			
		locPkg = alpm_list_next(locPkg);
	}

	QStringList upgrds = aHandle->getUpgradeablePackages();
	foreach (QString pac, upgrds)
	{
		QTreeWidgetItem *item = pkgsViewWG->findItems(pac, Qt::MatchExactly, 1).first();
		if (item)
		{
			item->setText(7, tr("Upgrade"));
			item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
		}
	}

	if(!upgrds.isEmpty())
	{
		systray->setIcon(QIcon(":/Icons/icons/view-refresh.png"));
		systray->setToolTip(QString(tr("qtPacman - Idle (Upgrades Available)")));
		systray->showMessage(QString(tr("System Upgrade")), QString(upgrds.size() == 1 ? tr("There is %1 upgradeable package.\n"
				"Click here to upgrade your System.") :	tr("There are %1 upgradeable packages.\nClick here to upgrade your System.")).
				arg(upgrds.size()));
		connect(systray, SIGNAL(messageClicked()), SLOT(fullSysUpgrade()));
	}

	pkgsViewWG->sortItems(1, Qt::AscendingOrder);
	pkgsViewWG->setSortingEnabled(true);//Enable sorting *after* inserting :D

	connect(pkgsViewWG, SIGNAL(itemSelectionChanged()), this, 
			SLOT(itemChanged()));

	return true;
}

void MainWindow::populateRepoColumn()
{
        switchToGrps->setChecked(false);
        dockWidget_2->setWindowTitle(tr("Repositories"));
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
	
	QListWidgetItem *itm = new QListWidgetItem(repoList);

	itm->setText(tr("Local Packages"));

	connect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), this, 
			SLOT(refinePkgView()));
}

void MainWindow::populateGrpsColumn()
{
        switchToRepo->setChecked(false);
        dockWidget_2->setWindowTitle(tr("Package Groups"));
	QStringList grps = aHandle->getPackageGroups();

	removeRepoColumn();

	for(int i = 0; i < grps.size(); ++i)
	{
		QListWidgetItem *item = new QListWidgetItem(repoList);

		item->setText(grps.at(i));
	}

	repoList->sortItems(Qt::AscendingOrder);

	QListWidgetItem *item = new QListWidgetItem();

	item->setText(tr("All Groups"));
	item->setSelected(true);
	repoList->insertItem(0, item);

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
			if(repoList->selectedItems().at(0)->text().compare(tr("Local Packages")))
				list = pkgsViewWG->findItems(repoList->selectedItems().at(0)->text(), 
						(Qt::MatchFlags)Qt::MatchExactly, 4);
			else
				list = pkgsViewWG->findItems("local", 
						(Qt::MatchFlags)Qt::MatchExactly, 4);
		else
		{
			list = pkgsViewWG->findItems(repoList->selectedItems().at(0)->text(), 
					(Qt::MatchFlags)Qt::MatchExactly, 5);
			QString tmp = repoList->selectedItems().at(0)->text();
			tmp.append(" ");
			tmp.prepend(" ");
			list += pkgsViewWG->findItems(tmp, 
					(Qt::MatchFlags)Qt::MatchContains, 5);
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
				if (!aHandle->isInstalled(item->text(1)))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Not installed packages"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (aHandle->isInstalled(item->text(1)))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Upgradeable packages"))
		{
			QStringList stringList = aHandle->getUpgradeablePackages();
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for upgradeable packages" + item->text(2);
				if (!aHandle->isInstalled(item->text(1)) || !stringList.contains(item->text(1)))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Packages in Queue"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (item->text(7).isEmpty())
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
			if(nameDescBox->currentText() == tr("Name"))
			{
				if (!item->text(1).contains(searchLine->text(), Qt::CaseInsensitive))
				{
					list.removeAt(list.indexOf(item));
				}
			}
			else if(nameDescBox->currentText() == tr("Description"))
			{
				if (!item->text(6).contains(searchLine->text(), Qt::CaseInsensitive))
				{
					list.removeAt(list.indexOf(item));
				}
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
	cancelButton->setDisabled(true);
	if (aHandle->isInstalled(pkgsViewWG->selectedItems().first()->text(1)))
	{
		removeButton->setEnabled(true);
		installButton->setDisabled(true);
		completeRemoveButton->setEnabled(true);
	}
	if (!aHandle->isInstalled(pkgsViewWG->selectedItems().first()->text(1)))
	{
		removeButton->setDisabled(true);
		installButton->setEnabled(true);
		completeRemoveButton->setDisabled(true);
	}
	//if (pkgsViewWG->selectedItems().first()->text(1) == tr("Upgradeable"))

	if (pkgsViewWG->selectedItems().first()->text(7) == tr("Install"))
		installButton->setDisabled(true);
	if (pkgsViewWG->selectedItems().first()->text(7) == tr("Uninstall"))
		removeButton->setDisabled(true);
	if (pkgsViewWG->selectedItems().first()->text(7) == tr("Complete Uninstall"))
		completeRemoveButton->setDisabled(true);
	if (!pkgsViewWG->selectedItems().first()->text(7).isEmpty())
		cancelButton->setEnabled(true);

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
		if(!strcmp(pkgsViewWG->currentItem()->text(4).toAscii().data(),
				alpm_db_get_name((pmdb_t *)alpm_list_getdata(databases))))
		{
			curdb = (pmdb_t *)alpm_list_getdata(databases);
			break;
		}
		databases = alpm_list_next(databases);
	}

	pkg = alpm_db_get_pkg(curdb, pkgsViewWG->currentItem()->text(1).toAscii().data());
	
	if(!pkg)
		/* Well, if pkg is NULL we're probably searching for something coming
		 * from the local database. */
		pkg = aHandle->getPackageFromName(pkgsViewWG->currentItem()->text(1).toAscii().data(), "local");

	databases = alpm_list_first(databases);

	QTreeWidgetItem *item = pkgsViewWG->selectedItems().first();
	description.append("<b>");
	description.append(alpm_pkg_get_name(pkg));
	description.append(" (");
	description.append(alpm_pkg_get_version(pkg));
	description.append(")</b><br><br>");
	description.append(alpm_pkg_get_desc(pkg));
	description.append("<br><br>");
	description.append("<b>" + tr("Status: ") + "</b> ");
	if (aHandle->isInstalled(item->text(1)))
		description.append(tr("Installed")); //FIXME: Icon!!!!
	else
		description.append(tr("Not installed"));

	if (!item->text(7).isEmpty())
	{
		description.append("<br><b>" + tr("Action: ") + "</b>");
		description.append(item->text(7));//FIXME: Icon!!!
	}

	pkgInfo->setHtml(description);

	dependenciesWidget->clear(); //First clear the widget
	foreach (QString dep, aHandle->getPackageDependencies(alpm_pkg_get_name(pkg) , pkgsViewWG->currentItem()->text(4)))
	{
		if (!dep.isEmpty())
			dependenciesWidget->addItem(dep);
	}

	filesWidget->clear();
	filesWidget->header()->hide();
	QStringList files = aHandle->getPackageFiles(pkgsViewWG->selectedItems().first()->text(1));
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

	systray->setIcon(QIcon(":/Icons/icons/edit-redo.png"));
	systray->setToolTip(QString(tr("qtPacman - Processing")));
}

void MainWindow::finishDbUpdate()
{
	disconnect(dbdialog, 0,0,0);
	
	if(dbdialog->anyErrors())
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Error"), 
				QString(tr("One or more Databases could not be updated.\nLast error reported was:\n%1")).arg(alpm_strerrorlast()),
				QMessageBox::Ok, dbdialog);
		
		message->exec();
		
		message->deleteLater();
	}

	if(dbdialog->dbHasBeenUpdated())
	{
		pkgsViewWG->setSortingEnabled(false);
		populatePackagesView();
	}

	dbdialog->deleteLater();

	systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
	systray->setToolTip(QString(tr("qtPacman - Idle")));
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

	if (aHandle->isInstalled(item->text(1)) && aHandle->getUpgradeablePackages().contains(item->text(1)))
	{
		installAction->setDisabled(true);
		removeAction->setDisabled(true);
	}
	else if (!aHandle->isInstalled(item->text(1)))
	{
		removeAction->setDisabled(true);
		upgradeAction->setDisabled(true);
	}
	else//Package is marked as installed
	{
		installAction->setDisabled(true);
		upgradeAction->setDisabled(true);
	}//FIXME: Add completeRemove-action

	if (item->text(7).isEmpty())
		cancelAction->setDisabled(true);
	else if (item->text(7) == tr("Install"))
		installAction->setDisabled(true);
	else if (item->text(7) == tr("Uninstall"))
		removeAction->setDisabled(true);
	else //Upgrade
		upgradeAction->setDisabled(true);


	menu->popup(QCursor::pos());
}

void MainWindow::showRepoViewContextMenu()
{
	if (repoList->selectedItems().isEmpty())
		return;

	//QListWidgetItem *item = repoList->selectedItems().first();
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
	qDebug() << "InstallAllPackages";
	if (repoList->selectedItems().isEmpty())
		return;
	qDebug() << "InstallAllPackages1";

	if (!repoList->findItems(tr("All Groups"), Qt::MatchExactly).isEmpty())
	{
		QString tmp = repoList->selectedItems().first()->text();
		tmp.append(" ");
		tmp.prepend(" ");
		qDebug() << "Hehe";
		foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(tmp, (Qt::MatchFlags)Qt::MatchContains, 5))
		{
			installPackage(item->text(1));
		}
	}
	else
	{
		foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(repoList->selectedItems().first()->text(), Qt::MatchExactly, 4))
		{
			installPackage(item->text(1));
		}
	}
}

void MainWindow::removeAllPackages()
{
	if (repoList->selectedItems().isEmpty())
		return;

	if (!repoList->findItems(tr("All Groups"), Qt::MatchExactly).isEmpty())
	{
		QString tmp = repoList->selectedItems().first()->text();
		tmp.append(" ");
		tmp.prepend(" ");
		foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(tmp, (Qt::MatchFlags)Qt::MatchContains, 5))
		{
			removePackage(item->text(1));
		}
	}
	else
	{
		foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(repoList->selectedItems().first()->text(), (Qt::MatchFlags)Qt::MatchExactly, 4))
		{
			removePackage(item->text(1));
		}
	}
}

void MainWindow::cancelAllActions()
{
	if (repoList->selectedItems().isEmpty())
		return;

	if (!repoList->findItems(tr("All Groups"), Qt::MatchExactly).isEmpty())
	{
		QString tmp = repoList->selectedItems().first()->text();
		tmp.append(" ");
		tmp.prepend(" ");
		foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(tmp, (Qt::MatchFlags)Qt::MatchContains, 5))
		{
			cancelAction(item->text(1));
		}
	}
	else
	{
		foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(repoList->selectedItems().first()->text(), (Qt::MatchFlags)Qt::MatchContains, 4))
		{
			cancelAction(item->text(1));
		}
	}
}

void MainWindow::installPackage()
{
	qDebug() << "Install Package";
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
		installPackage(item->text(1));

	itemChanged();
}

void MainWindow::installPackage(const QString &package)
{
	qDebug() << "Install package: " + package;
	if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).isEmpty())
	{
		qDebug() << "Can't find package: " + package;
		//QStringList providers = aHandle->getProviders(package, item->text(5));
		//if (!providers.isEmpty())
		//	installPackage(providers.first());
		return;
	}
	QTreeWidgetItem *item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).first();

	qDebug() << item->text(1);
	if(aHandle->isProviderInstalled(package))
		return;
	
	if (aHandle->isInstalled(item->text(1)) || item->text(7) == tr("Install"))
		return;
	else
	{
		item->setText(7, tr("Install"));
		item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
	}
	qDebug() << item->text(5);

	foreach (QString dep, aHandle->getPackageDependencies(package, item->text(4)))
	{
		installPackage(dep);
	}
}

void MainWindow::removePackage()
{
	qDebug() << "Remove Package";
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
		removePackage(item->text(1));

	itemChanged();
}

void MainWindow::removePackage(const QString &package)
{
	qDebug() << "Uninstall package: " + package;
	if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).isEmpty())
	{
		qDebug() << "Can't find package: " + package;
		return;
	}
	QTreeWidgetItem *item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).first();

	qDebug() << item->text(1);
	if (!aHandle->isInstalled(item->text(1)) || item->text(7) == tr("Remove"))
		return;
	else
	{
		item->setText(7, tr("Uninstall"));
		item->setIcon(2, QIcon(":/Icons/icons/list-remove.png"));
	}
	qDebug() << item->text(5);

	foreach (QString dep, aHandle->getDependenciesOnPackage(package, item->text(4)))
	{
		removePackage(dep);
	}
}

void MainWindow::completeRemovePackage()
{
	qDebug() << "Complete Remove Package";
	QTreeWidgetItem *item = pkgsViewWG->selectedItems().first();

	qDebug() << item->text(1);
	if (aHandle->isInstalled(item->text(1)))
		return;
	else
	{
		item->setText(7, tr("Complete Uninstall"));
		item->setIcon(2, QIcon(":/Icons/icons/edit-delete.png"));
	}
	qDebug() << item->text(5);

	//Now we remove the on-package-dependencies and the dependencies...
	
	foreach (QString onDep, aHandle->getDependenciesOnPackage(item->text(1), item->text(4)))
	{
		removePackage(onDep);
	}
	foreach (QString dep, aHandle->getPackageDependencies(item->text(1), item->text(4)))
	{
		removePackage(dep);
	}

	itemChanged();
}

void MainWindow::cancelAction()
{
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
		cancelAction(item->text(1));

	itemChanged();
}

void MainWindow::cancelAction(const QString &package)
{
	qDebug() << "cancel action for: " + package;
	if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).isEmpty())
	{
		qDebug() << "Can't find package: " + package;
		return;
	}
	QTreeWidgetItem *item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).first();
	if (item->text(7).isEmpty())
		return;

	item->setText(7, QString());
	item->setIcon(2, QIcon());
	
	foreach (QString onDep, aHandle->getDependenciesOnPackage(item->text(1), item->text(4)))
	{
		cancelAction(onDep);
	}
	foreach (QString dep, aHandle->getPackageDependencies(item->text(1), item->text(4)))
	{
		cancelAction(dep);
	}

}

void MainWindow::startUpgrading()
{
	disconnect(dbdialog, 0,0,0);

	dbdialog->deleteLater();

	systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
	systray->setToolTip(QString(tr("qtPacman - Idle")));

	if(aHandle->getUpgradeablePackages().isEmpty())
	{
		/* Display a simple popup saying the system is up-to-date. */
		QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("System Upgrade"), 
				tr("Your system is up to date!"), QMessageBox::Ok, this);
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
	systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
	systray->setToolTip(QString(tr("qtPacman - Idle")));
}

void MainWindow::addUpgradeableToQueue()
{
	qDebug() << "UpgradeableToQueue";
	if (aHandle->getUpgradeablePackages().isEmpty())
		return;

	foreach (QString package, aHandle->getUpgradeablePackages())
	{
		QTreeWidgetItem *item = pkgsViewWG->findItems(package, Qt::MatchExactly, 1).first();
		item->setText(0, tr("Upgradeable"));
		item->setText(7, tr("Upgrade"));
		item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
	}

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

	systray->setIcon(QIcon(":/Icons/icons/edit-redo.png"));
	systray->setToolTip(QString(tr("qtPacman - Processing")));
}

void MainWindow::upgradePackage()
{
	qDebug() << "Upgrade Package";
	foreach (QTreeWidgetItem *item, pkgsViewWG->selectedItems())
	{
		item->setText(7, tr("Upgrade"));//Look if there are dependencies for the upgrade
		item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
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

	systray->setIcon(QIcon(":/Icons/icons/edit-redo.png"));
	systray->setToolTip(QString(tr("qtPacman - Processing")));

}

void MainWindow::queueProcessingEnded(bool errors)
{
	if(errors)
	{
		// TODO: popup a message if there were errors
		qDebug() << "Errors Occourred";
	}

	qDebug() << "Transaction Completed Successfully";

	pkgsViewWG->setSortingEnabled(false);
	populatePackagesView();
	refinePkgView();
	
	QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("Queue Processed"), 
			tr("Your Queue was successfully processed!"), QMessageBox::Ok, queueDl);

	message->exec();
	
	message->deleteLater();
	queueDl->deleteLater();

	systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
	systray->setToolTip(QString(tr("qtPacman - Idle")));
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

	if(pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 7).isEmpty() &&
			pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 7).isEmpty() &&
			pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7).isEmpty() &&
			pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7).isEmpty())
		return;
	else if(pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 7).isEmpty() &&
			pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 7).isEmpty())
		aHandle->initQueue(false, true, false);
	else if(pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 1).isEmpty() && 
					pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7).isEmpty())
		aHandle->initQueue(true, false, false);
	else
		aHandle->initQueue(true, true, false);

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7))
		aHandle->addSyncToQueue(itm->text(1));

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7))
		aHandle->addSyncToQueue(itm->text(1));

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 7))
		aHandle->addRemoveToQueue(itm->text(1));

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 7))
		aHandle->addRemoveToQueue(itm->text(1));
	
	revActive = true;
	
	reviewQueue = new QDialog(this);
	Ui::QueueReadyDialog qUi;
	qUi.setupUi(reviewQueue);
	
	reviewQueue->setWindowModality(Qt::ApplicationModal);
	qUi.treeWidget->hide();
	reviewQueue->show();
	
	connect(qUi.processButton, SIGNAL(clicked()), SLOT(processQueue()));
	connect(qUi.cancelButton, SIGNAL(clicked()), SLOT(destroyReviewQueue()));
	
	QString toShow(tr("Your Queue is about to be processed. "
			"You are going to:<br />"));
	int n = aHandle->getNumberOfTargets(1);
	toShow.append(QString(n == 1 ? tr("Remove <b>%1 package</b><br />") : tr("Remove <b>%1 packages</b><br />")).arg(n));
	int k = aHandle->getNumberOfTargets(0);
	toShow.append(QString(k == 1 ? tr("Install/Upgrade <b>%1 package</b><br />") : tr("Install/Upgrade <b>%1 packages</b><br />")).arg(k));
	toShow.append(tr("Do you wish to continue?"));
	
	qUi.queueInfo->setText(toShow);

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

void MainWindow::dbUpdateTray()
{
	/* Ok, let's silently perform a Db Update.
	 */
	// TODO: App Icon, where are you?
	systray->setIcon(QIcon(":/Icons/icons/edit-redo.png"));
	systray->setToolTip(QString(tr("qtPacman - Processing")));
	
	upDbTh = new UpDbThread(aHandle);
	connect(upDbTh, SIGNAL(finished()), SLOT(dbUpdateTrayFinished()));
	upDbTh->start();
}

void MainWindow::dbUpdateTrayFinished()
{	
	
	if(upDbTh->getResult())
	{
		/* Hey, it looks like the Db was actually updated.
		 * So, we have to do a pair of things. First of all,
		 * let's reload our TreeView of packages. Secondly,
		 * let's check if Upgrades are available
		 */

		pkgsViewWG->setSortingEnabled(false);
		populatePackagesView();
		
		QStringList list(aHandle->getUpgradeablePackages());
		if(!list.isEmpty())
		{
			/* We actually have something to upgrade! We'd 
			 * better let the user know by changing icon, 
			 * and showing a baloon.
			 */
			QSettings *settings = new QSettings();

			systray->setIcon(QIcon(":/Icons/icons/view-refresh.png"));
			systray->setToolTip(QString(tr("qtPacman - Idle (Upgrades Available)")));
			if(settings->value("scheduledUpdate/notifyUpgrades").toBool())
				systray->showMessage(QString(tr("System Upgrade")), QString(list.size() == 1 ? tr("There is %1 upgradeable package.\n"
						"Click here to upgrade your System.") :	tr("There are %1 upgradeable packages.\nClick here to upgrade your System.")).
						arg(list.size()));
			connect(systray, SIGNAL(messageClicked()), SLOT(fullSysUpgrade()));
		}
		else
			systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
	}
	else
	{
		systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
		systray->setToolTip(QString(tr("qtPacman - Idle")));
	}

	delete(upDbTh);
	
}

void MainWindow::systrayActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::Trigger)
	{
		QSettings *settings = new QSettings();
		
		if (isHidden())
		{
			/* Uh, we have to stop the Timer! */
			if(settings->value("scheduledUpdate/enabled").toBool())
				trayUpDb->stop();
			show();
		}
		else
		{
			/* Start Your timer, baby! */
			hide();
			if(settings->value("scheduledUpdate/enabled").toBool())
				trayUpDb->start();
			
		}
		
		settings->deleteLater();
	}
}

void MainWindow::getPackageFromFile()
{
	QString fileName = QFileDialog::getOpenFileName(this,
	     tr("Install a Package"), getenv("HOME"), tr("Arch Linux Packages (*.pkg.tar.gz)"));
	pmpkg_t *pkg;
	
	if(fileName == NULL)
		return;
	
	// Sanity check
	if(alpm_pkg_load(fileName.toAscii().data(), 1, &pkg) == -1)
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Error"), QString(tr("%1 does not seem\na valid package")).
				arg(fileName), QMessageBox::Ok, this);

		message->exec();

		message->deleteLater();
		return;
	}
	
	printf("Selected %s\n", alpm_pkg_get_name(pkg));
	
	alpm_pkg_free(pkg);
	
	aHandle->initQueue(false, false, true);
	
	aHandle->addFFToQueue(fileName);
	
	processQueue();
	
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

void MainWindow::updateABSTree()
{
	if(!aHandle->isInstalled("abs"))
	{
		QMessageBox *msgBox = new QMessageBox(this);

		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowTitle(QString("Error"));

		msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

		msgBox->setWindowModality(Qt::ApplicationModal);

		msgBox->setText(QString(tr("You need to have ABS installed to use qtPacman's\nbuilding feature. Do you want to install it now?")));

		switch (msgBox->exec()) {
		case QMessageBox::Yes:
			installPackage("abs");
			widgetQueueToAlpmQueue();
			break;
		case QMessageBox::No:
			break;
		default:
			// should never be reached
			break;
		}

		msgBox->deleteLater();
		
		return;
	}
	
	buildDialog = new BuildingDialog(aHandle, this);
	
	buildDialog->show();
	
	buildDialog->updateABSTree();
}

void MainWindow::validateSourceQueue()
{
	if(!aHandle->isInstalled("abs"))
	{
		QMessageBox *msgBox = new QMessageBox(this);

		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowTitle(QString("Error"));

		msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

		msgBox->setWindowModality(Qt::ApplicationModal);

		msgBox->setText(QString(tr("You need to have ABS installed to use qtPacman's\nbuilding feature. Do you want to install it now?")));

		switch (msgBox->exec()) {
		case QMessageBox::Yes:
			installPackage("abs");
			widgetQueueToAlpmQueue();
			break;
		case QMessageBox::No:
			break;
		default:
			// should never be reached
			break;
		}

		msgBox->deleteLater();

		return;
	}
	
	if(pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 7).isEmpty() &&
			pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 7).isEmpty() &&
			pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7).isEmpty() &&
			pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7).isEmpty())
		return;
	else if(!pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 7).isEmpty() ||
			!pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 7).isEmpty())
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Error"), QString(tr("You can not remove packages when processing\n"
				"your queue from Source")), QMessageBox::Ok, this);

		message->exec();

		message->deleteLater();
		return;
	}

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7))
	{
		if(itm->text(4).compare("core") && itm->text(4).compare("extra") && itm->text(4).compare("community")
				&& itm->text(4).compare("unstable") && itm->text(4).compare("testing"))
		{
			QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Error"), QString(tr("Some of your packages do not belong to Arch\n"
					"Linux's official repository. qtPacman is able to\nbuild packages from official sources only.")), QMessageBox::Ok, this);

			message->exec();

			message->deleteLater();
			return;
		}
	}

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7))
	{
		if(itm->text(4).compare("core") && itm->text(4).compare("extra") && itm->text(4).compare("community")
				&& itm->text(4).compare("unstable") && itm->text(4).compare("testing"))
		{
			QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Error"), QString(tr("Some of your packages do not belong to Arch\n"
					"Linux's official repository. qtPacman is able to\nbuild packages from official sources only.")), QMessageBox::Ok, this);

			message->exec();

			message->deleteLater();
			return;
		}

	}
	
	reviewBQueue = new QDialog(this);
	
	revBuildUi = new Ui::reviewBuildingDialog();
	
	revBuildUi->setupUi(reviewBQueue);
	
	reviewBQueue->setWindowModality(Qt::ApplicationModal);
	reviewBQueue->setAttribute(Qt::WA_DeleteOnClose, true);

	revBuildUi->infoLabel->setText((pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7).size() + 
			pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7).size()) == 1 ? QString(tr("You are about to install <b>%1"
					" package</b> from source. Building from source<br>can give some advantages, however is very slow.<br>If "
					"you are not sure about that, you would probably prefer to process<br>your queue from binary files. "
					"Before you continue, you are advised to<br>review your configuration to improve your building performance.")).arg(
							pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7).size() + 
							pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7).size()) : 
								QString(tr("You are about to install <b>%1"
										" packages</b> from source. Building from source<br>can give some advantages, however is very slow.<br>If "
										"you are not sure about that, you would probably prefer to process<br>your queue from binary files. "
										"Before you continue, you are advised to<br>review your configuration to improve your building performance.")).arg(
												pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7).size() + 
												pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7).size()));

	connect(revBuildUi->binaryButton, SIGNAL(clicked()), reviewBQueue, SLOT(close()));
	connect(revBuildUi->binaryButton, SIGNAL(clicked()), SLOT(widgetQueueToAlpmQueue()));
	connect(revBuildUi->abortButton, SIGNAL(clicked()), reviewBQueue, SLOT(close()));
	connect(revBuildUi->sourceButton, SIGNAL(clicked()), reviewBQueue, SLOT(close()));
	connect(revBuildUi->sourceButton, SIGNAL(clicked()), SLOT(startSourceProcessing()));
	connect(revBuildUi->pBuildButton, SIGNAL(clicked()), SLOT(openPBuildDialog()));
	
	reviewBQueue->show();
}

void MainWindow::openPBuildDialog()
{
	QStringList targets;

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7))
		targets.append(itm->text(1));

	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7))
		targets.append(itm->text(1));
	
	pBuildEditor = new EditPBuild(targets, reviewBQueue);
	
	pBuildEditor->exec();
	
	pBuildEditor->deleteLater();
}

void MainWindow::startSourceProcessing()
{
	buildDialog = new BuildingDialog(aHandle, this);
	buildDialog->initBuildingQueue();
	
	buildDialog->setWindowModality(Qt::ApplicationModal);
	buildDialog->setAttribute(Qt::WA_DeleteOnClose, true);
	
	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 7))
		buildDialog->addBuildingQueueItem(itm->text(1));
	
	foreach(QTreeWidgetItem *itm, pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 7))
		buildDialog->addBuildingQueueItem(itm->text(1));
	
	if(revBuildUi->noProcessBox->isChecked())
		buildDialog->waitBeforeProcess(true);
	
	delete(revBuildUi);
	
	buildDialog->show();
	
	connect(buildDialog, SIGNAL(finishedBuilding(int,QStringList)), SLOT(finishedBuilding(int,QStringList)));
		
	buildDialog->processBuildingQueue();
}

void MainWindow::finishedBuilding(int failure, QStringList targets)
{
	buildTargets.clear();
	
	if(failure == 2)
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Warning, tr("Error"), QString(tr("Your packages Failed to Build.\n"
				"Look at the output for more details.")), QMessageBox::Ok, buildDialog);

		message->exec();

		message->deleteLater();
		
		buildDialog->abortButton->setText(QString(tr("Close")));
		disconnect(buildDialog->abortButton, SIGNAL(clicked()), buildDialog, SLOT(abortProcess()));
		connect(buildDialog->abortButton, SIGNAL(clicked()), buildDialog, SLOT(deleteLater()));
		buildDialog->processingLabel->setText(QString(tr("Building Packages Failed!!")));
		buildDialog->buildingLabel->setText(QString());

		systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
		systray->setToolTip(QString(tr("qtPacman - Idle")));
		return;	
	}
	else if(failure == 1)
	{		
		QMessageBox *msgBox = new QMessageBox(buildDialog);

		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowTitle(QString(tr("Error")));

		msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

		msgBox->setWindowModality(Qt::ApplicationModal);

		buildDialog->processingLabel->setText(QString(tr("Building Packages Failed!!")));
		buildDialog->buildingLabel->setText(QString());

		msgBox->setText(QString(tr("Some packages failed to build.\nDo you want to proceed anyway?")));

		switch (msgBox->exec()) {
		case QMessageBox::Yes:
			failure = 0;
			break;
		case QMessageBox::No:
			buildDialog->abortButton->setText(QString(tr("Close")));
			disconnect(buildDialog->abortButton, SIGNAL(clicked()), buildDialog, SLOT(abortProcess()));
			connect(buildDialog->abortButton, SIGNAL(clicked()), buildDialog, SLOT(deleteLater()));
			systray->setIcon(QIcon(":/Icons/icons/list-add.png"));
			systray->setToolTip(QString(tr("qtPacman - Idle")));
			break;
		default:
			// should never be reached
			break;
		}

		msgBox->deleteLater();
	}
	
	if(failure == 0)
	{
		buildTargets = targets;
		
		if(buildDialog->reviewOutputFirst())
		{
			buildDialog->reduceButton->setText(QString(tr("Install Built Packages")));
			buildDialog->abortButton->setText(QString(tr("Close Without Installing")));
			buildDialog->processingLabel->setText(QString(tr("Packages Built Successfully!")));
			buildDialog->buildingLabel->setText(QString());
			disconnect(buildDialog->abortButton, SIGNAL(clicked()), buildDialog, SLOT(abortProcess()));
			connect(buildDialog->abortButton, SIGNAL(clicked()), buildDialog, SLOT(deleteLater()));
			disconnect(buildDialog->reduceButton, SIGNAL(clicked()));
			connect(buildDialog->reduceButton, SIGNAL(clicked()), SLOT(processBuiltPackages()));
		}
		else
			processBuiltPackages();
	}
		
}

void MainWindow::processBuiltPackages()
{
	buildDialog->deleteLater();

	aHandle->initQueue(false, false, true);

	foreach(QString pac, buildTargets)
	aHandle->addFFToQueue(pac);

	processQueue();
}
