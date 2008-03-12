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
#include "ui_MainWindow.h"
#include "ui_reviewQueueDialog.h"
#include "AlpmHandler.h"
#include "kanimatedsystemtrayicon.h"

#include <QThread>

class UpdateDbDialog;
class SysUpgradeDialog;
class QueueDialog;
class ConfigDialog;
class ManteinanceDialog;
class UpDbThread;
class BuildingDialog;
class EditPBuild;
class BuildingHandler;
class ShamanTrayIcon;

class MainWindow : public QMainWindow, public Ui::MainWindow, private StringUtils
{
	Q_OBJECT
	
public:
	explicit MainWindow(AlpmHandler *handler, QMainWindow *parent = 0);
	~MainWindow();
	void doUpdView();
	void startTrayTimer();
	void installPackage(const QString &package);
	void reinstallPackage(const QString &package);
	void removePackage(const QString &package);
	QList<QTreeWidgetItem *> getInstallPackagesInWidgetQueue();
	QList<QTreeWidgetItem *> getUpgradePackagesInWidgetQueue();
	QList<QTreeWidgetItem *> getRemovePackagesInWidgetQueue();
	ShamanTrayIcon *getTrayIcon();

signals:
	void shamanReady();
	void aboutToQuit();
	void systemIsUpToDate();
	void upgradesAvailable();
	void actionStatusChanged(const QString &name);
	void streamDbUpdatingStatus(const QString &repo, int action);
	void streamTransDlProg(const QString &filename, int singlePercent, int singleSpeed,
					int totalPercent, int totalSpeed);
	void buildingStarted();
	void buildingFinished();
	
	void startTimer();
	void stopTimer();
	
public slots:
	bool populatePackagesView();
	bool populateQueuePackagesView();
	bool populatePackagesViewFromRepo(const QString &repo);
	void refinePkgView();
	void populateRepoColumn();
	void populateGrpsColumn();
	void removePackagesView();
	void removePackageFromView(const QString &pkgname);
	void removePackageFromView(QTreeWidgetItem *item);
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
	void streamTransQuestion(const QString &msg);
	void cancelAllActions();
	void processQueue();
	void updateABSTree();
	void initSourceQueue();
	void terminatedBuildingHandling();
	bool packageExists(const QString &pkg);
	
protected:
	void closeEvent(QCloseEvent *evt);

private slots:
	void quitApp();
	void itemChanged();
	void showPkgsViewContextMenu();
	void showRepoViewContextMenu();
	void installPackage();
	void reinstallPackage();
	void removePackage();
	void completeRemovePackage();
	void cancelAction();
	void cancelAction(const QString &package);
	void upgradePackage();
	void showSettings();
	void showAboutDialog();
	void systrayActivated(QSystemTrayIcon::ActivationReason reason);
	void installAllRepoPackages();
	void reinstallAllRepoPackages();
	void removeAllRepoPackages();
	void cancelAllRepoActions();
	
private:
	void loadDbUpdateDialog();
	void removeDbUpdateDialog();
	QString formatSize(unsigned long size);
	
public:
	QueueDialog *queueDl;

private:
	alpm_list_t *currentpkgs;
	AlpmHandler *aHandle;
	UpdateDbDialog *dbdialog;
	SysUpgradeDialog *upDl;
	ConfigDialog *configDialog;
	Ui::QueueReadyDialog *qUi;
	BuildingHandler *bHandler;
	QStatusBar *stBar;

	QDialog *reviewQueue;
	ShamanTrayIcon *trayicon;
	
	bool upActive;
	bool revActive;
	bool turnOffSys;

};

#endif /*MAINWINDOW_H_*/
