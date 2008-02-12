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

#include <QLineEdit>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

ConfigDialog::ConfigDialog(AlpmHandler *handler, QWidget *parent)
: QDialog(parent),
m_handler(handler),
upDb(false)
{
	setupUi(this);
	setupGeneral();
	setupPacman();
	setupRepos();
	connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(changeWidget(int)));
	connect(this, SIGNAL(accepted()), SLOT(saveConfiguration()));
	connect(addMirrorButton, SIGNAL(clicked()), SLOT(addMirror()));
}

ConfigDialog::~ConfigDialog()
{
}

QStringList ConfigDialog::getMirrorList()
{
	QFile file("/etc/pacman.d/mirrorlist");
	QStringList retlist;
	
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return retlist;
	
	QTextStream in(&file);
	while (!in.atEnd()) 
	{
		QString line = in.readLine();
		if(line.startsWith('#'))
			continue;
		
		if(!line.contains("server", Qt::CaseInsensitive))
			continue;
		
		QStringList list(line.split("=", QString::SkipEmptyParts));
		QString serverN(list.at(1));
		
		serverN.remove(QChar(' '), Qt::CaseInsensitive);
		
		retlist.append(serverN);
	}
	
	file.close();
	
	return retlist;

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
	QString whichMirror;
	QStringList mirrors;
	
	mirrors = getMirrorList();
	
	for(int i = 0; i < mirrors.size(); ++i)
		mirrorBox->addItem(mirrors.at(i));

	while(repos != NULL)
	{
		pmdb_t *curdb = (pmdb_t *)alpm_list_getdata(repos);

		if(!strcmp(alpm_db_get_name(curdb), "core"))
		{
			whichMirror = alpm_db_get_url(curdb);
			coreBox->setChecked(true);
		}
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
			itm->setText(0, alpm_db_get_name(curdb));
			itm->setText(1, alpm_db_get_url(curdb));
		}

		repos = alpm_list_next(repos);
	}

	QStringList tmplst = whichMirror.split(QString("core"), 
			QString::SkipEmptyParts, Qt::CaseInsensitive);

	QString dserv(tmplst.at(0));

	dserv.append("$repo");
	dserv.append(tmplst.at(1));

	if(mirrorBox->findText(dserv) != -1)
		mirrorBox->setCurrentIndex(mirrorBox->findText(dserv));

	connect(addThirdPartyButton, SIGNAL(clicked()), SLOT(openAddDialog()));
	connect(editThirdPartyButton, SIGNAL(clicked()), SLOT(openEditDialog()));
	connect(removeThirdPartyButton, SIGNAL(clicked()), SLOT(removeThirdParty()));
}


void ConfigDialog::setupPacman()
{
	listWidget->addItem(new QListWidgetItem(QIcon(":/Icons/icons/network-server-database.png"), tr("Pacman")));//FIXME: Replace icon
	
	/* Let's read alpm configuration! */
	if(alpm_option_get_nopassiveftp())
		noPassiveFtpBox->setChecked(true);
	
	useDeltaBox->setHidden(true);
	
	alpm_list_t *tmp;
	QString tmpStr;
	
	tmp = alpm_option_get_holdpkgs();
	while(tmp != NULL)
	{
		tmpStr.append((char *)alpm_list_getdata(tmp));
		tmpStr.append(" ");
		tmp = alpm_list_next(tmp);
	}
	holdPkgLine->setText(tmpStr);
	tmpStr = "";
	
	tmp = alpm_option_get_ignorepkgs();
	while(tmp != NULL)
	{
		tmpStr.append((char *)alpm_list_getdata(tmp));
		tmpStr.append(" ");
		tmp = alpm_list_next(tmp);
	}
	ignorePkgLine->setText(tmpStr);
	tmpStr = "";

	tmp = alpm_option_get_ignoregrps();
	while(tmp != NULL)
	{
		tmpStr.append((char *)alpm_list_getdata(tmp));
		tmpStr.append(" ");
		tmp = alpm_list_next(tmp);
	}
	ignoreGrpsLine->setText(tmpStr);
	tmpStr = "";
	
	tmp = alpm_option_get_noupgrades();
	while(tmp != NULL)
	{
		tmpStr.append((char *)alpm_list_getdata(tmp));
		tmpStr.append(" ");
		tmp = alpm_list_next(tmp);
	}
	noUpgradeLine->setText(tmpStr);
	tmpStr = "";

	tmp = alpm_option_get_noextracts();
	while(tmp != NULL)
	{
		tmpStr.append((char *)alpm_list_getdata(tmp));
		tmpStr.append(" ");
		tmp = alpm_list_next(tmp);
	}
	noExtractLine->setText(tmpStr);
	tmpStr = "";

	xFerCommandLine->setText((char *)alpm_option_get_xfercommand());
	tmpStr = "";

}

