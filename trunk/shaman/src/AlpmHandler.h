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

#include <alpm.h>
#include <alpm_list.h>
#include <iostream>
#include <string>
#include <QString>
#include <QStringList>

#include "ConfigurationParser.h"
#include "Authenticator.h"

using namespace std;

namespace Alpm {

	enum PackageStatus {
		AllPackages,
		InstalledPackages,
		UpgradeablePackages
	};

}  // namespace Alpm

class AlpmHandler : public QObject, private ConfigurationParser
{
	/* There goes our main class, that is aimed to... libalpm interaction.
	 * Well, here we are simplyfing things: we don't need all that crap that
	 * libalpm provides, so... Let's get a set of actions we can really use.
	 * Basically, this class inits libalpm and stores in itself data about
	 * current transaction, and manages current transaction asynchronously.
	 * Obviously, despite its asynchronous nature (we have to commit), calling
	 * the committing function of libalpm interrupts the application loop,
	 * "freezing" the process. So, when this is called, the instance of
	 * this class is moved to a different thread. It's extremely important to
	 * keep this class libalpm related-only, otherwise we would risk
	 * thread-unsafe operations, and this is something we don't want, right?
	 * Also, we definitely want to avoid alpm_lists and their fucking odd
	 * voids*, better use a QStringList. We only use alpm_list_t* where
	 * we can't do otherwise or it's a good solution for the sake of not implementing
	 * a useless type (something libalpm devs should learn too).
	 * 
	 * By inheriting ConfigurationParser we have all our configuration
	 * files at a glance, without the need of re-parsing it every time, as
	 * it is done only once, optimizing our flow.
	 */

	Q_OBJECT

public:
	AlpmHandler(bool init = false);
	virtual ~AlpmHandler();

	bool isTransaction();
	bool testLibrary();
	bool interruptTransaction();

	alpm_list_t *getAvailableRepos();
	QStringList getAvailableReposNames();
	
	QStringList getPackageGroups();
	
	alpm_list_t *getPackagesFromRepo(const QString &reponame);
	
	QStringList getUpgradeablePackages();
	alpm_list_t *getInstalledPackages();

	QStringList getPackageDependencies(pmpkg_t *package);
	QStringList getPackageDependencies(const QString &name, const QString &repo);

	QStringList getDependenciesOnPackage(pmpkg_t *package);
	QStringList getDependenciesOnPackage(const QString &name, const QString &repo);
	
	QStringList getPackageFiles(pmpkg_t *package);
	QStringList getPackageFiles(const QString &name);
	
	int countPackages(Alpm::PackageStatus status);
	
	QStringList getProviders(const QString &name, const QString &repo);
	QStringList getProviders(pmpkg_t *pkg);
	bool isProviderInstalled(const QString &provider);
	
	unsigned long getPackageSize(const QString &name, const QString &repo);
	unsigned long getPackageSize(pmpkg_t *package);
	
	QString getPackageVersion(const QString &name, const QString &repo);
	QString getPackageVersion(pmpkg_t *package);
	
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
	
	bool cleanUnusedDb(const char *dbpath);
	bool cleanCache(bool empty = false);
	
	int rmrf(const char *path);
	
	bool isInstalled(pmpkg_t *pkg);
	bool isInstalled(const QString &pkg);

	bool updateDatabase();
	bool fullSystemUpgrade();

	bool performCurrentTransaction();

	bool reloadPacmanConfiguration(); // In case the user modifies it.
	
	pmpkg_t *getPackageFromName(const QString &name, const QString &repo);
	
	QStringList alpmListToStringList(alpm_list_t *list);
	
	QString getAlpmVersion();
	
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
