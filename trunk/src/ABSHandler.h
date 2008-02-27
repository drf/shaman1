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

#ifndef ABSHANDLER_H_
#define ABSHANDLER_H_

#include <QString>

class ABSHandler
{
	
	/* This class is an abstraction to the Arch Build System.
	 * There are not so many methods, anyway it can search for
	 * a package in the ABS path, and set up and clean up
	 * local building environments. It can also get some useful
	 * informations about PKGBUILDs. It is a stripped parsed, just
	 * to suit our needs.
	 * 
	 * Some of its functions are static, it is ridiculous to inherit a 
	 * class or create an object just to pick a path, so getMakeDepends
	 * and getABSPath are static.
	 */
	
public:
	ABSHandler();
	virtual ~ABSHandler();

	static QString getABSPath(const QString &package);
	bool setUpBuildingEnvironment(const QString &package);
	bool cleanBuildingEnvironment(const QString &package);
	bool cleanAllBuildingEnvironments();
	static QStringList getMakeDepends(const QString &package);
	
private:
	int rmrf(const char *path);

};

#endif /*ABSHANDLER_H_*/
