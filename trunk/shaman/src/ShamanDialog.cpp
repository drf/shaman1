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
#include <QPushButton>
#include <QIcon>

ShamanDialog::ShamanDialog()
{
}

ShamanDialog::~ShamanDialog()
{
}

void ShamanDialog::popupDialog(const QString &title, const QString &text, QWidget *parent,
		ShamanProperties::DialogType dtype)
{
	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog)
			dlog->hide();
	}
	
	QMessageBox *message;
	
	if(parent == NULL)
		message = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::NoButton);
	else
		message = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::NoButton, parent);
	
	switch(dtype)
	{
	case ShamanProperties::InformationDialog:
		message->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
		break;
	case ShamanProperties::SuccessDialog:
		message->setIconPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
		break;
	case ShamanProperties::ErrorDialog:
		message->setIconPixmap(QPixmap(":/Icons/icons/dialog-error.png"));
		break;
	case ShamanProperties::WarningDialog:
		message->setIconPixmap(QPixmap(":/Icons/icons/dialog-warning.png"));
		break;
	case ShamanProperties::OtherDialog:
		message->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
		break;
	default:
		break;
	}

	QPushButton *okb = message->addButton(QMessageBox::Ok);

	okb->setText(QObject::tr("Ok"));
	okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));

	message->exec();

	message->deleteLater();

	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog != 0)
			dlog->show();
	}
}

int ShamanDialog::popupQuestionDialog(const QString &title, const QString &text, QWidget *parent,
		ShamanProperties::DialogType dtype)
{
	int retval = 0;

	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog)
			dlog->hide();
	}

	QMessageBox *msgBox = new QMessageBox(parent);

	switch(dtype)
	{
	case ShamanProperties::InformationDialog:
		msgBox->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
		break;
	case ShamanProperties::SuccessDialog:
		msgBox->setIconPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
		break;
	case ShamanProperties::ErrorDialog:
		msgBox->setIconPixmap(QPixmap(":/Icons/icons/dialog-error.png"));
		break;
	case ShamanProperties::WarningDialog:
		msgBox->setIconPixmap(QPixmap(":/Icons/icons/dialog-warning.png"));
		break;
	case ShamanProperties::OtherDialog:
		msgBox->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
		break;
	default:
		break;
	}
	
	msgBox->setWindowTitle(title);

	QPushButton *okb = msgBox->addButton(QMessageBox::Yes);
	QPushButton *nob = msgBox->addButton(QMessageBox::No);

	okb->setText(QObject::tr("Yes"));
	okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
	nob->setText(QObject::tr("No"));
	nob->setIcon(QIcon(":/Icons/icons/dialog-cancel.png"));
	
	msgBox->setDefaultButton(okb);
	
	msgBox->setWindowModality(Qt::ApplicationModal);

	msgBox->setText(text);

	retval = msgBox->exec();

	msgBox->deleteLater();

	foreach(QObject *ent, parent->children())
	{	
		QDialog *dlog = qobject_cast<QDialog *>(ent);
		if(dlog)
			dlog->show();
	}
	
	return retval;
}
