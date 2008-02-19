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

#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

#include "EditPBuild.h"

EditPBuild::EditPBuild(QStringList tg, QWidget *parent)
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
		QMessageBox *msgBox = new QMessageBox(this);

		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowTitle(QString(tr("Saving")));

		msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

		msgBox->setWindowModality(Qt::ApplicationModal);

		msgBox->setText(QString(tr("You modified this PKGBUILD.\nDo you want to save it?")));

		switch (msgBox->exec()) {
		case QMessageBox::Yes:
			saveFile(lastItem);
			break;
		case QMessageBox::No:
			break;
		default:
			// should never be reached
			break;
		}

		msgBox->deleteLater();
	}
	
	lastItem = packagesBox->currentText();
	
	QDir absDir("/var/abs");
	absDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);

	int found = 0;
	QString absSource;

	QFileInfoList list = absDir.entryInfoList();

	for (int i = 0; i < list.size(); ++i) 
	{
		QDir subAbsDir(list.at(i).absoluteFilePath());
		subAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
		QFileInfoList subList = subAbsDir.entryInfoList();
		for (int k = 0; k < subList.size(); ++k) 
		{
			QDir subUbAbsDir(subList.at(k).absoluteFilePath());
			subUbAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
			QFileInfoList subUbList = subUbAbsDir.entryInfoList();
			for (int j = 0; j < subUbList.size(); ++j) 
			{
				if(!subUbList.at(j).baseName().compare(name))
				{
					found = 1;
					absSource = subUbList.at(j).absoluteFilePath();
					break;
				}
			}
		}
		if(found == 1)
			break;
	}

	if(!found)
		return false;
	
	if(!absSource.endsWith("/"))
		absSource.append("/");
	
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

	int found = 0;
	QString absSource;

	QFileInfoList list = absDir.entryInfoList();

	for (int i = 0; i < list.size(); ++i) 
	{
		QDir subAbsDir(list.at(i).absoluteFilePath());
		subAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
		QFileInfoList subList = subAbsDir.entryInfoList();
		for (int k = 0; k < subList.size(); ++k) 
		{
			QDir subUbAbsDir(subList.at(k).absoluteFilePath());
			subUbAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
			QFileInfoList subUbList = subUbAbsDir.entryInfoList();
			for (int j = 0; j < subUbList.size(); ++j) 
			{
				if(!subUbList.at(j).baseName().compare(name))
				{
					found = 1;
					absSource = subUbList.at(j).absoluteFilePath();
					break;
				}
			}
		}
		if(found == 1)
			break;
	}

	if(!found)
		return false;
	
	if(!absSource.endsWith("/"))
		absSource.append("/");
	
	absSource.append("PKGBUILD");
	
	QFile file(absSource);
	
	file.remove();

	if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
		return false;
	
	if(file.write(PBEdit->toPlainText().toAscii()) == -1)
		return false;
	
	file.close();
	
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
		QMessageBox *msgBox = new QMessageBox(this);

		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowTitle(QString(tr("Saving")));

		msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

		msgBox->setWindowModality(Qt::ApplicationModal);

		msgBox->setText(QString(tr("You modified this PKGBUILD.\nDo you want to save it?")));

		switch (msgBox->exec()) {
		case QMessageBox::Yes:
			saveFile(lastItem);
			break;
		case QMessageBox::No:
			break;
		default:
			// should never be reached
			break;
		}

		msgBox->deleteLater();
	}
	
	evt->accept();
}
