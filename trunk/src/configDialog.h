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

#include "../ui_configDialog.h"
#include "ConfigurationParser.h"
#include <QThread>
#include <QProcess>

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


class ConfigDialog : public QDialog, public Ui::ConfigDialog, private ConfigurationParser
{
	
	Q_OBJECT
	
public:
	explicit ConfigDialog(AlpmHandler *handler, QWidget *parent = 0);
	~ConfigDialog();
	bool doDbUpdate();

private slots:
	void changeWidget(int position);
	void openAddDialog();
	void openEditDialog();
	void removeThirdParty();
	void performManteinanceAction();
	void cleanProc(int eC, QProcess::ExitStatus eS);
	void mantProgress();
	void showSuccess(int act);
	void showFailure(int act);
	void cleanThread();
	void saveConfiguration();
	void addMirror();
	void obfuscateSupfiles(bool state);
	void obfuscateDBUpdate(bool state);

private:
	void setupRepos();
	void setupGeneral();
	void setupPacman();
	void setupABS();
	QStringList getMirrorList();

private:
	AlpmHandler *m_handler;
	QDialog *addDialog;
	CleanThread *cTh;
	QProcess *mantProc;
	bool upDb;
};

#endif
