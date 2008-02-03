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

#include <iostream>
#include <string>
#include <alpm.h>
#include <alpm_list.h>

#include "AlpmHandler.h"
#include "callbacks.h"

AlpmHandler::AlpmHandler(bool init)
{
	
	/* First, initialize Alpm. Then, make the whole class aware that no
	 * transaction with libalpm is in progress */
	if(!init)
		return;
	
	alpm_initialize();
	onTransaction = false;
	
	setUpAlpmSettings();
	
}

AlpmHandler::~AlpmHandler()
{
	
	/*if(isTransaction())
		releaseTransaction();*/
	
	printf("ciao zio\n");
	
	sleep(2);
	
	alpm_release();
}

bool AlpmHandler::isTransaction()
{
	if(onTransaction)
		return true;
	else
		return false;
}

bool AlpmHandler::initTransaction(pmtranstype_t type, pmtransflag_t flags)
{
	if(isTransaction())
		return false;
	
	printf("Well");
	
	if(alpm_trans_init(type, flags, cb_trans_evt, cb_trans_conv,
			cb_trans_progress) == -1)
		return false;
	
	onTransaction = true;
	return onTransaction;
	
	
}

bool AlpmHandler::releaseTransaction()
{
	if(!isTransaction())
		return false;
	
	if(alpm_trans_release() == -1)
		if(alpm_trans_interrupt() == -1)
			return false;
	
	onTransaction = false;
	return true;
}

alpm_list_t *AlpmHandler::getAvailableRepos()
{
	return sync_databases;
}

alpm_list_t *AlpmHandler::getUpgradeablePackages()
{
	alpm_list_t *syncpkgs = NULL;
	
	alpm_list_t *syncdbs;
	
	syncdbs = alpm_list_first(sync_databases);
	
	if(alpm_sync_sysupgrade(db_local, syncdbs, &syncpkgs) == -1) 
		return NULL;
	
	while(syncdbs != NULL)
	{
		pmdb_t *dbcrnt = (pmdb_t *)alpm_list_getdata(syncdbs);
		
		printf("%s\n", alpm_db_get_name(dbcrnt));
		syncdbs = syncdbs->next;
		
	}
	
	if(!syncpkgs)
		return NULL;
	else
		return syncpkgs;
	
}

bool AlpmHandler::updateDatabase()
{
	int r;
	bool updated = false;
	alpm_list_t *syncdbs;
	
	syncdbs = alpm_list_first(sync_databases);
		
	emit dbQty(alpm_list_count(syncdbs));
	
	if(!initTransaction(PM_TRANS_TYPE_SYNC, PM_TRANS_FLAG_ALLDEPS))
	{
		printf("La madonna!! %s\n", alpm_strerrorlast());
		return false;
	}
		
	while(syncdbs != NULL)
	{
		pmdb_t *dbcrnt = (pmdb_t *)alpm_list_getdata(syncdbs);
				
		emit streamDbUpdatingStatus((char *)alpm_db_get_name(dbcrnt), 0);
		fflush(stdout);
		r = alpm_db_update(0, dbcrnt);
		if(r == 1)
			emit streamDbUpdatingStatus((char *)alpm_db_get_name(dbcrnt), 3);
		else if(r < 0)
			printf("Fallito Miseramente : %s", alpm_strerrorlast());
		else
		{
			printf("updated");
			emit dbUpdated();
			emit streamDbUpdatingStatus((char *)alpm_db_get_name(dbcrnt), 3);
		}
		
		emit dbUpdatePerformed();
		
		syncdbs = alpm_list_next(syncdbs);
	}
	
	if(!releaseTransaction())
		printf("azzo");
	
	printf("Fatto, bitches \n\n");
	return updated;
	
}

bool AlpmHandler::reloadPacmanConfiguration()
{
	PacmanConf pdata;
	
	pdata = getPacmanConf(true);
	
	if(!pdata.loaded)
		return false;
	
	/* After reloading configuration, we immediately commit changes to Alpm,
	 * otherwise users would have to reboot qtPacman. You know, we're not
	 * Windows, right?
	 */
	
	setUpAlpmSettings();
	
	return true;
}

