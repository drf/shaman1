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
#include "EditPBuild.h"

#include "ShamanDialog.h"

#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

EditPBuild::EditPBuild(const QStringList &tg, QWidget *parent)
: QDialog(parent),
targets(tg)
{
	setupUi(this);
	setWindowModality(Qt::ApplicationModal);

	packagesBox->addItems(targets);
	needsSaving = false;
	loadFile(packagesBox->currentText());

	connect(packagesBox, SIGNAL(currentIndexChanged(const QString&)), SLOT(loadFile(const QString&)));
	connect(PBEdit, SIGNAL(textChanged()), SLOT(hasBeenModified()));
	connect(closeButton, SIGNAL(clicked()), SLOT(close()));
	connect(saveButton, SIGNAL(clicked()), SLOT(saveFile()));
}

EditPBuild::~EditPBuild()
{
}

void EditPBuild::hasBeenModified()
{
	needsSaving = true;
}

bool EditPBuild::loadFile(const QString &name)
{
	if(needsSaving)
	{
		switch (ShamanDialog::popupQuestionDialog(QString(tr("Saving")), QString(tr("You modified this PKGBUILD.\n"
				"Do you want to save it?")), this, ShamanProperties::WarningDialog))
		{
		case QMessageBox::Yes:
			saveFile(lastItem);
			break;
		case QMessageBox::No:
			break;
		default:
			// should never be reached
			break;
		}
	}

	lastItem = packagesBox->currentText();

	QString absSource(getABSPath(name));

	if(absSource.isEmpty())
		return false;

	if(!absSource.endsWith(QChar('/')))
		absSource.append(QChar('/'));

	absSource.append("PKGBUILD");

	QFile file(absSource);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;

	PBEdit->setPlainText(file.readAll());

	file.close();

	needsSaving = false;

	return true;
}

bool EditPBuild::saveFile(const QString &name)
{
	QDir absDir("/var/abs");
	absDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);

	QString absSource(getABSPath(name));

	if(absSource.isEmpty())
		return false;

	if(!absSource.endsWith(QChar('/')))
		absSource.append(QChar('/'));

	absSource.append("PKGBUILD");

	ath.switchToRoot();

	QFile file(absSource);

	file.remove();

	if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
		return false;

	if(file.write(PBEdit->toPlainText().toAscii()) == -1)
		return false;

	file.close();

	ath.switchToStdUsr();

	needsSaving = false;

	return true;
}

bool EditPBuild::saveFile()
{
	return saveFile(packagesBox->currentText());
}

void EditPBuild::closeEvent(QCloseEvent *evt)
{
	if(needsSaving)
	{
		switch (ShamanDialog::popupQuestionDialog(QString(tr("Saving")), QString(tr("You modified this PKGBUILD.\n"
				"Do you want to save it?")), this, ShamanProperties::WarningDialog))
		{
		case QMessageBox::Yes:
			saveFile(lastItem);
			break;
		case QMessageBox::No:
			break;
		default:
			// should never be reached
			break;
		}
	}

	evt->accept();
}
