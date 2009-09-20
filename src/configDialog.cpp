/***************************************************************************
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                           *
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

#include "ABSHandler.h"
#include "ShamanDialog.h"

#include <aqpm/Backend.h>
#include <aqpm/Configuration.h>
#include <aqpm/ConfigurationParser.h>
#include <aqpm/Maintenance.h>

#include <config-shaman1.h>

#include <QLineEdit>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QUrl>
#include <QProcess>
#include <QDebug>
#include <QTime>

#include <ActionButton>

using namespace Aqpm;

ConfigDialog::ConfigDialog(QWidget *parent)
        : QDialog(parent),
        upDb(false)
{
    setupUi(this);
    setupGeneral();
    setupPacman();
    setupRepos();
    setupABS();
    setupAdvanced();
    connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(changeWidget(int)));
    connect(Maintenance::instance(), SIGNAL(actionPerformed(bool)), this, SLOT(maintenancePerformed(bool)));
    connect(Maintenance::instance(), SIGNAL(actionOutput(QString)), this, SLOT(mantProgress(QString)));
    connect(this, SIGNAL(accepted()), SLOT(saveConfiguration()));
    setModal(true);
    PolkitQt::ActionButton *but = new PolkitQt::ActionButton(okButton, "org.chakraproject.aqpm.saveconfiguration", this);
    connect(but, SIGNAL(clicked(QAbstractButton*)), but, SLOT(activate()));
    connect(but, SIGNAL(activated()), this, SLOT(accept()));
    but->setText(QObject::tr("O&k"));
    but->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
    cancelButton->setText(QObject::tr("C&ancel"));
}

ConfigDialog::~ConfigDialog()
{
}

void ConfigDialog::setupGeneral()
{
    listWidget->insertItem(0, new QListWidgetItem(QIcon(":/Icons/icons/shaman/hi32-app-shaman.png"), tr("General")));

    mantActionBox->addItems(QStringList() << QString(tr("Clean Unused Databases")) << QString(tr("Clean Cache")) <<
                            QString(tr("Empty Cache")) << QString(tr("Optimize Pacman Database")) <<
                            QString(tr("Clean All Building Environments")));

    PolkitQt::ActionButton *but = new PolkitQt::ActionButton(mantProcessButton, "org.chakraproject.aqpm.performmaintenance",
                                                             this);
    connect(but, SIGNAL(clicked(QAbstractButton*)), but, SLOT(activate()));
    connect(but, SIGNAL(activated()), this, SLOT(performManteinanceAction()));
    but->setText(tr("Process Selected"));
    but->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));

    /* Load values from our settings file, so easy this time. */

    QSettings *settings = new QSettings();

    if (settings->value("gui/actionupgrade").toString() == "add")
        addUpRadio->setChecked(true);
    else if (settings->value("gui/actionupgrade").toString() == "upgrade")
        upNowRadio->setChecked(true);
    else
        askUpRadio->setChecked(true);

    disableTray->setChecked(settings->value("gui/disabletray", false).toBool());
    keepQueueTrayBox->setChecked(settings->value("gui/processintray").toBool());

    if (settings->value("gui/startupmode").toString() == "tray")
        startTrayBox->setChecked(true);
    else
        startTrayBox->setChecked(false);

    if (settings->value("gui/showsplashscreen", true).toBool())
        splashScreenBox->setChecked(true);

    QString filePath = INSTALL_PREFIX;
    filePath.append("/share/shaman/translations/");

    QDir dir(filePath);
    QStringList locales;

    foreach(const QString &ent, dir.entryList(QDir::Files | QDir::NoSymLinks)) {
        if (!ent.contains('_') || !ent.contains('.'))
            continue;

        locales.append(ent.split('_').at(1).split('.').at(0));
    }

    languageCombo->addItems(locales);

    if (settings->value("gui/language").toString().isEmpty()) {
        QString locale = QLocale::system().name();

        foreach(const QString &ent, locales) {
            if (locale.contains(ent)) {
                languageCombo->setCurrentIndex(languageCombo->findText(ent));
            }
        }
    } else {
        languageCombo->setCurrentIndex(languageCombo->findText(settings->value("gui/language").toString()));
    }

    settings->deleteLater();
}

