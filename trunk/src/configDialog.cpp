/***************************************************************************
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de               									   *
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

#include "configDialog.h"

#include "AlpmHandler.h"
#include "ABSHandler.h"

#include <QLineEdit>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QProcess>

ConfigDialog::ConfigDialog(AlpmHandler *handler, QWidget *parent)
: QDialog(parent),
m_handler(handler),
upDb(false)
{
	setupUi(this);
	setupGeneral();
	setupPacman();
	setupRepos();
	setupABS();
	connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(changeWidget(int)));
	connect(this, SIGNAL(accepted()), SLOT(saveConfiguration()));
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
	
	mantActionBox->addItems(QStringList() << QString(tr("Clean Unused Databases")) << QString(tr("Clean Cache")) << 
			QString(tr("Empty Cache")) << QString(tr("Optimize Pacman Database")) << QString(tr("Clean All Building Environments")));
	
	connect(mantProcessButton, SIGNAL(clicked()), SLOT(performManteinanceAction()));
	
	/* Load values from our settings file, so easy this time. */
	
	QSettings *settings = new QSettings();
	
	if(settings->value("gui/actionupgrade").toString() == "add")
		addUpRadio->setChecked(true);
	else if(settings->value("gui/actionupgrade").toString() == "upgrade")
		upNowRadio->setChecked(true);
	else
		askUpRadio->setChecked(true);
	
	if(settings->value("gui/processintray").toBool())
		keepQueueTrayBox->setChecked(true);
	
	if(settings->value("gui/startupmode").toString() == "tray")
		startTrayBox->setChecked(true);
	
	if(settings->value("scheduledUpdate/enabled").toBool())
		updateDbTrayBox->setChecked(true);
	else
	{
		minutesSpin->setEnabled(false);
		upNotifyRadio->setEnabled(false);
		upNotifyAddRadio->setEnabled(false);
	}
	
	connect(updateDbTrayBox, SIGNAL(toggled(bool)), SLOT(obfuscateDBUpdate(bool)));
	
	minutesSpin->setValue(settings->value("scheduledUpdate/interval", 10).toInt());
	
	if(settings->value("scheduledUpdate/addupgradestoqueue").toBool())
		upNotifyAddRadio->setChecked(true);
	else
		upNotifyRadio->setChecked(true);
	
	settings->deleteLater();
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

	connect(addMirrorButton, SIGNAL(clicked()), SLOT(addMirror()));
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

