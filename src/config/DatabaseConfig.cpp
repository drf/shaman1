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

#include "DatabaseConfig.h"

#include <aqpm/Backend.h>
#include <aqpm/Configuration.h>

#include <QDebug>

#include "MirrorWidget.h"
#include "ThirdPartyWidget.h"

#include <ActionButton>

#include "ui_databaseConfig.h"

using namespace Aqpm;

#ifdef KDE4_INTEGRATION
#include <KPluginFactory>
#include <KAboutData>
#include <klocalizedstring.h>
#include <KMessageBox>

K_PLUGIN_FACTORY(DatabaseConfigFactory,
                 registerPlugin<DatabaseConfig>();
                )
K_EXPORT_PLUGIN(DatabaseConfigFactory("kcmaqpmdatabaseconfig"))

#endif

DatabaseConfig::DatabaseConfig(QWidget *parent, const QVariantList &args)
#ifndef KDE4_INTEGRATION
        : QWidget(parent)
#else
        : KCModule(parent, args)
#endif
        , m_ui(new Ui::DatabaseConfig)
{
#ifdef KDE4_INTEGRATION
    QLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);

    setButtons(Apply | Help);

    KAboutData *about =
        new KAboutData("kcmaqpmdatabaseconfig", "aqpmdatabaseconfig", ki18n("Aqpm Database Configuration"),
                       "bla", ki18n("A configurator for Aqpm databases"),
                       KAboutData::License_GPL, ki18n("(c), 2009 Dario Freddi"));

    about->addAuthor(ki18n("Dario Freddi"), ki18n("Maintainer") , "drf@chakra-project.org",
                     "http://drfav.wordpress.com");

    setAboutData(about);

    QWidget *widget = new QWidget(this);
    m_ui->setupUi(widget);
    layout->addWidget(widget);
#else
    m_ui->setupUi(this);
#endif

    init();
    load();
}

void DatabaseConfig::init()
{
    m_archLay = new QVBoxLayout();
    m_kdemodLay = new QVBoxLayout();
    m_thirdPartyLay = new QVBoxLayout();

    m_ui->archScrollArea->setLayout(m_archLay);
    m_ui->kdemodScrollArea->setLayout(m_kdemodLay);
    m_ui->thirdPartyScrollArea->setLayout(m_thirdPartyLay);

    PolkitQt::ActionButton *but = new PolkitQt::ActionButton(m_ui->addMirrorButton, "org.chakraproject.aqpm.addmirror", this);
    connect(but, SIGNAL(clicked(QAbstractButton*)), but, SLOT(activate()));
    connect(but, SIGNAL(activated()), this, SLOT(addMirror()));
    but->setText(tr("Add Mirror"));
    but->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));

    but = new PolkitQt::ActionButton(m_ui->addKDEModMirrorButton, "org.chakraproject.aqpm.addmirror", this);
    connect(but, SIGNAL(clicked(QAbstractButton*)), but, SLOT(activate()));
    connect(but, SIGNAL(activated()), this, SLOT(addKDEModMirror()));
    but->setText(tr("Add Mirror"));
    but->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
}

void DatabaseConfig::load()
{
    Database::List repos = Backend::instance()->getAvailableDatabases();

    foreach (const Database &db, repos) {
        if (db.name() == "core") {
            m_ui->coreBox->setChecked(true);
        } else if (db.name() == "extra")
            m_ui->extraBox->setChecked(true);
        else if (db.name() == "community")
            m_ui->communityBox->setChecked(true);
        else if (db.name() == "testing")
            m_ui->testingBox->setChecked(true);
        else if (db.name() == "kdemod-core") {
            m_ui->KDEMod4Box->setChecked(true);
        } else if (db.name() == "kdemod-extragear") {
            m_ui->KDEMod4ExtragearBox->setChecked(true);
        } else if (db.name() == "kdemod-playground") {
            m_ui->KDEMod4PlaygroundBox->setChecked(true);
        } else if (db.name() == "kdemod-testing") {
            m_ui->KDEMod4TestingBox->setChecked(true);
        } else if (db.name() == "kdemod-unstable") {
            m_ui->KDEMod4UnstableBox->setChecked(true);
        } else if (db.name() == "kdemod-legacy") {
            m_ui->KDEMod3Box->setChecked(true);
        }
    }

    qDebug() << "one";
    qDebug() << Configuration::instance()->serversForMirror("arch");

    // Now the servers
    foreach (QString string, Configuration::instance()->serversForMirror("arch")) {
        MirrorWidget *wg = new MirrorWidget(Configuration::ArchMirror);
        wg->setMirror(string);
        connect (wg, SIGNAL(remove()), this, SLOT(removeWidget()));
        qDebug() << "wg";

        m_archMirrors.append(wg);
        m_ui->archScrollArea->layout()->addWidget(wg);
        qDebug() << "app";
    }
    m_archLay->addStretch();

    qDebug() << "one";
    qDebug() << Configuration::instance()->serversForMirror("kdemod");

    foreach (QString string, Configuration::instance()->serversForMirror("kdemod")) {
        MirrorWidget *wg = new MirrorWidget(Configuration::KdemodMirror);
        wg->setMirror(string);
        connect (wg, SIGNAL(remove()), this, SLOT(removeWidget()));
        qDebug() << "wg";

        m_kdemodMirrors.append(wg);
        m_ui->kdemodScrollArea->layout()->addWidget(wg);
        qDebug() << "app";
    }
    m_kdemodLay->addStretch();

    qDebug() << "one";

    // Now third parties
    foreach (QString string, Configuration::instance()->mirrors(true)) {
        ThirdPartyWidget *tp = new ThirdPartyWidget();
        tp->setMirrorName(string);
        connect (tp, SIGNAL(remove()), this, SLOT(removeWidget()));

        m_thirdParty.append(tp);
        m_ui->thirdPartyScrollArea->layout()->addWidget(tp);
    }
    m_thirdPartyLay->addStretch();

    qDebug() << "one";
}

void DatabaseConfig::save()
{
}

void DatabaseConfig::defaults()
{
}

void DatabaseConfig::removeWidget()
{
    if (qobject_cast<ThirdPartyWidget*>(sender()) != 0) {
        m_thirdParty.removeOne(qobject_cast<ThirdPartyWidget*>(sender()));
        sender()->deleteLater();
    } else {
        MirrorWidget *wg = qobject_cast<MirrorWidget*>(sender());
        if (wg->type() == Configuration::ArchMirror) {
            m_archMirrors.removeOne(wg);
            wg->deleteLater();
        } else {
            m_kdemodMirrors.removeOne(wg);
            wg->deleteLater();
        }
    }
}
