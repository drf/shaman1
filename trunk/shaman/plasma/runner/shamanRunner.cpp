/*
 *   Copyright (C) 2008 by Lukas Appelhans				   				   
 *   l.appelhans@gmx.de		
 *   Copyright (C) 2008 by Dario Freddi                                    
 *   drf54321@yahoo.it                                                     					   						   
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License version 2 as
 *   published by the Free Software Foundation
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "shamanRunner.h"

#include <KIcon>
#include <KLocale>
#include <KDebug>
#include <KRun>
#include <QDBusInterface>
#include <QDBusConnectionInterface>

ShamanRunner::ShamanRunner(QObject *parent, const QVariantList &args)
    : Plasma::AbstractRunner(parent, args),
    dbus(QDBusConnection::systemBus())
{
    Q_UNUSED(args)

    words << "install" << "remove" << "uninstall" << "upgrade-system" << "upgrade system" << "update database" 
                            << "update db" << "update-db" << "update-database" << "us" << "ud" << "i" << "r" 
                            << "complete-remove" << "complete-uninstall" << "pm" << "shaman" << "package manager";
    
    setObjectName(i18n("Shaman Package Manager"));
}

ShamanRunner::~ShamanRunner()
{
}

void ShamanRunner::match(Plasma::RunnerContext *search)
{
    kDebug() << "Match search context?";
    QString term = search->query();

    foreach(QString word, words)
    {
    	if (term.startsWith(word, Qt::CaseInsensitive))
    	{
    		if (word == "update database" || word == "update db" || 
    				word == "update-db" || word == "update-database" || 
    				word == "ud")
    		{
    			Plasma::QueryMatch* match = new Plasma::QueryMatch(this);
    			match->setType(Plasma::QueryMatch::ExactMatch);
    			
    			match->setIcon(QIcon(":/Icons/icons/shaman/shaman-yellow-icon-32.png"));
    			match->setText(i18n("Update Databases"));
    			
    			match->setRelevance(1);
    			search->addMatch(term, match);
    		}
    		else if (word == "upgrade-system" || word == "upgrade system" ||
    				word == "us")
    		{
    			Plasma::QueryMatch* match = new Plasma::QueryMatch(this);
    			match->setType(Plasma::QueryMatch::ExactMatch);

    			match->setIcon(QIcon(":/Icons/icons/shaman/shaman-system-is-up-to-date-32.png"));
    			match->setText(i18n("Upgrade System"));

    			match->setRelevance(1);
    			search->addMatch(term, match);
    		}
    		else if (word == "install" || word == "i")
    		{
    			if(term.split(' ').count() < 2)
    				return;
    			
    			Plasma::QueryMatch* match = new Plasma::QueryMatch(this);
    			match->setType(Plasma::QueryMatch::ExactMatch);

    			match->setIcon(QIcon(":/Icons/icons/shaman/shaman-32.png"));
    			
    			if(term.split(' ').count() == 2)
    				match->setText(i18n("Install %1", term.split(' ').at(1)));
    			else
    			{
    				QString textA = i18n("Install Packages: %1", term.split(' ').at(1));
    				
    				for(int i = 2; i < term.split(' ').count(); i++)
    					textA.append(QString(", %1").arg(term.split(' ').at(i)));
    				
    				match->setText(textA);
    			}

    			match->setRelevance(1);
    			search->addMatch(term, match);
    		}
    		else if (word == "remove" || word == "r")
    		{
    			if(term.split(' ').count() < 2)
    				return;

    			Plasma::QueryMatch* match = new Plasma::QueryMatch(this);
    			match->setType(Plasma::QueryMatch::ExactMatch);

    			match->setIcon(QIcon(":/Icons/icons/shaman/shaman-updates-available-32.png"));

    			if(term.split(' ').count() == 2)
    				match->setText(i18n("Remove %1", term.split(' ').at(1)));
    			else
    			{
    				QString textA = i18n("Remove Packages: %1", term.split(' ').at(1));

    				for(int i = 2; i < term.split(' ').count(); i++)
    					textA.append(QString(", %1").arg(term.split(' ').at(i)));

    				match->setText(textA);
    			}

    			match->setRelevance(1);
    			search->addMatch(term, match);
    		}
    		else if (word == "pm" || word == "shaman" || 
    				word == "package manager")
    		{
    			Plasma::QueryMatch* match = new Plasma::QueryMatch(this);
    			match->setType(Plasma::QueryMatch::ExactMatch);

    			match->setIcon(QIcon(":/Icons/icons/shaman/shaman-32.png"));
    			match->setText(i18n("Start Package Manager"));

    			match->setRelevance(1);
    			search->addMatch(term, match);
    		}
    		else
    		{
    			Plasma::QueryMatch* match = new Plasma::QueryMatch(this);
    			match->setType(Plasma::QueryMatch::ExactMatch);
    			
    			match->setIcon(QIcon(":/Icons/icons/shaman/shaman-32.png"));
    			match->setText(i18n("Package Manager: %1", term));
    			
    			match->setRelevance(1);
    			search->addMatch(term, match);
    		}  		
    	}
    }
}

void ShamanRunner::run(const Plasma::RunnerContext *context, const Plasma::QueryMatch *action)
{
    Q_UNUSED(action);
	
	execTerm = context->query();
    
    /* First of all, let's check if Shaman has been already
     * started.
     */
    
    if(!dbus.interface()->isServiceRegistered("org.archlinux.shaman"))
    	startShaman();
    else
    	executeAction();
}

