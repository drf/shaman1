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

#ifndef MANTEINANCEDIALOG_H_
#define MANTEINANCEDIALOG_H_

#include <iostream>
#include <QtGui>
#include "../ui_mantDialog.h"
#include <AlpmHandler.h>

class CleanThread : public QThread
{
	Q_OBJECT
	
public:
	CleanThread(AlpmHandler *aH, int act);
	void run();
	
signals:
	void success(int act);
	void failure(int act);
	
private:
	AlpmHandler *aHandle;
	int action;
};

class ManteinanceDialog : public QDialog, private Ui::mantDialog
{
	Q_OBJECT
	
public:
	ManteinanceDialog(AlpmHandler *hnd, QWidget *parent = 0);
	virtual ~ManteinanceDialog();
	
public slots:
	void cleanUnused();
	void cleanCache();
	void clearCache();
	
	void showSuccess(int act);
	void showFailure(int act);
	
	void cleanThread();
	
private:
	AlpmHandler *aHandle;
	CleanThread *cTh;
};

#endif /*MANTEINANCEDIALOG_H_*/
