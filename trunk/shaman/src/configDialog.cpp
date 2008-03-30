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
#include "ShamanDialog.h"

#include <QLineEdit>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QProcess>
#include <QDebug>

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
	setupAdvanced();
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
		if (list.count() >= 1)
		{
			QString serverN(list.at(1));
		
			serverN.remove(QChar(' '), Qt::CaseInsensitive);
		
			retlist.append(serverN);
		}
	}
	
	file.close();
	
	return retlist;

}

void ConfigDialog::setupGeneral()
{
	listWidget->insertItem(0, new QListWidgetItem(QIcon(":/Icons/icons/shaman/shaman-22.png"), tr("General")));//FIXME: Replace icon

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

	keepQueueTrayBox->setChecked(settings->value("gui/processintray").toBool());

	if(settings->value("gui/startupmode").toString() == "tray")
		startTrayBox->setChecked(true);
	else
		startTrayBox->setChecked(false);

	if(settings->value("gui/showsplashscreen", true).toBool())
		splashScreenBox->setChecked(true);

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
			KDEMod3TestBox->setChecked(true);
		else if(!strcmp(alpm_db_get_name(curdb), "kdemod-unstable"))
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

	if (tmplst.count() >= 1)
	{
		QString dserv(tmplst.at(0));

		dserv.append("$repo");
		dserv.append(tmplst.at(1));

		if(mirrorBox->findText(dserv) != -1)
			mirrorBox->setCurrentIndex(mirrorBox->findText(dserv));
	}

	connect(addMirrorButton, SIGNAL(clicked()), SLOT(addMirror()));
	connect(addThirdPartyButton, SIGNAL(clicked()), SLOT(openAddDialog()));
	connect(editThirdPartyButton, SIGNAL(clicked()), SLOT(openEditDialog()));
	connect(removeThirdPartyButton, SIGNAL(clicked()), SLOT(removeThirdParty()));
}


void ConfigDialog::setupPacman()
{
	listWidget->addItem(new QListWidgetItem(QIcon(":/Icons/icons/shaman/animation_source/anim06.png"), tr("Pacman")));//FIXME: Replace icon

	/* Let's read alpm configuration! */
	if(alpm_option_get_nopassiveftp())
		noPassiveFtpBox->setChecked(true);

	if(alpm_option_get_usesyslog())
		sysLogBox->setChecked(true);

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
	logFileLine->setText((char *)alpm_option_get_logfile());
	tmpStr = "";

}

