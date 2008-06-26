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
#include "ShamanDialog.h"

#include <config.h>

#include <iostream>
#include <QApplication>
#include <QString>
#include <QSettings>
#include <QFile>
#include <QDate>
#include <QTranslator>
#include <QDebug>
#include <QSplashScreen>
#include <QtDBus>
#include <signal.h>
#include <alpm.h>

static void cleanup(int signum)
{
	if(signum==SIGSEGV)
	{
		/* write a log message and write to stderr */
		qCritical() << "Segmentation Fault! We are sorry. You probably found a bug! And you can help us solving it!";
		qCritical() << "Please report it to our bugtracker ( http://shaman.iskrembilen.com/trac ), including: when it crashed,";
		qCritical() << "Terminal output, and possibly a backtrace (use gdb for that)";
		exit(signum);
	} 
	else if((signum == SIGINT)) 
	{
		printf("\n");
		
		qCritical() << "Caught Interrupt Signal";
		
		if(alpm_trans_interrupt() == 0)
			/* a transaction is being interrupted, don't exit Shaman yet. */
			return;

		/* no committing transaction, we can release it now and then exit pacman */
		alpm_trans_release();
		
		qCritical("Shaman was terminated and all Alpm Transactions interrupted and released.");
		/* output a newline to be sure we clear any line we may be on */
		printf("\n");
	}

	/* free alpm library resources */
	if(alpm_release() == -1) {
		qCritical() << alpm_strerrorlast();
	}

	exit(signum);
}

void stdDebugOutput(QtMsgType type, const char *msg)
{
    QString rmsg;
    
    switch (type) {
	case QtDebugMsg:
		fprintf(stderr, "%s\n", msg);
		break;
	case QtWarningMsg:
	    rmsg = msg;
	    
	    if(rmsg.contains("QPixmap"))
	        return;

		fprintf(stderr, "Shaman/%s - Warning: %s\n", SHAMAN_VERSION, msg);
		break;
	case QtCriticalMsg:
		fprintf(stderr, "Shaman/%s - Critical: %s\n", SHAMAN_VERSION, msg);
		break;
	case QtFatalMsg:
		fprintf(stderr, "Shaman/%s - Fatal: %s\n", SHAMAN_VERSION, msg);
		abort();
		break;
	default:
		break;
	}
}

