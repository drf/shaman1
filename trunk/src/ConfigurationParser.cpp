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
#include "ConfigurationParser.h"

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

#include <QSettings>
#include <QFile>
#include <QTextStream>

using namespace std;

alpm_list_t *ConfigurationParser::setrepeatingoption(const QString &ptr)
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

void ConfigurationParser::parsePacmanConfig(const QString &file, const QString &givensection,
		const QString &givendb)
{
	QFile fp(file);
	QString line, db(NULL), section(NULL);
	int linenum = 0, serverparsed = 0;

	if(!pacData.loaded)
	{
		pacData.syncdbs.clear();
		pacData.serverAssoc.clear();
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
			
			if(section.operator!=("options"))
			{
				QString toAdd(section);
				pacData.syncdbs.append(toAdd);
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
						QString toAdd(tmplst.at(0));
						
						toAdd.append(section);
						toAdd.append(tmplst.at(1));

						pacData.serverAssoc.append(toAdd);
					}
					else
					{
						pacData.serverAssoc.append(line);
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

bool ConfigurationParser::editPacmanKey(const QString &key, const QString &value, int action)
{
	QFile fp("/etc/pacman.conf");
	QStringList list(key.split("/")), fileContent;
	QString key1(list.at(0)), key2(list.at(1)), realVal;

	if(!fp.open(QIODevice::ReadWrite | QIODevice::Text))
		return false;

	QTextStream in(&fp);
	
	if(value != NULL)
	{
		if(value.contains('$'))
		{
			QStringList tmplst = value.split(QString("$repo"), 
					QString::SkipEmptyParts, Qt::CaseInsensitive);
			QStringList tmp2lst = key.split(QString("/"), 
					QString::SkipEmptyParts, Qt::CaseInsensitive);

			QString dserv(tmplst.at(0));

			dserv.append(tmp2lst.at(0));
			dserv.append(tmplst.at(1));
			realVal = dserv;
		}
		else
			realVal = value;
	}
	while(!in.atEnd()) 
	{
		QString line(in.readLine());
		fileContent.append(line);
	}
	
	fp.close();
	
	if(action == 0)
	{
		// Add
		if(key1.compare("options"))
		{
			QString toFind("[");
			toFind.append(key1);
			toFind.append("]");
			if(!fileContent.filter(toFind).isEmpty())
			{
				for(int i=0; i < fileContent.size(); ++i)
				{
					if(!fileContent.at(i).startsWith(toFind))
						continue;

					for(int j=i+1; j < fileContent.size(); ++j)
					{
						if(fileContent.at(j).startsWith("["))
							break;

						if(fileContent.at(j).startsWith(key2))
							return false;
					}
					QString toAdd2(key2);
					toAdd2.append("=");
					toAdd2.append(realVal);
					fileContent.insert(i+1, toAdd2);

					QFile::remove("/etc/pacman.conf");
					if(!fp.open(QIODevice::ReadWrite | QIODevice::Text))
						return false;

					QTextStream str(&fp);

					for(int i=0; i < fileContent.size(); ++i)
						str << fileContent.at(i) << endl;

					fp.close();
					return true;

				}
			}
			
			QString toAdd("[");
			toAdd.append(key1);
			toAdd.append("]");
			fileContent.append(toAdd);
			QString toAdd2(key2);
			toAdd2.append("=");
			toAdd2.append(realVal);
			fileContent.append(toAdd2);

			QFile::remove("/etc/pacman.conf");
			if(!fp.open(QIODevice::ReadWrite | QIODevice::Text))
				return false;
			
			QTextStream str(&fp);
			
			for(int i=0; i < fileContent.size(); ++i)
				str << fileContent.at(i) << endl;
			
			fp.close();
			
			return true;
		}
		else
		{
			for(int i=0; i < fileContent.size(); ++i)
				if(fileContent.at(i).startsWith(key2))
					return false;
			
			for(int i=0; i < fileContent.size(); ++i)
			{
				if(!fileContent.at(i).startsWith("[options]"))
					continue;
				QString toAdd(key2);
				toAdd.append("=");
				toAdd.append(realVal);
				fileContent.insert(i+1, toAdd);
				
				QFile::remove("/etc/pacman.conf");
				if(!fp.open(QIODevice::ReadWrite | QIODevice::Text))
					return false;

				QTextStream str(&fp);

				for(int i=0; i < fileContent.size(); ++i)
					str << fileContent.at(i) << endl;

				fp.close();
				return true;
				
			}
			return false;
		}
		
		return false;

	}
	else if(action == 1)
	{
		//Edit
		QString toFindE("[");
		toFindE.append(key1);
		toFindE.append("]");
		if(fileContent.filter(toFindE).isEmpty())
			return false;
		
		int found = 0;
		
		for(int i=0; i < fileContent.size(); ++i)
		{
			if(!fileContent.at(i).startsWith(toFindE) && found == 0)
				continue;
			
			found = 1;
			printf("here\n");
			if(fileContent.at(i).startsWith(toFindE))
				continue;
			
			if(fileContent.at(i).startsWith("["))
				return false;
			
			printf("done\n");
			
			if(fileContent.at(i).startsWith(key2))
			{
				QString toAdd(key2);
				toAdd.append("=");
				toAdd.append(realVal);
				if(fileContent.at(i).contains(realVal))
					return false;
				fileContent.replace(i, toAdd);

				QFile::remove("/etc/pacman.conf");
				if(!fp.open(QIODevice::ReadWrite | QIODevice::Text))
					return false;

				QTextStream str(&fp);

				for(int i=0; i < fileContent.size(); ++i)
					str << fileContent.at(i) << endl;

				fp.close();
				return true;
			}
		}

		return false;	
	}
	else if(action == 2)
	{
		//Remove
		QString toFindE("[");
		toFindE.append(key1);
		toFindE.append("]");
		if(fileContent.filter(toFindE).isEmpty())
			return false;

		int found = 0, i = 0;

		for(i=0; i < fileContent.size(); ++i)
		{
			if(!fileContent.at(i).startsWith(toFindE) && found == 0)
				continue;

			found = 1;
			
			int removeroot = 1;
			bool changed = false;
			for(int j=i+1; j < fileContent.size(); ++j)
			{
				if(fileContent.at(j).startsWith("["))
					break;
				
				if(!fileContent.at(j).startsWith(key2) && !fileContent.at(j).startsWith("#")
						&& !fileContent.at(j).isEmpty())
					removeroot = 0;

				if(fileContent.at(j).startsWith(key2))
				{
					fileContent.removeAt(j);

					QFile::remove("/etc/pacman.conf");
					if(!fp.open(QIODevice::ReadWrite | QIODevice::Text))
						return false;

					QTextStream str(&fp);

					for(int k=0; k < fileContent.size(); ++k)
						str << fileContent.at(k) << endl;

					fp.close();
					changed = true;
					break;
				}
			}
			
			if(removeroot == 1)
			{
				fileContent.removeAt(i);

				QFile::remove("/etc/pacman.conf");
				if(!fp.open(QIODevice::ReadWrite | QIODevice::Text))
					return false;

				QTextStream str(&fp);

				for(int k=0; k < fileContent.size(); ++k)
					str << fileContent.at(k) << endl;

				fp.close();
				return true;
			}
			
			if(changed == false)
				return false;
			
			return true;
		}

		return false;
	}
	else
		return false;
	
	return false;
}

ConfigurationParser::ConfigurationParser()
{
	pacData.useDelta = 0;
	pacData.useSysLog = 0;
	pacData.noPassiveFTP = 0;
    pacData.xferCommand = NULL;
    pacData.IgnoreGrp = NULL;
    pacData.IgnorePkg = NULL;
    pacData.NoExtract = NULL;
    pacData.NoUpgrade = NULL;
	pacData.loaded = false;
}

ConfigurationParser::~ConfigurationParser()
{
	
}

PacmanConf ConfigurationParser::getPacmanConf(bool forcereload = false)
{
	if(pacData.loaded && !forcereload)
		return pacData;
	
	pacData.syncdbs.clear();
	pacData.serverAssoc.clear();

	pacData.useDelta = 0;
	pacData.useSysLog = 0;
	pacData.noPassiveFTP = 0;
	pacData.xferCommand = NULL;
	pacData.IgnoreGrp = NULL;
	pacData.IgnorePkg = NULL;
	pacData.NoExtract = NULL;
	pacData.NoUpgrade = NULL;
	pacData.loaded = false;
	
	parsePacmanConfig("/etc/pacman.conf", NULL, NULL);
	
	return pacData;
}
