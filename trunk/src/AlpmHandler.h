#ifndef ALPMHANDLER_H_
#define ALPMHANDLER_H_

#include <alpm.h>
#include <alpm_list.h>
#include <iostream>
#include <string>

#include "ConfigurationParser.h"

using namespace std;

class AlpmHandler : private ConfigurationParser
{
	/* There goes our main class, that is aimed to... pacman interaction.
	 * Well, here we are simplyfing things: we don't need all that crap that
	 * libalpm provides, so... Let's get a set of actions we can really use.
	 * Basically, this class inits libalpm and stores in itself data about
	 * current transaction, and manages current transaction asynchronously.
	 * 
	 * Not only, by inheriting ConfigurationParser we have all our configuration
	 * files at a glance, without the need of re-parsing it every time, as
	 * it is done only once, optimizing our flow.
	 */
	
public:
	AlpmHandler(bool init = false);
	virtual ~AlpmHandler();
	
	bool isTransaction();
	
	alpm_list_t *getAvailableRepos();
	alpm_list_t *searchPackages(char *keywords, char *repo, bool local);
	alpm_list_t *getConflicts(string pkgname);
	alpm_list_t *getUpgradeablePackages();
	alpm_list_t *checkDeps(string pkgname);
	
	bool isPerformable(string pkgname, int action);
	
	bool updateDatabase();
	bool upgradeSystem();
	
	bool upgradePackages(alpm_list_t *packages);
	bool installPackages(alpm_list_t *packages);
	bool removePackages(alpm_list_t *packages);
	bool cleanUpCache(alpm_list_t *cache);
	bool deleteCache(alpm_list_t *cache);
	bool isPackage(char *packagename);
	
	string getTransactionStatus();
	float getTransactionItemProgress();
	string getTransactionCurrentItem();
	float getTransactionTotalProgress();
	
	bool reloadPacmanConfiguration(); // In case the user modifies it.
	
private:
	int calculateTotalProgress();
	bool initTransaction(pmtranstype_t type, pmtransflag_t flags);
	bool releaseTransaction();
	bool configure();
	bool parsePacmanConf();
	bool setUpAlpmSettings();
	
private:
	pmdb_t *db_local;
	alpm_list_t *sync_databases;
	pmdb_t *dbs_sync;
	bool onTransaction;
	
	
	
};

#endif /*AlpmHandler_H_*/
