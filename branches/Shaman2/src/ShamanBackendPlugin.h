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

using namespace std;
class Package;

namespace Backend {

	enum PackageStatus {
		AllPackages,
		InstalledPackages,
		UpgradeablePackages
	};

}  // namespace Alpm

class ShamanBackendPlugin : public QObject, private ConfigurationParser
{
	Q_OBJECT

public:
	ShamanBackendPlugin(bool init = false);
	virtual ~ShamanBackendPlugin();

	bool isTransaction();
	bool testLibrary();
	bool interruptTransaction();

	QStringList getAvailableRepos();
	
	QStringList getPackageGroups();
	
	PackageList getPackagesFromRepo(const QString &reponame);
	
	PackageList getUpgradeablePackages();
	PackageList getInstalledPackages();

	QStringList getPackageDependencies(Package *package);
	QStringList getPackageDependencies(const QString &name, const QString &repo);

	QStringList getDependenciesOnPackage(Package package);
	QStringList getDependenciesOnPackage(const QString &name, const QString &repo);
	
	QStringList getPackageFiles(Package package);
	QStringList getPackageFiles(const QString &name);
	
	int countPackages(Alpm::PackageStatus status);
	
	QStringList getProviders(const QString &name, const QString &repo);
	QStringList getProviders(Package pkg);
	bool isProviderInstalled(const QString &provider);
	
	unsigned long getPackageSize(const QString &name, const QString &repo);
	unsigned long getPackageSize(Package package);
	
	QString getPackageVersion(const QString &name, const QString &repo);
	QString getPackageVersion(Package package);
	
	QString getPackageRepo(const QString &name, bool checkver = false);
	
	void initQueue(bool rem, bool syncd, bool ff);
	
	void addSyncToQueue(const QString &toAdd);
	void addRemoveToQueue(const QString &toRm);
	void addFFToQueue(const QString &toFF);
	
	QStringList getSyncInQueue();
	QStringList getRemoveInQueue();
	QStringList getFFInQueue();
	
	void processQueue();
	int getNumberOfTargets(int action);

	bool updateDatabase();
	bool fullSystemUpgrade();

	bool performCurrentTransaction();

	bool reloadBackendConfiguration(); // In case the user modifies it.
	
	Package getPackageFromName(const QString &name, const QString &repo);
	
	QString getBackendVersion();
	
	void setuseragent();

private:
	bool initTransaction(pmtranstype_t type, pmtransflag_t flags);
	bool releaseTransaction();
	bool setUpAlpmSettings();
	void handleError(int action, alpm_list_t *data);

signals:
	void streamDbUpdatingStatus(const QString &repo, int action);
	void dbUpdated(const QString &dbname);
	void dbQty(const QStringList &db);
	void dbUpdatePerformed();
	void transactionStarted();
	void transactionReleased();
	
	// Error streaming
	void preparingUpgradeError();
	void preparingTransactionError(const QString &msg);
	void committingTransactionError(const QString &msg);

private:
	pmdb_t *db_local;
	alpm_list_t *sync_databases;
	alpm_list_t *registered_db;
	pmdb_t *dbs_sync;
	bool onTransaction;
	bool removeAct;
	bool syncAct;
	bool upgradeAct;
	bool fromFileAct;
	bool logFileIsSet;
	
	QStringList toRemove;
	QStringList toSync;
	QStringList toFromFile;
	
	Authenticator ath;

};

#endif /*AlpmHandler_H_*/