void ConfigDialog::setupRepos()
{
    listWidget->addItem(new QListWidgetItem(QIcon(":/Icons/icons/network-server-database.png"), tr("Repositories")));

}


void ConfigDialog::setupPacman()
{
    listWidget->addItem(new QListWidgetItem(QIcon(":/Icons/icons/shaman/animation_source/anim06.png"), tr("Pacman")));        //FIXME: Replace icon

    /* Let's read alpm configuration! */
    if (alpm_option_get_nopassiveftp())
        noPassiveFtpBox->setChecked(true);

    if (alpm_option_get_usesyslog())
        sysLogBox->setChecked(true);

    useDeltaBox->setHidden(true);

    alpm_list_t *tmp;
    QString tmpStr;

    /*tmp = alpm_option_get_holdpkgs();
    while ( tmp != NULL ) {
        tmpStr.append(( char * )alpm_list_getdata( tmp ) );
        tmpStr.append( " " );
        tmp = alpm_list_next( tmp );
    }
    holdPkgLine->setText( tmpStr );
    tmpStr = "";*/

    tmp = alpm_option_get_ignorepkgs();
    while (tmp != NULL) {
        tmpStr.append((char *)alpm_list_getdata(tmp));
        tmpStr.append(" ");
        tmp = alpm_list_next(tmp);
    }
    ignorePkgLine->setText(tmpStr);
    tmpStr = "";

    tmp = alpm_option_get_ignoregrps();
    while (tmp != NULL) {
        tmpStr.append((char *)alpm_list_getdata(tmp));
        tmpStr.append(" ");
        tmp = alpm_list_next(tmp);
    }
    ignoreGrpsLine->setText(tmpStr);
    tmpStr = "";

    tmp = alpm_option_get_noupgrades();
    while (tmp != NULL) {
        tmpStr.append((char *)alpm_list_getdata(tmp));
        tmpStr.append(" ");
        tmp = alpm_list_next(tmp);
    }
    noUpgradeLine->setText(tmpStr);
    tmpStr = "";

    tmp = alpm_option_get_noextracts();
    while (tmp != NULL) {
        tmpStr.append((char *)alpm_list_getdata(tmp));
        tmpStr.append(" ");
        tmp = alpm_list_next(tmp);
    }
    noExtractLine->setText(tmpStr);
    tmpStr = "";

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

    if (settings->value("absbuilding/syncsupfiles").toBool()) {
        useMatchSupRadio->setChecked(true);
        supEdit->setEnabled(false);
    } else
        useCustomSupRadio->setChecked(true);

    connect(useCustomSupRadio, SIGNAL(toggled(bool)), SLOT(obfuscateSupfiles(bool)));

    ABSConf abD = ConfigurationParser::instance()->getABSConf();

    supEdit->setText(abD.supfiles);
    rsyncServerEdit->setText(abD.rsyncsrv);

    MakePkgConf mkpD = ConfigurationParser::instance()->getMakepkgConf();

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

    if (settings->value("scheduledUpdate/enabled").toBool()) {
        updateDbTrayBox->setChecked(true);
        obfuscateDBUpdate(true);
    } else
        obfuscateDBUpdate(false);

    if (settings->value("scheduledUpdate/enabledat").toBool()) {
        updateDbTrayAtBox->setChecked(true);
        obfuscateDBUpdateAt(true);
    } else
        obfuscateDBUpdateAt(false);

    if (settings->value("scheduledUpdate/updateDbShowNotify").toBool())
        updateDbShowNotify->setChecked(true);

    connect(updateDbTrayBox, SIGNAL(toggled(bool)), SLOT(obfuscateDBUpdate(bool)));
    connect(updateDbTrayAtBox, SIGNAL(toggled(bool)), SLOT(obfuscateDBUpdateAt(bool)));

    minutesSpin->setValue(settings->value("scheduledUpdate/interval", 10).toInt());
    schedTimeEdit->setTime(settings->value("scheduledUpdate/updatetime", QTime(0, 0)).toTime());

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

    if (settings->value("scheduledUpdate/addupgradestoqueue").toBool())
        upNotifyAddRadio->setChecked(true);
    else
        upNotifyRadio->setChecked(true);

    if (settings->value("newsreader/userss", true).toBool())
        useRSSBox->setChecked(true);

    if (settings->value("newsreader/doupdate").toBool())
        updateRSSBox->setChecked(true);
    else {
        updateRSSBox->setChecked(false);
        updateRSSSpin->setEnabled(false);
    }

    connect(updateRSSBox, SIGNAL(toggled(bool)), SLOT(obfuscateRSSUpdate(bool)));

    updateRSSSpin->setValue(settings->value("newsreader/updateinterval", 60).toInt());

    if (settings->value("newsreader/notifynew").toBool())
        notifyRSSBox->setChecked(true);
    else
        notifyRSSBox->setChecked(false);

    if (settings->value("newsreader/queuenotifier", true).toBool())
        notifyQueueRSSBox->setChecked(true);
    else
        notifyQueueRSSBox->setChecked(false);

    noRootBox->setChecked(settings->value("gui/noroot").toBool());

    autoStartBox->setChecked(settings->value("gui/autostart").toBool());

    useAnimatedBox->setChecked(settings->value("trayicon/useanimatedicon", true).toBool());

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
    if (addDialog->result() == 1) {   //QDialog::accepted
        QTreeWidgetItem *itm = new QTreeWidgetItem(thirdPartyWidget);
        itm->setText(0, name->text());
        itm->setText(1, server->text());
    }

    addDialog->deleteLater();
}

