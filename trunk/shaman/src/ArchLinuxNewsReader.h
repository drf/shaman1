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

#ifndef ARCHLINUXNEWSREADER_H
#define ARCHLINUXNEWSREADER_H

#include <QPointer>
#include <QHttp>
#include <QXmlStreamReader>

class QTimer;

namespace ArchLinuxNews
{

struct arNws {
    QString title;
    QString link;
    bool nRead;
    bool nNew;
};

typedef struct arNws ArchNews;

}  // namespace ArchLinuxNews

class ArchLinuxNewsReader : public QObject
{
        Q_OBJECT

    public:
        ArchLinuxNewsReader();
        virtual ~ArchLinuxNewsReader();

        QList<ArchLinuxNews::ArchNews> getAllEntries();
        void setUpdateInterval();

        QStringList getEntriesNames();
        bool isEntryRead( const QString &title );

        QString getHttpError();

        bool checkUnreadNewsOnPkg( const QString &pkgname );

    public slots:
        void fetch();
        void finished( int id, bool error );
        void readData( const QHttpResponseHeader & );
        void markAsRead( const QString &name, bool status );

    signals:
        void fetchingFailed();
        void newItems();
        void fetchingStarted();
        void fetchingFinished();

    private:
        void parseXml();

        QString titleString;
        QString linkString;
        QString currentTag;

        QXmlStreamReader xml;
        QPointer<QHttp> http;
        QPointer<QTimer> timer;
        QList<ArchLinuxNews::ArchNews> entries;

        int connectionId;
};

#endif /*ARCHLINUXNEWSREADER_H*/
