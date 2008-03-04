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

#ifndef SHAMANENGINE_H
#define SHAMANENGINE_H

#include <plasma/dataengine.h>

#include <QtDBus/QDBusConnection>

static const QString SHAMAN_DBUS_SERVICE = "org.archlinux.shaman";
static const QString SHAMAN_DBUS_PATH = "/Shaman";
static const QString SHAMAN_DBUS_INTERFACE = "org.archlinux.shaman";

class ShamanEngine : public Plasma::DataEngine
{
	Q_OBJECT
	Q_PROPERTY(uint refreshTime READ refreshTime WRITE setRefreshTime)
	
public:
	ShamanEngine(QObject* parent, const QVariantList &args);
	~ShamanEngine();
	void setRefreshTime(uint time);
	uint refreshTime() const;

protected:
	bool sourceRequested(const QString &name);
	bool updateSource(const QString &name);

private slots:
	void getShamanData(const QString &name);
	void actionStatusChanged(const QString &action);
	void updateShamanData();
	void connectDBusSlots();
	void serviceRegistered(const QString &srvname);

private:
	bool isDBusServiceRegistered();

	QDBusConnection dbus;
	QString currentAction;
};

K_EXPORT_PLASMA_DATAENGINE(shaman, ShamanEngine)

#endif
