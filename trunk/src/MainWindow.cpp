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

bool MainWindow::populatePackagesView(alpm_list_t *pkgs)
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
	
	pbar->reset();
	pbar->setRange(0, alpm_list_count(pkgs));
	
	layout->addWidget(label);
	layout->addWidget(pbar);
	
	pbarWG->setLayout(layout);
	
	pbarWG->show();
	label->show();

	removePackagesView();
	
	currentpkgs = pkgs;
	
	currentpkgs = alpm_list_first(currentpkgs);
	
	databases = aHandle->getAvailableRepos();
	
	while(currentpkgs != NULL)
	{
		pmpkg_t *pkg = (pmpkg_t *)alpm_list_getdata(currentpkgs);
		QTreeWidgetItem *item = new QTreeWidgetItem(pkgsViewWG);
		alpm_list_t *strings;
		
		item->setText(2, alpm_pkg_get_name(pkg));
		item->setText(3, alpm_pkg_get_version(pkg));
		item->setText(4, alpm_pkg_get_desc(pkg));
		
		databases = alpm_list_first(databases);
		
		while(databases != NULL)
		{
			pmdb_t *dbcrnt = (pmdb_t *)alpm_list_getdata(databases);
			
			strings = strsplit(alpm_pkg_get_url(pkg), '/');
			
			while(strings != NULL)
			{
				if(!strcmp((char *)alpm_list_getdata(strings), alpm_db_get_name(dbcrnt)))
				{
					item->setText(5, alpm_db_get_name(dbcrnt));
					found = 1;
					break;
				}
				strings = alpm_list_next(strings);
			}
			
			if(found == 1)
			{
				found = 0;
				break;
			}
			
			databases = alpm_list_next(databases);
		}
		
		databases = alpm_list_first(databases);
				
		//pkgsViewWG->addTopLevelItem(item);
		
		//printf("%s", alpm_pkg_get_name(pkg));
		
		currentpkgs = alpm_list_next(currentpkgs);
		
		pbar->setValue( count );
		
		count++;
	}
	
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

void MainWindow::changePackagesView(QListWidgetItem *itm)
{
	QString data = itm->text();
	
	if(!data.compare("All Repositories"))
		populatePackagesView(aHandle->searchPackages(NULL,NULL,0));
	else	
		populatePackagesView(aHandle->searchPackages(NULL,data.toAscii().data(),0));
}

void MainWindow::showPkgInfo(QTreeWidgetItem *itm)
{
	char *name = itm->text(2).toAscii().data();
	char *db = itm->text(5).toAscii().data();
	pmpkg_t *pkg;
	
	//pkg = alpm_db_get_pkg(db, name);
	
	
}

