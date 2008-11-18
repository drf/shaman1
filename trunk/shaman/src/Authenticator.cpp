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

#include "Authenticator.h"

#include <aqpm/Backend.h>

#include <QDebug>
#include <QSettings>
#include <QMutex>
#include <QWaitCondition>

Authenticator_Callback athCback;
struct pam_response *reply;

static struct pam_conv conv = {
    auth_cback,
    NULL
};

Authenticator::Authenticator( QObject *parent )
        : QObject( parent ),
        pamh( NULL ),
        retval( 0 ),
        onTransaction( false ),
        alreadyAuthed( false )
{
}

Authenticator::~Authenticator()
{
}

bool Authenticator::switchToRoot()
{
    if ( geteuid() == 0 )
        return true;

    seteuid( 0 );
    //setuid(0);

    if ( geteuid() != 0 ) {
        qDebug() << "Couldn't switch to root!!";
        return false;
    } else {
        QSettings *settings = new QSettings();

        if ( settings->value( "auth/askforpwd", true ).toBool() ) {
            if ( !alreadyAuthed ) {
                if ( !checkUser( "root" ) ) {
                    seteuid( getuid() );
                    return false;
                }
            }
        }

        settings->deleteLater();

        qDebug() << "Root Privileges granted.";
    }

    qDebug() << "Uid is:" << getuid();

    return true;
}

bool Authenticator::switchToStdUsr()
{
    if ( geteuid() == getuid() )
        return true;

    seteuid( getuid() );
    //setuid(real_uid);

    if ( geteuid() != getuid() ) {
        qDebug() << "Couldn't switch back to the real id!!";
        return false;
    } else
        qDebug() << "Root privileges retired.";

    return true;
}

bool Authenticator::checkUser( const QString &uname )
{
    retval = pam_start( "shaman_use_auth", uname.toAscii().data(), &conv, &pamh );

    if ( retval == PAM_SUCCESS ) {
        retval = pam_authenticate( pamh, 0 );  /* is user really user? */
        onTransaction = true;
        qDebug() << "PAM Transaction inited successfully!";
    } else
        qDebug() << "Couldn't init PAM transaction!";

    if ( retval == PAM_SUCCESS ) {
        retval = pam_acct_mgmt( pamh, 0 );     /* permitted access? */
        qDebug() << "Authentication was successful!";
        alreadyAuthed = true;
        QSettings *settings = new QSettings();

        if ( settings->value( "askedforkeeping", false ).toBool() ) {
            settings->remove( "askedforkeeping" );
            settings->setValue( "auth/askforpwd", false );
        }

        settings->deleteLater();
    } else
        qDebug() << "Auth failed!";

    /* This is where we have been authorized or not. */

    if ( retval == PAM_SUCCESS )
        return true;
    else
        return false;

}

bool Authenticator::releaseTransaction()
{
    if ( pam_end( pamh, retval ) != PAM_SUCCESS )
        return false;

    return true;
}

int auth_cback( int num_msg, const struct pam_message **msg,
                struct pam_response **resp, void *appdata_ptr )
{
    return athCback.auth_cback( num_msg, msg, resp, appdata_ptr );
}

Authenticator_Callback::Authenticator_Callback( QObject *parent )
        : QObject( parent )
{

}

Authenticator_Callback::~Authenticator_Callback()
{

}

int Authenticator_Callback::auth_cback( int num_msg, const struct pam_message **msg,
                                        struct pam_response **resp, void *appdata_ptr )
{
    Q_UNUSED( appdata_ptr );
    Q_UNUSED( msg );

    QMutexLocker lock(Aqpm::Backend::instance()->backendMutex());

    qDebug() << "Starting PAM Auth Routine, messages to process:" << num_msg;

    int count = 0;

    if ( num_msg <= 0 )
        return PAM_CONV_ERR;

    reply = ( struct pam_response * ) calloc( num_msg,
            sizeof( struct pam_response ) );

    if ( reply == NULL )
        return PAM_CONV_ERR;

    for ( count = 0; count < num_msg; ++count ) {
        qDebug() << "Processing message" << count;

        pam_response tmp;
        tmp.resp_retcode = 15;

        QString fakePwd( "shaman_reserved_password_for_pam_trs" );

        QByteArray b = fakePwd.toAscii();
        tmp.resp = b.data();

        reply[count] = tmp;

        emit passwordRequired( count );

        if ( reply == NULL ) {
            return PAM_CONV_ERR;
        }

        if ( reply[count].resp == tmp.resp && reply[count].resp_retcode == tmp.resp_retcode )
            Aqpm::Backend::instance()->backendWCond()->wait( Aqpm::Backend::instance()->backendMutex() );
    }

    qDebug() << "Ok, streaming now the response";

    *resp = reply;
    reply = NULL;

    return PAM_SUCCESS;
}

RootProcess::RootProcess( QObject *parent )
        : QProcess( parent )
{

}

RootProcess::~RootProcess()
{

}

void RootProcess::setupChildProcess()
{
    // We need to set the **REAL** UID to 0
    ::setuid( 0 );
}