void ConfigDialog::setupABS()
{
	listWidget->insertItem(3, new QListWidgetItem(QIcon(":/Icons/icons/network-server-database.png"), tr("ABS")));//FIXME: Replace icon
	
	/* Read options related to our Config file first */
	
	QSettings *settings = new QSettings();
	
	if(settings->value("absbuilding/wizardbuild").toBool())
		makeDepsSourceBox->setChecked(true);
	
	if(settings->value("absbuilding/reviewoutput").toBool())
		reviewBuildOutBox->setChecked(true);
	
	buildPathEdit->setText(settings->value("absbuilding/buildpath").toString());
	
	if(settings->value("absbuilding/clearmakedepends").toBool())
		cleanMakeDepsBox->setChecked(true);

	if(settings->value("absbuilding/cleanbuildenv").toBool())
		cleanBuildEnvBox->setChecked(true);
	
	if(settings->value("absbuilding/syncsupfiles").toBool())
	{
		useMatchSupRadio->setChecked(true);
		supEdit->setEnabled(false);
	}
	else
		useCustomSupRadio->setChecked(true);
	
	connect(useCustomSupRadio, SIGNAL(toggled(bool)), SLOT(obfuscateSupfiles(bool)));
	
	ABSConf abD = getABSConf();
	supEdit->setText(abD.supfiles);
	
	MakePkgConf mkpD = getMakepkgConf();
	
	CFlagEdit->setText(mkpD.cflags);
	CXXFlagEdit->setText(mkpD.cxxflags);
	buildEnvEdit->setText(mkpD.buildenv);
	optionsMkPkgEdit->setText(mkpD.options);
	docDirsEdit->setText(mkpD.docdirs);
	
	settings->deleteLater();
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

void ConfigDialog::performManteinanceAction()
{
	mantProcessButton->setEnabled(false);
	
	if(!mantActionBox->currentText().compare(QString(tr("Clean Unused Databases"))))
	{
		cTh = new CleanThread(m_handler, 0);

		statusLabel->setText(QString(tr("Cleaning up unused Databases...")));
		mantDetails->append(QString(tr("Cleaning up unused Databases...")));

		connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
		connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
		connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
		cTh->start();
	}
	else if(!mantActionBox->currentText().compare(QString(tr("Clean Cache"))))
	{
		cTh = new CleanThread(m_handler, 1);

		statusLabel->setText(QString(tr("Cleaning up Cache...")));
		mantDetails->append(QString(tr("Cleaning up Cache...")));

		connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
		connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
		connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
		cTh->start();
	}
	else if(!mantActionBox->currentText().compare(QString(tr("Empty Cache"))))
	{
		cTh = new CleanThread(m_handler, 2);

		statusLabel->setText(QString(tr("Deleting Cache...")));
		mantDetails->append(QString(tr("Deleting Cache...")));

		connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
		connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
		connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
		cTh->start();
	}
	else if(!mantActionBox->currentText().compare(QString(tr("Optimize Pacman Database"))))
	{
		mantProc = new QProcess();

		connect(mantProc, SIGNAL(readyReadStandardError()), SLOT(mantProgress()));
		connect(mantProc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(cleanProc(int,QProcess::ExitStatus)));

		statusLabel->setText(QString(tr("Optimizing Pacman Database...")));
		mantDetails->append(QString(tr("Optimizing Pacman Database...")));
		
		mantProc->start("pacman-optimize");
	}
	else if(!mantActionBox->currentText().compare(QString(tr("Clean All Building Environments"))))
	{
		cTh = new CleanThread(m_handler, 3);

		statusLabel->setText(QString(tr("Cleaning up building Environments...")));
		mantDetails->append(QString(tr("Cleaning up building Environments...")));

		connect(cTh, SIGNAL(success(int)), SLOT(showSuccess(int)));
		connect(cTh, SIGNAL(failure(int)), SLOT(showFailure(int)));
		connect(cTh, SIGNAL(finished()), SLOT(cleanThread()));
		cTh->start();
	}
}

void ConfigDialog::showFailure(int act)
{
	switch(act)
	{
	case 0:
		statusLabel->setText(QString(tr("Cleaning up Unused Databases Failed!")));
		mantDetails->append(QString(tr("Cleaning up Unused Databases Failed!")));
		break;

	case 1:
		statusLabel->setText(QString(tr("Cleaning up Cache Failed!")));
		mantDetails->append(QString(tr("Cleaning up Cache Failed!")));
		break;

	case 2:
		statusLabel->setText(QString(tr("Deleting Cache Failed!")));
		mantDetails->append(QString(tr("Deleting Cache Failed!")));
		break;
		
	case 3:
		statusLabel->setText(QString(tr("Could not clean Build Environments!!")));
		mantDetails->append(QString(tr("Could not clean Build Environments!!")));
		break;
	}

	mantProcessButton->setEnabled(true);
}

void ConfigDialog::showSuccess(int act)
{
	switch(act)
	{
	case 0:
		statusLabel->setText(QString(tr("Unused Databases Cleaned up successfully!")));
		mantDetails->append(QString(tr("Unused Databases Cleaned up successfully!")));
		break;

	case 1:
		statusLabel->setText(QString(tr("Cache Cleaned Up Successfully!")));
		mantDetails->append(QString(tr("Cache Cleaned Up Successfully!")));
		break;

	case 2:
		statusLabel->setText(QString(tr("Cache Successfully Deleted!")));
		mantDetails->append(QString(tr("Cache Successfully Deleted!")));
		break;
		
	case 3:
		statusLabel->setText(QString(tr("Build Environments Successfully Cleaned!")));
		mantDetails->append(QString(tr("Build Environments Successfully Cleaned!!")));
		break;
	}

	mantProcessButton->setEnabled(true);
}

void ConfigDialog::saveConfiguration()
{
	bool dbChanged = false;
	QString mirror(mirrorBox->currentText());
	mirror = mirror.remove(' ');

	if(coreBox->isChecked())
	{
		if(!editPacmanKey("core/Server", mirror, 0))
		{
			if(editPacmanKey("core/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			editPacmanKey("core/Include", NULL, 2);
		}
	}
	else
	{
		if(editPacmanKey("core/Server", NULL, 2))
			dbChanged = true;
		if(editPacmanKey("core/Include", NULL, 2))
			dbChanged = true;
	}

	if(extraBox->isChecked())
	{
		if(!editPacmanKey("extra/Server", mirror, 0))
		{
			if(editPacmanKey("extra/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			editPacmanKey("extra/Include", NULL, 2);
		}
	}
	else
	{
		if(editPacmanKey("extra/Server", NULL, 2))
			dbChanged = true;
		if(editPacmanKey("extra/Include", NULL, 2))
			dbChanged = true;
	}

	if(communityBox->isChecked())
	{
		if(!editPacmanKey("community/Server", mirror, 0))
		{
			if(editPacmanKey("community/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			editPacmanKey("community/Include", NULL, 2);
		}
	}
	else
	{
		if(editPacmanKey("community/Server", NULL, 2))
			dbChanged = true;
		if(editPacmanKey("community/Include", NULL, 2))
			dbChanged = true;
	}

	if(testingBox->isChecked())
	{
		if(!editPacmanKey("testing/Server", mirror, 0))
		{
			if(editPacmanKey("testing/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			editPacmanKey("testing/Include", NULL, 2);
		}
	}
	else
	{
		if(editPacmanKey("testing/Server", NULL, 2))
			dbChanged = true;
		if(editPacmanKey("testing/Include", NULL, 2))
			dbChanged = true;
	}

	if(unstableBox->isChecked())
	{
		if(!editPacmanKey("unstable/Server", mirror, 0))
		{
			if(editPacmanKey("unstable/Server", mirror, 1))
				dbChanged = true;
		}
		else
		{
			dbChanged = true;
			editPacmanKey("unstable/Include", NULL, 2);
		}
	}
	else
	{
		if(editPacmanKey("unstable/Server", NULL, 2))
			dbChanged = true;
		if(editPacmanKey("unstable/Include", NULL, 2))
			dbChanged = true;
	}

	if(KDEMod3Box->isChecked())
	{
		mirror = "http://kdemod.ath.cx/repo/current/i686";
		if(!editPacmanKey("kdemod/Server", mirror, 0))
		{
			if(editPacmanKey("kdemod/Server", mirror, 1))
				dbChanged = true;
		}
		else
			dbChanged = true;
	}
	else
		if(editPacmanKey("kdemod/Server", NULL, 2))
			dbChanged = true;

	if(KDEMod4Box->isChecked())
	{
		mirror = "http://kdemod.ath.cx/repo/testing/i686";
		if(!editPacmanKey("kdemod-testing/Server", mirror, 0))
		{
			if(editPacmanKey("kdemod-testing/Server", mirror, 1))
				dbChanged = true;
		}
		else
			dbChanged = true;
	}
	else
		if(editPacmanKey("kdemod-testing/Server", NULL, 2))
			dbChanged = true;

	/* Whew, now with the third party elements. We also take the
	 * chance to free them, for the sake of memory.
	 */

	QTreeWidgetItem *itm;

	while((itm = thirdPartyWidget->takeTopLevelItem(0)) != NULL)
	{
		QString tName(itm->text(0));

		tName.append("/Server");

		if(!editPacmanKey(tName, itm->text(1), 0))
		{
			if(editPacmanKey(tName, itm->text(1), 1))
				dbChanged = true;
		}
		else
			dbChanged = true;

		delete(itm);
	}
	
	/* Well done, let's start committing changes to pacman's options */
	if(noPassiveFtpBox->isChecked())
		editPacmanKey("options/NoPassiveFtp", "", 0);
	else
		editPacmanKey("options/NoPassiveFtp", NULL, 2);

	if(holdPkgLine->isModified())
	{
		if(holdPkgLine->text().isEmpty())
			editPacmanKey("options/HoldPkg", NULL, 2);
		else
			if(!editPacmanKey("options/HoldPkg", holdPkgLine->text(), 0))
				editPacmanKey("options/HoldPkg", holdPkgLine->text(), 1);
	}

	if(ignorePkgLine->isModified())
	{
		if(ignorePkgLine->text().isEmpty())
			editPacmanKey("options/IgnorePkg", NULL, 2);
		else
			if(!editPacmanKey("options/IgnorePkg", ignorePkgLine->text(), 0))
				editPacmanKey("options/IgnorePkg", ignorePkgLine->text(), 1);
	}

	if(ignoreGrpsLine->isModified())
	{
		if(ignoreGrpsLine->text().isEmpty())
			editPacmanKey("options/IgnoreGroup", NULL, 2);
		else
			if(!editPacmanKey("options/IgnoreGroup", ignoreGrpsLine->text(), 0))
				editPacmanKey("options/IgnoreGroup", ignoreGrpsLine->text(), 1);
	}

	if(noUpgradeLine->isModified())
	{
		if(noUpgradeLine->text().isEmpty())
			editPacmanKey("options/NoUpgrade", NULL, 2);
		else
			if(!editPacmanKey("options/NoUpgrade", noUpgradeLine->text(), 0))
				editPacmanKey("options/NoUpgrade", noUpgradeLine->text(), 1);
	}

	if(noExtractLine->isModified())
	{
		if(noExtractLine->text().isEmpty())
			editPacmanKey("options/NoExtract", NULL, 2);
		else
			if(!editPacmanKey("options/NoExtract", noExtractLine->text(), 0))
				editPacmanKey("options/NoExtract", noExtractLine->text(), 1);
	}

	if(xFerCommandLine->isModified())
	{
		if(xFerCommandLine->text().isEmpty())
			editPacmanKey("options/XferCommand", QString(), 2);
		else
			if(!editPacmanKey("options/XferCommand", xFerCommandLine->text(), 0))
				editPacmanKey("options/XferCommand", xFerCommandLine->text(), 1);
	}


	/* Ok, saving finished, commit changes to Alpm now */
	m_handler->reloadPacmanConfiguration();
	
	/* Now, off to the Preferences in the settings file */

	QSettings *settings = new QSettings();

	if(addUpRadio->isChecked())
		settings->setValue("gui/actionupgrade", "add");
	else if(upNowRadio->isChecked())
		settings->setValue("gui/actionupgrade", "upgrade");
	else
		settings->setValue("gui/actionupgrade", "ask");

	if(keepQueueTrayBox->isChecked())
		settings->setValue("gui/processintray", true);
	else
		settings->setValue("gui/processintray", false);

	if(startTrayBox->isChecked())
		settings->setValue("gui/startupmode", "tray");
	else
		settings->setValue("gui/startupmode", "window");

	if(updateDbTrayBox->isChecked())
		settings->setValue("scheduledUpdate/enabled", true);
	else
		settings->setValue("scheduledUpdate/enabled", false);

	settings->setValue("scheduledUpdate/interval", minutesSpin->value());

	if(upNotifyAddRadio->isChecked())
		settings->setValue("scheduledUpdate/addupgradestoqueue", true);
	else
		settings->setValue("scheduledUpdate/addupgradestoqueue", false);

	if(makeDepsSourceBox->isChecked())
		settings->setValue("absbuilding/wizardbuild", true);
	else
		settings->setValue("absbuilding/wizardbuild", false);

	if(reviewBuildOutBox->isChecked())
		settings->setValue("absbuilding/reviewoutput", true);
	else
		settings->setValue("absbuilding/reviewoutput", false);

	/* Additional checks here. Since this thing could be rm -rf'ed,
	 * better being sure that is set properly. */
	if(buildPathEdit->text() != "/" && !buildPathEdit->text().isEmpty() && buildPathEdit->text().startsWith(QChar('/')))
		settings->setValue("absbuilding/buildpath", buildPathEdit->text());
	else
		settings->setValue("absbuilding/buildpath", "/var/shaman/builds");

	if(cleanMakeDepsBox->isChecked())
		settings->setValue("absbuilding/clearmakedepends", true);
	else
		settings->setValue("absbuilding/clearmakedepends", false);

	if(cleanBuildEnvBox->isChecked())
		settings->setValue("absbuilding/cleanbuildenv", true);
	else
		settings->setValue("absbuilding/cleanbuildenv", false);

	if(useMatchSupRadio->isChecked())
	{
		settings->setValue("absbuilding/syncsupfiles", true);

		/* We need to generate a SUPFILES containing our current repos 
		 * then.
		 */

		QString supfiles;

		if(coreBox->isChecked())
			supfiles.append("core");
		else
			supfiles.append("!core");
		
		supfiles.append(" ");

		if(extraBox->isChecked())
			supfiles.append("extra");
		else
			supfiles.append("!extra");
		
		supfiles.append(" ");

		if(communityBox->isChecked())
			supfiles.append("community");
		else
			supfiles.append("!community");
		
		supfiles.append(" ");

		if(testingBox->isChecked())
			supfiles.append("testing");
		else
			supfiles.append("!testing");
		
		supfiles.append(" ");

		if(unstableBox->isChecked())
			supfiles.append("unstable");
		else
			supfiles.append("!unstable");
		
		editABSSection("supfiles", supfiles);
	}
	else
	{
		settings->setValue("absbuilding/syncsupfiles", false);

		/* Ok, we just have to put the supfiles into abs.conf
		 */

		if(supEdit->isModified())
			editABSSection("supfiles", supEdit->text());
	}

	settings->deleteLater();

	/* Last, but not least, commit changes to makepkg.conf */

	if(CFlagEdit->isModified())
		editMakepkgSection("cflags", CFlagEdit->text());

	if(CXXFlagEdit->isModified())
		editMakepkgSection("cxxflags", CXXFlagEdit->text());

	if(buildEnvEdit->isModified())
		editMakepkgSection("buildenv", buildEnvEdit->text());

	if(optionsMkPkgEdit->isModified())
		editMakepkgSection("options", optionsMkPkgEdit->text());

	if(docDirsEdit->isModified())
		editMakepkgSection("docdirs", docDirsEdit->text());
	

	/* Did we change anything in the repos? Better update our
	 * local DB then.
	 */

	if(dbChanged)
	{
		QMessageBox *msgBox = new QMessageBox(this);

		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowTitle(QString(tr("Settings Changed")));

		msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

		msgBox->setWindowModality(Qt::ApplicationModal);

		msgBox->setText(QString(tr("Your repositories have changed.\nDo you want to Update Your Database?")));

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
			!mirror.startsWith(QString("ftp://"))) || mirror.contains(QString(" ")) || !QUrl(mirror).isValid())
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Information, tr("Add Mirror"),
				tr("Mirror Format is incorrect. Your mirror should look like this:\nhttp://mirror.org/$repo/os/i686",
						"Obviously keep the example as it is ;)"), QMessageBox::Ok);
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
			tr("Your Mirror was successfully added!\nIt is now available in mirrorlist.",
					"mirrorlist here means /etc/pacman.d/mirrorlist, so it should not "
					"be translated."), QMessageBox::Ok);
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

void ConfigDialog::mantProgress()
{
	mantProc->setReadChannel(QProcess::StandardError);
	mantDetails->append(mantProc->readLine(1024));
}

void ConfigDialog::cleanProc(int eC, QProcess::ExitStatus eS)
{
	if(eC == 0)
	{
		statusLabel->setText(QString(tr("Pacman Database Optimized Successfully!")));
		mantDetails->append(QString(tr("Pacman Database Optimized Successfully!")));
	}
	else
	{
		statusLabel->setText(QString(tr("Could not Optimize Pacman Database!")));
		mantDetails->append(QString(tr("Could not Optimize Pacman Database!")));
	}
	
	mantProc->deleteLater();

	statusLabel->setText(QString(tr("Running sync...", "sync is a command, so it should not be translated")));
	mantDetails->append(QString(tr("Running sync...", "sync is a command, so it should not be translated")));
	
	mantProc = new QProcess();
	
	if(mantProc->execute("sync") == 0)
	{
		statusLabel->setText(QString(tr("Operation Completed Successfully!")));
		mantDetails->append(QString(tr("Sync was successfully executed!!", "Sync is always the command")));
		mantDetails->append(QString(tr("Operation Completed Successfully!")));
	}
	else
	{
		statusLabel->setText(QString(tr("Sync could not be executed!", "Sync is always the command")));
		mantDetails->append(QString(tr("Sync could not be executed!!", "Sync is always the command")));
	}
	
	mantProc->deleteLater();
	
	mantProcessButton->setEnabled(true);
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
		
	case 3:
		ABSHandler absH;
		
		if(absH.cleanAllBuildingEnvironments())
			emit success(action);
		else
			emit failure(action);
		break;

	}
}

void ConfigDialog::obfuscateDBUpdate(bool state)
{
	if(state)
	{
		minutesSpin->setEnabled(true);
		upNotifyRadio->setEnabled(true);
		upNotifyAddRadio->setEnabled(true);
	}
	else
	{
		minutesSpin->setEnabled(false);
		upNotifyRadio->setEnabled(false);
		upNotifyAddRadio->setEnabled(false);
	}
}

void ConfigDialog::obfuscateSupfiles(bool state)
{
	if(state)
		supEdit->setEnabled(true);
	else
		supEdit->setEnabled(false);
}
