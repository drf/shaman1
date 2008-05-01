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
#include <QtDBus/QDBusMessage>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QLineEdit>

#include <KIcon>

#include <plasma/widgets/icon.h>
#include <plasma/dataengine.h>

ShamanApplet::ShamanApplet(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args),
    dbus(QDBusConnection::systemBus())
{
    //setDrawStandardBackground(true);//TODO
}

ShamanApplet::~ShamanApplet()
{
}

void ShamanApplet::init()
{
    Plasma::DataEngine *m_engine = dataEngine("shaman");
    if (m_engine) {
        m_engine->connectSource("Shaman", this);
    }
    else {
        kDebug()<<"Shaman Engine could not be loaded";
    }

    QGraphicsLinearLayout *m_layout = new QGraphicsLinearLayout(Qt::Vertical, this);
    QGraphicsLinearLayout *m_actionsLayout = new QGraphicsLinearLayout(m_layout);
    Plasma::Icon *m_updateDatabaseIcon = new Plasma::Icon(KIcon("view-refresh"), i18n("Update Database"), this);
    connect(m_updateDatabaseIcon, SIGNAL(clicked()), SLOT(updateDatabase()));
    m_actionsLayout->addItem(m_updateDatabaseIcon);
    Plasma::Icon *m_upgradeSystemIcon = new Plasma::Icon(KIcon("system-software-update"), i18n("Upgrade System"), this);
    connect(m_upgradeSystemIcon, SIGNAL(clicked()), SLOT(upgradeSystem()));
    m_actionsLayout->addItem(m_upgradeSystemIcon);
    m_layout->addItem(m_actionsLayout);
    QGraphicsLinearLayout *m_lineLayout = new QGraphicsLinearLayout(m_layout);
    QGraphicsProxyWidget *m_lineEdit = new QGraphicsProxyWidget(this);
    m_lineEdit->setWidget(new QLineEdit(0));
    m_lineLayout->addItem(m_lineEdit);
    Plasma::Icon *m_actionIcon = new Plasma::Icon(KIcon("tools-wizard"), i18n("Action"), this);
    m_lineLayout->addItem(m_actionIcon);
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