void ConfigDialog::openAddDialog()
{
	addDialog = new QDialog(this);
	addDialog->setWindowModality(Qt::ApplicationModal);

	QLabel *nameLabel = new QLabel(tr("Enter Here the Repository's Name"), addDialog);
	QLineEdit *name = new QLineEdit(addDialog);
	QLabel *serverLabel = new QLabel(tr("Enter Here the Repository's Server"), addDialog);
	QLineEdit *server = new QLineEdit(addDialog);
	QVBoxLayout *layout = new QVBoxLayout();
	QDialogButtonBox *buttons = new QDialogButtonBox(addDialog);

	buttons->addButton(QDialogButtonBox::Ok);
	buttons->addButton(QDialogButtonBox::Cancel);

	connect(buttons, SIGNAL(accepted()), addDialog, SLOT(accept()));
	connect(buttons, SIGNAL(rejected()), addDialog, SLOT(reject()));

	layout->addWidget(nameLabel);
	layout->addWidget(name);
	layout->addWidget(serverLabel);
	layout->addWidget(server);
	layout->addWidget(buttons);

	addDialog->setLayout(layout);

	addDialog->exec();
	if (addDialog->result() == 1) //QDialog::accepted
	{
		QTreeWidgetItem *itm = new QTreeWidgetItem(thirdPartyWidget);
		itm->setText(0, name->text());
		itm->setText(1, server->text());
	}

	addDialog->deleteLater();
}

void ConfigDialog::openEditDialog()
{
	if(!thirdPartyWidget->currentItem())
		return;

	addDialog = new QDialog(this);
	addDialog->setWindowModality(Qt::ApplicationModal);

	QLabel *nameLabel = new QLabel(tr("Enter Here the Repository's Name"), addDialog);
	QLineEdit *name = new QLineEdit(addDialog);
	QLabel *serverLabel = new QLabel(tr("Enter Here the Repository's Server"), addDialog);
	QLineEdit *server = new QLineEdit(addDialog);
	QVBoxLayout *layout = new QVBoxLayout();
	QDialogButtonBox *buttons = new QDialogButtonBox(addDialog);

	buttons->addButton(QDialogButtonBox::Ok);
	buttons->addButton(QDialogButtonBox::Cancel);

	connect(buttons, SIGNAL(accepted()), addDialog, SLOT(accept()));
	connect(buttons, SIGNAL(rejected()), addDialog, SLOT(reject()));

	layout->addWidget(nameLabel);
	layout->addWidget(name);
	layout->addWidget(serverLabel);
	layout->addWidget(server);
	layout->addWidget(buttons);

	name->setText(thirdPartyWidget->currentItem()->text(0));
	server->setText(thirdPartyWidget->currentItem()->text(1));

	addDialog->setLayout(layout);

	addDialog->exec();
	if (addDialog->result() == 1) //QDialog::accepted
	{
		thirdPartyWidget->currentItem()->setText(0, name->text());
		thirdPartyWidget->currentItem()->setText(1, server->text());
	}

	addDialog->deleteLater();
}

