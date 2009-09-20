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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "ui_MainWindow.h"
#include "kanimatedsystemtrayicon.h"

#include <config-shaman1.h>

#ifdef KDE4_INTEGRATION
#include <kmainwindow.h>
#else
#include <QMainWindow>
#endif

#include <aqpm/Globals.h>

#include <QThread>
#include <QPointer>
#include <QLabel>
#include <QDialog>

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
class ReviewQueueDialog;
class ArchLinuxNewsReader;
class NewsViewer;
class LogViewer;
class ShamanStatusBar;
class PackageProperties;
class ShamanTreeWidgetItem;
class LocalPackageDialog;

class CreateItemsThread : public QThread
{
    Q_OBJECT

public:
    CreateItemsThread(QObject *parent = 0);
    void run();
    QList<QTreeWidgetItem *> getResult();

signals:
    void updateProgress(int percentage);

private:
    QList<QTreeWidgetItem *> retlist;
};

#ifndef KDE4_INTEGRATION
class MainWindow : public QMainWindow, public Ui::MainWindow
#else
class MainWindow : public KMainWindow, public Ui::MainWindow
#endif
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();
    void doUpdView();
    void startTrayTimer();
    void installPackage(const QString &package, const QString &repo = QString());
    void reinstallPackage(const QString &package, const QString &repo = QString());
    void removePackage(const QString &package, const QString &repo = QString());
    QList<QTreeWidgetItem *> getInstallPackagesInWidgetQueue();
    QList<QTreeWidgetItem *> getUpgradePackagesInWidgetQueue();
    QList<QTreeWidgetItem *> getRemovePackagesInWidgetQueue();
    ShamanTrayIcon *getTrayIcon();
    void streamReadySignal();
    void setUpTrayIcon();

signals:
    void shamanReady();
    void aboutToQuit();
    void systemIsUpToDate();
    void upgradesAvailable();
    void actionStatusChanged(const QString &name);
    void streamDbUpdatingStatus(const QString &repo, int action);
    void streamTransDlProg(const QString &c, int bytedone, int bytetotal, int speed,
                           int listdone, int listtotal, int speedtotal);
    void streamTransactionProgress(int percent);
    void buildingStarted();
    void buildingFinished();
    void transactionStarted();
    void transactionReleased();

    void startTimer();
    void stopTimer();
    void streamPackages(const QStringList&);
    void packagesLoaded();

public slots:
    void populatePackagesView();
    void populatePackagesViewFinished();
    void refinePkgView();
    void refineRepoView();
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
    void getPackageFromFile();
    void streamTransQuestion(Aqpm::Globals::TransactionQuestion event, QVariantMap args);
    void cancelAllActions();
    void processQueue();
    void updateABSTree();
    void initSourceQueue();
    void terminatedBuildingHandling();
    bool packageExists(const QString &pkg);
    void setProxy();
    void openNewsDialog();
    void openLogViewer();
    void shiftItemAction();
    void showInfoDialog();
    void doStreamPackages();
    void installPackageFromFile(const QString &filename);

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
    void cancelAction(const QString &package, const QString &repo = QString());
    void upgradePackage();
    void showSettings();
    void showAboutDialog();
    void systrayActivated(QSystemTrayIcon::ActivationReason reason);
    void installAllRepoPackages();
    void reinstallAllRepoPackages();
    void removeAllRepoPackages();
    void cancelAllRepoActions();
    void settingsClosed();
    void openUrl();
    void triggerEditTimer();

private:
    void loadDbUpdateDialog();
    void removeDbUpdateDialog();
    void upgrade(const QStringList &packages);

public:
    QueueDialog *queueDl;

private:
    QPointer<UpdateDbDialog> dbdialog;
    QPointer<SysUpgradeDialog> upDl;
    QPointer<ConfigDialog> configDialog;
    QPointer<ReviewQueueDialog> qUi;
    QPointer<BuildingHandler> bHandler;
    QPointer<NewsViewer> nView;
    QPointer<LogViewer> lView;
    QPointer<ShamanStatusBar> stBar;
    QPointer<PackageProperties> pkgProp;
    QPointer<QTimer> editTimer;
    QPointer<CreateItemsThread> cThread;
    QPointer<LocalPackageDialog> lpkgDialog;

    QPointer<QDialog> reviewQueue;
    QPointer<ShamanTrayIcon> trayicon;
    ArchLinuxNewsReader *newsReader;

    bool upActive;
    bool revActive;
    bool dbActive;
    bool quiActive;
    bool turnOffSys;

};

#endif /*MAINWINDOW_H*/
