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
        //FIXME: Translate everything in this file to english
	uid_t myuid = geteuid();
	
	if(myuid > 0)
	{	
		printf("Ehi ehi stronzo ma dove credi di andare? Solo root può farlo\n");
		return 1;
	}

	QApplication app(argc, argv);

	AlpmHandler *aHandler = new AlpmHandler(true);
	alpm_list_t *getpkg;
	
	MainWindow mainwin(aHandler);
	
	mainwin.show();
	
	//mainwin.populatePackagesView();
	mainwin.populateRepoColumn();
	
	return app.exec();
	
	printf("Il database locale ha %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, NULL, true)));
	printf("In core ci sono %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, "core", false)));
	printf("In extra ci sono %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, "extra", false)));
	printf("In sblub ci sono %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, "sblub", false)));
	printf("In totale sono disponibili %d pacchetti\n", alpm_list_count(aHandler->searchPackages(NULL, NULL, false)));
	
	aHandler->updateDatabase();
	
		printf("Minchiazzzio allora mo aggiorno\n");
		
		getpkg = aHandler->getUpgradeablePackages();
		
		if(getpkg == NULL)
			printf("Nulla di nulla zio\n");
		else
			printf("Ouch\n");
	
		printf("Nulla da fare qui.\n");
	
	
	sleep(1);
	
	//return 0;
}