bool AlpmHandler::setUpAlpmSettings()
{
	PacmanConf pdata;
	char *curdb, *temp;
	int count = 0;
	
	/* Let's prepare Alpm for the big showdown. First of all, let's set up
	 * some root paths, we will use pacman's default for now
	 */
	
	alpm_option_set_root("/");
	alpm_option_set_dbpath("/var/lib/pacman");
	alpm_option_add_cachedir("/var/cache/pacman/pkg");
	
	/* I love classes interaction */
	
	pdata = getPacmanConf(false);
	
	/* Register local database */
	
	db_local = alpm_db_register_local();
	
	/* Register our sync databases, kindly taken from pacdata */
	
	pdata.syncdbs = alpm_list_first(pdata.syncdbs);
	
	pdata.serverAssoc = alpm_list_first(pdata.serverAssoc);
	
	if(!pdata.loaded)
		printf("La madonna");
	
	while(pdata.syncdbs != NULL)
	{
		
		curdb = (char *)alpm_list_getdata(pdata.syncdbs);
		
		dbs_sync = alpm_db_register_sync(curdb);
		
		temp = (char *)alpm_list_getdata(pdata.serverAssoc);
		
		if(alpm_db_setserver(dbs_sync, temp) == 0)
			printf("Associato %s a %s\n", temp, curdb );
				
		pdata.syncdbs = alpm_list_next(pdata.syncdbs);
		pdata.serverAssoc = alpm_list_next(pdata.serverAssoc);
		
		count++;
	}
	
	if(pdata.xferCommand != NULL)
            alpm_option_set_xfercommand(pdata.xferCommand);
        
	alpm_option_set_dlcb(cb_dl_progress);
	alpm_option_set_nopassiveftp(pdata.noPassiveFTP);
	alpm_option_set_holdpkgs(pdata.HoldPkg);
	alpm_option_set_ignorepkgs(pdata.IgnorePkg);
	alpm_option_set_ignoregrps(pdata.IgnoreGrp);
	alpm_option_set_usedelta(pdata.useDelta);
	alpm_option_set_usesyslog(pdata.useSysLog);
	
	sync_databases = alpm_option_get_syncdbs();
	
	return true;
}

alpm_list_t *AlpmHandler::searchPackages(char *keywords, char *repo, bool local)
{
	alpm_list_t *syncdbs, *searchs = NULL, *returnlist = NULL, *tmplist;
	
	syncdbs = alpm_list_first(sync_databases);
	
	if(keywords != NULL)
		searchs = setrepeatingoption(keywords);
	
	if(local)
	{
		if(searchs)
			returnlist = alpm_db_search(db_local, searchs);
		else
			returnlist = alpm_db_getpkgcache(db_local);
	}
	else
	{
		while(syncdbs != NULL)
		{
			pmdb_t *dbcrnt = (pmdb_t *)alpm_list_getdata(syncdbs);
			
			if(repo != NULL)
				if(strcmp(repo, alpm_db_get_name( dbcrnt )))
				{
					syncdbs = alpm_list_next(syncdbs);
					continue;
				}
			
			if(searchs)
				tmplist = alpm_db_search(dbcrnt, searchs);
			else
				tmplist = alpm_db_getpkgcache(dbcrnt);
			
			if(returnlist == NULL)
				returnlist = tmplist;
			else if(tmplist != NULL)
				returnlist = alpm_list_join(returnlist, tmplist);
			
			syncdbs = alpm_list_next(syncdbs);
			
		}
	}
	
	if(searchs)
		alpm_list_free(searchs);
	
	return returnlist;
}

alpm_list_t *AlpmHandler::getPackageGroups()
{
	alpm_list_t *grps = NULL, *syncdbs;
	
	syncdbs = alpm_list_first(sync_databases);
	
	while(syncdbs != NULL)
	{
		if(grps == NULL)
			grps = alpm_db_getgrpcache((pmdb_t *)alpm_list_getdata(syncdbs));
		else
			grps = alpm_list_join(grps, alpm_db_getgrpcache(
					(pmdb_t *)alpm_list_getdata(syncdbs)));
	}
	
	return grps;
}
