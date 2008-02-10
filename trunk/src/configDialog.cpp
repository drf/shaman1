/***************************************************************************
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

#include "configDialog.h"

#include "AlpmHandler.h"

ConfigDialog::ConfigDialog(AlpmHandler *handler, QWidget *parent)
  : QDialog(parent),
    m_handler(handler)
{
    setupUi(this);
    setupGeneral();
    setupRepos();
    connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(changeWidget(int)));
}

ConfigDialog::~ConfigDialog()
{
}

void ConfigDialog::setupGeneral()
{
    listWidget->insertItem(0, new QListWidgetItem(QIcon(":/Icons/icons/network-server-database.png"), tr("General")));//FIXME: Replace icon
    connect(cleanDbButton, SIGNAL(clicked()), SLOT(cleanUnused()));
    connect(cleanCacheButton, SIGNAL(clicked()), SLOT(cleanCache()));
    connect(emptyCacheButton, SIGNAL(clicked()), SLOT(clearCache()));
}

void ConfigDialog::setupRepos()
{
        listWidget->addItem(new QListWidgetItem(QIcon(":/Icons/icons/network-server-database.png"), tr("Repositories")));
	alpm_list_t *repos = alpm_list_first(m_handler->getAvailableRepos());

	while(repos != NULL)
	{
		pmdb_t *curdb = (pmdb_t *)alpm_list_getdata(repos);

		if(!strcmp(alpm_db_get_name(curdb), "core"))
			coreBox->setChecked(true);
		else if(!strcmp(alpm_db_get_name(curdb), "extra"))
			extraBox->setChecked(true);
		else if(!strcmp(alpm_db_get_name(curdb), "community"))
			communityBox->setChecked(true);
		else if(!strcmp(alpm_db_get_name(curdb), "testing"))
			testingBox->setChecked(true);
		else if(!strcmp(alpm_db_get_name(curdb), "unstable"))
			unstableBox->setChecked(true);
		else if(!strcmp(alpm_db_get_name(curdb), "kdemod"))
			KDEMod3Box->setChecked(true);
		else if(!strcmp(alpm_db_get_name(curdb), "kdemod-testing"))
			KDEMod4Box->setChecked(true);
		else
		{
			QTreeWidgetItem *itm = new QTreeWidgetItem(thirdPartyWidget);
			itm->setText(0,alpm_db_get_name(curdb));
			itm->setText(1, alpm_db_get_url(curdb));
		}
		
		repos = alpm_list_next(repos);
	}
	
	connect(addThirdPartyButton, SIGNAL(clicked()), SLOT(openAddDialog()));
}

void ConfigDialog::openAddDialog()
{
	addDialog = new QDialog(this);
	addDialog->setWindowModality(Qt::ApplicationModal);
	
	QLabel *nameLabel = new QLabel("Enter Here the Repository's Name", addDialog);
	QLineEdit *name = new QLineEdit(addDialog);
	QLabel *serverLabel = new QLabel("Enter Here the Repository's Server", addDialog);
	QLineEdit *server = new QLineEdit(addDialog);
	QVBoxLayout *layout = new QVBoxLayout();
	QDialogButtonBox *buttons = new QDialogButtonBox(addDialog);
	
	buttons->addButton(QDialogButtonBox::Ok);
	buttons->addButton(QDialogButtonBox::Cancel);
	
	layout->addWidget(nameLabel);
	layout->addWidget(name);
	layout->addWidget(serverLabel);
	layout->addWidget(server);
	layout->addWidget(buttons);
	
	addDialog->setLayout(layout);
	
	addDialog->exec();
	if (addDialog->result() == 1) //QDialog::accepted
	{
		//FIXME: Add repository here...
	}
}

void ConfigDialog::changeWidget(int position)
{
    stackedWidget->setCurrentIndex(position);
}

void ConfigDialog::cleanUnused()
{
	cTh = new CleanThread(m_handler, 0);

	cleanDbButton->setEnabled(false);
	cleanCacheButton->setEnabled(false);
	emptyCacheButton->setEnabled(false);

	statusLabel->setText(QString(tr("Cleaning up unused Databases...")));

	connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
	connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
	connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
	cTh->start();
}

void ConfigDialog::cleanCache()
{
	cTh = new CleanThread(m_handler, 1);

	cleanDbButton->setEnabled(false);
	cleanCacheButton->setEnabled(false);
	emptyCacheButton->setEnabled(false);

	statusLabel->setText(QString(tr("Cleaning up Cache...")));

	connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
	connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
	connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
	cTh->start();
}

void ConfigDialog::clearCache()
{
	cTh = new CleanThread(m_handler, 2);

	cleanDbButton->setEnabled(false);
	cleanCacheButton->setEnabled(false);
	emptyCacheButton->setEnabled(false);

	statusLabel->setText(QString(tr("Deleting Cache...")));

	connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
	connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
	connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
	cTh->start();
}

void ConfigDialog::showFailure(int act)
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

void ConfigDialog::showSuccess(int act)
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

void ConfigDialog::cleanThread()
{
	cTh->deleteLater();
}

CleanThread::CleanThread(AlpmHandler *aH, int act)
: m_handler(aH),
action(act)
{

}

void CleanThread::run()
{
	switch(action)
	{
	case 0:
		if(m_handler->cleanUnusedDb())
			emit success(action);
		else
			emit failure(action);
		break;

	case 1:
		if(m_handler->cleanCache())
			emit success(action);
		else
			emit failure(action);
		break;
	case 2:
		if(m_handler->cleanCache(true))
			emit success(action);
		else
			emit failure(action);
		break;

	}
}

