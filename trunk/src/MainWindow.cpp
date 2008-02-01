#include <iostream>
#include <QtGui>
#include <QString>
#include <QListWidgetItem>
#include <alpm.h>

#include "MainWindow.h"
#include "callbacks.h"


MainWindow::MainWindow(AlpmHandler *handler, QMainWindow *parent) : QMainWindow(parent)
{
	setupUi(this);
	currentpkgs = NULL;
	
	aHandle = handler;
	
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

bool MainWindow::populatePackagesView()
{
	QWidget *pbarWG = new QWidget();
	QVBoxLayout *layout = new QVBoxLayout;
	QLabel *label = new QLabel(pbarWG);
	QProgressBar *pbar = new QProgressBar(pbarWG);
	alpm_list_t *databases;
	int found = 0, count = 0;
	
	label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	label->setText(QString("Loading View, please wait..."));
	label->setIndent(10);	
	
	layout->addWidget(label);
	layout->addWidget(pbar);
	
	pbarWG->setLayout(layout);
	
	pbarWG->show();
	label->show();
	
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
	delete(label);
	delete(pbar);
	
	pkgsViewWG->sortItems(2, Qt::AscendingOrder);
	
	connect(pkgsViewWG, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, 
			SLOT(showPkgInfo(QTreeWidgetItem*)));
	
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

void MainWindow::showPkgInfo(QTreeWidgetItem *itm)
{
	char *name = itm->text(2).toAscii().data();
	char *db = itm->text(5).toAscii().data();
	pmpkg_t *pkg;
	
	//pkg = alpm_db_get_pkg(db, name);
	
	
}

