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
#include <QString>
#include <QSettings>
#include <signal.h>

static void cleanup(int signum)
{
	if(signum==SIGSEGV)
	{
		/* write a log message and write to stderr */
		printf("Segmentation Fault! We're sorry. Please report a bug, so we can fix that\n");
		exit(signum);
	} 
	else if((signum == SIGINT)) 
	{
		if(alpm_trans_interrupt() == 0)
			/* a transaction is being interrupted, don't exit qtPacman yet. */
			return;

		/* no commiting transaction, we can release it now and then exit pacman */
		alpm_trans_release();
		/* output a newline to be sure we clear any line we may be on */
		printf("\n");
	}

	/* free alpm library resources */
	if(alpm_release() == -1) {
		printf("%s", alpm_strerrorlast());
	}

	exit(signum);
}

int main(int argc, char **argv)
{
	uid_t myuid = geteuid();

	QApplication app(argc, argv);

	if(myuid > 0)
	{	
		/* TODO: Add translation */

		QMessageBox *message = new QMessageBox(QMessageBox::Information, "qtPacman", "You have to be root to run qtPacman.\nPlease restart it with root privileges.", QMessageBox::Ok);

		message->show();

		return app.exec();
	}

	AlpmHandler *aHandler = new AlpmHandler(true);

	if(!aHandler->testLibrary())
	{
		/* TODO: Add translation, Give the dialog the 
		 * ability to clean up pacman cache?
		 */

		QMessageBox *message = new QMessageBox(QMessageBox::Information, "qtPacman", "There was a problem while testing libalpm.\n Maybe another"
				"application has a lock on it.", QMessageBox::Ok);

		message->show();

		return app.exec();
	}

	signal(SIGINT, cleanup);
	signal(SIGTERM, cleanup);
	signal(SIGSEGV, cleanup);
	
	QSettings *settings = new QSettings(QSettings::SystemScope, "qtPacman", "qtPacman");
	
	if(settings->value("gui/startupmode").toString() == 0)
	{
		/* Whoa! This probably means that this is either the first time we
		 * start qtPacman, or the config file has gone. In both cases,
		 * let's create some reasonable defaults.
		 */
		settings->setValue("gui/startupmode", "window");
	}
	
	settings->deleteLater();

	MainWindow mainwin(aHandler);

	if(settings->value("gui/startupmode").toString() == "window")
	{
		/* case 1: we want to show Main Window
		 */
		mainwin.show();
		
	}
	else
	{
		/* TODO: case 2: we don't want to show Main Window,
		 * we want the program to start up in the systray
		 * only.
		 */
	}

	mainwin.populateRepoColumn();

	mainwin.populatePackagesView();
	return app.exec();

}