void noDebugOutput(QtMsgType type, const char *msg)
{
    QString rmsg;
    
    switch (type) {
	case QtDebugMsg:
		break;
	case QtWarningMsg:
	    rmsg = msg;
	    
	    if(rmsg.contains("QPixmap"))
	        return;
	    
		fprintf(stderr, "Shaman/%s - Warning: %s\n", SHAMAN_VERSION, msg);
		break;
	case QtCriticalMsg:
		fprintf(stderr, "Shaman/%s - Critical: %s\n", SHAMAN_VERSION, msg);
		break;
	case QtFatalMsg:
		fprintf(stderr, "Shaman/%s - Fatal: %s\n", SHAMAN_VERSION, msg);
		abort();
		break;
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv, QApplication::GuiClient);

	QCoreApplication::setOrganizationName("shaman");
	QCoreApplication::setOrganizationDomain("shaman.iskrembilen.com");
	QCoreApplication::setApplicationName("shaman");

	QStringList arguments = app.arguments();

	if(arguments.contains("--help") || arguments.contains("-h"))
	{
		printf("\n");
		printf("Shaman: A libalpm frontend in Qt4\n");
		printf("Command Line Options:\n\n");
		printf("  -h, --help                   shows this help and exits\n\n");
		printf("  -v, --version                shows Shaman version and exits\n");
		printf("      --qt-version             shows version of the Qt toolkit installed on the system\n"
				"                               and version of the Qt toolkit Shaman was compiled against and exits\n\n");
		printf("      --no-i18n                disables translations\n");
		printf("      --no-splashscreen        does not show the splashscreen\n\n");
		printf("      --start-in-window        shows main window on startup\n");
		printf("      --start-in-tray          starts Shaman in the system tray\n\n");
		printf("      --clear-settings         clears all Shaman settings and starts Shaman\n");
		printf("      --no-debugging-output    does not show debugging output in the terminal\n");
		printf("\n");
		return(EXIT_SUCCESS);
	}

	if(arguments.contains("--version") || arguments.contains("-v"))
	{
		printf("\n");
		printf("Shaman is version %s, built from revision %s", SHAMAN_VERSION, SHAMAN_REVISION);
		printf("\n");
		printf("\n");
		return(EXIT_SUCCESS);
	}

	if(arguments.contains("--qt-version"))
	{
		printf("\n");
		printf("This System is running Qt Version %s\n", qVersion());
		printf("Shaman was compiled against Qt Version %s\n", QT_VERSION_STR);		
		printf("\n");
		printf("\n");
		return(EXIT_SUCCESS);
	}

	if(arguments.contains("--you-suck"))
	{
		printf("\n\nOh, really?\n");
		exit(0);
	}
	if(arguments.contains("--ya-rly"))
	{
		printf("\n\nHonestly, you DO suck more than me\n");
		exit(0);
	}
	if(arguments.contains("--well-actually-not"))
	{
		printf("\n\nNo, you are a sucker. Get away from here and go kill yourself. Bitch.\n");
		exit(0);
	}

	if(arguments.contains("--no-debugging-output"))
		qInstallMsgHandler(noDebugOutput);
	else
		qInstallMsgHandler(stdDebugOutput);
	
	QTranslator translator;

	if(!arguments.contains("--no-i18n"))
	{
		QString locale = QLocale::system().name();

		qDebug() << "Translations are enabled."; 
		QString trpath(QString("shaman_") + locale);
		
		QString filePath = INSTALL_PREFIX;
		filePath.append("/share/shaman/translations/");

		if(!translator.load(trpath))
			if(!translator.load(trpath, filePath))
				if(!translator.load(trpath, "translations/"))
					qDebug() << "Could not find a translation for this locale.";
				else 
					qDebug() << "Loading translations from" << "translations/";
			else
				qDebug() << "Loading translations from" << filePath;
		else
			qDebug() << "Loading translations from" << '.';

		app.installTranslator(&translator);
	}
	else
		qWarning() << "Translations are Disabled on user request.";

	QDBusConnection testconn = QDBusConnection::systemBus();
	if(testconn.interface()->isServiceRegistered("org.archlinux.shaman"))
	{
		foreach ( QString ent, arguments )
		{
		    if ( ent.contains("pkg.tar.gz") )
		    {
		        QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman",
		                "org.archlinux.shaman", "installPackageFromFile");
		        msg << ent;
		        testconn.call(msg);
		        
		        exit(0);
		    }
		}
	    
	    ShamanDialog::popupDialog(QObject::tr("Shaman"), 
				QObject::tr("It looks like another copy of Shaman is running.\nYou can only run "
						"one copy of Shaman at a time."), NULL, ShamanProperties::ErrorDialog);

		exit(1);
	}

	AlpmHandler *aHandler = new AlpmHandler(true);

	if(!aHandler->testLibrary())
	{
		Authenticator ath;

		if(!ath.switchToRoot())
		{
			ShamanDialog::popupDialog(QObject::tr("Shaman"), QObject::tr("Shaman could not"
					" switch to root.\nProbably you have not set the SUID bit to it.\nYou can do that by "
					"issuing as root\nchown root shaman && chmod u+s shaman.\nNote that this is safe, please "
					"read Shaman wiki\nfor more details."), NULL, ShamanProperties::ErrorDialog);
			exit(1);
		}

		ShamanDialog::popupDialog(QObject::tr("Shaman"), QObject::tr("There was a problem"
				" while testing libalpm.\nMaybe another application has a lock on it."), NULL,
				ShamanProperties::ErrorDialog);

		exit(1);
	}

	QSettings *settings = new QSettings();

	if(!settings->isWritable())
	{
		ShamanDialog::popupDialog( QObject::tr("Shaman", "Hey! "
				"If you are reading this, first of all thanks for helping us in making Shaman better. "
				"There are not many comments unless where needed, since all the strings are pretty self-explanatory. "
				"You will see a lot of HTML in some cases: do not let that scare you, but please edit text only. Editing "
				"HTML tags too may break our layout, so be careful. A good practice could be copying the whole string, "
				"and then translating just what's outside the tags, usually just a few words. "
				"If you have any doubts, or if you just want to drop us a line, there goes our email addresses:\n"
				"Dario: drf54321@gmail.com\nLukas: l.appelhans@gmx.de\n"
				"Thanks again, and enjoy your translation!"), 
				QObject::tr("Your settings file seems unwritable.\nPlease check permissions on it."), NULL,
				ShamanProperties::ErrorDialog);
		
		exit(1);
	}
	
	qDebug() << settings->fileName();

	if(arguments.contains("--clear-settings"))
	{
		qWarning() << "All Settings will be cleared!";
		settings->clear();
	}

	QSplashScreen splscr(QPixmap(":/Images/images/splash.png"));

	bool showSplash = settings->value("gui/showsplashscreen", true).toBool();

	if(arguments.contains("--no-splashscreen"))
		showSplash = false;

	qDebug() << ">>";
	qDebug() << ">>		Shaman" << SHAMAN_VERSION;
	qDebug() << ">>		Compiled against Qt" << QT_VERSION_STR;
	qDebug() << ">>		Running with Qt" << qVersion();
	qDebug() << ">>";
	qDebug() << ">>	Our website is @ http://shaman.iskrembilen.com/ , join in!!";
	qDebug() << ">>	You can also find a bugtracker in the website, please use it.";
	qDebug() << ">> ";
	qDebug() << ">>    Have you found a bug? Help us solving it faster! Please read";
	qDebug() << ">>    http://shaman.iskrembilen.com/trac/wiki/Debugging_Shaman";
	qDebug() << ">>    and please follow these steps to report bugs effectively!";
	qDebug() << ">>";
	qDebug() << ">>	Starting Up Shaman...";
	qDebug() << "";

	if(showSplash)
	{
		splscr.show();
		app.processEvents();

		splscr.showMessage(QString(QObject::tr("Please Wait...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
		app.processEvents();
	}

	if(getuid() == 0)
	{
		if(settings->value("gui/noroot").toBool())
		{
			ShamanDialog::popupDialog(QObject::tr("Shaman"), 
					QObject::tr("Shaman can not be started as root.\nPlease restart it as "
							"unprivileged user."), NULL,
							ShamanProperties::ErrorDialog);

			exit(1);
		}


		ShamanDialog::popupDialogDontShow(QObject::tr("Shaman"), 
				QObject::tr("You have started Shaman as root.\nIt is advised to start it as unprivileged user.\n"
						"Shaman will ask you for root password when needed."), "gui/rootwarning", NULL,
						ShamanProperties::WarningDialog);
	}

	QString alversion(aHandler->getAlpmVersion());
	alversion[1];
	
	if(alversion[0].digitValue() <= 2 && alversion[2].digitValue() < 1)
	{
		ShamanDialog::popupDialog(QObject::tr("Shaman"), QString(QObject::tr("Pacman is not updated."
				"\nShaman needs libalpm >= 2.1.0 to run.\nYours is %1. Please update Pacman.")).arg(alversion),
				NULL, ShamanProperties::ErrorDialog);
		
		exit(1);
	}
	
	app.setQuitOnLastWindowClosed(false);

	signal(SIGINT, cleanup);
	signal(SIGTERM, cleanup);
	signal(SIGSEGV, cleanup);
	
	aHandler->setuseragent();
	
	qDebug() << "User agent is:" << qgetenv("HTTP_USER_AGENT");
	
	if(settings->value("gui/startupmode").toString() == 0)
	{
		/* Whoa! This probably means that this is either the first time we
		 * start Shaman, or the config file has gone. In both cases,
		 * let's create some reasonable defaults. And let's backup
		 * conf files too, our parser rocks, but one never knows, right?
		 */
		
		QFile::copy("/etc/pacman.conf", QString("/etc/pacman.conf.bak.").append(QDate::currentDate().toString("ddMMyyyy")));
		QFile::copy("/etc/makepkg.conf", QString("/etc/makepkg.conf.bak.").append(QDate::currentDate().toString("ddMMyyyy")));
		QFile::copy("/etc/abs.conf", QString("/etc/abs.conf.bak.").append(QDate::currentDate().toString("ddMMyyyy")));
		
		settings->setValue("gui/startupmode", "window");
		settings->setValue("scheduledUpdate/enabled", true);
		settings->setValue("scheduledUpdate/interval", 60);
		settings->setValue("scheduledUpdate/addupgradestoqueue", true);
		settings->setValue("absbuilding/clearmakedepends", true);
		settings->setValue("absbuilding/syncsupfiles", false);
		settings->setValue("gui/showsplashscreen", true);
	}

	if(settings->value("absbuilding/buildpath").toString() == 0 || !settings->contains("absbuilding/buildpath") || 
			settings->value("absbuilding/buildpath").toString() == "/")
		// This can be dangerous, so set it properly
		settings->setValue("absbuilding/buildpath", "/var/shaman/builds");

	MainWindow mainwin(aHandler);

	if(settings->contains("gui/size"))
		mainwin.resize(settings->value("gui/size").toSize());
	if(settings->contains("gui/pos"))
		mainwin.move(settings->value("gui/pos").toPoint());

	if(showSplash)
	{
		splscr.showMessage(QString(QObject::tr("Loading Databases...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
		app.processEvents();
	}

	mainwin.populateRepoColumn();

	if(showSplash)
	{
		splscr.showMessage(QString(QObject::tr("Loading Packages...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
		app.processEvents();
	}

	mainwin.populatePackagesView();

	if(showSplash)
	{
		splscr.showMessage(QString(QObject::tr("Starting up Shaman...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
		app.processEvents();
	}
	
	mainwin.setUpTrayIcon();

	if((settings->value("gui/startupmode").toString() == "window" || arguments.contains("--start-in-window")) &&
			!arguments.contains("--start-in-tray"))
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
		
		mainwin.startTrayTimer();
	}

	QObject::connect(&mainwin, SIGNAL(aboutToQuit()), &app, SLOT(quit()));
	
	if(showSplash)
		splscr.close();
	
	settings->deleteLater();
	
	qDebug() << "Log file is:" << alpm_option_get_logfile();
	
	mainwin.streamReadySignal();

	foreach ( QString ent, arguments )
	{
	    if ( ent.contains("pkg.tar.gz") )
	    {
	        mainwin.installPackageFromFile(ent);
	    }
	}
	
	return app.exec();

}
