/*
 *	 Copyright (C) 2008 by Lukas Appelhans				   				   
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

#ifndef SHAMANRUNNER_H
#define SHAMANRUNNER_H

#include <plasma/abstractrunner.h>
#include <QDBusConnection>

class ShamanRunner : public Plasma::AbstractRunner
{
    Q_OBJECT
    public:
        ShamanRunner(QObject *parent, const QVariantList &args);
        ~ShamanRunner();

        void match(Plasma::RunnerContext &context);
        void run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &action);
        
    private slots:
    	void executeAction();
    	
    private:
    	void startShaman();

    private:
        QStringList words;
        QString execTerm;
        QDBusConnection dbus;
};

K_EXPORT_PLASMA_RUNNER(shaman, ShamanRunner);

#endif
