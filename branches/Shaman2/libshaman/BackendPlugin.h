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

#ifndef ALPMHANDLER_H_
#define ALPMHANDLER_H_

#include "Authenticator.h"
#include "ConfigurationParser.h"
//URGENT TODO: FIXME: HACK: ALL: FIXME: TODO: Clean up that things here :P why do we have to know about transactions? ---> transaction Class??? And other things...
//TODO: Remove all that QString repo things
//TODO: Write documentation and change the functions to better names
using namespace std;
class Package;

namespace Backend {//Why that?

	enum PackageStatus {
		AllPackages,
		InstalledPackages,
		UpgradeablePackages
	};//TODO: Use PackageStatus stuff from Package-class...

}  // namespace Alpm

namespace Shaman{
class BackendPlugin : public QObject, private ConfigurationParser
{
Q_OBJECT
    public:
	BackendPlugin(QObject *parent);
	virtual ~BackendPlugin();

	bool isTransaction();
	bool testLibrary();//Fuck all :P Wth is that?????
	bool interruptTransaction();//Fuck all :P Wth is that?????

        RepositoriesList availableRepos();

        GroupsList packageGroups();//With s or not?

        Package * package(const QString &name);
        PackageList packages(Package::State state);
        PackageList packages(Package::Action action);

        void processQueue();

        void updateDatabase();
        void fullSystemUpgrade();

        bool reloadBackendConfiguration(); // In case the user modifies it.

    signals:
        void statusChanged(Status status);
        void processingSuccesfull();
        void error(Error error);
};
}

#endif /*AlpmHandler_H_*/
