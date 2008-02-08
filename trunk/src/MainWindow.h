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

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iostream>
#include <QtGui>
#include <QWidget>
#include <alpm.h>
#include <alpm_list.h>
#include "../ui_MainWindow.h"
#include "AlpmHandler.h"


class UpdateDbDialog;
class SysUpgradeDialog;
class QueueDialog;
class RepoDialogCl;
class ConfigDialog;

class QSystemTrayIcon;

class MainWindow : public QMainWindow, private Ui::MainWindow, private StringUtils
{
	Q_OBJECT
	
public:
	MainWindow(AlpmHandler *handler, QMainWindow *parent = 0);
	virtual ~MainWindow();
	void doUpdView();

signals:
	void aboutToQuit();
	
public slots:
	bool populatePackagesView();
	void refinePkgView();
	void populateRepoColumn();
	void populateGrpsColumn();
	void removePackagesView();
	void removeRepoColumn();
	void showPkgInfo();
	void doDbUpdate();
	void finishDbUpdate();
	void startUpgrading();
	void fullSysUpgrade();
	void upgradeAborted();
	void addUpgradeableToQueue();
	void queueProcessingEnded(bool errors);
	void widgetQueueToAlpmQueue();
	void configureRepositories();

private slots:
	void quitApp();
	void itemChanged();
	void showContextMenu();
	void installPackage();
	void removePackage();
	void completeRemovePackage();
	void cancelAction();
	void cancelAction(QString package);
	void upgradePackage();
	void processQueue();
        void showSettings();
	void systrayActivated(QSystemTrayIcon::ActivationReason reason);
	
private:
	void installPackage(QString package);
	void removePackage(QString package);
	void loadDbUpdateDialog();
	void removeDbUpdateDialog();
	void setupSystray();
	
private:
	alpm_list_t *currentpkgs;
	AlpmHandler *aHandle;
	UpdateDbDialog *dbdialog;
	SysUpgradeDialog *upDl;
	QueueDialog *queueDl;
	RepoDialogCl *repoDl;
	ConfigDialog *configDialog;

	QSystemTrayIcon *systray;

};

#endif /*MAINWINDOW_H_*/
