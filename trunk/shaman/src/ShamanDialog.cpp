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
 ***************************************************************************/

#include "ShamanDialog.h"

#include <QMessageBox>

ShamanDialog::ShamanDialog()
{
}

ShamanDialog::~ShamanDialog()
{
}

void ShamanDialog::popupDialog(const QString &title, const QString &text, QWidget *parent)
{
	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog != 0)
			dlog->hide();
	}

	QMessageBox *message = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::Ok, parent);

	message->exec();

	message->deleteLater();

	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog != 0)
			dlog->show();
	}
}

int ShamanDialog::popupQuestionDialog(const QString &title, const QString &text, QWidget *parent)
{
	int retval = 0;

	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog != 0)
			dlog->hide();
	}

	QMessageBox *msgBox = new QMessageBox(parent);

	msgBox->setIcon(QMessageBox::Question);
	msgBox->setWindowTitle(title);

	msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

	msgBox->setWindowModality(Qt::ApplicationModal);

	msgBox->setText(text);

	retval = msgBox->exec();

	msgBox->deleteLater();

	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog != 0)
			dlog->show();
	}
	
	return retval;
}
