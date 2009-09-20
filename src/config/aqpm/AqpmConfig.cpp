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

#include "AqpmConfig.h"

#include <aqpm/Backend.h>
#include <aqpm/Configuration.h>

#include <QDebug>

#include "ShamanDialog.h"

#include "ui_aqpmConfig.h"

using namespace Aqpm;

#ifdef KDE4_INTEGRATION
#include <KPluginFactory>
#include <KAboutData>
#include <klocalizedstring.h>
#include <KMessageBox>

K_PLUGIN_FACTORY(AqpmConfigFactory,
                 registerPlugin<AqpmConfig>();
                )
K_EXPORT_PLUGIN(AqpmConfigFactory("kcmaqpmconfig"))

#endif

AqpmConfig::AqpmConfig(QWidget *parent, const QVariantList &args)
#ifndef KDE4_INTEGRATION
        : QWidget(parent)
#else
        : KCModule(parent, args)
#endif
        , m_ui(new Ui::AqpmConfig)
{
#ifdef KDE4_INTEGRATION
    QLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);

    setButtons(Apply | Help);

    KAboutData *about =
        new KAboutData("kcmaqpmconfig", "aqpmdatabaseconfig", ki18n("Aqpm Configuration"),
                       "bla", ki18n("Configures Aqpm global options"),
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


void AqpmConfig::load()
{
    QString txt;

    foreach(const QString &str, Aqpm::Configuration::instance()->value("options/IgnorePkg").toStringList()) {
        txt.append(str);
        txt.append(QChar(' '));
    }
    if (txt.size()) {
        txt.remove(txt.size() - 1, 1);
    }
    m_ui->ignorePkgLine->setText(txt);
    txt.clear();

    foreach(const QString &str, Aqpm::Configuration::instance()->value("options/IgnoreGroup").toStringList()) {
        txt.append(str);
        txt.append(QChar(' '));
    }
    if (txt.size()) {
        txt.remove(txt.size() - 1, 1);
    }
    m_ui->ignoreGrpsLine->setText(txt);
    txt.clear();

    foreach(const QString &str, Aqpm::Configuration::instance()->value("options/NoExtract").toStringList()) {
        txt.append(str);
        txt.append(QChar(' '));
    }
    if (txt.size()) {
        txt.remove(txt.size() - 1, 1);
    }
    m_ui->noExtractLine->setText(txt);
    txt.clear();

    foreach(const QString &str, Aqpm::Configuration::instance()->value("options/NoUpgrade").toStringList()) {
        txt.append(str);
        txt.append(QChar(' '));
    }
    if (txt.size()) {
        txt.remove(txt.size() - 1, 1);
    }
    m_ui->noUpgradeLine->setText(txt);
    txt.clear();

    m_ui->logFileLine->setText(Aqpm::Configuration::instance()->value("options/LogFile").toString());
    m_ui->useDeltaBox->setChecked(Aqpm::Configuration::instance()->value("options/UseDelta").toBool());
    m_ui->sysLogBox->setChecked(Aqpm::Configuration::instance()->value("options/UseSyslog").toBool());
    m_ui->multiServerBox->setChecked(Aqpm::Configuration::instance()->value("options/MultiDownload").toBool());
}


void AqpmConfig::save()
{
    Configuration::instance()->setValue("options/IgnorePkg", m_ui->ignorePkgLine->text().split(QChar(' ')));
    Configuration::instance()->setValue("options/IgnoreGroup", m_ui->ignoreGrpsLine->text().split(QChar(' ')));
    Configuration::instance()->setValue("options/NoExtract", m_ui->noExtractLine->text().split(QChar(' ')));
    Configuration::instance()->setValue("options/NoUpgrade", m_ui->noUpgradeLine->text().split(QChar(' ')));

    Configuration::instance()->setValue("options/LogFile", m_ui->logFileLine->text());
    Configuration::instance()->setValue("options/UseDelta", m_ui->useDeltaBox->isChecked());
    Configuration::instance()->setValue("options/UseSyslog", m_ui->sysLogBox->isChecked());
    Configuration::instance()->setValue("options/MultiDownload", m_ui->multiServerBox->isChecked());

    if (!Configuration::instance()->saveConfiguration()) {
        qDebug() << "argh";
        ShamanDialog::popupDialog(tr("Error"), tr("There has been a problem while saving the configuration!"), this,
                                  ShamanProperties::ErrorDialog);
    }
}


void AqpmConfig::defaults()
{

}

#include "AqpmConfig.moc"