void ConfigDialog::removeThirdParty()
{
	if(!thirdPartyWidget->currentItem())
		return;

	delete(thirdPartyWidget->takeTopLevelItem(thirdPartyWidget->indexOfTopLevelItem(
			thirdPartyWidget->currentItem())));
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

void ConfigDialog::saveConfiguration()
{
	bool dbChanged = false;
	QString mirror(mirrorBox->currentText());
	ConfigurationParser parser;

	if(coreBox->checkState() == Qt::Checked)
	{
		if(!parser.editPacmanKey("core/Server", mirror, 0))
		{
			if(parser.editPacmanKey("core/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			parser.editPacmanKey("core/Include", NULL, 2);
		}
	}
	else
	{
		if(parser.editPacmanKey("core/Server", NULL, 2))
			dbChanged = true;
		if(parser.editPacmanKey("core/Include", NULL, 2))
			dbChanged = true;
	}

	if(extraBox->checkState() == Qt::Checked)
	{
		if(!parser.editPacmanKey("extra/Server", mirror, 0))
		{
			if(parser.editPacmanKey("extra/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			parser.editPacmanKey("extra/Include", NULL, 2);
		}
	}
	else
	{
		if(parser.editPacmanKey("extra/Server", NULL, 2))
			dbChanged = true;
		if(parser.editPacmanKey("extra/Include", NULL, 2))
			dbChanged = true;
	}

	if(communityBox->checkState() == Qt::Checked)
	{
		if(!parser.editPacmanKey("community/Server", mirror, 0))
		{
			if(parser.editPacmanKey("community/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			parser.editPacmanKey("community/Include", NULL, 2);
		}
	}
	else
	{
		if(parser.editPacmanKey("community/Server", NULL, 2))
			dbChanged = true;
		if(parser.editPacmanKey("community/Include", NULL, 2))
			dbChanged = true;
	}

	if(testingBox->checkState() == Qt::Checked)
	{
		if(!parser.editPacmanKey("testing/Server", mirror, 0))
		{
			if(parser.editPacmanKey("testing/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			parser.editPacmanKey("testing/Include", NULL, 2);
		}
	}
	else
	{
		if(parser.editPacmanKey("testing/Server", NULL, 2))
			dbChanged = true;
		if(parser.editPacmanKey("testing/Include", NULL, 2))
			dbChanged = true;
	}

	if(unstableBox->checkState() == Qt::Checked)
	{
		if(!parser.editPacmanKey("unstable/Server", mirror, 0))
		{
			if(parser.editPacmanKey("unstable/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			parser.editPacmanKey("unstable/Include", NULL, 2);
		}
	}
	else
	{
		if(parser.editPacmanKey("unstable/Server", NULL, 2))
			dbChanged = true;
		if(parser.editPacmanKey("unstable/Include", NULL, 2))
			dbChanged = true;
	}

	if(KDEMod3Box->checkState() == Qt::Checked)
	{
		mirror = "http://kdemod.ath.cx/repo/current/i686";
		if(!parser.editPacmanKey("kdemod/Server", mirror, 0))
		{
			if(parser.editPacmanKey("kdemod/Server", mirror, 1))
				dbChanged = true;
		}
		else
			dbChanged = true;
	}
	else
		if(parser.editPacmanKey("kdemod/Server", NULL, 2))
			dbChanged = true;

	if(KDEMod4Box->checkState() == Qt::Checked)
	{
		mirror = "http://kdemod.ath.cx/repo/testing/i686";
		if(!parser.editPacmanKey("kdemod-testing/Server", mirror, 0))
		{
			if(parser.editPacmanKey("kdemod-testing/Server", mirror, 1))
				dbChanged = true;
		}
		else
			dbChanged = true;
	}
	else
		if(parser.editPacmanKey("kdemod-testing/Server", NULL, 2))
			dbChanged = true;

	/* Whew, now with the third party elements. We also take the
	 * chance to free them, for the sake of memory.
	 */

	QTreeWidgetItem *itm;

	while((itm = thirdPartyWidget->takeTopLevelItem(0)) != NULL)
	{
		QString tName(itm->text(0));

		tName.append("/Server");

		if(!parser.editPacmanKey(tName, itm->text(1), 0))
		{
			if(parser.editPacmanKey(tName, itm->text(1), 1))
				dbChanged = true;
		}
		else
			dbChanged = true;

		delete(itm);
	}
	
	/* Well done, let's start committing changes to pacman's options */
	if(noPassiveFtpBox->checkState() == Qt::Checked)
		parser.editPacmanKey("options/NoPassiveFtp", "", 0);
	else
		parser.editPacmanKey("options/NoPassiveFtp", NULL, 2);

	if(holdPkgLine->isModified())
	{
		if(holdPkgLine->text().isEmpty())
			parser.editPacmanKey("options/HoldPkg", NULL, 2);
		else
			if(!parser.editPacmanKey("options/HoldPkg", holdPkgLine->text(), 0))
				parser.editPacmanKey("options/HoldPkg", holdPkgLine->text(), 1);
	}

	if(ignorePkgLine->isModified())
	{
		if(ignorePkgLine->text().isEmpty())
			parser.editPacmanKey("options/IgnorePkg", NULL, 2);
		else
			if(!parser.editPacmanKey("options/IgnorePkg", ignorePkgLine->text(), 0))
				parser.editPacmanKey("options/IgnorePkg", ignorePkgLine->text(), 1);
	}

	if(ignoreGrpsLine->isModified())
	{
		if(ignoreGrpsLine->text().isEmpty())
			parser.editPacmanKey("options/IgnoreGroup", NULL, 2);
		else
			if(!parser.editPacmanKey("options/IgnoreGroup", ignoreGrpsLine->text(), 0))
				parser.editPacmanKey("options/IgnoreGroup", ignoreGrpsLine->text(), 1);
	}

	if(noUpgradeLine->isModified())
	{
		if(noUpgradeLine->text().isEmpty())
			parser.editPacmanKey("options/NoUpgrade", NULL, 2);
		else
			if(!parser.editPacmanKey("options/NoUpgrade", noUpgradeLine->text(), 0))
				parser.editPacmanKey("options/NoUpgrade", noUpgradeLine->text(), 1);
	}

	if(noExtractLine->isModified())
	{
		if(noExtractLine->text().isEmpty())
			parser.editPacmanKey("options/NoExtract", NULL, 2);
		else
			if(!parser.editPacmanKey("options/NoExtract", noExtractLine->text(), 0))
				parser.editPacmanKey("options/NoExtract", noExtractLine->text(), 1);
	}

	if(xFerCommandLine->isModified())
	{
		if(xFerCommandLine->text().isEmpty())
			parser.editPacmanKey("options/XferCommand", NULL, 2);
		else
			if(!parser.editPacmanKey("options/XferCommand", xFerCommandLine->text(), 0))
				parser.editPacmanKey("options/XferCommand", xFerCommandLine->text(), 1);
	}


	/* Ok, saving finished, commit changes to Alpm now */
	m_handler->reloadPacmanConfiguration();

	/* Did we change anything in the repos? Better update our
	 * local DB then.
	 */

	if(dbChanged)
	{
		QMessageBox *msgBox = new QMessageBox(this);

		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowTitle(QString("Settings Changed"));

		msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

		msgBox->setWindowModality(Qt::ApplicationModal);

		msgBox->setText("Your repositories have changed.\nDo you want to Update Your Database?");

		switch (msgBox->exec()) {
		case QMessageBox::Yes:
			upDb = true;
			break;
		case QMessageBox::No:
			upDb = false;
			break;
		default:
			// should never be reached
			break;
		}

		msgBox->deleteLater();
	}

}

void ConfigDialog::addMirror()
{
	if(addMirrorLine->text().isEmpty())
		return;

	QString mirror(addMirrorLine->text());

	if(!mirror.contains(QString("$repo")) || (!mirror.startsWith(QString("http://")) &&
			!mirror.startsWith(QString("ftp://"))) || mirror.contains(QString(" ")))
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("Add Mirror"),
				tr("Mirror Format is incorrect. Your mirror should look like this:\nhttp://mirror.org/$repo/os/i686"), QMessageBox::Ok);
		message->exec();
		return;
	}

	/* Ok, our mirror should be valid. Let's add it to mirrorlist. */
	QString toInsert("Server=");
	toInsert.append(mirror);

	QFile file("/etc/pacman.d/mirrorlist");
	file.open(QIODevice::Append | QIODevice::Text);

	file.write(toInsert.toAscii().data(), toInsert.length());
	file.write("\n", 1);

	file.close();
	
	mirrorBox->addItem(mirror);

	QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("Add Mirror"),
			tr("Your Mirror was successfully added!\nIt is now available in mirrorlist."), QMessageBox::Ok);
	message->exec();
	
	addMirrorLine->clear();
}

bool ConfigDialog::doDbUpdate()
{
	return upDb;
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

