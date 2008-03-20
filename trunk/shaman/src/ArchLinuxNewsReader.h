/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it													   *
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

#ifndef ARCHLINUXNEWSREADER_H_
#define ARCHLINUXNEWSREADER_H_

#include <QHttp>
#include <QWidget>
#include <QBuffer>
#include <QXmlStreamReader>
#include <QTimer>

namespace ArchLinuxNews {

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
	
	QList<QStringList> getAllEntries();
	void setUpdateInterval(int interval);

	void fetch();
	void finished(int id, bool error);
	void readData(const QHttpResponseHeader &);

private:
	void parseXml();

	QXmlStreamReader xml;
	QHttp http;
	QTimer timer;
	QList<ArchLinuxNews::ArchNews> entries;
	
	int connectionId;
};

#endif /*ARCHLINUXNEWSREADER_H_*/
