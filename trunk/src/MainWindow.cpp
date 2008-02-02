#include <iostream>
#include <QtGui>
#include <QString>
#include <QListWidgetItem>
#include <alpm.h>

#include "MainWindow.h"
#include "callbacks.h"
#include "UpdateDbDialog.h"

extern CallBacks CbackReference;


MainWindow::MainWindow(AlpmHandler *handler, QApplication *appl, QMainWindow *parent) : QMainWindow(parent)
{
	setupUi(this);
	currentpkgs = NULL;
	
	aHandle = handler;
	app = appl;
	
	connect(actionUpdate_Database, SIGNAL(triggered()), this, SLOT(doDbUpdate()));
	
	return;
	
}

MainWindow::~MainWindow()
{
	return;
}

bool MainWindow::removePackagesView()
{
	QTreeWidgetItem *itm;
	
	while((itm = pkgsViewWG->takeTopLevelItem(0)) != NULL)
		delete(itm);
	
	return true;
}

void MainWindow::doUpdView()
{
	
}

bool MainWindow::populatePackagesView()
{
	QDialog *pbarWG = new QDialog(this);
	QVBoxLayout *layout = new QVBoxLayout;
	QProgressBar *pbar = new QProgressBar(pbarWG);
	alpm_list_t *databases;
	int found = 0, count = 0;
	
	pbarWG->show();
	
	layout->addWidget(new QLabel("Loading View..."));
	layout->addWidget(pbar);
		
	pbarWG->setLayout(layout);
	
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
						
			item->setText(2, alpm_pkg_get_name(pkg));
			item->setText(3, alpm_pkg_get_version(pkg));
			item->setText(4, alpm_pkg_get_desc(pkg));
			item->setText(5, alpm_db_get_name(dbcrnt));
			
			currentpkgs = alpm_list_next(currentpkgs);
			
			pbar->setValue( count );
							
			count++;
		}
	
		databases = alpm_list_next(databases);
	}
		
	databases = alpm_list_first(databases);
				
	pbarWG->close();
	
	delete(layout);
	delete(pbar);
	
	pkgsViewWG->sortItems(2, Qt::AscendingOrder);
	
	connect(pkgsViewWG, SIGNAL(itemSelectionChanged()), this, 
			SLOT(showPkgInfo()));
	
	return true;
}

bool MainWindow::populateRepoColumn()
{
	alpm_list_t *list = aHandle->getAvailableRepos();
	
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
	
	connect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(changePackagesView(QListWidgetItem*)));
	
	return true;
}

void MainWindow::refinePkgView(char *repo, char *searches)
{
	int index = 0;
	QTreeWidgetItem *itm;
	
	itm = pkgsViewWG->topLevelItem(index);
	
	while(itm != NULL)
	{
		int set = 0;
		
		if(repo != NULL)
		{
			set = 1;
			if(!strcmp(repo, itm->text(5).toAscii().data()))
				itm->setHidden(false);
			else
				itm->setHidden(true);
		}
		if(searches != NULL)
		{
			if(set != 1 || itm->isHidden())
			{
				itm->setHidden(false);
			}
			set = 1;
		}
		if(!set)
			itm->setHidden(false);
		
		index++;
		itm = pkgsViewWG->topLevelItem(index);
	}
}

void MainWindow::changePackagesView(QListWidgetItem *itm)
{
	QString data = itm->text();
	
	if(!data.compare("All Repositories"))
		refinePkgView(NULL,NULL);
	else	
		refinePkgView(data.toAscii().data(),NULL);
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
	
	dbdialog = new UpdateDbDialog(aHandle);
	
	dbdialog->show();
	
	connect(this, SIGNAL(updateDB()), dbdialog, SLOT(doAction()));
	
	app->processEvents();
	
	emit updateDB();
	
	connect(dbdialog, SIGNAL(killMe()), this, SLOT(finishDbUpdate()));
	
	//dbdialog->doAction();
	
}

void MainWindow::finishDbUpdate()
{
	disconnect(dbdialog, 0,0,0);
	
	delete(dbdialog);
}

UpPkgViewThread::UpPkgViewThread(MainWindow *mW)
{
	mainWin = mW;
}

void UpPkgViewThread::run()
{
	mainWin->doUpdView();
}

