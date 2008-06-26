/***************************************************************************
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

#include "IdleView.h"

#include <QAction>
#include <QtDBus/QDBusMessage>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneDragDropEvent>

#include <KLineEdit>
#include <KIcon>
#include <KMenu>
#include <KDebug>
#include <KCompletion>

#include <plasma/widgets/icon.h>

IdleView::IdleView(Plasma::Applet *parent, QDBusConnection dbs)
: AbstractView(parent),
    m_dbus(dbs)
{
    m_layout = static_cast <QGraphicsLinearLayout *> (parent->layout());
    
    if ( m_layout )
    {
        m_contextMenu = new KMenu(0);
        
        m_actionsLayout = new QGraphicsLinearLayout(m_layout);

        m_updateDatabaseIcon = new Plasma::Icon(KIcon("view-refresh"), i18n("Update Database"), parent);
        connect(m_updateDatabaseIcon, SIGNAL(activated()), SLOT(updateDatabase()));
        m_actionsLayout->addItem(m_updateDatabaseIcon);

        m_upgradeSystemIcon = new Plasma::Icon(KIcon("system-software-update"), i18n("Upgrade System"), parent);
        connect(m_upgradeSystemIcon, SIGNAL(activated()), SLOT(upgradeSystem()));
        m_actionsLayout->addItem(m_upgradeSystemIcon);

        m_layout->addItem(m_actionsLayout);

        m_lineLayout = new QGraphicsLinearLayout(m_layout);

        m_lineEdit = new QGraphicsProxyWidget(parent);
        m_packageLineEdit = new KLineEdit(0);
        
        m_packageLineEdit->setClearButtonShown(true);
        m_completion = new KCompletion();

        m_completion->setOrder( KCompletion::Sorted );

        m_dbus.connect("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", 
                "streamPackages", m_completion, SLOT(setItems(const QStringList&)));

        m_packageLineEdit->setCompletionObject( m_completion );
        
        m_lineEdit->setWidget(m_packageLineEdit);
        m_lineLayout->addItem(m_lineEdit);

        m_actionIcon = new Plasma::Icon(KIcon("tools-wizard"), i18n("Action"), parent);
        QAction *m_installAction = new QAction(KIcon("list-add"), i18n("Install Package"), this);
        connect(m_installAction, SIGNAL(triggered()), SLOT(installPackage()));
        m_actionIcon->addIconAction(m_installAction);
        m_contextMenu->addAction(m_installAction);
        
        QAction *m_removeAction = new QAction(KIcon("list-remove"), i18n("Uninstall Package"), this);
        connect(m_removeAction, SIGNAL(triggered()), SLOT(removePackage()));
        m_actionIcon->addIconAction(m_removeAction);
        m_contextMenu->addAction(m_removeAction);
        connect(m_actionIcon, SIGNAL(activated()), SLOT(showContextMenu()));

        m_lineLayout->addItem(m_actionIcon);

        m_layout->addItem(m_lineLayout);
    }
    
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "doStreamPackages");
        m_dbus.call(msg);
}

IdleView::~IdleView()
{
    m_lineEdit->setWidget(0);
    
    delete m_lineEdit;
    delete m_actionIcon;
    delete m_updateDatabaseIcon;
    delete m_upgradeSystemIcon;
}

void IdleView::showContextMenu()
{
    if (m_contextMenu)
        m_contextMenu->popup(QCursor::pos());
}

void IdleView::updateDatabase()
{
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "doDbUpdate");
    m_dbus.call(msg);
}

void IdleView::upgradeSystem()
{
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", "fullSysUpgrade");
    m_dbus.call(msg);
}

void IdleView::installPackage()
{
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman",
            "org.archlinux.shaman", "installPackage");
    msg << m_packageLineEdit->text();
    m_dbus.call(msg);
    QDBusMessage processMsg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman",
            "org.archlinux.shaman", "widgetQueueToAlpmQueue");
    m_dbus.call(processMsg);
}

void IdleView::installPackageFromFile(const QString &filename)
{
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman",
            "org.archlinux.shaman", "installPackageFromFile");
    msg << filename;
    m_dbus.call(msg);
}

void IdleView::removePackage()
{
    QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman",
            "org.archlinux.shaman", "removePackage");
    msg << m_packageLineEdit->text();
    m_dbus.call(msg);
    QDBusMessage processMsg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman",
            "org.archlinux.shaman", "widgetQueueToAlpmQueue");
    m_dbus.call(processMsg);
}

void IdleView::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if ( KUrl::List::canDecode(event->mimeData()) ) 
    {
        const KUrl::List urls = KUrl::List::fromMimeData(event->mimeData());
        if ( urls.count() > 0 )
        {
            event->accept();
            
            foreach ( const KUrl& url, urls )
            {
                installPackageFromFile(url.path());
            }
        }
    }
}

#include "IdleView.moc"
