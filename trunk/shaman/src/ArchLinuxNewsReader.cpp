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

#include "ArchLinuxNewsReader.h"

#include <QHttp>
#include <QUrl>
#include <QSettings>
#include <QDebug>

ArchLinuxNewsReader::ArchLinuxNewsReader()
{
	QSettings *settings = new QSettings();
	
	if(settings->value("proxy/enabled").toBool() && settings->value("proxy/httpProxy").toBool())
		http.setProxy(settings->value("proxy/proxyServer").toString(), settings->value("proxy/proxyPort").toInt());
	
	settings->deleteLater();
	
	connect(&http, SIGNAL(readyRead(const QHttpResponseHeader &)),
			this, SLOT(readData(const QHttpResponseHeader &)));

	connect(&http, SIGNAL(requestFinished(int, bool)),
			this, SLOT(finished(int, bool)));
}

ArchLinuxNewsReader::~ArchLinuxNewsReader()
{
}

void ArchLinuxNewsReader::fetch()
{
	xml.clear();

	QUrl url("http://www.archlinux.org/feeds/news/");

	http.setHost(url.host());
	connectionId = http.get(url.path());
}

void ArchLinuxNewsReader::finished(int id, bool error)
{
	if (error) 
	{

	}
	else if (id == connectionId) 
	{

	}
}

void ArchLinuxNewsReader::readData(const QHttpResponseHeader &resp)
{
    if (resp.statusCode() != 200)
        http.abort();
    else 
    {
        xml.addData(http.readAll());
        parseXml();
    }
}

void ArchLinuxNewsReader::parseXml()
{
	QString titleString;
	QString linkString;
	QString currentTag;
	QMap<QString, QVariant> oldEntries;
	
	QSettings *settings = new QSettings();
	
	oldEntries = settings->value("newsreader/oldnewsitem").toMap();
	
	entries.clear();

	while (!xml.atEnd()) 
	{
		xml.readNext();
		if (xml.isStartElement()) 
		{
			if (xml.name() == "item")
				linkString = xml.attributes().value("rss:about").toString();
			
			currentTag = xml.name().toString();
		}
		else if (xml.isEndElement())
		{
			if(xml.name() == "item")
			{
				if(!oldEntries.contains(linkString))
				{
					ArchLinuxNews::ArchNews tmp;
					tmp.link = linkString;
					tmp.title = titleString;
					tmp.nNew = true;
					tmp.nRead = false;
					
					oldEntries[linkString] = false;
					
					settings->setValue("newsreader/oldnewsitem", oldEntries);
					
					entries.append(tmp);
				}
				else
				{
					ArchLinuxNews::ArchNews tmp;
					tmp.link = linkString;
					tmp.title = titleString;
					tmp.nNew = false;
					tmp.nRead = oldEntries[linkString].toBool();

					entries.append(tmp);
				}
				
				titleString.clear();
				linkString.clear();
			}

		} 
		else if (xml.isCharacters() && !xml.isWhitespace()) 
		{
			if (currentTag == "title")
				titleString += xml.text().toString();
			else if (currentTag == "link")
				linkString += xml.text().toString();
		}
	}
	
	if (xml.error() && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError) 
	{
		qWarning() << "XML ERROR:" << xml.lineNumber() << ": " << xml.errorString();
		http.abort();
	}
	
	settings->deleteLater();
}
