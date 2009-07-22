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

#ifndef IDLEVIEW_H
#define IDLEVIEW_H

namespace Plasma
{
class Applet;
class Icon;
}

#include "AbstractView.h"

#include <QtDBus/QDBusConnection>

class QGraphicsLinearLayout;
class QGraphicsProxyWidget;
class KLineEdit;
class KMenu;
class KCompletion;

class IdleView : public AbstractView
{
    Q_OBJECT

public:
    IdleView(Plasma::Applet *parent, QDBusConnection dbs);
    virtual ~IdleView();

    void installPackageFromFile(const QString &filename);

private slots:
    void updateDatabase();
    void upgradeSystem();
    void installPackage();
    void removePackage();
    void showContextMenu();


private:
    QDBusConnection m_dbus;
    QGraphicsLinearLayout *m_layout;
    KLineEdit *m_packageLineEdit;
    Plasma::Icon *m_updateDatabaseIcon;
    Plasma::Icon *m_upgradeSystemIcon;
    QGraphicsLinearLayout *m_actionsLayout;
    Plasma::Icon *m_actionIcon;
    QGraphicsLinearLayout *m_lineLayout;
    QGraphicsProxyWidget *m_lineEdit;
    KMenu *m_contextMenu;
    KCompletion *m_completion;
};

#endif /*IDLEVIEW_H*/
