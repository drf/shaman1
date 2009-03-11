/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                *
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

#include "ArchLinuxNewsReader.h"

#include <QHttp>
#include <QUrl>
#include <QNetworkProxy>
#include <QSettings>
#include <QDebug>
#include <QTimer>

ArchLinuxNewsReader::ArchLinuxNewsReader()
        : http( new QHttp( this ) ),
        timer( new QTimer( this ) )
{
    connect( http, SIGNAL( readyRead( const QHttpResponseHeader & ) ),
             this, SLOT( readData( const QHttpResponseHeader & ) ) );

    connect( http, SIGNAL( requestFinished( int, bool ) ),
             this, SLOT( finished( int, bool ) ) );

    connect( timer, SIGNAL( timeout() ), SLOT( fetch() ) );
}

ArchLinuxNewsReader::~ArchLinuxNewsReader()
{
}

void ArchLinuxNewsReader::setUpdateInterval()
{
    if ( timer->isActive() )
        timer->stop();

    QSettings *settings = new QSettings();

    if ( !settings->value( "newsreader/doupdate" ).toBool() )
        return;

    timer->setInterval( settings->value( "newsreader/updateinterval", 60 ).toInt() * 60000 );

    timer->start();
}

void ArchLinuxNewsReader::fetch()
{
    qDebug() << "Fetching Started";

    emit fetchingStarted();

    xml.clear();
    entries.clear();

    QUrl url( "http://www.archlinux.org/feeds/news/" );

    http->setProxy( QNetworkProxy() );
    http->setHost( url.host() );
    connectionId = http->get( url.path() );
}

void ArchLinuxNewsReader::finished( int id, bool error )
{
    if ( error ) {
        qDebug() << "Unable to fetch the RSS feed!!";
        emit fetchingFailed();
    } else if ( id == connectionId ) {
        emit fetchingFinished();
        qDebug() << "RSS feed fetched successfully!!";
    }
}

void ArchLinuxNewsReader::readData( const QHttpResponseHeader &resp )
{
    if ( resp.statusCode() != 200 )
        http->abort();
    else {
        xml.addData( http->readAll() );
        parseXml();
    }
}

void ArchLinuxNewsReader::parseXml()
{
    QMap<QString, QVariant> oldEntries;
    bool newStuff = false;

    qDebug() << "XML Parsing Started";

    QSettings *settings = new QSettings();

    oldEntries = settings->value( "newsreader/oldnewsitem" ).toMap();

    while ( !xml.atEnd() ) {
        xml.readNext();
        if ( xml.isStartElement() ) {
            if ( xml.name() == "item" )
                linkString = xml.attributes().value( "rss:about" ).toString();

            currentTag = xml.name().toString();
        } else if ( xml.isEndElement() ) {
            if ( xml.name() == "item" ) {
                QString realTitle = QString( titleString );
                if ( realTitle.startsWith( "Recent News Updates" ) )
                    realTitle.remove( 0, 19 );

                realTitle = realTitle.trimmed();

                if ( !oldEntries.contains( realTitle ) ) {
                    ArchLinuxNews::ArchNews tmp;
                    tmp.link = QString( linkString );
                    tmp.title = QString( realTitle );
                    tmp.nNew = true;
                    tmp.nRead = false;

                    oldEntries[tmp.title] = false;

                    settings->setValue( "newsreader/oldnewsitem", oldEntries );

                    entries.append( tmp );

                    newStuff = true;
                } else {
                    ArchLinuxNews::ArchNews tmp;
                    tmp.link = QString( linkString );
                    tmp.title = QString( realTitle );
                    tmp.nNew = false;
                    tmp.nRead = oldEntries[realTitle].toBool();

                    entries.append( tmp );
                }

                titleString.clear();
                linkString.clear();
            }

        } else if ( xml.isCharacters() && !xml.isWhitespace() ) {
            if ( currentTag == "title" )
                titleString += xml.text().toString();
            else if ( currentTag == "link" )
                linkString += xml.text().toString();
        }
    }

    if ( xml.error() && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError ) {
        qWarning() << "XML ERROR:" << xml.lineNumber() << ": " << xml.errorString();
        http->abort();
    }

    settings->deleteLater();

    if ( newStuff )
        emit newItems();
}

QList<ArchLinuxNews::ArchNews> ArchLinuxNewsReader::getAllEntries()
{
    return entries;
}

void ArchLinuxNewsReader::markAsRead( const QString &name, bool status )
{
    QMap<QString, QVariant> oldEntries;

    QSettings *settings = new QSettings();

    oldEntries = settings->value( "newsreader/oldnewsitem" ).toMap();

    if ( !oldEntries.contains( name ) )
        return;

    oldEntries[name] = status;
    qDebug() << "Setting Read Entry";

    settings->setValue( "newsreader/oldnewsitem", oldEntries );

    QList<ArchLinuxNews::ArchNews> newEntries;

    foreach( ArchLinuxNews::ArchNews ent, entries ) { //krazy:exclude=foreach
        if ( ent.title == name ) {
            ent.nRead = status;
            qDebug() << "Setting Read Entry";
        }

        newEntries.append( ent );
    }

    entries = newEntries;

    settings->deleteLater();
}

QStringList ArchLinuxNewsReader::getEntriesNames()
{
    QMap<QString, QVariant> oldEntries;

    QSettings *settings = new QSettings();

    oldEntries = settings->value( "newsreader/oldnewsitem" ).toMap();

    settings->deleteLater();

    return oldEntries.keys();
}

bool ArchLinuxNewsReader::isEntryRead( const QString &title )
{
    QMap<QString, QVariant> oldEntries;

    QSettings *settings = new QSettings();

    oldEntries = settings->value( "newsreader/oldnewsitem" ).toMap();

    settings->deleteLater();

    if ( !oldEntries.contains( title ) )
        return true;

    return oldEntries[title].toBool();
}

QString ArchLinuxNewsReader::getHttpError()
{
    return http->errorString();
}

bool ArchLinuxNewsReader::checkUnreadNewsOnPkg( const QString &pkgname )
{
    QMap<QString, QVariant> oldEntries;

    QSettings *settings = new QSettings();

    oldEntries = settings->value( "newsreader/oldnewsitem" ).toMap();

    settings->deleteLater();

    foreach( const QString &ent, oldEntries.keys() ) {
        if ( ent.contains( pkgname, Qt::CaseInsensitive ) )
            if ( oldEntries[ent] == false )
                return true;
    }

    return false;
}
