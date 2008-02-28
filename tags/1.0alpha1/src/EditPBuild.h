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

#ifndef EDITPBUILD_H_
#define EDITPBUILD_H_

#include "../ui_editPBDialog.h"
#include "ABSHandler.h"

class EditPBuild : public QDialog, private Ui::editPBDialog, private ABSHandler 
{
	Q_OBJECT
	
public:
	explicit EditPBuild(const QStringList &tg, QWidget *parent = 0);
	virtual ~EditPBuild();
	
public slots:
	bool saveFile();
	bool saveFile(const QString &name);
	bool loadFile(const QString &name);
	void hasBeenModified();
	
protected:
	void closeEvent(QCloseEvent *evt);
	
private:
	QStringList targets;
	bool needsSaving;
	QString lastItem;
};

#endif /*EDITPBUILD_H_*/