void ConfigDialog::setupABS()
{
	QListWidgetItem *item = new QListWidgetItem(QIcon(":/Icons/icons/document-open-remote.png"), tr("ABS"), listWidget);
	item->setTextAlignment(Qt::AlignHCenter);
	item->setSizeHint(QSize(90, 50));
	listWidget->insertItem(3, item);


	/* Read options related to our Config file first */

	QSettings *settings = new QSettings();

	makeDepsSourceBox->setChecked(settings->value("absbuilding/wizardbuild").toBool());
	reviewBuildOutBox->setChecked(settings->value("absbuilding/reviewoutput").toBool());
	buildPathEdit->setText(settings->value("absbuilding/buildpath").toString());
	cleanMakeDepsBox->setChecked(settings->value("absbuilding/clearmakedepends").toBool());
	cleanBuildEnvBox->setChecked(settings->value("absbuilding/cleanbuildenv").toBool());

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

void ConfigDialog::setupAdvanced()
{
	QListWidgetItem *item = new QListWidgetItem(QIcon(":/Icons/icons/preferences-other.png"), tr("Advanced"), listWidget);
	item->setTextAlignment(Qt::AlignHCenter);
	item->setSizeHint(QSize(90, 50));
	listWidget->insertItem(4, item);
	
	QSettings *settings = new QSettings();

	if(settings->value("scheduledUpdate/enabled").toBool())
		updateDbTrayBox->setChecked(true);
	else
	{
		minutesSpin->setEnabled(false);
		upNotifyRadio->setEnabled(false);
		upNotifyAddRadio->setEnabled(false);
	}

	if (settings->value("scheduledUpdate/updateDbShowNotify").toBool())
		updateDbShowNotify->setChecked(true);

	connect(updateDbTrayBox, SIGNAL(toggled(bool)), SLOT(obfuscateDBUpdate(bool)));

	minutesSpin->setValue(settings->value("scheduledUpdate/interval", 10).toInt());

	if (settings->value("proxy/enabled").toBool())
		proxyGroup->setChecked(true);

	if (settings->value("proxy/httpProxy").toBool())
		httpProxyBox->setChecked(true);
	else
		httpProxyBox->setChecked(false);

	if (settings->value("proxy/ftpProxy").toBool())
		ftpProxyBox->setChecked(true);
	else
		ftpProxyBox->setChecked(false);

	proxyServer->setText(settings->value("proxy/proxyServer").toString());
	proxyPort->setText(settings->value("proxy/proxyPort").toString());

	if(settings->value("scheduledUpdate/addupgradestoqueue").toBool())
		upNotifyAddRadio->setChecked(true);
	else
		upNotifyRadio->setChecked(true);
	
	if(settings->value("newsreader/userss", true).toBool())
		useRSSBox->setChecked(true);
	
	if(settings->value("newsreader/doupdate").toBool())
		updateRSSBox->setChecked(true);
	else
	{
		updateRSSBox->setChecked(false);
		updateRSSSpin->setEnabled(false);
	}

	connect(updateRSSBox, SIGNAL(toggled(bool)), SLOT(obfuscateRSSUpdate(bool)));
	
	updateRSSSpin->setValue(settings->value("newsreader/updateinterval", 60).toInt());
	
	if(settings->value("newsreader/notifynew").toBool())
		notifyRSSBox->setChecked(true);
	else
		notifyRSSBox->setChecked(false);
	
	if(settings->value("newsreader/queuenotifier", true).toBool())
		notifyQueueRSSBox->setChecked(true);
	else
		notifyQueueRSSBox->setChecked(false);

	noRootBox->setChecked(settings->value("gui/noroot").toBool());
		
	autoStartBox->setChecked(settings->value("gui/autostart").toBool());
	
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
	QPushButton *okb = new QPushButton(addDialog);
	QPushButton *cancb = new QPushButton(addDialog);
	QVBoxLayout *layout = new QVBoxLayout();
	QHBoxLayout *hlay = new QHBoxLayout();

	okb->setText(tr("Ok"));
	okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
	cancb->setText(tr("Cancel"));
	cancb->setIcon(QIcon(":/Icons/icons/dialog-cancel.png"));

	connect(okb, SIGNAL(clicked()), addDialog, SLOT(accept()));
	connect(cancb, SIGNAL(clicked()), addDialog, SLOT(reject()));
	
	hlay->insertStretch(0);
	hlay->addWidget(cancb);
	hlay->addWidget(okb);

	layout->addWidget(nameLabel);
	layout->addWidget(name);
	layout->addWidget(serverLabel);
	layout->addWidget(server);
	layout->addLayout(hlay);

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
	QPushButton *okb = new QPushButton(addDialog);
	QPushButton *cancb = new QPushButton(addDialog);
	QVBoxLayout *layout = new QVBoxLayout();
	QHBoxLayout *hlay = new QHBoxLayout();

	okb->setText(tr("Ok"));
	okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
	cancb->setText(tr("Cancel"));
	cancb->setIcon(QIcon(":/Icons/icons/dialog-cancel.png"));

	connect(okb, SIGNAL(clicked()), addDialog, SLOT(accept()));
	connect(cancb, SIGNAL(clicked()), addDialog, SLOT(reject()));

	hlay->insertStretch(0);
	hlay->addWidget(cancb);
	hlay->addWidget(okb);

	layout->addWidget(nameLabel);
	layout->addWidget(name);
	layout->addWidget(serverLabel);
	layout->addWidget(server);
	layout->addLayout(hlay);

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

	mantDetails->append(QString());

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
		mantProc = new RootProcess();

		connect(mantProc, SIGNAL(readyReadStandardError()), SLOT(mantProgress()));
		connect(mantProc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(cleanProc(int,QProcess::ExitStatus)));

		statusLabel->setText(QString(tr("Optimizing Pacman Database...")));
		mantDetails->append(QString(tr("Optimizing Pacman Database...")));
		
		qDebug() << "Starting the process";
		
		seteuid(0);		
		mantProc->start("pacman-optimize");
		seteuid(getuid());
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
		alpm_logaction(QString(tr("Unused Databases Cleaned up successfully!") + QChar('\n')).toUtf8().data());
		break;

	case 1:
		statusLabel->setText(QString(tr("Cache Cleaned Up Successfully!")));
		mantDetails->append(QString(tr("Cache Cleaned Up Successfully!")));
		alpm_logaction(QString(tr("Cache Cleaned Up Successfully!") + QChar('\n')).toUtf8().data());
		break;

	case 2:
		statusLabel->setText(QString(tr("Cache Successfully Deleted!")));
		mantDetails->append(QString(tr("Cache Successfully Deleted!")));
		alpm_logaction(QString(tr("Cache Successfully Deleted!") + QChar('\n')).toUtf8().data());
		break;

	case 3:
		statusLabel->setText(QString(tr("Build Environments Successfully Cleaned!")));
		mantDetails->append(QString(tr("Build Environments Successfully Cleaned!")));
		alpm_logaction(QString(tr("Build Environments Successfully Cleaned!") + QChar('\n')).toUtf8().data());
		break;
	}

	mantProcessButton->setEnabled(true);
}

