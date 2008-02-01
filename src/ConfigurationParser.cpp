#include <iostream>
#include <string>
#include <alpm.h>
#include <alpm_list.h>
#include <stdlib.h> /* atoi */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h> /* time_t */

#include "ConfigurationParser.h"

using namespace std;

alpm_list_t *ConfigurationParser::setrepeatingoption(const char *ptr)
{
	char *p = (char*)ptr;
	char *q;
	alpm_list_t *list = NULL;

	while((q = strchr(p, ' '))) {
		*q = '\0';
		list = alpm_list_add(list, p);
		p = q;
		p++;
	}
	list = alpm_list_add(list, p);
	return list;
}

void ConfigurationParser::parsePacmanConfig(const char *file, const char *givensection,
		char *givendb)
{
	FILE *fp = NULL;
	char line[PATH_MAX+1];
	int linenum = 0;
	char *ptr, *section = NULL;
	char *db = NULL;
	
	if(!pacData.loaded)
	{
		pacData.syncdbs = NULL;
		pacData.serverAssoc = NULL;
	}
	
	pacData.loaded = true;

	fp = fopen(file, "r");
	if(fp == NULL)
	{
		pacData.loaded = false;
		return;
	}

	/* if we are passed a section, use it as our starting point */
	if(givensection != NULL) 
		section = strdup(givensection);	
		
	/* if we are passed a db, use it as our starting point */
	if(givendb != NULL)
		db = givendb;

	while(fgets(line, PATH_MAX, fp)) 
	{
		linenum++;
		strtrim(line);

		/* ignore whole line and end of line comments */
		if(strlen(line) == 0 || line[0] == '#') 
			continue;

		if((ptr = strchr(line, '#'))) 
			*ptr = '\0';

		if(line[0] == '[' && line[strlen(line)-1] == ']') 
		{
			/* new config section, skip the '[' */
			ptr = line;
			ptr++;
			if(section)
				free(section);
				
			section = strdup(ptr);
			section[strlen(section)-1] = '\0';
			if(!strlen(section))
			{
				pacData.loaded = false;
				return;
			}
			
			/* if we are not looking at the options section, register a db and also
			 * ensure we have set all of our library paths as the library is too stupid
			 * at the moment to do lazy opening of the databases */
			
			if(strcmp(section, "options") != 0)
			{
				char *tmp = (char *)malloc(strlen(section) * sizeof(char));
				
				strcpy(tmp, section);
				
				pacData.syncdbs = alpm_list_add(pacData.syncdbs, tmp);
				
				db = (char *)malloc(strlen(section) * sizeof(char));
				
				strcpy(db,section);
			}
		}
		else 
		{
			/* directive */
			char *key, *upperkey;
			/* strsep modifies the 'line' string: 'key \0 ptr' */
			key = line;
			ptr = line;
			strsep(&ptr, "=");
			strtrim(key);
			strtrim(ptr);

			if(key == NULL)
			{
				pacData.loaded = false;
				return;
			}
			/* For each directive, compare to the uppercase and camelcase string.
			 * This prevents issues with certain locales where characters don't
			 * follow the toupper() rules we may expect, e.g. tr_TR where i != I.
			 */
			upperkey = strtoupper(strdup(key));
			if(section == NULL) 
			{
				pacData.loaded = false;
				return;
			}

			if(ptr == NULL && strcmp(section, "options") == 0) 
			{
				/* directives without settings, all in [options] */
				if(strcmp(key, "NoPassiveFTP") == 0 || strcmp(upperkey, "NOPASSIVEFTP") == 0)
					pacData.noPassiveFTP = 1;
				else if(strcmp(key, "UseSyslog") == 0 || strcmp(upperkey, "USESYSLOG") == 0)
					pacData.useSysLog = 1;
				else if(strcmp(key, "UseDelta") == 0 || strcmp(upperkey, "USEDELTA") == 0)
					pacData.useDelta = 1; 
				
			} 
			else
			{
				/* directives with settings */
				if(strcmp(key, "Include") == 0 || strcmp(upperkey, "INCLUDE") == 0)
				{
					parsePacmanConfig(ptr, section, db);
					if(!pacData.loaded)
					{
						pacData.loaded = false;
						return;
					}
				}
					/* Ignore include failures... assume non-critical */
				else if(strcmp(section, "options") == 0)
				{
					if(strcmp(key, "NoUpgrade") == 0
							|| strcmp(upperkey, "NOUPGRADE") == 0)
						pacData.NoUpgrade = setrepeatingoption(ptr);
					else if(strcmp(key, "NoExtract") == 0
							|| strcmp(upperkey, "NOEXTRACT") == 0)
						pacData.NoExtract = setrepeatingoption(ptr);
					else if(strcmp(key, "IgnorePkg") == 0
							|| strcmp(upperkey, "IGNOREPKG") == 0)
						pacData.IgnorePkg = setrepeatingoption(ptr);
					else if(strcmp(key, "IgnoreGroup") == 0
							|| strcmp(upperkey, "IGNOREGROUP") == 0)
						pacData.IgnoreGrp = setrepeatingoption(ptr);
					else if(strcmp(key, "HoldPkg") == 0
							|| strcmp(upperkey, "HOLDPKG") == 0)
						pacData.HoldPkg = setrepeatingoption(ptr);
					else if (strcmp(key, "XferCommand") == 0 || strcmp(upperkey, "XFERCOMMAND") == 0)
					{
						pacData.xferCommand = (char *)malloc(strlen(ptr) * sizeof(char));
						
						strcpy(pacData.xferCommand, ptr);	
					}
											
				} 
				else if(strcmp(key, "Server") == 0 || strcmp(upperkey, "SERVER") == 0) 
				{
					/* let's attempt a replacement for the current repo */
					char *server = strreplace(ptr, "$repo", section);
					char *temp;
					
					temp = (char *)malloc(strlen(server) * sizeof(char));
					
					strcpy(temp, server);
					
					pacData.serverAssoc = alpm_list_add(pacData.serverAssoc, temp);
					
					free(server);
				}
				else 
				{
					pacData.loaded = false;
					return;
				}
			}
			free(upperkey);
		}
	}
	fclose(fp);
	if(section)
		free(section);
	if(db)
		free(db);
}

void ConfigurationParser::parsePaKmodConf()
{
	PaKmodConf newst;
	
	paKData = newst;
	
	return;
}


ConfigurationParser::ConfigurationParser()
{
	pacData.useDelta = 0;
	pacData.useSysLog = 0;
	pacData.noPassiveFTP = 0;
        pacData.xferCommand = NULL;
	pacData.loaded = false;
}

ConfigurationParser::~ConfigurationParser()
{
	
}

PacmanConf ConfigurationParser::getPacmanConf(bool forcereload = false)
{
	if(pacData.loaded && !forcereload)
		return pacData;
	
	parsePacmanConfig("/etc/pacman.conf", NULL, NULL);
	
	return pacData;
}

PaKmodConf ConfigurationParser::getPaKmodConf(bool forcereload = false)
{
	return paKData;
}
