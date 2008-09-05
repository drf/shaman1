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
 **************************************************************************/

#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <security/pam_appl.h>

#include <QObject>
#include <QString>
#include <QProcess>

class Authenticator : public QObject
{
public:
	Authenticator(QObject *parent = 0);
	virtual ~Authenticator();

	bool switchToRoot();
	bool switchToStdUsr();

private:
	bool checkUser(const QString &uname);
	bool releaseTransaction();

private:
	pam_handle_t *pamh;
	int retval;
	bool onTransaction;
	bool alreadyAuthed;
};

class Authenticator_Callback : public QObject
{
	Q_OBJECT

public:
	explicit Authenticator_Callback(QObject *parent = 0);
	virtual ~Authenticator_Callback();

	int auth_cback(int num_msg, const struct pam_message **msg,
            struct pam_response **resp, void *appdata_ptr);

signals:
	void passwordRequired(int count);
};

class RootProcess : public QProcess
{
	Q_OBJECT

public:
	explicit RootProcess( QObject * parent = 0 );
	virtual ~RootProcess();

protected:
	virtual void setupChildProcess();
};

int auth_cback(int num_msg, const struct pam_message **msg,
                struct pam_response **resp, void *appdata_ptr);

#endif /*AUTHENTICATOR_H*/
