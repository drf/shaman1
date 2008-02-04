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
#include "MainWindow.h"
#include "callbacks.h"
#include "UpdateDbDialog.h"

#include <iostream>
#include <QMenu>
#include <QString>
#include <QListWidgetItem>
#include <QDebug>
#include <alpm.h>

extern CallBacks CbackReference;


MainWindow::MainWindow(AlpmHandler *handler, QMainWindow *parent) 
 : QMainWindow(parent),
   currentpkgs(0),
   aHandle(handler)
{
	setupUi(this);
        pkgsViewWG->setContextMenuPolicy(Qt::CustomContextMenu);
	
	connect(actionUpdate_Database, SIGNAL(triggered()), SLOT(doDbUpdate()));
	connect(pkgsViewWG, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(showContextMenu()));
	connect(actionProcess_Queue, SIGNAL(triggered()), SLOT(processQueue()));
	connect(switchToRepo, SIGNAL(clicked()), SLOT(populateRepoColumn()));
	connect(switchToGrps, SIGNAL(clicked()), SLOT(populateGrpsColumn()));
	connect(installButton, SIGNAL(clicked()), SLOT(installPackage()));
	connect(removeButton, SIGNAL(clicked()), SLOT(removePackage()));
	connect(actionUpgrade_System, SIGNAL(triggered()), SLOT(fullSysUpgrade()));
	connect(packageSwitchCombo, SIGNAL(currentIndexChanged(int)), SLOT(refinePkgView()));
	connect(searchLine, SIGNAL(textChanged(const QString&)), SLOT(refinePkgView()));
	
	return;
	
}

MainWindow::~MainWindow()
{
	return;
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
	QDialog *pbarWG = new QDialog(this);
	QVBoxLayout *layout = new QVBoxLayout;
	QProgressBar *pbar = new QProgressBar(pbarWG);
	alpm_list_t *databases;
	int count = 0;
	
	layout->addWidget(new QLabel("Loading View..."));
	layout->addWidget(pbar);
		
	pbarWG->setLayout(layout);
	
	pbarWG->show();
	
	disconnect(pkgsViewWG, SIGNAL(itemSelectionChanged()), 0, 0);
	
	removePackagesView();
	
	databases = aHandle->getAvailableRepos();
	
	databases = alpm_list_first(databases);
	
	while(databases != NULL)
	{
		pmdb_t *dbcrnt = (pmdb_t *)alpm_list_getdata(databases);
	
		currentpkgs = alpm_db_getpkgcache(dbcrnt);
		pbar->setRange(0, alpm_list_count(currentpkgs));
		pbar->reset();
		count = 0;
		
		while(currentpkgs != NULL)
		{
			pmpkg_t *pkg = (pmpkg_t *)alpm_list_getdata(currentpkgs);
			QTreeWidgetItem *item = new QTreeWidgetItem(pkgsViewWG);
			alpm_list_t *grps = (alpm_list_t *)alpm_pkg_get_groups(pkg);
			QString grStr("");
									
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
			
			pbar->setValue( count );
							
			count++;
		}
	
		databases = alpm_list_next(databases);
	}
		
	databases = alpm_list_first(databases);
				
	pbarWG->close();
	
	layout->deleteLater();
	pbar->deleteLater();
	
	pkgsViewWG->sortItems(2, Qt::AscendingOrder);
	
	connect(pkgsViewWG, SIGNAL(itemSelectionChanged()), this, 
			SLOT(showPkgInfo()));
	
	return true;
}

