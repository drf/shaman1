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

#include "LogViewer.h"

#include <QFile>
#include <QTextStream>
#include <QDate>

LogViewer::LogViewer(QWidget *parent)
 : QDialog(parent)
{
	setupUi(this);
	
	loadLog();
	refreshView();
	
	connect(refreshButton, SIGNAL(clicked()), SLOT(refreshView()));
	
	setAttribute(Qt::WA_DeleteOnClose);
}

LogViewer::~LogViewer()
{
}

void LogViewer::loadLog()
{
	QFile fp("/var/log/pacman.log");
	
	contents.clear();
	
	if(!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	
	QTextStream in(&fp);

	while(!in.atEnd()) 
	{
		QString line = in.readLine();
		contents.append(line);
	}
	
	yearFromSpin->setValue(contents.at(0).mid(1, 4).toInt());
	monthFromSpin->setValue(contents.at(0).mid(6, 2).toInt());
	dayFromSpin->setValue(contents.at(0).mid(9, 2).toInt());
	
	yearTilSpin->setValue(contents.at(contents.size() - 1).mid(1, 4).toInt());
	monthTilSpin->setValue(contents.at(contents.size() - 1).mid(6, 2).toInt());
	dayTilSpin->setValue(contents.at(contents.size() - 1).mid(9, 2).toInt());
}

void LogViewer::refreshView()
{
	refreshButton->setEnabled(false);
	
	qApp->processEvents();
	
	textEdit->clear();
	
	foreach(QString ent, contents)
	{
		if(dateFromBox->isChecked())
		{
			QDate boxDate(yearFromSpin->value(), monthFromSpin->value(), dayFromSpin->value());
			QDate lineDate(ent.mid(1, 4).toInt(), ent.mid(6, 2).toInt(), ent.mid(9, 2).toInt());
			
			if(lineDate < boxDate)
				continue;
		}

		if(dateTilBox->isChecked())
		{
			QDate boxDate(yearTilSpin->value(), monthTilSpin->value(), dayTilSpin->value());
			QDate lineDate(ent.mid(1, 4).toInt(), ent.mid(6, 2).toInt(), ent.mid(9, 2).toInt());

			if(lineDate > boxDate)
				continue;
		}
		
		if(lineBox->isChecked())
			if(!ent.contains(refineEdit->text()))
				continue;
		
		textEdit->append(ent);
	}
	
	refreshButton->setEnabled(true);
}
