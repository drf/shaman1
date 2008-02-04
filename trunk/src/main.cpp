/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                                                    *
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

#include "AlpmHandler.h"
#include "alpm_list.h"
#include "MainWindow.h"

#include <iostream>
#include <QApplication>

int main(int argc, char **argv)
{
	uid_t myuid = geteuid();
	
	if(myuid > 0)
	{	
		/* TODO: Create a popup that tells the user he has
		 * to be root, then return. */
		
		printf("Sorry, you have to be root to run qtPacman.\n");
		return 0;
	}

	QApplication app(argc, argv);

	AlpmHandler *aHandler = new AlpmHandler(true);
	
	MainWindow mainwin(aHandler);
	
	mainwin.show();
	mainwin.populateRepoColumn();
	
	mainwin.populatePackagesView();
	return app.exec();
	
}

