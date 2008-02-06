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

void ConfigurationParser::parsePacmanConfig(QString file, QString givendb)
{
	QSettings *settings = new QSettings(file, QSettings::NativeFormat);
	
	QString db(NULL);
	int serverparsed = 0;
	
	pacData.loaded = true;
		
	/* if we are passed a db, use it as our starting point */
	if(givendb != NULL)
		db.operator=(givendb);

	foreach(QString str, settings->allKeys())
	{
		if(!str.contains("options") && str.contains("/") && !str.contains("#"))
		{
			// Oooh, it's a database!
			QStringList splitted = str.split('/');
			pacData.syncdbs.append(splitted.at(0));
			db.operator=(splitted.at(0));
			serverparsed = 0;
			
			if(!splitted.at(1).compare("Server"))
			{

				if(settings->value(str).toString().contains('$'))
				{
					QStringList tmplst = settings->value(str).toString().split(QString("$repo"), 
							QString::SkipEmptyParts, Qt::CaseInsensitive);
					
					QString dserv(tmplst.at(0));
					
					dserv.append(str);
					dserv.append(tmplst.at(1));
					pacData.serverAssoc.append(dserv);
				}
				else
					pacData.serverAssoc.append(settings->value(str).toString());
				
				serverparsed = 1;
			}
			
			
			if(!splitted.at(1).compare("Include"))
				parsePacmanConfig(settings->value(str).toString(), db);
		}
	}

	if(settings->contains("options/NoPassiveFTP"))
		pacData.noPassiveFTP = 1;
	if(settings->contains("options/UseSyslog"))
		pacData.useSysLog = 1;
	if(settings->contains("options/UseDelta"))
		pacData.useDelta = 1; 

	if(settings->contains("options/Include"))
	{
		parsePacmanConfig(settings->value("options/Include").toString(), db);
		if(!pacData.loaded)
		{
			pacData.loaded = false;

			return;
		}
	}
	if(settings->contains("options/NoUpgrade"))
		pacData.NoUpgrade = setrepeatingoption(settings->value("options/NoUpgrade").toString());
	if(settings->contains("options/NoExtract"))
		pacData.NoExtract = setrepeatingoption(settings->value("options/NoExtract").toString());
	if(settings->contains("options/IgnorePkg"))
		pacData.IgnorePkg = setrepeatingoption(settings->value("options/IgnorePkg").toString());
	if(settings->contains("options/IgnoreGroup"))
		pacData.IgnoreGrp = setrepeatingoption(settings->value("options/IgnoreGroup").toString());
	if(settings->contains("options/HoldPkg"))
		pacData.HoldPkg = setrepeatingoption(settings->value("options/HoldPkg").toString());
	if(settings->contains("options/XferCommand"))
		pacData.xferCommand = settings->value("options/XferCommand").toString().toAscii().data();


	if(settings->contains("Server")) 
	{
		if(serverparsed != 1)
		{
			if(settings->value("Server").toString().contains('$'))
			{
				QStringList tmplst = settings->value("Server").toString().split(QString("$repo"), 
						QString::SkipEmptyParts, Qt::CaseInsensitive);

				QString dserv(tmplst.at(0));

				dserv.append(db);
				dserv.append(tmplst.at(1));
				pacData.serverAssoc.append(dserv);
			}
			else
				pacData.serverAssoc.append(settings->value("Server").toString());

		}
		serverparsed = 1;
	}
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
	
	parsePacmanConfig("/etc/pacman.conf", NULL);
	
	return pacData;
}

PaKmodConf ConfigurationParser::getPaKmodConf(bool forcereload = false)
{
	return paKData;
}