void ShamanRunner::executeAction()
{
	dbus.disconnect("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", 
			"shamanReady", this, SLOT(executeAction()));

	if (execTerm.startsWith("install", Qt::CaseInsensitive) || 
			execTerm.startsWith("i ", Qt::CaseInsensitive))
	{
		if (execTerm.split(' ').count() <= 1)
			return;

		QDBusInterface iface("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", QDBusConnection::systemBus());

		for(int i = 1; i < execTerm.split(' ').size(); i++)
			iface.call("installPackage", execTerm.split(' ').at(i));

		iface.call("widgetQueueToAlpmQueue");
	}
	else if (execTerm.startsWith("remove", Qt::CaseInsensitive) || execTerm.startsWith("uninstall", Qt::CaseInsensitive) || 
			execTerm.startsWith("r ", Qt::CaseInsensitive))
	{
		if (execTerm.split(' ').count() <= 1)
			return;

		QDBusInterface iface("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", QDBusConnection::systemBus());

		for(int i = 1; i < execTerm.split(' ').size(); i++)
			iface.call("removePackage", execTerm.split(' ').at(i));

		iface.call("widgetQueueToAlpmQueue");
	}
	else if (execTerm.startsWith("upgrade-system", Qt::CaseInsensitive) || execTerm.startsWith("upgrade system", Qt::CaseInsensitive) ||
			execTerm == "us")
	{
		QDBusInterface iface("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", QDBusConnection::systemBus());

		iface.call("fullSysUpgrade");
	}
	else if (execTerm.startsWith("update database", Qt::CaseInsensitive) || execTerm.startsWith("update-database", Qt::CaseInsensitive) || 
			execTerm.startsWith("update db", Qt::CaseInsensitive) || execTerm.startsWith("update-db", Qt::CaseInsensitive) || 
			execTerm == "ud")
	{
		QDBusInterface iface("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", QDBusConnection::systemBus());

		iface.call("doDbUpdate");
	}
}

void ShamanRunner::startShaman()
{
	KRun::runCommand("shaman", "Shaman Package Manager", "shaman", 0);

	if (!dbus.interface()->isServiceRegistered("org.archlinux.shaman"))
		sleep(0.2);
	
	dbus.connect("org.archlinux.shaman", "/Shaman", "org.archlinux.shaman", 
				"shamanReady", this, SLOT(executeAction()));
}

#include "shamanRunner.moc"
