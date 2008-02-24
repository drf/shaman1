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
#include <QWidget>
#include <alpm.h>
#include <alpm_list.h>
#include "../ui_MainWindow.h"
#include "../ui_reviewBuildingDialog.h"
#include "AlpmHandler.h"

#include <QSystemTrayIcon>
#include <QThread>

class UpdateDbDialog;
class SysUpgradeDialog;
class QueueDialog;
class ConfigDialog;
class ManteinanceDialog;
class UpDbThread;
class BuildingDialog;
class EditPBuild;

class MainWindow : public QMainWindow, private Ui::MainWindow, private StringUtils
{
	Q_OBJECT
	
public:
	explicit MainWindow(AlpmHandler *handler, QMainWindow *parent = 0);
	~MainWindow();
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
	void destroyReviewQueue();
	void getPackageFromFile();
	void dbUpdateTray();
	void dbUpdateTrayFinished();
	void updateABSTree();
	void validateSourceQueue();
	void startSourceProcessing();
	void finishedBuilding(int failure, QStringList targets);
	void processBuiltPackages();
	void openPBuildDialog();
	void processBuildWizard();
	
protected:
	void closeEvent(QCloseEvent *evt);

private slots:
	void quitApp();
	void itemChanged();
	void showPkgsViewContextMenu();
	void showRepoViewContextMenu();
	void installPackage();
	void removePackage();
	void completeRemovePackage();
	void cancelAction();
	void cancelAction(const QString &package);
	void upgradePackage();
	void processQueue();
	void showSettings();
	void showAboutDialog();
	void systrayActivated(QSystemTrayIcon::ActivationReason reason);
	void installAllRepoPackages();
	void removeAllRepoPackages();
	void cancelAllRepoActions();
	void cancelAllActions();
	
private:
	void installPackage(const QString &package);
	void removePackage(const QString &package);
	void loadDbUpdateDialog();
	void removeDbUpdateDialog();
	void setupSystray();
	QString formatSize(unsigned long size);
	
private:
	alpm_list_t *currentpkgs;
	AlpmHandler *aHandle;
	UpdateDbDialog *dbdialog;
	SysUpgradeDialog *upDl;
	QueueDialog *queueDl;
	ConfigDialog *configDialog;
	BuildingDialog *buildDialog;
	Ui::reviewBuildingDialog *revBuildUi;
	EditPBuild *pBuildEditor;
	QDialog *reviewBQueue;

	QSystemTrayIcon *systray;
	QDialog *reviewQueue;
	QTimer *trayUpDb;
	UpDbThread *upDbTh;
	QStringList buildTargets;
	
	bool upActive;
	bool revActive;

};

#endif /*MAINWINDOW_H_*/