void ConfigDialog::openEditDialog()
{
    if (!thirdPartyWidget->currentItem())
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
    if (addDialog->result() == 1) {   //QDialog::accepted
        thirdPartyWidget->currentItem()->setText(0, name->text());
        thirdPartyWidget->currentItem()->setText(1, server->text());
    }

    addDialog->deleteLater();
}

void ConfigDialog::removeThirdParty()
{
    if (!thirdPartyWidget->currentItem())
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

    if (!mantActionBox->currentText().compare(QString(tr("Clean Unused Databases")))) {
        m_currentMaint = 0;

        statusLabel->setText(QString(tr("Cleaning up unused Databases...")));
        mantDetails->append(QString(tr("Cleaning up unused Databases...")));

        Maintenance::instance()->performAction(Maintenance::CleanUnusedDatabases);
    } else if (!mantActionBox->currentText().compare(QString(tr("Clean Cache")))) {
        m_currentMaint = 1;

        statusLabel->setText(QString(tr("Cleaning up Cache...")));
        mantDetails->append(QString(tr("Cleaning up Cache...")));

        Maintenance::instance()->performAction(Maintenance::CleanCache);
    } else if (!mantActionBox->currentText().compare(QString(tr("Empty Cache")))) {
        m_currentMaint = 2;

        statusLabel->setText(QString(tr("Deleting Cache...")));
        mantDetails->append(QString(tr("Deleting Cache...")));

        Maintenance::instance()->performAction(Maintenance::EmptyCache);
    } else if (!mantActionBox->currentText().compare(QString(tr("Optimize Pacman Database")))) {
        m_currentMaint = 4;
        
        statusLabel->setText( QString( tr( "Optimizing Pacman Database..." ) ) );
        mantDetails->append( QString( tr( "Optimizing Pacman Database..." ) ) );

        Maintenance::instance()->performAction(Maintenance::OptimizeDatabases);
    } else if (!mantActionBox->currentText().compare(QString(tr("Clean All Building Environments")))) {
        m_currentMaint = 3;

        statusLabel->setText(QString(tr("Cleaning up building Environments...")));
        mantDetails->append(QString(tr("Cleaning up building Environments...")));

        Maintenance::instance()->performAction(Maintenance::CleanABS);
    }

    mantDetails->moveCursor(QTextCursor::End);
}

