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

using namespace std;

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

	alpm_list_t *getAvailableRepos();
	alpm_list_t *getPackageGroups();
	alpm_list_t *searchPackages(char *keywords, char *repo, bool local);
	alpm_list_t *getUpgradeablePackages();

	QStringList getPackageDependencies(pmpkg_t *package);
	QStringList getPackageDependencies(QString *name, QString *repo);

	QStringList getDependenciesOnPackage(pmpkg_t *package);
	QStringList getDependenciesOnPackage(QString *name, QString *repo);
	
	QStringList getPackageFiles(pmpkg_t *package);
	QStringList getPackageFiles(QString *name);
	
	QStringList getProviders(QString *name, QString *repo);
	
	void initQueue(bool rem, bool syncd);
	void addSyncToQueue(QString toAdd);
	void addRemoveToQueue(QString toRm);
	void processQueue();
	int getNumberOfTargets(int action);
	
	bool cleanUnusedDb();
	bool cleanCache(bool empty = false);
	
	int rmrf(const char *path);
	int makepath(const char *path);

	bool isPerformable(string pkgname, int action);
	bool isInstalled(pmpkg_t *pkg);

	bool updateDatabase();
	bool fullSystemUpgrade();

	bool isPackage(char *packagename);

	bool performCurrentTransaction();

	bool reloadPacmanConfiguration(); // In case the user modifies it.

private:
	bool initTransaction(pmtranstype_t type, pmtransflag_t flags);
	bool releaseTransaction();
	bool setUpAlpmSettings();
	pmpkg_t *getPackageFromName(QString *name, QString *repo);

signals:
	void streamDbUpdatingStatus(char *repo, int action);
	void dbUpdated();
	void dbQty(QStringList *db);
	void dbUpdatePerformed();

private:
	pmdb_t *db_local;
	alpm_list_t *sync_databases;
	alpm_list_t *registered_db;
	pmdb_t *dbs_sync;
	bool onTransaction;
	bool removeAct;
	bool syncAct;
	bool upgradeAct;
	
	QStringList toRemove;
	QStringList toSync;


};

#endif /*AlpmHandler_H_*/
