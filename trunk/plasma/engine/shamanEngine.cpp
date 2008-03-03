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
  currentAction("idle")
{
    Q_UNUSED(args)

    if(isDBusServiceRegistered())
    {
    	if(!dbus.connect(SHAMAN_DBUS_SERVICE, SHAMAN_DBUS_PATH, SHAMAN_DBUS_INTERFACE, 
    			SIGNAL(actionStatusChanged(const QString&)), this, SLOT(actionStatusChanged(const QString&))))
    		kDebug() << "Couldn't connect a slot through DBus";
    }
    
}

ShamanEngine::~ShamanEngine()
{
}

bool ShamanEngine::sourceRequested(const QString &name)
{
	return updateSource(name);
}

bool ShamanEngine::updateSource(const QString &name)
{
	if(!name.compare("shaman", Qt::CaseInsensitive))
		getShamanData(name);
	
	return true;
}

void ShamanEngine::getShamanData(const QString &name)
{
	clearData(name);

	if(isDBusServiceRegistered()) 
	{
		setData(name, "error", false);
		setData(name, "transactionStatus", currentAction);
	}
	else 
	{
		setData(name, "error", true);
		setData(name, "errorMessage", I18N_NOOP("Is Shaman up and running?"));
	}
}

bool ShamanEngine::isDBusServiceRegistered()
{
	return dbus.interface()->isServiceRegistered(SHAMAN_DBUS_SERVICE);
}

void ShamanEngine::actionStatusChanged(const QString &action)
{
	currentAction = action;
	updateSource("shaman");
}

#include "shamanEngine.moc"
