/***************************************************************************
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                                                    *
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

#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include "ui_configDialog.h"
#include <QThread>

class AlpmHandler;

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
	AlpmHandler *m_handler;
	int action;
};


class ConfigDialog : public QDialog, public Ui::ConfigDialog
{
    Q_OBJECT
    public:
        ConfigDialog(AlpmHandler *handler, QWidget *parent = 0);
        ~ConfigDialog();

    private slots:
        void changeWidget(int position);
	void openAddDialog();
	void cleanUnused();
	void cleanCache();
	void clearCache();
	void showSuccess(int act);
	void showFailure(int act);
	void cleanThread();

    private:
        void setupRepos();
        void setupGeneral();

    private:
        AlpmHandler *m_handler;
	QDialog *addDialog;
	CleanThread *cTh;
};

#endif
