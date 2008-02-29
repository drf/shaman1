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
#include "MainWindow.h"

#include <iostream>
#include <QApplication>
#include <QString>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QDate>
#include <QTranslator>
#include <QDebug>
#include <QSplashScreen>
#include <signal.h>
#include <sys/utsname.h>
#include <alpm.h>

#define SHAMAN_VERSION "1.0Alpha2dev"

static void cleanup(int signum)
{
	if(signum==SIGSEGV)
	{
		/* write a log message and write to stderr */
		printf("Segmentation Fault! We are sorry. Please report a bug, so we can fix that\n");
		exit(signum);
	} 
	else if((signum == SIGINT)) 
	{
		if(alpm_trans_interrupt() == 0)
			/* a transaction is being interrupted, don't exit Shaman yet. */
			return;

		/* no committing transaction, we can release it now and then exit pacman */
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

static void setuseragent(const QString &version)
{
	char agent[101];
	struct utsname un;

	uname(&un);
	snprintf(agent, 100, "shaman/" SHAMAN_VERSION " (%s %s) libalpm/%s",
			un.sysname, un.machine, version.toAscii().data());
	setenv("HTTP_USER_AGENT", agent, 0);
}

int main(int argc, char **argv)
{
	uid_t myuid = geteuid();

	QApplication app(argc, argv, QApplication::GuiClient);

	QCoreApplication::setOrganizationName("shaman");
	QCoreApplication::setOrganizationDomain("shaman.iskremblien.org");
	QCoreApplication::setApplicationName("shaman");

	QString locale = QLocale::system().name();

	QTranslator translator;
	QString trpath(QString("shaman_") + locale);
	
	if(!translator.load(trpath))
		if(!translator.load(trpath, "../share/shaman/translations/"))
			if(!translator.load(trpath, "/usr/share/shaman/translations/"))
				if(!translator.load(trpath, "/usr/local/share/shaman/translations/"))
					qDebug() << "Could not find a translation for this locale.";
	
	app.installTranslator(&translator);

	if(myuid > 0)
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Information, QObject::tr("Shaman", "Hey! "
				"If you are reading this, first of all thanks for helping us in making Shaman better. "
				"There are not many comments unless where needed, since all the strings are pretty self-explanatory. "
				"You will see a lot of HTML in some cases: do not let that scare you, but please edit text only. Editing "
				"HTML tags too may break our layout, so be careful. A good practice could be copying the whole string, "
				"and then translating just what's outside the tags, usually just a few words. "
				"If you have any doubts, or if you just want to drop us a line, there goes our email addresses:\n"
				"Dario: drf54321@gmail.com\nLukas: l.appelhans@gmx.de\n"
				"Thanks again, and enjoy your translation!"), 
				QObject::tr("You have to be root to run Shaman.\nPlease restart it with root privileges."), QMessageBox::Ok);

		message->show();

		return app.exec();
	}

	AlpmHandler *aHandler = new AlpmHandler(true);

	if(!aHandler->testLibrary())
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Information, QObject::tr("Shaman"), QObject::tr("There was a problem"
				" while testing libalpm.\nMaybe another application has a lock on it."), QMessageBox::Ok);

		message->show();

		return app.exec();
	}

	QString alversion(aHandler->getAlpmVersion());
	alversion[1];
	
	if(alversion[0].digitValue() <= 2 && alversion[2].digitValue() < 1)
	{
		QMessageBox *message = new QMessageBox(QMessageBox::Information, QObject::tr("Shaman"), QString(QObject::tr("Your pacman is not updated."
				"\nShaman needs libalpm >= 2.1.0 to run.\nYours is %. Please update Pacman.")).arg(alversion), QMessageBox::Ok);

		message->show();

		return app.exec();
	}
	
	app.setQuitOnLastWindowClosed(false);

	QSplashScreen splscr(QPixmap(":/Images/images/splash.png"));
	splscr.show();
	app.processEvents();
	
	splscr.showMessage(QString(QObject::tr("Please Wait...")), Qt::AlignBottom | Qt::AlignRight);
	app.processEvents();

	signal(SIGINT, cleanup);
	signal(SIGTERM, cleanup);
	signal(SIGSEGV, cleanup);
	
	setuseragent(aHandler->getAlpmVersion());
	
	qDebug() << "User agent is:" << qgetenv("HTTP_USER_AGENT");
	
	QSettings *settings = new QSettings();
	
	if(settings->value("gui/startupmode").toString() == 0)
	{
		/* Whoa! This probably means that this is either the first time we
		 * start Shaman, or the config file has gone. In both cases,
		 * let's create some reasonable defaults. And let's backup
		 * conf files too, our parser rocks, but one never knows, right?
		 */
		
		QFile::copy("/etc/pacman.conf", QString("/etc/pacman.conf.bak.").append(QDate::currentDate().toString("ddMMyyyy")));
		QFile::copy("/etc/makepkg.conf", QString("/etc/makepkg.conf.bak.").append(QDate::currentDate().toString("ddMMyyyy")));
		QFile::copy("/etc/abs/abs.conf", QString("/etc/abs/abs.conf.bak.").append(QDate::currentDate().toString("ddMMyyyy")));
		
		settings->setValue("gui/startupmode", "window");
		settings->setValue("scheduledUpdate/enabled", true);
		settings->setValue("scheduledUpdate/interval", 10);
		settings->setValue("scheduledUpdate/addupgradestoqueue", true);
		settings->setValue("absbuilding/clearmakedepends", true);
		settings->setValue("absbuilding/syncsupfiles", false);
	}

	if(settings->value("absbuilding/buildpath").toString() == 0 || !settings->contains("absbuilding/buildpath"))
		// This can be dangerous, so set it properly
		settings->setValue("absbuilding/buildpath", "/var/shaman/builds");

	settings->deleteLater();

	MainWindow mainwin(aHandler);

	splscr.showMessage(QString(QObject::tr("Loading Databases...")), Qt::AlignBottom | Qt::AlignRight);
	app.processEvents();

	mainwin.populateRepoColumn();

	splscr.showMessage(QString(QObject::tr("Loading Packages...")), Qt::AlignBottom | Qt::AlignRight);
	app.processEvents();

	mainwin.populatePackagesView();

	splscr.showMessage(QString(QObject::tr("Starting up Shaman...")), Qt::AlignBottom | Qt::AlignRight);
	app.processEvents();

	if(settings->value("gui/startupmode").toString() == "window")
	{
		/* case 1: we want to show Main Window
		 */
		mainwin.show();
		
	}
	else
	{
		/* case 2: we don't want to show Main Window,
		 * we want the program to start up in the systray
		 * only.
		 */
		
		mainwin.startTimer();
	}

	QObject::connect(&mainwin, SIGNAL(aboutToQuit()), &app, SLOT(quit()));
	splscr.close();
	return app.exec();

}

