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

#include "Shaman.h"
#include "ShamanDialog.h"

#include <config-shaman1.h>

#include <aqpm/Backend.h>

#include <iostream>
#include <sys/utsname.h>
#include <QApplication>
#include <QString>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QDate>
#include <QTranslator>
#include <QDebug>
#include <QSplashScreen>
#include <QtDBus>
#include <QIcon>
#include <signal.h>
#include <alpm.h>

#ifdef KDE4_INTEGRATION
#include <kuniqueapplication.h>
#include <kcmdlineargs.h>
#include <kaboutdata.h>
#endif

using namespace Aqpm;

static void cleanup(int signum)
{
    if (signum == SIGSEGV) {
        /* write a log message and write to stderr */
        qCritical() << "Segmentation Fault! We are sorry. You probably found a bug! And you can help us solving it!";
        qCritical() << "Please report it to our bugtracker ( http://shaman.iskrembilen.com/trac ), including: when it crashed,";
        qCritical() << "Terminal output, and possibly a backtrace (use gdb for that)";
        exit(signum);
    } else if ((signum == SIGINT)) {
        printf("\n");

        qCritical() << "Caught Interrupt Signal";

        if (alpm_trans_interrupt() == 0)
            /* a transaction is being interrupted, don't exit Shaman yet. */
            return;

        /* no committing transaction, we can release it now and then exit pacman */
        alpm_trans_release();

        qCritical("Shaman was terminated and all Alpm Transactions interrupted and released.");
        /* output a newline to be sure we clear any line we may be on */
        printf("\n");
    }

    /* free alpm library resources */
    if (alpm_release() == -1) {
        qCritical() << QString::fromLocal8Bit(alpm_strerrorlast());
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

        if (rmsg.contains("QPixmap"))
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

        if (rmsg.contains("QPixmap"))
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
#ifndef KDE4_INTEGRATION
    QApplication app(argc, argv, QApplication::GuiClient);

    QCoreApplication::setOrganizationName("shaman");
    QCoreApplication::setOrganizationDomain("shaman.iskrembilen.com");
    QCoreApplication::setApplicationName("shaman");
#else
    printf("Spawning KApplication\n");

    KAboutData aboutData("shaman", 0, ki18n("Shaman"), SHAMAN_VERSION,
                         ki18n("A Package Manager for Arch Linux"),
                         KAboutData::License_GPL,
                         ki18n("(C) 2008, Shaman Development Team"),
                         ki18n("<a href=\"mailto:shaman@chakra-project.org\">shaman@chakra-project.org</a>"));
    aboutData.addAuthor(ki18n("Dario Freddi"), ki18n("Maintainer"), "drf54321@gmail.com");
    aboutData.addAuthor(ki18n("Lukas Appelhans"), ki18n("Maintainer"), "l.appelhans@gmx.de");

    KCmdLineArgs::init(argc, argv, &aboutData);

    if (!KUniqueApplication::start()) {
        fprintf(stderr, "Shaman is already running!\n");
        return 0;
    }

    KUniqueApplication app;
    app.disableSessionManagement();
#endif

    app.setQuitOnLastWindowClosed(false);
    QIcon shamanIcon;
    shamanIcon.addFile(":/Icons/icons/shaman/hi32-app-shaman.png");
    shamanIcon.addFile(":/Icons/icons/shaman/hi48-app-shaman.png");
    shamanIcon.addFile(":/Icons/icons/shaman/hi64-app-shaman.png");
    shamanIcon.addFile(":/Icons/icons/shaman/hi128-app-shaman.png");
    app.setWindowIcon(shamanIcon);

    signal(SIGINT, cleanup);
    signal(SIGTERM, cleanup);
    signal(SIGSEGV, cleanup);

    QStringList arguments = app.arguments();

    if (arguments.contains("--help") || arguments.contains("-h")) {
        printf("\n");
        printf("Shaman: A libalpm frontend in Qt4\n");
        printf("Command Line Options:\n\n");
        printf("  -h, --help                   shows this help and exits\n\n");
        printf("  -v, --version                shows Shaman version and exits\n");
        printf("      --qt-version             shows version of the Qt toolkit installed on the system\n"
               "                               and version of the Qt toolkit Shaman was compiled against and exits\n\n");
        printf("      --no-i18n                disables translations\n");
        printf("      --force-i18n=locale      forces Shaman to use locale as language\n");
        printf("      --no-splashscreen        does not show the splashscreen\n\n");
        printf("      --start-in-window        shows main window on startup\n");
        printf("      --start-in-tray          starts Shaman in the system tray\n\n");
        printf("      --clear-settings         clears all Shaman settings and starts Shaman\n");
        printf("      --no-debugging-output    does not show debugging output in the terminal\n");
        printf("\n");
        return(EXIT_SUCCESS);
    }

    if (arguments.contains("--version") || arguments.contains("-v")) {
        printf("\n");
        printf("Shaman is version %s, built from revision %s", SHAMAN_VERSION, SHAMAN_REVISION);
        printf("\n");
        printf("\n");
        return(EXIT_SUCCESS);
    }

    if (arguments.contains("--qt-version")) {
        printf("\n");
        printf("This System is running Qt Version %s\n", qVersion());
        printf("Shaman was compiled against Qt Version %s\n", QT_VERSION_STR);
        printf("\n");
        printf("\n");
        return(EXIT_SUCCESS);
    }

    if (arguments.contains("--you-suck")) {
        printf("\n\nOh, really?\n");
        return(0);
    }
    if (arguments.contains("--ya-rly")) {
        printf("\n\nHonestly, you DO suck more than me\n");
        return(0);
    }
    if (arguments.contains("--well-actually-not")) {
        printf("\n\nNo, you are a sucker. Get away from here and go kill yourself. Bitch.\n");
        return(0);
    }

    if (arguments.contains("--no-debugging-output"))
        qInstallMsgHandler(noDebugOutput);
    else
        qInstallMsgHandler(stdDebugOutput);

    QTranslator translator;

    if (!arguments.contains("--no-i18n")) {
        QString locale;
        QSettings *settings = new QSettings();

        if (settings->value("gui/language").toString().isEmpty()) {
            locale = QLocale::system().name();
        } else {
            locale = settings->value("gui/language").toString();
        }

        settings->deleteLater();

        foreach(const QString &ent, arguments) {
            if (ent.contains("--force-i18n=")) {
                locale = ent.split('=').at(1);
            }
        }

        qDebug() << "Translations are enabled.";
        QString trpath(QString("shaman_") + locale);

        QString filePath = INSTALL_PREFIX;
        filePath.append("/share/shaman/translations/");

        if (!translator.load(trpath))
            if (!translator.load(trpath, filePath))
                if (!translator.load(trpath, "translations/"))
                    qDebug() << "Could not find a translation for this locale.";
                else
                    qDebug() << "Loading translations from" << "translations/";
            else
                qDebug() << "Loading translations from" << filePath;
        else
            qDebug() << "Loading translations from" << '.';

        app.installTranslator(&translator);
    } else {
        qWarning() << "Translations are Disabled on user request.";
    }

    QDBusConnection testconn = QDBusConnection::systemBus();
    if (testconn.interface()->isServiceRegistered("org.archlinux.shaman")) {
        foreach(const QString &ent, arguments) {
            QString path = ent;

            if (path.contains("pkg.tar.gz")) {
                if (!path.startsWith(QChar('/'))) {
                    path.prepend(QString(QDir::currentPath() + QChar('/')));
                }

                QDBusMessage msg = QDBusMessage::createMethodCall("org.archlinux.shaman", "/Shaman",
                                   "org.archlinux.shaman", "installPackageFromFile");
                msg << path;
                testconn.call(msg);

                return(0);
            }
        }

        ShamanDialog::popupDialog(QObject::tr("Shaman"),
                                  QObject::tr("It looks like another copy of Shaman is running.\nYou can only run "
                                              "one copy of Shaman at a time."), NULL, ShamanProperties::ErrorDialog);

        return(1);
    }

    Shaman *shaman = new Shaman(arguments);

    shaman->init();

    int returncode = app.exec();

    return returncode;

}
