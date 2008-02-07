#include <iostream>
#include "../ui_repoDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

#include "RepoDialogCl.h"

RepoDialogCl::RepoDialogCl(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
  aHandle(hnd)
{
	setupUi(this);
	setWindowModality(Qt::ApplicationModal);

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
	
	connect(repoButtonBox, SIGNAL(clicked(QAbstractButton*)), SLOT(handleClick(QAbstractButton*)));
	connect(addThirdPartyButton, SIGNAL(clicked()), SLOT(openAddDialog()));
}

RepoDialogCl::~RepoDialogCl()
{
}

void RepoDialogCl::openAddDialog()
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

void RepoDialogCl::cancelAddDialog()
{
	
}

void RepoDialogCl::applyAddDialog()
{
	
}

void RepoDialogCl::handleClick(QAbstractButton *button)
{
	
}
