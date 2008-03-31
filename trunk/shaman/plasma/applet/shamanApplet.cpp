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
#include "shamanApplet.h"

#include <QAction>

#include <KIcon>

#include <plasma/layouts/boxlayout.h>
#include <plasma/widgets/icon.h>
#include <plasma/widgets/lineedit.h>
#include <QtDBus/QDBusMessage>

ShamanApplet::ShamanApplet(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args),
    dbus(QDBusConnection::systemBus())
{
    setDrawStandardBackground(true);
} 

ShamanApplet::~ShamanApplet()
{
}

void ShamanApplet::init()
{
    m_engine = dataEngine("shaman");
    if (m_engine) {
        m_engine->connectSource("Shaman", this);
    }
    else {
        kDebug()<<"Shaman Engine could not be loaded";
    }

    m_layout = new Plasma::VBoxLayout(this);
    m_actionLayout = new Plasma::HBoxLayout(m_layout);
    m_lineLayout = new Plasma::HBoxLayout(m_layout);
    //Why are those things not shown?
    m_updateDatabaseIcon = new Plasma::Icon(KIcon("view-refresh"), tr("Update Database"), this);
    m_actionLayout->addItem(m_updateDatabaseIcon);
    connect(m_updateDatabaseIcon, SIGNAL(clicked()), SLOT(updateDatabase()));
    m_upgradeSystemIcon = new Plasma::Icon(KIcon("edit-redo.png"), tr("Upgrade System"), this);
    m_actionLayout->addItem(m_upgradeSystemIcon);
    connect(m_upgradeSystemIcon, SIGNAL(clicked()), SLOT(upgradeSystem()));

    m_packageLine = new Plasma::LineEdit(this);
    
    m_lineLayout->addItem(m_packageLine);
    m_layout->addItem(m_actionLayout);
    m_layout->addItem(m_lineLayout);
    setLayout(m_layout);
}

void ShamanApplet::updateDatabase()
{
	QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "doDbUpdate");
	dbus.call(msg);
}

void ShamanApplet::upgradeSystem()
{
	QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "fullSysUpgrade");
	dbus.call(msg);
}

void ShamanApplet::dataUpdated(const QString &name, const Plasma::DataEngine::Data &data)
{
    //TODO: Do the Info-updates here...
}

#include "shamanApplet.moc"
