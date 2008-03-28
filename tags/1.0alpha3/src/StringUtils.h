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

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <iostream>
#include <string.h>

#include <alpm_list.h>

class StringUtils
{
	
public:
	StringUtils();
	virtual ~StringUtils();
	
protected:
	char *strtoupper(char *str);
	char *strtrim(char *str);
	static void _strnadd(char **str, const char *append, unsigned int count);
	char *strreplace(const char *str, const char *needle, const char *replace);
	alpm_list_t *strsplit(const char *str, const char splitchar);
};

#endif /*STRINGUTILS_H_*/