void ConfigDialog::maintenancePerformed(bool success)
{
    QString result;

    switch (m_currentMaint) {
    case 0:
        if (success) {
            result = tr("Unused Databases Cleaned up successfully!");
        } else {
            result = tr("Cleaning up Unused Databases Failed!");
        }
        break;
    case 1:
        if (success) {
            result = tr("Cache Cleaned Up Successfully!");
        } else {
            result = tr("Cleaning up Cache Failed!");
        }
        break;

    case 2:
        if (success) {
            result = tr("Cache Successfully Deleted!");
        } else {
            result = tr("Deleting Cache Failed!");
        }
        break;

    case 3:
        if (success) {
            result = tr("Build Environments Successfully Cleaned!");
        } else {
            result = tr("Could not clean Build Environments!!");
        }
        break;

    case 4:
        if (success) {
            result = tr("Database optimized successfully!");
        } else {
            result = tr("Could not optimize database!");
        }
        break;
    }

    statusLabel->setText(result);
    mantDetails->append(result);

    mantDetails->moveCursor(QTextCursor::End);

    mantProcessButton->setEnabled(true);
}

void ConfigDialog::saveConfiguration()
{
    qDebug() << "Saving Configuration...";

    bool dbChanged = false, restartNeeded = false;
    QString mirror(mirrorBox->currentText());
    QString kdemodmirror(KDEModMirrorBox->currentText());
    mirror = mirror.remove(' ');
    kdemodmirror = kdemodmirror.remove(' ');

    QProcess proc;
    proc.start("arch");
    proc.waitForFinished(20000);

    QString arch = QString(proc.readAllStandardOutput()).remove('\n').remove(' ');

    kdemodmirror.replace("$arch", arch);

    saveSettings();

    emit setProxy();

    QHash<QCheckBox*, QString> repos;

    repos.insert(coreBox, "core");
    repos.insert(extraBox, "extra");
    repos.insert(testingBox, "testing");
    repos.insert(communityBox, "community");

    foreach(QCheckBox *c, repos.keys()) {
        if (c->isChecked()) {
            if (!Configuration::instance()->exists(QString("%1/Server").arg(repos[c]), mirror)) {
                Configuration::instance()->setValue(QString("%1/Server").arg(repos[c]), mirror);
                dbChanged = true;
            }
        } else {
            if (Configuration::instance()->exists(QString("%1/Server").arg(repos[c]))) {
                Configuration::instance()->remove(repos[c]);
                dbChanged = true;
            }
        }
    }

    repos.clear();

    repos.insert(KDEMod4Box, "kdemod-core");
    repos.insert(KDEMod4ExtragearBox, "kdemod-extragear");
    repos.insert(KDEMod4PlaygroundBox, "kdemod-playground");
    repos.insert(KDEMod4TestingBox, "kdemod-testing");
    repos.insert(KDEMod4UnstableBox, "kdemod-unstable");
    repos.insert(KDEMod3Box, "kdemod-legacy");

    foreach(QCheckBox *c, repos.keys()) {
        if (c->isChecked()) {
            if (!Configuration::instance()->exists(QString("%1/Server").arg(repos[c]), kdemodmirror)) {
                Configuration::instance()->setValue(QString("%1/Server").arg(repos[c]), kdemodmirror);
                dbChanged = true;
            }
        } else {
            if (Configuration::instance()->exists(QString("%1/Server").arg(repos[c]))) {
                Configuration::instance()->remove(repos[c]);
                dbChanged = true;
            }
        }
    }

    /* Whew, now with the third party elements. We also take the
     * chance to free them, for the sake of memory.
     * But first, let's check if we need to remove something.
     */

    foreach(const Database &dbs, Backend::instance()->getAvailableDatabases()) {
        if (dbs.name() != "core" && dbs.name() != "extra" && dbs.name() != "community" && dbs.name() != "testing"
                && dbs.name() != "kdemod-core" && dbs.name() != "kdemod-extragear" &&
                dbs.name() != "kdemod-playground" && dbs.name() != "kdemod-testing" &&
                dbs.name() != "kdemod-unstable" && dbs.name() != "kdemod-legacy" &&
                thirdPartyWidget->findItems(dbs.name(), Qt::MatchExactly, 0).isEmpty()) {
            Configuration::instance()->remove(dbs.name());
            dbChanged = true;
        }
    }

    QTreeWidgetItem *itm;

    while ((itm = thirdPartyWidget->takeTopLevelItem(0)) != NULL) {
        QString tName(itm->text(0));

        tName.append("/Server");

        if (!Configuration::instance()->exists(tName, itm->text(1))) {
            Configuration::instance()->setValue(tName, itm->text(1));
            dbChanged = true;
        }

        delete(itm);
    }

    /* Well done, let's start committing changes to pacman's options */
    Configuration::instance()->setOrUnset(noPassiveFtpBox->isChecked(), "options/NoPassiveFtp");
    Configuration::instance()->setOrUnset(sysLogBox->isChecked(), "options/UseSyslog");

    QHash<QLineEdit*, QString> opts;

    opts.insert(holdPkgLine, "HoldPkg");
    opts.insert(ignorePkgLine, "IgnorePkg");
    opts.insert(ignoreGrpsLine, "IgnoreGroup");
    opts.insert(noUpgradeLine, "NoUpgrade");
    opts.insert(noExtractLine, "NoExtract");
    opts.insert(logFileLine, "LogFile");

    foreach(QLineEdit *l, opts.keys()) {
        if (l->isModified()) {
            Configuration::instance()->setValue(QString("options/%1").arg(opts[l]), l->text());
        }
    }

    /* Ok, saving finished, commit changes to Alpm now */
    Backend::instance()->reloadPacmanConfiguration();

    /* Now, off to the Preferences in the settings file */

    if (autoStartBox->isChecked()) {
        if (QFile::exists("../etc/shaman.desktop"))
            QFile::copy("../etc/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
        else if (QFile::exists("../../etc/shaman.desktop"))
            QFile::copy("../../etc/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
        else if (QFile::exists("etc/shaman.desktop"))
            QFile::copy("etc/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
        else if (QFile::exists("../share/applications/shaman.desktop"))
            QFile::copy("../share/applications/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
        else if (QFile::exists("/usr/share/applications/shaman.desktop"))
            QFile::copy("/usr/share/applications/shaman.desktop", "/etc/xdg/autostart/shaman.desktop");
    } else {
        QFile::remove("/etc/xdg/autostart/shaman.desktop");
    }

    if (!Configuration::instance()->saveConfiguration()) {
        ShamanDialog::popupDialog(tr("Error saving configuration"),
                                  tr("There was an error while saving the configuration. "
                                     "This is probably due to an internal error or you being not "
                                     "authorized to perform the operation"), this, ShamanProperties::ErrorDialog);
    }

    /*if ( useMatchSupRadio->isChecked() ) {
        /* We need to generate a SUPFILES containing our current repos
         * then.
         */

    /*  QString supfiles;

      supfiles.append( coreBox->isChecked() ? "core" : "!core" );
      supfiles.append( " " );

      supfiles.append( extraBox->isChecked() ? "extra" : "!extra" );
      supfiles.append( " " );

      supfiles.append( communityBox->isChecked() ? "community" : "!community" );
      supfiles.append( " " );

      supfiles.append( testingBox->isChecked() ? "testing" : "!testing" );
      supfiles.append( " " );

      ConfigurationParser::instance()->editABSSection( "repos", supfiles );
    } else {
      /* Ok, we just have to put the supfiles into abs.conf
       */
    /*
            if ( supEdit->isModified() )
                ConfigurationParser::instance()->editABSSection( "repos", supEdit->text() );
        }

        if ( rsyncServerEdit->isModified() )
            ConfigurationParser::instance()->editABSSection( "rsync", rsyncServerEdit->text() );

        /* Last, but not least, commit changes to makepkg.conf */

    /*  if ( CFlagEdit->isModified() )
          ConfigurationParser::instance()->editMakepkgSection( "cflags", CFlagEdit->text() );

      if ( CXXFlagEdit->isModified() )
          ConfigurationParser::instance()->editMakepkgSection( "cxxflags", CXXFlagEdit->text() );

      if ( buildEnvEdit->isModified() )
          ConfigurationParser::instance()->editMakepkgSection( "buildenv", buildEnvEdit->text() );

      if ( optionsMkPkgEdit->isModified() )
          ConfigurationParser::instance()->editMakepkgSection( "options", optionsMkPkgEdit->text() );

      if ( docDirsEdit->isModified() )
          ConfigurationParser::instance()->editMakepkgSection( "docdirs", docDirsEdit->text() );
    */

    if (restartNeeded)
        ShamanDialog::popupDialogDontShow(tr("Saving Configuration"), tr("Some of your changes have not been applied,\n"
                                          "since alpm needs to be released.\nYou need to restart Shaman to make them effective."), "gui/configwarning", this,
                                          ShamanProperties::WarningDialog);

    /* Did we change anything in the repos? Better update our
     * local DB then.
     */

    if (dbChanged) {
        switch (ShamanDialog::popupQuestionDialog(QString(tr("Settings Changed")),
                QString(tr("Your repositories have changed.\nDo you want to Update Your Database?")), this)) {
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

void ConfigDialog::saveSettings()
{
    QSettings *settings = new QSettings();

    if (addUpRadio->isChecked())
        settings->setValue("gui/actionupgrade", "add");
    else if (upNowRadio->isChecked())
        settings->setValue("gui/actionupgrade", "upgrade");
    else
        settings->setValue("gui/actionupgrade", "ask");

    settings->setValue("gui/disabletray", disableTray->isChecked());
    settings->setValue("gui/processintray", keepQueueTrayBox->isChecked());
    if (startTrayBox->isChecked())
        settings->setValue("gui/startupmode", "tray");
    else
        settings->setValue("gui/startupmode", "window");

    settings->setValue("gui/language", languageCombo->currentText());

    settings->setValue("gui/showsplashscreen", splashScreenBox->isChecked());
    settings->setValue("scheduledUpdate/enabled", updateDbTrayBox->isChecked());
    settings->setValue("scheduledUpdate/enabledat", updateDbTrayAtBox->isChecked());
    settings->setValue("scheduledUpdate/interval", minutesSpin->value());
    settings->setValue("scheduledUpdate/updatetime", schedTimeEdit->time());
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
    settings->setValue("trayicon/useanimatedicon", useAnimatedBox->isChecked());

    /* Additional checks here. Since this thing could be rm -rf'ed,
     * better being sure that is set properly. */
    if (buildPathEdit->text() != "/" && !buildPathEdit->text().isEmpty() && buildPathEdit->text().startsWith(QChar('/')))
        settings->setValue("absbuilding/buildpath", buildPathEdit->text());
    else
        settings->setValue("absbuilding/buildpath", "/var/shaman/builds");

    settings->setValue("absbuilding/clearmakedepends", cleanMakeDepsBox->isChecked());

    settings->setValue("absbuilding/cleanbuildenv", cleanBuildEnvBox->isChecked());


    settings->setValue("absbuilding/syncsupfiles", useMatchSupRadio->isChecked());

    settings->deleteLater();
}

void ConfigDialog::addMirror()
{
    if (addMirrorLine->text().isEmpty()) {
        return;
    }

    QString mirror(addMirrorLine->text());

    if (!mirror.contains(QString("$repo")) || (!mirror.startsWith(QString("http://")) &&
            !mirror.startsWith(QString("ftp://")) && !mirror.startsWith(QString("file://"))) ||
            mirror.contains(QString(" ")) || !QUrl(mirror).isValid()) {
        ShamanDialog::popupDialog(tr("Add Mirror"), tr("Mirror Format is incorrect. "
                                  "Your mirror should look like this:\nhttp://mirror.org/$repo/os/i686",
                                  "Obviously keep the example as it is ;)"), this, ShamanProperties::ErrorDialog);
        return;
    }

    /* Ok, our mirror should be valid. Let's add it to mirrorlist. */
    if (Configuration::instance()->addMirror(mirror, Configuration::ArchMirror)) {
        mirrorBox->addItem(mirror);

        ShamanDialog::popupDialog(tr("Add Mirror"),
                                  tr("Your Mirror was successfully added!\nIt is now available in mirrorlist.",
                                     "mirrorlist here means /etc/pacman.d/mirrorlist, so it should not "
                                     "be translated."), this);

        addMirrorLine->clear();
    } else {
        ShamanDialog::popupDialog(tr("Add Mirror"),
                                  tr("There was an error while trying to add the mirror! This could be due also "
                                     "to your system policy preventing you from performing this action"),
                                  this, ShamanProperties::ErrorDialog);
    }
}

void ConfigDialog::addKDEModMirror()
{
    if (addKDEModMirrorLine->text().isEmpty()) {
        return;
    }

    QString mirror(addKDEModMirrorLine->text());

    if (!mirror.contains(QString("$repo")) || !mirror.contains(QString("$arch")) || (!mirror.startsWith(QString("http://")) &&
            !mirror.startsWith(QString("ftp://"))) || mirror.contains(QString(" ")) || !QUrl(mirror).isValid()) {
        ShamanDialog::popupDialog(tr("Add Mirror"), tr("Mirror Format is incorrect. "
                                  "Your mirror should look like this:\nhttp://mirror.org/$repo/$arch",
                                  "Obviously keep the example as it is ;)"), this, ShamanProperties::ErrorDialog);
        return;
    }

    /* Ok, our mirror should be valid. Let's add it to mirrorlist. */
    if (Configuration::instance()->addMirror(mirror, Configuration::KdemodMirror)) {
        KDEModMirrorBox->addItem(mirror);

        ShamanDialog::popupDialog(tr("Add Mirror"),
                                  tr("Your Mirror was successfully added!\nIt is now available in kdemodmirrorlist.",
                                     "mirrorlist here means /etc/pacman.d/kdemodmirrorlist, so it should not "
                                     "be translated."), this);

        addKDEModMirrorLine->clear();
    } else {
        ShamanDialog::popupDialog(tr("Add Mirror"),
                                  tr("There was an error while trying to add the mirror! This could be due also "
                                     "to your system policy preventing you from performing this action"),
                                  this, ShamanProperties::ErrorDialog);
    }
}

bool ConfigDialog::doDbUpdate()
{
    return upDb;
}

void ConfigDialog::mantProgress(const QString &progress)
{
    mantDetails->append(QString("<b><i>" + progress + "</b></i>"));
    mantDetails->moveCursor( QTextCursor::End );
}

void ConfigDialog::obfuscateDBUpdate(bool state)
{
    if (state) {
        minutesSpin->setEnabled(true);
        upNotifyRadio->setEnabled(true);
        upNotifyAddRadio->setEnabled(true);
    } else {
        minutesSpin->setEnabled(false);
        upNotifyRadio->setEnabled(false);
        upNotifyAddRadio->setEnabled(false);
    }
}

void ConfigDialog::obfuscateDBUpdateAt(bool state)
{
    if (state)
        schedTimeEdit->setEnabled(true);
    else
        schedTimeEdit->setEnabled(false);
}

void ConfigDialog::obfuscateSupfiles(bool state)
{
    if (state)
        supEdit->setEnabled(true);
    else
        supEdit->setEnabled(false);
}

void ConfigDialog::obfuscateRSSUpdate(bool state)
{
    if (state)
        updateRSSSpin->setEnabled(true);
    else
        updateRSSSpin->setEnabled(false);
}