void MainWindow::populateRepoColumn()
{
	alpm_list_t *list = aHandle->getAvailableRepos();
	
	removeRepoColumn();
	
	list = alpm_list_first(list);
	
	QListWidgetItem *item = new QListWidgetItem(repoList);
	
	item->setText("All Repositories");
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
			
	item->setText("All Groups");
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
	foreach (QTreeWidgetItem *item, pkgsViewWG->findItems(QString(), Qt::MatchContains | Qt::MatchWildcard))
	{
		item->setHidden(true);
	}
	
	QList<QTreeWidgetItem*> list = pkgsViewWG->findItems(QString(), Qt::MatchContains | Qt::MatchWildcard);
	
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
	qDebug() << "The left TextBox is over, let's do the ComboBox";
	if (packageSwitchCombo->currentText() != tr("All Packages"))
        {
		qDebug() << "Hehe, we should not show all Packages";
		if (packageSwitchCombo->currentText() == tr("Installed packages"))
		{
			//qDebug() << "We should only show the installed packages";
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (!item->text(0).compare("Installed"))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Not installed packages"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (!item->text(0).compare("Not installed"))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Upgradeable packages"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (!item->text(0).compare("Upgradeable"))
					list.removeAt(list.indexOf(item));
			}
		}
		if (packageSwitchCombo->currentText() == tr("Packages in Queue"))
		{
			foreach (QTreeWidgetItem *item, list)
			{
				//qDebug() << "Checking for installed packages" + item->text(2);
				if (!item->text(0).compare("In Queue"))
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

void MainWindow::showPkgInfo()
{
	char *pkgname = pkgsViewWG->currentItem()->text(2).toAscii().data();
	char *db = pkgsViewWG->currentItem()->text(5).toAscii().data();
	QString description;
	pmpkg_t *pkg;
	alpm_list_t *databases;
	pmdb_t *curdb = NULL;
	
	databases = aHandle->getAvailableRepos();
		
	databases = alpm_list_first(databases);
	printf("%s:", db);
	printf("%s\n", pkgname);
	
	while(databases != NULL)
	{
		if(!strcmp(db, alpm_db_get_name((pmdb_t *)alpm_list_getdata(databases))))
		{
			curdb = (pmdb_t *)alpm_list_getdata(databases);
			break;
		}
		printf("%s,", alpm_db_get_name((pmdb_t *)alpm_list_getdata(databases)));
		databases = alpm_list_next(databases);
	}
	
	printf("%s\n", pkgname);
	
	pkg = alpm_db_get_pkg(curdb, pkgname);
	
	databases = alpm_list_first(databases);

	printf("\n");
	
	description.append("<b>");
	description.append(alpm_pkg_get_name(pkg));
	description.append(" (");
	description.append(alpm_pkg_get_version(pkg));
	description.append(")</b><br><br>");
	description.append(alpm_pkg_get_desc(pkg));

	pkgInfo->setHtml(description);
	
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
	
	dbdialog->deleteLater();
}

void MainWindow::showContextMenu()
{
	qDebug() << "Let's show a context menu";
	QMenu *menu = new QMenu(this);
        //FIXME: Disable actions if they're not needed f.e. installAction on installed packages
	QAction *installAction = menu->addAction(tr("Mark for Installation"));
        connect(installAction, SIGNAL(triggered()), SLOT(installPackage()));
        QAction *removeAction = menu->addAction(tr("Mark for Removal"));
        connect(removeAction, SIGNAL(triggered()), SLOT(removePackage()));
        QAction *upgradeAction = menu->addAction(tr("Mark for Upgrade"));
        connect(upgradeAction, SIGNAL(triggered()), SLOT(upgradePackage()));
        menu->popup(QCursor::pos());
}

void MainWindow::installPackage()
{
	qDebug() << "Install Package";
	//FIXME: Add the package to a list, which will get processed, when "Process Queue" is clicked
}

void MainWindow::removePackage()
{
	qDebug() << "Remove Package";
        //FIXME: Same as installPackage
}

void MainWindow::startUpgrading()
{
	disconnect(dbdialog, 0,0,0);
		
	dbdialog->deleteLater();
	
	
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
        //FIXME: Same as installPackage
}

void MainWindow::processQueue()
{
	qDebug() << "Process Queue";
	//FIXME: Process here the created list...
}


