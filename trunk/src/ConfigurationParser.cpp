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
#include <stdlib.h> /* atoi */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h> /* time_t */
#include <QtGui>

#include "ConfigurationParser.h"

using namespace std;

alpm_list_t *ConfigurationParser::setrepeatingoption(QString ptr)
{
	QStringList strlist;
	alpm_list_t *list = NULL;

	strlist = ptr.split(" ", QString::SkipEmptyParts);
	
	for (int i = 0; i < strlist.size(); ++i)
	{
		char *dest = (char *)malloc(strlist.at(i).length()*sizeof(char));
		strcpy(dest, strlist.at(i).toAscii().data());
		
		list = alpm_list_add(list, dest);
	}
		
	return list;
}

void ConfigurationParser::parsePacmanConfig(QString file, QString givensection,
		QString givendb)
{
	QFile fp(file);
	QString line, db(NULL), section(NULL);
	int linenum = 0, serverparsed = 0;
		
	if(!pacData.loaded)
	{
		pacData.syncdbs = NULL;
		pacData.serverAssoc = NULL;
	}
	
	pacData.loaded = true;

	if(!fp.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		pacData.loaded = false;
		return;
	}
	
	QTextStream in(&fp);

	/* if we are passed a section, use it as our starting point */
	if(givensection != NULL) 
		section.operator=(givensection);	
		
	/* if we are passed a db, use it as our starting point */
	if(givendb != NULL)
		db.operator=(givendb);

	while(!in.atEnd()) 
	{
		line = in.readLine();
		linenum++;
		//strtrim(line);
		while(line.contains('\n'))
			line.remove(line.indexOf('\n'), 1);

		/* ignore whole line and end of line comments */
		if(line.length() == 0 || line.startsWith('#')) 
			continue;

		if(line.indexOf("#") != -1) 
			line.truncate(line.indexOf("#"));

		if(line.startsWith('[') && line.endsWith(']')) 
		{
			/* new config section, skip the '[' */
			line.remove(0,1);
			line.remove(line.length()-1, line.length());
			section.operator=(line);
			while(section.contains(' '))
				section.remove(section.indexOf(' '), 1);
			/*ptr = line;
			ptr++;
			if(section)
				free(section);
				
			section = strdup(ptr);
			section[strlen(section)-1] = '\0';
			if(!strlen(section))
			{
				pacData.loaded = false;
				return;
			}*/
			
			/* if we are not looking at the options section, register a db and also
			 * ensure we have set all of our library paths as the library is too stupid
			 * at the moment to do lazy opening of the databases */
			
			if(section.operator!=("options"))
			{
				char *dest = (char *)malloc(section.length()*sizeof(char));
				strcpy(dest, section.toAscii().data());
				pacData.syncdbs = alpm_list_add(pacData.syncdbs, dest);
				serverparsed = 0;
								
				db.operator=(line);
			}
		}
		else 
		{
			/* directive */
			QString key;
			QStringList templst;
			/* strsep modifies the 'line' string: 'key \0 ptr' */
			templst = line.split("=");
			if(templst.size() != 2)
			{
				pacData.loaded = false;
				
				return;
			}
			key.operator=(templst.at(0));
			line.operator=(templst.at(1));

			if(key == NULL)
			{
				pacData.loaded = false;
				return;
			}
			
			if(section == NULL) 
			{
				pacData.loaded = false;
				return;
			}
			
			while(key.contains(' '))
				key.remove(key.indexOf(' '), 1);

			if(line == NULL && section.compare("options", Qt::CaseInsensitive) == 0) 
			{
				/* directives without settings, all in [options] */
				if(key.compare("NoPassiveFTP", Qt::CaseInsensitive) == 0)
					pacData.noPassiveFTP = 1;
				else if(key.compare("UseSyslog", Qt::CaseInsensitive) == 0)
					pacData.useSysLog = 1;
				else if(key.compare("UseDelta", Qt::CaseInsensitive) == 0)
					pacData.useDelta = 1; 
				
			}
			else
			{
				/* directives with settings */
				if(key.compare("Include", Qt::CaseInsensitive) == 0)
				{
					while(line.contains(' '))
						line.remove(line.indexOf(' '), 1);
					parsePacmanConfig(line, section, db);
					if(!pacData.loaded)
					{
						pacData.loaded = false;
						
						return;
					}
				}
					/* Ignore include failures... assume non-critical */
				else if(section.compare("options", Qt::CaseInsensitive) == 0)
				{
					if(key.compare("NoUpgrade", Qt::CaseInsensitive) == 0)
						pacData.NoUpgrade = setrepeatingoption(line);
					else if(key.compare("NoExtract", Qt::CaseInsensitive) == 0)
						pacData.NoExtract = setrepeatingoption(line);
					else if(key.compare("IgnorePkg", Qt::CaseInsensitive) == 0)
						pacData.IgnorePkg = setrepeatingoption(line);
					else if(key.compare("IgnoreGroup", Qt::CaseInsensitive) == 0)
						pacData.IgnoreGrp = setrepeatingoption(line);
					else if(key.compare("HoldPkg", Qt::CaseInsensitive) == 0)
						pacData.HoldPkg = setrepeatingoption(line);
					else if (key.compare("XferCommand", Qt::CaseInsensitive) == 0)
					{
						pacData.xferCommand = line.toAscii().data();	
					}
											
				} 
				else if(key.compare("Server", Qt::CaseInsensitive) == 0) 
				{
					if(serverparsed == 1)
						continue;
					
					serverparsed = 1;
					/* let's attempt a replacement for the current repo */
					while(line.contains(' '))
						line.remove(line.indexOf(' '), 1);
					
					
					if(line.contains('$'))
					{
						QStringList tmplst = line.split(QString("$repo"), 
								QString::SkipEmptyParts, Qt::CaseInsensitive);
						char *dest = (char *)malloc((tmplst.at(0).length() + 
								section.length() + tmplst.at(1).length())*sizeof(char));
						strcpy(dest, tmplst.at(0).toAscii().data());
						strcat(dest, section.toAscii().data());
						strcat(dest, tmplst.at(1).toAscii().data());
						pacData.serverAssoc = alpm_list_add(pacData.serverAssoc, dest);
					}
					else
					{
						char *dest = (char *)malloc(line.length()*sizeof(char));
						strcpy(dest, line.toAscii().data());
						pacData.serverAssoc = alpm_list_add(pacData.serverAssoc, dest);
					}
				}
				else 
				{
					pacData.loaded = false;
					return;
				}
			}
		}
	}
	fp.close();
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
    pacData.IgnoreGrp = NULL;
    pacData.IgnorePkg = NULL;
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
