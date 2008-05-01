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

#ifndef SHAMANAPPLET_H
#define SHAMANAPPLET_H

#include <plasma/applet.h>
#include <plasma/dataengine.h>
#include <QtDBus/QDBusConnection>

namespace Plasma
{
    class HBoxLayout;
    class VBoxLayout;
    class Icon;
    class LineEdit;
}

class ShamanApplet : public Plasma::Applet
{
    Q_OBJECT
    public:
        ShamanApplet(QObject *parent, const QVariantList &args);
        ~ShamanApplet();

    public slots:
        void dataUpdated(const QString &name, const Plasma::DataEngine::Data &data);

    private slots:
        void updateDatabase();
        void upgradeSystem();

    private:
        void init();

        QDBusConnection dbus;
}; 

K_EXPORT_PLASMA_APPLET(shaman, ShamanApplet)

#endif
