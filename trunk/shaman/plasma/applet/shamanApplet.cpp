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
#include <QLabel>
#include <QProgressBar>

#include <KIcon>
#include <KMenu>
#include <KDebug>

#include <plasma/widgets/icon.h>

ShamanApplet::ShamanApplet(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args),
    dbus(QDBusConnection::systemBus()),
    m_packageLineEdit(0),
    m_contextMenu(0)
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
        m_engine->connectAllSources(this);
    }
    else {
        kDebug()<<"Shaman Engine could not be loaded";
    }
    m_contextMenu = new KMenu(0);

    QGraphicsLinearLayout *m_layout = new QGraphicsLinearLayout(Qt::Vertical, this);

    QGraphicsLinearLayout *m_actionsLayout = new QGraphicsLinearLayout(m_layout);

    Plasma::Icon *m_updateDatabaseIcon = new Plasma::Icon(KIcon("view-refresh"), i18n("Update Database"), this);
    connect(m_updateDatabaseIcon, SIGNAL(activated()), SLOT(updateDatabase()));
    m_actionsLayout->addItem(m_updateDatabaseIcon);

    Plasma::Icon *m_upgradeSystemIcon = new Plasma::Icon(KIcon("system-software-update"), i18n("Upgrade System"), this);
    connect(m_upgradeSystemIcon, SIGNAL(activated()), SLOT(upgradeSystem()));
    m_actionsLayout->addItem(m_upgradeSystemIcon);

    m_layout->addItem(m_actionsLayout);

    QGraphicsLinearLayout *m_lineLayout = new QGraphicsLinearLayout(m_layout);

    QGraphicsProxyWidget *m_lineEdit = new QGraphicsProxyWidget(this);
    m_packageLineEdit = new QLineEdit(0);
    m_lineEdit->setWidget(m_packageLineEdit);
    m_lineLayout->addItem(m_lineEdit);

    Plasma::Icon *m_actionIcon = new Plasma::Icon(KIcon("tools-wizard"), i18n("Action"), this);
    QAction *m_installAction = new QAction(KIcon("list-add"), i18n("Install Package"), this);
    connect(m_installAction, SIGNAL(triggered()), SLOT(installPackage()));
    m_actionIcon->addAction(m_installAction);
    m_contextMenu->addAction(m_installAction);
    QAction *m_removeAction = new QAction(KIcon("list-remove"), i18n("Uninstall Package"), this);
    connect(m_removeAction, SIGNAL(triggered()), SLOT(removePackage()));
    m_actionIcon->addAction(m_removeAction);
    m_contextMenu->addAction(m_removeAction);
    connect(m_actionIcon, SIGNAL(activated()), SLOT(showContextMenu()));

    m_lineLayout->addItem(m_actionIcon);

    m_layout->addItem(m_lineLayout);

    QGraphicsProxyWidget *m_statusLabel = new QGraphicsProxyWidget(this);
    m_statusLabelWidget = new QLabel(0);
    m_statusLabelWidget->setStyleSheet("background-color: transparent; color: white");
    m_statusLabelWidget->setAlignment(Qt::AlignCenter);
    m_statusLabelWidget->setText("Hello this is the status");
    m_statusLabel->setWidget(m_statusLabelWidget);
    m_layout->addItem(m_statusLabel);

    QGraphicsProxyWidget *m_progressBar = new QGraphicsProxyWidget(this);
    m_progressBarWidget = new QProgressBar(0);
    m_progressBarWidget->setStyleSheet("background-color: transparent");
    m_progressBarWidget->setValue(30);
    m_progressBar->setWidget(m_progressBarWidget);
    m_layout->addItem(m_progressBar);

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

void ShamanApplet::installPackage()
{
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "installPackage");
    msg << m_packageLineEdit->text();
    dbus.call(msg);
    QDBusMessage processMsg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "widgetQueueToAlpmQueue");
    dbus.call(processMsg);
}

void ShamanApplet::removePackage()
{
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "removePackage");
    msg << m_packageLineEdit->text();
    dbus.call(msg);
    QDBusMessage processMsg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "widgetQueueToAlpmQueue");
    dbus.call(processMsg);
}

void ShamanApplet::dataUpdated(const QString &name, const Plasma::DataEngine::Data &data)
{
    kDebug() << "called";
    
    if ( data.size() == 0 ) 
        return;
    
    if ( name != "shaman" )
        return;
    
    m_progressBarWidget->setValue( data[ "TotalDlPercent" ].toInt() );
    
    m_statusLabelWidget->setText( data[ "transactionStatus" ].toString() );
}

void ShamanApplet::showContextMenu()
{
    if (m_contextMenu)
        m_contextMenu->popup(QCursor::pos());
}

#include "shamanApplet.moc"
