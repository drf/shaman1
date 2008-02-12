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

#ifndef CONFIGURATIONPARSER_H_
#define CONFIGURATIONPARSER_H_

#include <iostream>
#include <string>
#include <alpm.h>
#include <alpm_list.h>
#include <string.h>

#include <QStringList>

#include "StringUtils.h"

using namespace std;

struct PcCnf {
	QStringList syncdbs;
	alpm_list_t *NoUpgrade;
	alpm_list_t *NoExtract;
	alpm_list_t *IgnorePkg;
	alpm_list_t *IgnoreGrp;
	alpm_list_t *HoldPkg;
	int noPassiveFTP;
	int useDelta;
	int useSysLog;
	char *xferCommand;
	QStringList serverAssoc;
	bool loaded;
};

struct PkCnf {
	string somefield;
};

typedef struct PcCnf PacmanConf;
typedef struct PkCnf PaKmodConf;

class ConfigurationParser : private StringUtils
{
	
public:
	ConfigurationParser();
	virtual ~ConfigurationParser();
	
	PacmanConf getPacmanConf(bool forcereload);
	PaKmodConf getPaKmodConf(bool forcereload);
	
	bool editPacmanKey(const QString &key, const QString &value, int action);
	
protected:
	alpm_list_t *setrepeatingoption(const QString &ptr);
	
private:
	void parsePacmanConfig(const QString &file, const QString &givendb);
	void parsePaKmodConf();
	
private:
	PacmanConf pacData;
	PaKmodConf paKData;
};

#endif /*CONFIGURATIONPARSER_H_*/