void ConfigDialog::saveConfiguration()
{
	qDebug() << "Saving Configuration...";
	
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
		if(!strcmp(alpm_pkg_get_arch(m_handler->getPackageFromName("pacman", "local")), "i686"))
			mirror = "http://kdemod.ath.cx/repo/current/i686";
		else
			mirror = "http://kdemod.ath.cx/repo/current/x86_64";

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

	if(KDEMod3TestBox->isChecked())
	{
		if(!strcmp(alpm_pkg_get_arch(m_handler->getPackageFromName("pacman", "local")), "i686"))
			mirror = "http://kdemod.ath.cx/repo/testing/i686";
		else
			mirror = "http://kdemod.ath.cx/repo/testing/x86_64";

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

	if(KDEMod4Box->isChecked())
	{
		if(!strcmp(alpm_pkg_get_arch(m_handler->getPackageFromName("pacman", "local")), "i686"))
			mirror = "http://kdemod.ath.cx/repo/unstable/i686";
		else
			mirror = "http://kdemod.ath.cx/repo/unstable/x86_64";

		if(!editPacmanKey("kdemod-unstable/Server", mirror, 0))
		{
			if(editPacmanKey("kdemod-unstable/Server", mirror, 1))
				dbChanged = true;
		}
		else
			dbChanged = true;
	}
	else
		if(editPacmanKey("kdemod-unstable/Server", NULL, 2))
			dbChanged = true;

	/* Whew, now with the third party elements. We also take the
	 * chance to free them, for the sake of memory.
	 * But first, let's check if we need to remove something.
	 */

	foreach(QString dbs, m_handler->getAvailableReposNames())
	{
		if(dbs != "core" && dbs != "extra" && dbs != "community" && dbs != "testing"
			&& dbs != "unstable" && dbs != "kdemod" && dbs != "kdemod-unstable" && dbs != "kdemod-testing" &&
			thirdPartyWidget->findItems(dbs, Qt::MatchExactly, 0).isEmpty())
			if(editPacmanKey(QString(dbs + "/Server"), NULL, 2))
				dbChanged = true;
	}

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

	if(sysLogBox->isChecked())
		editPacmanKey("options/UseSyslog", "", 0);
	else
		editPacmanKey("options/UseSyslog", NULL, 2);

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

	if(logFileLine->isModified())
	{
		if(logFileLine->text().isEmpty())
			editPacmanKey("options/LogFile", QString(), 2);
		else
			if(!editPacmanKey("options/LogFile", logFileLine->text(), 0))
				editPacmanKey("options/LogFile", logFileLine->text(), 1);
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

	settings->setValue("gui/processintray", keepQueueTrayBox->isChecked());
	if(startTrayBox->isChecked())
		settings->setValue("gui/startupmode", "tray");
	else
		settings->setValue("gui/startupmode", "window");

	settings->setValue("gui/showsplashscreen", splashScreenBox->isChecked());
	settings->setValue("scheduledUpdate/enabled", updateDbTrayBox->isChecked());
	settings->setValue("scheduledUpdate/interval", minutesSpin->value());
	settings->setValue("scheduledUpdate/updateDbShowNotify", updateDbShowNotify->isChecked());
	settings->setValue("proxy/enabled", proxyGroup->isChecked());
	settings->setValue("proxy/proxyServer", proxyServer->text());
	settings->setValue("proxy/proxyPort", proxyPort->text());
	settings->setValue("proxy/httpProxy", httpProxyBox->isChecked());
	settings->setValue("proxy/ftpProxy", ftpProxyBox->isChecked());
	settings->setValue("scheduledUpdate/addupgradestoqueue", upNotifyAddRadio->isChecked());
	settings->setValue("absbuilding/wizardbuild", makeDepsSourceBox->isChecked());
	settings->setValue("absbuilding/reviewoutput", reviewBuildOutBox->isChecked());
	settings->setValue("newsreader/userss", useRSSBox->isChecked());
	settings->setValue("newsreader/doupdate", updateRSSBox->isChecked());
	settings->setValue("newsreader/updateinterval", updateRSSSpin->value());
	settings->setValue("newsreader/notifynew", notifyRSSBox->isChecked());
	settings->setValue("newsreader/queuenotifier", notifyQueueRSSBox->isChecked());
	settings->setValue("gui/noroot", noRootBox->isChecked());
	settings->setValue("gui/autostart", autoStartBox->isChecked());

	if(autoStartBox->isChecked())
	{
		seteuid(0);
		if(QFile::exists("../etc/shaman.desktop"))
			QFile::copy("../etc/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
		else if(QFile::exists("../../etc/shaman.desktop"))
			QFile::copy("../../etc/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
		else if(QFile::exists("etc/shaman.desktop"))
			QFile::copy("etc/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
		else if(QFile::exists("../share/applications/shaman.desktop"))
			QFile::copy("../share/applications/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
		else if(QFile::exists("/usr/share/applications/shaman.desktop"))
			QFile::copy("/usr/share/applications/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
		seteuid(getuid());
	}
	else
	{
		seteuid(0);
		
		QFile::remove("/etc/xdg/autostart/shaman.desktop");
		
		seteuid(getuid());
	}


	/* Additional checks here. Since this thing could be rm -rf'ed,
	 * better being sure that is set properly. */
	if(buildPathEdit->text() != "/" && !buildPathEdit->text().isEmpty() && buildPathEdit->text().startsWith(QChar('/')))
		settings->setValue("absbuilding/buildpath", buildPathEdit->text());
	else
		settings->setValue("absbuilding/buildpath", "/var/shaman/builds");

	settings->setValue("absbuilding/clearmakedepends", cleanMakeDepsBox->isChecked());

	settings->setValue("absbuilding/cleanbuildenv", cleanBuildEnvBox->isChecked());


	settings->setValue("absbuilding/syncsupfiles", useMatchSupRadio->isChecked());
	
	settings->deleteLater();
	
	if(useMatchSupRadio->isChecked())
	{
		/* We need to generate a SUPFILES containing our current repos
		 * then.
		 */

		QString supfiles;

		supfiles.append(coreBox->isChecked() ? "core" : "!core");
		supfiles.append(" ");

		supfiles.append(extraBox->isChecked() ? "extra" : "!extra");
		supfiles.append(" ");

		supfiles.append(communityBox->isChecked() ? "community" : "!community");
		supfiles.append(" ");

		supfiles.append(testingBox->isChecked() ? "testing" : "!testing");
		supfiles.append(" ");

		supfiles.append(unstableBox->isChecked() ? "unstable" : "!unstable");

		editABSSection("supfiles", supfiles);
	}
	else
	{
		/* Ok, we just have to put the supfiles into abs.conf
		 */

		if(supEdit->isModified())
			editABSSection("supfiles", supEdit->text());
	}

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

	emit setProxy();

	if(dbChanged)
	{
		switch (ShamanDialog::popupQuestionDialog(QString(tr("Settings Changed")), 
				QString(tr("Your repositories have changed.\nDo you want to Update Your Database?")), this)) 
		{
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
		ShamanDialog::popupDialog(tr("Add Mirror"), tr("Mirror Format is incorrect. "
				"Your mirror should look like this:\nhttp://mirror.org/$repo/os/i686",
						"Obviously keep the example as it is ;)"), this);
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

	ShamanDialog::popupDialog(tr("Add Mirror"),
			tr("Your Mirror was successfully added!\nIt is now available in mirrorlist.",
					"mirrorlist here means /etc/pacman.d/mirrorlist, so it should not "
					"be translated."), this);
	
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
	QString str(mantProc->readLine(1024));
	mantDetails->append(QString("<b><i>" + str + "</b></i>"));
	qDebug() << str;
}

void ConfigDialog::cleanProc(int eC, QProcess::ExitStatus eS)
{
	Q_UNUSED(eS);

	if(eC == 0)
	{
		statusLabel->setText(QString(tr("Pacman Database Optimized Successfully!")));
		mantDetails->append(QString(tr("Pacman Database Optimized Successfully!")));
		alpm_logaction(QString(tr("Pacman Database Optimized Successfully!") + QChar('\n')).toUtf8().data());
	}
	else
	{
		statusLabel->setText(QString(tr("Could not Optimize Pacman Database!")));
		mantDetails->append(QString(tr("Could not Optimize Pacman Database!")));
		alpm_logaction(QString(tr("Could not Optimize Pacman Database!") + QChar('\n')).toUtf8().data());
	}

	mantProc->deleteLater();

	statusLabel->setText(QString(tr("Running sync...", "sync is a command, so it should not be translated")));
	mantDetails->append(QString(tr("Running sync...", "sync is a command, so it should not be translated")));

	mantProc = new RootProcess();
	
	seteuid(0);
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
	seteuid(getuid());

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

void ConfigDialog::obfuscateRSSUpdate(bool state)
{
	if(state)
		updateRSSSpin->setEnabled(true);
	else
		updateRSSSpin->setEnabled(false);
}
