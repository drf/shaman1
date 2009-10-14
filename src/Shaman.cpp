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

#include "Shaman.h"

#include "MainWindow.h"
#include "ShamanDialog.h"

#include <aqpm/Backend.h>

#include <config-shaman1.h>

#include <iostream>
#include <sys/utsname.h>
#include <QApplication>
#include <QString>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QDate>
#include <QDebug>
#include <QSplashScreen>
#include <QtDBus>
#include <signal.h>

using namespace Aqpm;

Shaman::Shaman(const QStringList &a)
        : m_arguments(a)
{
}

Shaman::~Shaman()
{
}

void Shaman::startShaman()
{
    // Initialize Aqpm
    Backend::instance()->safeInitialization();

    // We manage polkit auth on our own
    Backend::instance()->setShouldHandleAuthorization(false);

    if (QFile::exists("/var/lib/pacman/db.lck")) {
        ShamanDialog::popupDialog(QObject::tr("Shaman"), QObject::tr("There was a problem"
                                  " while testing libalpm.\nMaybe another application has a lock on it."), NULL,
                                  ShamanProperties::ErrorDialog);

        QCoreApplication::exit(1);
    }

    QSettings *settings = new QSettings();

    if (!settings->isWritable()) {
        ShamanDialog::popupDialog(QObject::tr("Shaman", "Hey! "
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

        QCoreApplication::exit(1);
    }

    qDebug() << settings->fileName();

    if (m_arguments.contains("--clear-settings")) {
        qWarning() << "All Settings will be cleared!";
        settings->clear();
    }

    QSplashScreen splscr(QPixmap(":/Images/images/splash.png"));

    bool showSplash = settings->value("gui/showsplashscreen", true).toBool();

    if (m_arguments.contains("--no-splashscreen"))
        showSplash = false;

    qDebug() << ">>";
    qDebug() << ">>  Shaman" << SHAMAN_VERSION;
    qDebug() << ">>  Compiled against Qt" << QT_VERSION_STR;
    qDebug() << ">>  Running with Qt" << qVersion();
    qDebug() << ">>";
    qDebug() << ">> Our website is @ http://shaman.iskrembilen.com/ , join in!!";
    qDebug() << ">> You can also find a bugtracker in the website, please use it.";
    qDebug() << ">> ";
    qDebug() << ">> Have you found a bug? Help us solving it faster! Please read";
    qDebug() << ">> http://shaman.iskrembilen.com/trac/wiki/Debugging_Shaman";
    qDebug() << ">> and please follow these steps to report bugs effectively!";
    qDebug() << ">>";
    qDebug() << ">> Starting Up Shaman...";
    qDebug() << "";

    if (showSplash) {
        splscr.show();

        splscr.showMessage(QString(QObject::tr("Please Wait...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
    }

    if (getuid() == 0) {
        ShamanDialog::popupDialog(QObject::tr("Shaman"),
                                  QObject::tr("Shaman can not be started as root. Please restart it as "
                                              "unprivileged user."), NULL,
                                  ShamanProperties::ErrorDialog);

        QCoreApplication::exit(1);
    }

    char agent[101];
    struct utsname un;

    uname(&un);
    snprintf(agent, 100, "shaman/%s (%s %s) aqpm/%s", SHAMAN_VERSION,
             un.sysname, un.machine, Backend::version().toUtf8().data());
    setenv("HTTP_USER_AGENT", agent, 0);

    qDebug() << "User agent is:" << qgetenv("HTTP_USER_AGENT");

    if (settings->value("gui/startupmode").toString() == 0) {
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

    if (settings->value("absbuilding/buildpath").toString() == 0 || !settings->contains("absbuilding/buildpath") ||
            settings->value("absbuilding/buildpath").toString() == "/") {
        // This can be dangerous, so set it properly
        settings->setValue("absbuilding/buildpath", "/var/shaman/builds");
    }

    m_mainwin = new MainWindow();

    if (settings->contains("gui/size"))
        m_mainwin->resize(settings->value("gui/size").toSize());
    if (settings->contains("gui/pos"))
        m_mainwin->move(settings->value("gui/pos").toPoint());

    if (showSplash) {
        splscr.showMessage(QString(QObject::tr("Loading Databases...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
    }

    m_mainwin->populateRepoColumn();

    if (showSplash) {
        splscr.showMessage(QString(QObject::tr("Loading Packages...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
    }

    m_mainwin->populatePackagesView();

    if (showSplash) {
        splscr.showMessage(QString(QObject::tr("Starting up Shaman...")), Qt::AlignBottom | Qt::AlignRight, Qt::white);
    }

    if (!settings->value("gui/disabletray", false).toBool()) {
        m_mainwin->setUpTrayIcon();
    }

    if ((settings->value("gui/startupmode").toString() == "window" || m_arguments.contains("--start-in-window")) &&
            !m_arguments.contains("--start-in-tray")) {
        /* case 1: we want to show Main Window
         */
        m_mainwin->show();

    } else {
        /* case 2: we don't want to show Main Window,
         * we want the program to start up in the systray
         * only.
         */

        m_mainwin->startTrayTimer();
    }

    if (showSplash)
        splscr.close();

    settings->deleteLater();

    m_mainwin->streamReadySignal();

    foreach(const QString &ent, m_arguments) {
        if (ent.contains("pkg.tar.gz")) {
            m_mainwin->installPackageFromFile(ent);
        }
    }
}
