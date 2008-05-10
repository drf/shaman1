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
static const uint MINIMUM_UPDATE_INTERVAL = 1000;

class ShamanEngine : public Plasma::DataEngine
{
	Q_OBJECT
	Q_PROPERTY(uint refreshTime READ refreshTime WRITE setRefreshTime)
	
public:
	ShamanEngine(QObject* parent, const QVariantList &args);
	~ShamanEngine();
	
	QStringList sources() const;
	
	void setRefreshTime(uint time);
	uint refreshTime() const;

protected:
    bool sourceRequestEvent(const QString &name);
    bool updateSourceEvent(const QString& source);

private slots:
	void getShamanData(const QString &name);
	void updateShamanData();
	void connectDBusSlots();
	void dbUpdate(const QString &repo, int action);
	void actionChanged(const QString &action);
	void dlProg(const QString &filename, int singlePercent, int singleSpeed,
			int totalPercent, int totalSpeed);
	
private:
	bool isDBusServiceRegistered();

	QDBusConnection dbus;
	QString currentAction;
	bool dbusError;
	bool slotsAreConnected;
	
	QString curitm;
	int curitmAct;
	
	int singleDlPercent;
	int singleDlSpd;
	int totalDlPercent;
	int totalDlSpd;
};

K_EXPORT_PLASMA_DATAENGINE(shaman, ShamanEngine)

#endif
