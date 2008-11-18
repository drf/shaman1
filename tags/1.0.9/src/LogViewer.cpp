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
#include "alpm.h"

LogViewer::LogViewer(QWidget *parent)
 : QDialog(parent)
{
	setupUi(this);

	loadLog();
	refreshView();

	connect(refreshButton, SIGNAL(clicked()), SLOT(refreshView()));
	connect(searchLine, SIGNAL(textChanged(QString)), SLOT(refreshView()));

	setAttribute(Qt::WA_DeleteOnClose);
}

LogViewer::~LogViewer()
{
}

void LogViewer::loadLog()
{
	QFile fp(alpm_option_get_logfile());

	contents.clear();

	if(!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&fp);

	while(!in.atEnd())
	{
		QString line = in.readLine();
		contents.append(line);
	}

	fp.close();

	dateFrom->setDate(QDate(contents.at(0).mid(1, 4).toInt(),
	        contents.at(0).mid(6, 2).toInt(),
	        contents.at(0).mid(9, 2).toInt()));

	dateUntil->setDate(QDate(contents.at(contents.size() - 1).mid(1, 4).toInt(),
	        contents.at(contents.size() - 1).mid(6, 2).toInt(),
	        contents.at(contents.size() - 1).mid(9, 2).toInt()));

}

void LogViewer::refreshView()
{
	QString toShow;

	refreshButton->setEnabled(false);

	qApp->processEvents();

	textEdit->clear();

	foreach(const QString &ent, contents)
	{
		if(dateFromBox->isChecked())
		{
			QDate lineDate(ent.mid(1, 4).toInt(), ent.mid(6, 2).toInt(), ent.mid(9, 2).toInt());

			if(lineDate < dateFrom->date())
				continue;
		}

		if(dateTilBox->isChecked())
		{
			QDate lineDate(ent.mid(1, 4).toInt(), ent.mid(6, 2).toInt(), ent.mid(9, 2).toInt());

			if(lineDate > dateUntil->date())
				continue;
		}

		if(!searchLine->text().isEmpty())
			if(!ent.contains(searchLine->text()))
				continue;

		toShow.append(ent + QChar('\n'));
	}

	textEdit->setText(toShow);

	textEdit->moveCursor(QTextCursor::End);

	refreshButton->setEnabled(true);
}
