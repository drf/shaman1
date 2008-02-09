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
#include "RepoWidget.h"

#include "configDialog.h"
#include <iostream>
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

RepoWidget::RepoWidget(AlpmHandler *hnd, ConfigDialog *parent)
  : QWidget(parent),
    aHandle(hnd)
{
	setupUi(this);
	//setWindowModality(Qt::ApplicationModal);

	alpm_list_t *repos = alpm_list_first(aHandle->getAvailableRepos());

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
	
	//connect(repoButtonBox, SIGNAL(clicked(QAbstractButton*)), SLOT(handleClick(QAbstractButton*)));
	connect(addThirdPartyButton, SIGNAL(clicked()), SLOT(openAddDialog()));
	connect(parent, SIGNAL(saveState()), SLOT(save()));
}

RepoWidget::~RepoWidget()
{
}

void RepoWidget::openAddDialog()
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
	
	addDialog->show();
	
}

void RepoWidget::cancelAddDialog()
{
	
}

void RepoWidget::applyAddDialog()
{
	
}

void RepoWidget::handleClick(QAbstractButton *button)
{
	
}
