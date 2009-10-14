/***************************************************************************
 *   Copyright (C) 2009 by Dario Freddi                                    *
 *   drf@chakra-project.org                                                *
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

#include "ShamanGeneralConfig.h"

#include <aqpm/Maintenance.h>
#include <aqpm/Backend.h>

#include <ActionButton>

#include <QSettings>
#include <QDir>

#include "ShamanIcon.h"

#include "ui_shamanGeneral.h"

using namespace Aqpm;

#ifdef KDE4_INTEGRATION
#include <KPluginFactory>
#include <KAboutData>
#include <klocalizedstring.h>
#include <KMessageBox>

K_PLUGIN_FACTORY(ShamanGeneralConfigFactory,
                 registerPlugin<ShamanGeneralConfig>();
                )
K_EXPORT_PLUGIN(ShamanGeneralConfigFactory("kcmshamangeneralconfig"))

#endif

ShamanGeneralConfig::ShamanGeneralConfig(QWidget *parent, const QVariantList &args)
#ifndef KDE4_INTEGRATION
        : QWidget(parent)
#else
        : KCModule(ShamanGeneralConfigFactory::componentData(), parent, args)
#endif
        , m_ui(new Ui::ShamanGeneralConfig)
{
    // Initialize the backend correctly
    Backend::instance()->safeInitialization();
    Backend::instance()->setShouldHandleAuthorization(true);

#ifdef KDE4_INTEGRATION
    QLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);

    setButtons(Apply);

    KAboutData *about =
        new KAboutData("kcmshamangeneralconfig", "shamangeneralconfig", ki18n("Shaman Configuration"),
                       "bla", ki18n("Configures Shaman"),
                       KAboutData::License_GPL, ki18n("(c), 2009 Dario Freddi"));

    about->addAuthor(ki18n("Dario Freddi"), ki18n("Maintainer") , "drf@chakra-project.org",
                     "http://drfav.wordpress.com");

    setAboutData(about);

    QWidget *widget = new QWidget(this);
    m_ui->setupUi(widget);
    layout->addWidget(widget);

    init();
#else
    m_ui->setupUi(this);

    load();
#endif
}


void ShamanGeneralConfig::init()
{
    m_ui->mantActionBox->addItems(QStringList() << QString(tr("Clean Unused Databases")) << QString(tr("Clean Cache")) <<
                            QString(tr("Empty Cache")) << QString(tr("Optimize Pacman Database")) <<
                            QString(tr("Clean All Building Environments")));

    PolkitQt::ActionButton *but = new PolkitQt::ActionButton(m_ui->mantProcessButton, "org.chakraproject.aqpm.performmaintenance",
                                                             this);
    connect(but, SIGNAL(clicked(QAbstractButton*)), but, SLOT(activate()));
    connect(but, SIGNAL(activated()), this, SLOT(performManteinanceAction()));
    but->setText(tr("Process Selected"));
    but->setIcon(ShamanIcon::getIconFromName("dialog-ok-apply"));

    connect(Maintenance::instance(), SIGNAL(actionPerformed(bool)), this, SLOT(maintenancePerformed(bool)));
    connect(Maintenance::instance(), SIGNAL(actionOutput(QString)), this, SLOT(mantProgress(QString)));

    connect(m_ui->addUpRadio, SIGNAL(toggled(bool)), this, SLOT(changed()));
    connect(m_ui->upNowRadio, SIGNAL(toggled(bool)), this, SLOT(changed()));
    connect(m_ui->askUpRadio, SIGNAL(toggled(bool)), this, SLOT(changed()));
    connect(m_ui->disableTray, SIGNAL(stateChanged(int)), this, SLOT(changed()));
    connect(m_ui->keepQueueTrayBox, SIGNAL(stateChanged(int)), this, SLOT(changed()));
    connect(m_ui->startTrayBox, SIGNAL(stateChanged(int)), this, SLOT(changed()));
    connect(m_ui->splashScreenBox, SIGNAL(stateChanged(int)), this, SLOT(changed()));
    connect(m_ui->languageCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(changed()));
}


void ShamanGeneralConfig::defaults()
{
}

void ShamanGeneralConfig::load()
{
#ifndef KDE4_INTEGRATION
    QSettings *settings = new QSettings("shaman", "shaman");
#else
    QSettings *settings = new QSettings("kde.org", "shaman");
#endif

    if (settings->value("gui/actionupgrade").toString() == "add") {
        m_ui->addUpRadio->setChecked(true);
    } else if (settings->value("gui/actionupgrade").toString() == "upgrade") {
        m_ui->upNowRadio->setChecked(true);
    } else {
        m_ui->askUpRadio->setChecked(true);
    }

    m_ui->disableTray->setChecked(settings->value("gui/disabletray", false).toBool());
    m_ui->keepQueueTrayBox->setChecked(settings->value("gui/processintray").toBool());

    if (settings->value("gui/startupmode").toString() == "tray") {
        m_ui->startTrayBox->setChecked(true);
    } else {
        m_ui->startTrayBox->setChecked(false);
    }

    m_ui->splashScreenBox->setChecked(settings->value("gui/showsplashscreen", true).toBool());

    QString filePath = INSTALL_PREFIX;
    filePath.append("/share/shaman/translations/");

    QDir dir(filePath);
    QStringList locales;

    foreach(const QString &ent, dir.entryList(QDir::Files | QDir::NoSymLinks)) {
        if (!ent.contains('_') || !ent.contains('.')) {
            continue;
        }

        locales.append(ent.split('_').at(1).split('.').at(0));
    }

    m_ui->languageCombo->addItems(locales);

    if (settings->value("gui/language").toString().isEmpty()) {
        QString locale = QLocale::system().name();

        foreach(const QString &ent, locales) {
            if (locale.contains(ent)) {
                m_ui->languageCombo->setCurrentIndex(m_ui->languageCombo->findText(ent));
            }
        }
    } else {
        m_ui->languageCombo->setCurrentIndex(m_ui->languageCombo->findText(settings->value("gui/language").toString()));
    }

    settings->deleteLater();
}

void ShamanGeneralConfig::save()
{
#ifndef KDE4_INTEGRATION
    QSettings *settings = new QSettings("shaman", "shaman");
#else
    QSettings *settings = new QSettings("kde.org", "shaman");
#endif

    if (m_ui->addUpRadio->isChecked()) {
        settings->setValue("gui/actionupgrade", "add");
    } else if (m_ui->upNowRadio->isChecked()) {
        settings->setValue("gui/actionupgrade", "upgrade");
    } else {
        settings->setValue("gui/actionupgrade", "ask");
    }

    settings->setValue("gui/disabletray", m_ui->disableTray->isChecked());
    settings->setValue("gui/processintray", m_ui->keepQueueTrayBox->isChecked());

    if (m_ui->startTrayBox->isChecked()) {
        settings->setValue("gui/startupmode", "tray");
    } else {
        settings->setValue("gui/startupmode", "window");
    }

    settings->setValue("gui/language", m_ui->languageCombo->currentText());

    settings->setValue("gui/showsplashscreen", m_ui->splashScreenBox->isChecked());

    settings->deleteLater();
}

void ShamanGeneralConfig::performManteinanceAction()
{
    m_ui->mantProcessButton->setEnabled(false);

    m_ui->mantDetails->append(QString());

    if (!m_ui->mantActionBox->currentText().compare(QString(tr("Clean Unused Databases")))) {
        m_currentMaint = 0;

        m_ui->statusLabel->setText(QString(tr("Cleaning up unused Databases...")));
        m_ui->mantDetails->append(QString(tr("Cleaning up unused Databases...")));

        Maintenance::instance()->performAction(Maintenance::CleanUnusedDatabases);
    } else if (!m_ui->mantActionBox->currentText().compare(QString(tr("Clean Cache")))) {
        m_currentMaint = 1;

        m_ui->statusLabel->setText(QString(tr("Cleaning up Cache...")));
        m_ui->mantDetails->append(QString(tr("Cleaning up Cache...")));

        Maintenance::instance()->performAction(Maintenance::CleanCache);
    } else if (!m_ui->mantActionBox->currentText().compare(QString(tr("Empty Cache")))) {
        m_currentMaint = 2;

        m_ui->statusLabel->setText(QString(tr("Deleting Cache...")));
        m_ui->mantDetails->append(QString(tr("Deleting Cache...")));

        Maintenance::instance()->performAction(Maintenance::EmptyCache);
    } else if (!m_ui->mantActionBox->currentText().compare(QString(tr("Optimize Pacman Database")))) {
        m_currentMaint = 4;

        m_ui->statusLabel->setText( QString( tr( "Optimizing Pacman Database..." ) ) );
        m_ui->mantDetails->append( QString( tr( "Optimizing Pacman Database..." ) ) );

        Maintenance::instance()->performAction(Maintenance::OptimizeDatabases);
    } else if (!m_ui->mantActionBox->currentText().compare(QString(tr("Clean All Building Environments")))) {
        m_currentMaint = 3;

        m_ui->statusLabel->setText(QString(tr("Cleaning up building Environments...")));
        m_ui->mantDetails->append(QString(tr("Cleaning up building Environments...")));

        Maintenance::instance()->performAction(Maintenance::CleanABS);
    }

    m_ui->mantDetails->moveCursor(QTextCursor::End);
}

void ShamanGeneralConfig::maintenancePerformed(bool success)
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

    m_ui->statusLabel->setText(result);
    m_ui->mantDetails->append(result);

    m_ui->mantDetails->moveCursor(QTextCursor::End);

    m_ui->mantProcessButton->setEnabled(true);
}

void ShamanGeneralConfig::mantProgress(const QString &progress)
{
    m_ui->mantDetails->append(QString("<b><i>" + progress + "</i></b>"));
    m_ui->mantDetails->moveCursor( QTextCursor::End );
}
