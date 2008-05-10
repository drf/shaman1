/***************************************************************************
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de       											   *
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

#include "shamanEngine.h"

#include <QtDBus/QDBusConnectionInterface>
#include <KDebug>

#include "plasma/datacontainer.h"

ShamanEngine::ShamanEngine(QObject *parent, const QVariantList &args)
  : Plasma::DataEngine(parent),
  dbus(QDBusConnection::systemBus()),
  currentAction("idle"),
  dbusError(false),
  slotsAreConnected(false),
  curitm(QString()),
  curitmAct(0),
  singleDlPercent(0),
  singleDlSpd(0),
  totalDlPercent(0),
  totalDlSpd(0)
{
	Q_UNUSED(args)
	
	setMinimumPollingInterval(MINIMUM_UPDATE_INTERVAL);
	
}

ShamanEngine::~ShamanEngine()
{
}

QStringList ShamanEngine::sources() const
{
    QStringList sources;
    sources << "Shaman";

    return sources;
}

void ShamanEngine::setRefreshTime(uint time)
{
        setPollingInterval(time);
}

uint ShamanEngine::refreshTime() const
{
        return 1000;
}

bool ShamanEngine::sourceRequestEvent(const QString &name)
{
	return updateSourceEvent(name);
}

bool ShamanEngine::updateSourceEvent(const QString &name)
{
	if(!name.compare("Shaman", Qt::CaseInsensitive))
		getShamanData(name);
	
	return true;
}

void ShamanEngine::getShamanData(const QString &name)
{
	removeAllData(name);

	if(isDBusServiceRegistered()) 
	{
		setData(name, "error", false);
		setData(name, "transactionStatus", currentAction);
		setData(name, "DBusError", dbusError);
		setData(name, "CurrentItemProcessed", curitm);
		setData(name, "CurrentItemStatus", curitmAct);
		setData(name, "CurrentItemDlSpeed", singleDlSpd);
		setData(name, "CurrentItemDlPercent", singleDlPercent);
		setData(name, "TotalDlSpeed", totalDlSpd);
		setData(name, "TotalDlPercent", totalDlPercent);
	}
	else 
	{
		setData(name, "error", true);
		setData(name, "errorMessage", I18N_NOOP("Is Shaman up and running?"));
	}
}

bool ShamanEngine::isDBusServiceRegistered()
{
	if(dbus.interface()->isServiceRegistered(SHAMAN_DBUS_SERVICE))
	{
		if(!slotsAreConnected)
		{
			connectDBusSlots();
			slotsAreConnected = true;
		}
		return true;
	}
	else
	{
		if(slotsAreConnected)
		{
			slotsAreConnected = false;
		}
		return false;
	}
}

void ShamanEngine::actionChanged(const QString &action)
{
	currentAction = action;
	updateSourceEvent("Shaman");
}

void ShamanEngine::updateShamanData()
{
	getShamanData("Shaman");
}

void ShamanEngine::connectDBusSlots()
{
	if(!dbus.connect("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", 
			"actionStatusChanged", this, SLOT(actionChanged(const QString&))))
		dbusError = true;
	else
		dbusError = false;

	if(!dbus.connect("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", 
			"streamDbUpdatingStatus", this, SLOT(dbUpdate(const QString&,int))))
		dbusError = true;
	else
		dbusError = false;

	if(!dbus.connect("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", 
			"streamTransDlProg", this, SLOT(dlProg(const QString&,int,int,int,int))))
		dbusError = true;
	else
		dbusError = false;
}

void ShamanEngine::dbUpdate(const QString &repo, int action)
{
	curitm = repo;
	curitmAct = action;
}

void ShamanEngine::dlProg(const QString &filename, int singlePercent, int singleSpeed,
		int totalPercent, int totalSpeed)
{
	curitm = filename;
	singleDlPercent = singlePercent;
	singleDlSpd = singleSpeed;
	totalDlPercent = totalPercent;
	totalDlSpd = totalSpeed;
}

#include "shamanEngine.moc"
