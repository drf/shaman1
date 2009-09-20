/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *   Copyright (C) 2008 by Lukas Appelhans              *
 *   l.appelhans@gmx.de                   *
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

#include "MainWindow.h"

#include "UpdateDbDialog.h"
#include "SysUpgradeDialog.h"
#include "QueueDialog.h"

#ifndef KDE4_INTEGRATION
#include "config/ConfigDialog.h"
#else
#include <kcmultidialog.h>
#endif

#include "BuildingDialog.h"
#include "EditPBuild.h"
#include "ABSHandler.h"
#include "BuildingHandler.h"
#include "ShamanTrayIcon.h"
#include "ui_aboutDialog.h"
#include "shamanadaptor.h"
#include "ReviewQueueDialog.h"
#include "ArchLinuxNewsReader.h"
#include "NewsViewer.h"
#include "LogViewer.h"
#include "ShamanDialog.h"
#include "ShamanStatusBar.h"
#include "PackageProperties.h"
#include "ShamanTreeWidgetItem.h"
#include "MaintenanceBar.h"
#include "LocalPackageDialog.h"
#include "ErrorHandler.h"

#include <config-shaman1.h>

#include <aqpm/Backend.h>
#include <aqpm/Globals.h>

#include <iostream>
#include <alpm.h>
#include <sys/types.h>

#include <QMenu>
#include <QString>
#include <QListWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <QFileDialog>
#include <QTimer>
#include <QCloseEvent>
#include <QSettings>
#include <QWaitCondition>
#include <QMovie>
#include <QShortcut>
#include <QNetworkProxy>
#include <QMutex>
#include <QDesktopServices>
#include <QUrl>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#include <Action>
#include <Auth>

using namespace Aqpm;

// Thread Definition

CreateItemsThread::CreateItemsThread(QObject *parent)
        : QThread(parent)
{
}

QList<QTreeWidgetItem *> CreateItemsThread::getResult()
{
    return retlist;
}

void CreateItemsThread::run()
{
    int count = 0;
    int totalPkgs = Backend::instance()->countPackages(Globals::AllPackages);
    QList<QTreeWidgetItem *> itmLst;
    Package::List currentpkgs;

    Database::List databases = Backend::instance()->getAvailableDatabases();

    count = 0;

    QStringList conflPackages;

    foreach(const Database &db, databases) {
        currentpkgs = Backend::instance()->getPackagesFromDatabase(db);

        foreach(Package pkg, currentpkgs) {
            bool installed = false;

            if (Backend::instance()->isInstalled(pkg)) {
                Package pkg1 = Backend::instance()->getPackage(pkg.name(), "local");

                if (pkg.version() != pkg1.version()) {
                    conflPackages.append(pkg.name());
                } else {
                    pkg = pkg1;
                    installed = true;
                }
            }

            ShamanTreeWidgetItem *item = new ShamanTreeWidgetItem();
            Group::List grps = Backend::instance()->getPackageGroups(pkg);
            QString grStr;

            item->setData(0, Qt::UserRole + 1, QVariant::fromValue(pkg));

            if (installed) {
                //item->setText(0, tr("Installed"));
                item->setIcon(0, QIcon(":/Icons/icons/user-online.png"));
                item->setData(0, Qt::UserRole, (int)2);
            } else {
                //item->setText(0, tr("Not Installed"));
                item->setIcon(0, QIcon(":/Icons/icons/user-offline.png"));
                item->setData(0, Qt::UserRole, (int)0);
            }

            item->setText(3, pkg.version());
            item->setText(1, pkg.name());
            item->setText(5, db.name());
            item->setText(4, PackageProperties::formatSize(pkg.size()));
            item->setData(4, Qt::UserRole, pkg.size());
            item->setText(7, pkg.desc());

            foreach(const Group &group, grps) {
                grStr.append(' ');
                grStr.append(group.name());
            }
            grStr.append(' ');

            item->setText(6, grStr);

            retlist.append(item);

            count++;

            emit updateProgress((int)(count / totalPkgs) * 100);
        }
    }

    foreach(Package pkg, Backend::instance()->getPackagesFromDatabase(Backend::instance()->getLocalDatabase())) {
        ShamanTreeWidgetItem *item = new ShamanTreeWidgetItem();

        item->setIcon(0, QIcon(":/Icons/icons/user-online.png"));
        item->setData(0, Qt::UserRole, (int)2);
        item->setData(0, Qt::UserRole + 1, QVariant::fromValue(pkg));
        item->setText(1, pkg.name());
        item->setText(3, pkg.version());
        item->setText(7, pkg.desc());
        item->setText(5, "local");
        item->setText(4, PackageProperties::formatSize(pkg.size()));
        item->setData(4, Qt::UserRole, (int)pkg.size());

        retlist.append(item);
    }

    foreach(const QString &ent, conflPackages) {
        int count = 0;
        QTreeWidgetItem *match = 0;

        foreach(QTreeWidgetItem *itm, retlist) {
            if (itm->text(1) == ent) {
                count++;
                match = itm;
            }
        }

        if (count == 1) {
            match->setIcon(0, QIcon(":/Icons/icons/user-online.png"));
            match->setData(0, Qt::UserRole, (int)2);
            match->setText(3, Backend::instance()->getPackage(match->text(1), "local").version());
        }
    }
}

// MainWindow Definition

MainWindow::MainWindow(QMainWindow *parent)
#ifndef KDE4_INTEGRATION
        : QMainWindow(parent),
#else
        : KMainWindow(parent),
#endif
        queueDl(),
        dbdialog(),
        upDl(),
        configDialog(),
        qUi(),
        bHandler(),
        nView(),
        lView(),
        stBar(),
        reviewQueue(),
        trayicon(),
        upActive(false),
        revActive(false),
        dbActive(false),
        quiActive(false),
        turnOffSys(false)
{
    setupUi(this);
    addDockWidget(Qt::LeftDockWidgetArea, repoDockWidget);
    addDockWidget(Qt::BottomDockWidgetArea, pkgDockWidget);

    new ShamanAdaptor(this);

    QDBusConnection dbus = QDBusConnection::systemBus();

    dbus.registerObject("/Shaman", this);

    newsReader = new ArchLinuxNewsReader();

    newsReader->setUpdateInterval();

    qDebug() << "Shaman registered on the System Bus as" << dbus.baseService();

    if (!dbus.registerService("org.archlinux.shaman"))
        qWarning() << "Failed to register alias Service on DBus";
    else
        qDebug() << "Service org.archlinux.shaman successfully exported on the System Bus.";

    editTimer = new QTimer(this);
    editTimer->setSingleShot(true);

    connect(editTimer, SIGNAL(timeout()), SLOT(refinePkgView()));

    pkgsViewWG->setContextMenuPolicy(Qt::CustomContextMenu);
    repoList->setContextMenuPolicy(Qt::CustomContextMenu);
    pkgsViewWG->hideColumn(7);
    pkgsViewWG->hideColumn(8);
    resize(500, size().height());
    pkgsViewWG->headerItem()->setIcon(0, QIcon(":/Icons/icons/user-invisible.png"));
    pkgsViewWG->headerItem()->setText(0, QString());   //Set text to ""
    pkgsViewWG->setColumnWidth(0, 30);  //TODO: Remember column-width
    pkgsViewWG->headerItem()->setIcon(2, QIcon(":/Icons/icons/applications-development.png"));
    pkgsViewWG->headerItem()->setText(2, QString());
    pkgsViewWG->setColumnWidth(2, 30);
    pkgsViewWG->setAllColumnsShowFocus(true);

    nameDescBox->addItem(tr("Name"));
    nameDescBox->addItem(tr("Description"));
    nameDescBox->addItem(tr("Name and Description"));

    PolkitQt::Action *actionUpdate_Database = new PolkitQt::Action("org.chakraproject.aqpm.updatedatabase", this);
    actionUpdate_Database->setText(tr("Update Database"));
    actionUpdate_Database->setIcon(QIcon(":/Icons/icons/view-refresh.png"));
    connect(actionUpdate_Database, SIGNAL(triggered(bool)), actionUpdate_Database, SLOT(activate()));
    connect(actionUpdate_Database, SIGNAL(activated()), this, SLOT(doDbUpdate()));
    mToolBar->insertAction(actionUpgrade_System, actionUpdate_Database);
    menuActions->insertAction(actionUpgrade_System, actionUpdate_Database);

    PolkitQt::Action *actionProcess_Queue = new PolkitQt::Action("org.chakraproject.aqpm.processqueue", this);
    actionProcess_Queue->setText(tr("Process Queue"));
    actionProcess_Queue->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
    connect(actionProcess_Queue, SIGNAL(triggered(bool)), actionProcess_Queue, SLOT(activate()));
    connect(actionProcess_Queue, SIGNAL(activated()), this, SLOT(widgetQueueToAlpmQueue()));
    mToolBar->insertAction(actionUpgrade_System, actionProcess_Queue);
    menuActions->insertAction(actionUpgrade_System, actionProcess_Queue);

    connect(Backend::instance(), SIGNAL(streamTransQuestion(Aqpm::Globals::TransactionQuestion, QVariantMap)), this,
            SLOT(streamTransQuestion(Aqpm::Globals::TransactionQuestion, QVariantMap)));
    connect(pkgsViewWG, SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showPkgsViewContextMenu()));
    connect(repoList, SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showRepoViewContextMenu()));
    connect(switchToRepo, SIGNAL(clicked()), SLOT(populateRepoColumn()));
    connect(switchToGrps, SIGNAL(clicked()), SLOT(populateGrpsColumn()));
    connect(removeButton, SIGNAL(clicked()), SLOT(removePackage()));
    connect(completeRemoveButton, SIGNAL(clicked()), SLOT(completeRemovePackage()));
    connect(cancelButton, SIGNAL(clicked()), SLOT(cancelAction()));
    connect(actionUpgrade_System, SIGNAL(triggered()), SLOT(fullSysUpgrade()));
    connect(packageSwitchCombo, SIGNAL(currentIndexChanged(int)), SLOT(refinePkgView()));
    connect(nameDescBox, SIGNAL(currentIndexChanged(int)), SLOT(refinePkgView()));
    connect(searchLine, SIGNAL(textChanged(const QString&)), SLOT(triggerEditTimer()));
    connect(refineRepoEdit, SIGNAL(textChanged(const QString&)), SLOT(refineRepoView()));
    connect(actionPacman_Preferences, SIGNAL(triggered()), SLOT(showSettings()));
    connect(actionQuit, SIGNAL(triggered()), SLOT(quitApp()));
    connect(actionAbout, SIGNAL(triggered()), SLOT(showAboutDialog()));
    connect(actionInstall_Package_From_File, SIGNAL(triggered()), SLOT(getPackageFromFile()));
    connect(actionUpdate_ABS_Tree, SIGNAL(triggered()), SLOT(updateABSTree()));
    connect(actionBuild_and_Install_Selected, SIGNAL(triggered()), SLOT(initSourceQueue()));
    connect(actionCancel_all_actions, SIGNAL(triggered()), SLOT(cancelAllActions()));
    connect(actionReadNews, SIGNAL(triggered()), SLOT(openNewsDialog()));
    connect(actionViewLog, SIGNAL(triggered()), SLOT(openLogViewer()));
    connect(Backend::instance(), SIGNAL(transactionStarted()), SIGNAL(transactionStarted()));
    connect(Backend::instance(), SIGNAL(transactionReleased()), SIGNAL(transactionReleased()));

    connect(Backend::instance(), SIGNAL(errorOccurred(Aqpm::Globals::Errors, QVariantMap)),
            new ErrorHandler(this), SLOT(spawnErrorDialog(Aqpm::Globals::Errors, QVariantMap)));

    completeRemoveButton->setEnabled(false);   // Until it works...

    addToolBar(new MaintenanceBar(this));

    QSettings *settings = new QSettings();

    if (settings->contains("gui/widgetstate"))
        restoreState(settings->value("gui/widgetstate").toByteArray());

    settings->deleteLater();

    setProxy();

    new QShortcut(QKeySequence("Esc"), searchLine, SLOT(clear()));
    new QShortcut(QKeySequence("F5"), this, SLOT(doDbUpdate()));
    new QShortcut(QKeySequence(tr("Ctrl+Q", "Exit Shaman Shortcut")), this, SLOT(quitApp()));

    stBar = new ShamanStatusBar(this);

    setStatusBar(stBar);

    return;
}

MainWindow::~MainWindow()
{
    return;
}

void MainWindow::setUpTrayIcon()
{
    trayicon = new ShamanTrayIcon(this);

    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            SLOT(systrayActivated(QSystemTrayIcon::ActivationReason)));
    connect(trayicon, SIGNAL(startDbUpdate()), SLOT(doDbUpdate()));
    connect(trayicon, SIGNAL(upgradePkgs()), SLOT(startUpgrading()));
    connect(this, SIGNAL(startTimer()), trayicon, SLOT(startTimer()));
    connect(this, SIGNAL(stopTimer()), trayicon, SLOT(stopTimer()));
    connect(newsReader, SIGNAL(newItems()), trayicon, SLOT(newNewsAvailable()));
    connect(newsReader, SIGNAL(fetchingFailed()), trayicon, SLOT(newsFetchingFailed()));
}

void MainWindow::streamReadySignal()
{
    emit shamanReady();
}

void MainWindow::quitApp()
{
    QSettings *settings = new QSettings();

    settings->setValue("gui/size", size());
    settings->setValue("gui/pos", pos());
    settings->setValue("gui/widgetstate", saveState());

    settings->deleteLater();

    QCoreApplication::quit();
}

void MainWindow::closeEvent(QCloseEvent *evt)
{
    if (!trayicon) {
        evt->accept();
        QCoreApplication::quit();
    }


    ShamanDialog::popupDialogDontShow(QString(tr("Shaman - Reducing To Tray")),
                                      QString(tr("Shaman will keep running in the system tray.\n"
                                                 "To close it, click Quit in the file menu "
                                                 "or in the tray icon context menu.\nWhile in the "
                                                 "System Tray, Shaman will update your Databases\nat a regular"
                                                 " interval and notify you about available upgrades.\n"
                                                 "You can change this behaviour in Settings.")),
                                      "gui/confirmquit", this, ShamanProperties::InformationDialog);

    emit startTimer();

    evt->accept();
}

void MainWindow::removePackagesView()
{
    QTreeWidgetItem *itm;

    while ((itm = pkgsViewWG->takeTopLevelItem(0)) != NULL)
        delete(itm);

}

void MainWindow::removeRepoColumn()
{
    QListWidgetItem *itm;

    while ((itm = repoList->takeItem(0)) != 0)
        delete itm;

    disconnect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), 0, 0);
}

void MainWindow::populatePackagesView()
{
    pkgsViewWG->setSortingEnabled(false);

    disconnect(pkgsViewWG, SIGNAL(itemSelectionChanged()), 0, 0);
    disconnect(PkgInfos, SIGNAL(currentChanged(int)), 0, 0);
    disconnect(pkgsViewWG, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), 0, 0);

    removePackagesView();

    if (cThread)
        cThread->deleteLater();

    cThread = new CreateItemsThread(Backend::instance());

    connect(cThread, SIGNAL(finished()), SLOT(populatePackagesViewFinished()));
    connect(cThread, SIGNAL(updateProgress(int)), stBar, SLOT(updateProgressBar(int)));

    stBar->startProgressBar();

    cThread->start();
}

void MainWindow::populatePackagesViewFinished()
{
    pkgsViewWG->addTopLevelItems(cThread->getResult());

    cThread->deleteLater();

    pkgsViewWG->sortItems(1, Qt::AscendingOrder);
    pkgsViewWG->setSortingEnabled(true);  //Enable sorting *after* inserting :D
    QAbstractItemModel *model = pkgsViewWG->model();

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    proxyModel->setSortRole(Qt::UserRole);

    stBar->stopProgressBar();

    connect(pkgsViewWG, SIGNAL(itemSelectionChanged()), this,
            SLOT(itemChanged()));

    connect(PkgInfos, SIGNAL(currentChanged(int)), SLOT(showPkgInfo()));
    connect(pkgsViewWG, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), SLOT(shiftItemAction()));

    refinePkgView();

    emit packagesLoaded();
}

void MainWindow::shiftItemAction()
{
    if (!pkgsViewWG->selectedItems().first()->text(8).isEmpty()) {
        cancelAction();
    } else if (Backend::instance()->isInstalled(pkgsViewWG->selectedItems().first()->data(0, Qt::UserRole + 1).value<Package>())) {
        removePackage();
    } else {
        installPackage();
    }
}

void MainWindow::populateRepoColumn()
{
    qDebug() << "Populating Repo column";

    switchToGrps->setChecked(false);
    repoDockWidget->setWindowTitle(tr("Repositories"));
    Database::List list = Backend::instance()->getAvailableDatabases();

    removeRepoColumn();

    QListWidgetItem *item = new QListWidgetItem(repoList);

    item->setText(tr("All Repositories"));
    item->setSelected(true);

    foreach(const Database &db, list) {
        QListWidgetItem *item = new QListWidgetItem(repoList);

        item->setText(db.name());
        item->setData(Qt::UserRole, QVariant::fromValue(db));
    }


    QListWidgetItem *itm = new QListWidgetItem(repoList);

    itm->setText(tr("Local Packages"));

    refineRepoView();

    connect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), this,
            SLOT(refinePkgView()));
}

void MainWindow::populateGrpsColumn()
{
    switchToRepo->setChecked(false);
    repoDockWidget->setWindowTitle(tr("Package Groups"));
    Group::List grps = Backend::instance()->getAvailableGroups();

    removeRepoColumn();

    foreach(const Group &g, grps) {
        QListWidgetItem *item = new QListWidgetItem(repoList);

        item->setText(g.name());
        item->setData(Qt::UserRole, QVariant::fromValue(g));
    }

    repoList->sortItems(Qt::AscendingOrder);

    QListWidgetItem *item = new QListWidgetItem();

    item->setText(tr("All Groups"));
    item->setSelected(true);
    repoList->insertItem(0, item);

    refineRepoView();

    connect(repoList, SIGNAL(itemPressed(QListWidgetItem*)), this,
            SLOT(refinePkgView()));
    editTimer->setInterval(800);
}

void MainWindow::refinePkgView()
{
    qDebug() << "refinePkgView";

    QList<QTreeWidgetItem*> list = pkgsViewWG->findItems(QString(), Qt::MatchRegExp | Qt::MatchWildcard);

    // Now first: What do we need to refine in the right column?
    if (list.isEmpty() && list.count() >= 0)
        return;

    if (repoList->selectedItems().count() > 0) {
        if ((repoList->selectedItems().at(0)->text().compare(tr("All Repositories")) &&
                repoList->selectedItems().at(0)->text().compare(tr("All Groups"))) &&
                !repoList->selectedItems().isEmpty()) {
            if (!repoList->findItems(QString(tr("All Repositories")),
                                     (Qt::MatchFlags)Qt::MatchExactly).isEmpty())
                // First time, so don't check anything.
                if (repoList->selectedItems().at(0)->text().compare(tr("Local Packages")))
                    list = pkgsViewWG->findItems(repoList->selectedItems().at(0)->text(),
                                                 (Qt::MatchFlags)Qt::MatchExactly, 5);
                else
                    list = pkgsViewWG->findItems("local",
                                                 (Qt::MatchFlags)Qt::MatchExactly, 5);
            else {
                list = pkgsViewWG->findItems(repoList->selectedItems().at(0)->text(),
                                             (Qt::MatchFlags)Qt::MatchExactly, 6);
                QString tmp = repoList->selectedItems().at(0)->text();
                tmp.append(" ");
                tmp.prepend(" ");
                list += pkgsViewWG->findItems(tmp,
                                              (Qt::MatchFlags)Qt::MatchContains, 6);
            }
        } else {
            for (int i = 0; i < pkgsViewWG->topLevelItemCount(); ++i) {
                list += pkgsViewWG->topLevelItem(i);
            }
        }
    }
    qDebug() << "The left TextBox is over, let's do the ComboBox";
    if (!packageSwitchCombo->currentIndex() == 0) {
        qDebug() << "Hehe, we should not show all Packages";
        if (packageSwitchCombo->currentText() == tr("Installed packages")) {
            //qDebug() << "We should only show the installed packages";
            foreach(QTreeWidgetItem *item, list) {
                //qDebug() << "Checking for installed packages" + item->text(2);
                if (!Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()))
                    list.removeAt(list.indexOf(item));
            }
        }
        if (packageSwitchCombo->currentText() == tr("Not installed packages")) {
            foreach(QTreeWidgetItem *item, list) {
                //qDebug() << "Checking for installed packages" + item->text(2);
                if (Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()))
                    list.removeAt(list.indexOf(item));
            }
        }
        if (packageSwitchCombo->currentText() == tr("Upgradeable packages")) {
            Package::List upgrList = Backend::instance()->getUpgradeablePackages();
            foreach(QTreeWidgetItem *item, list) {
                //qDebug() << "Checking for upgradeable packages" + item->text(2);
                if (!Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()) ||
                        !upgrList.contains(item->data(0, Qt::UserRole + 1).value<Package>())) {
                    list.removeAt(list.indexOf(item));
                }
            }
        }
        if (packageSwitchCombo->currentText() == tr("Packages in Queue")) {
            foreach(QTreeWidgetItem *item, list) {
                //qDebug() << "Checking for installed packages" + item->text(2);
                if (item->text(8).isEmpty()) {
                    list.removeAt(list.indexOf(item));
                }
            }
        }
    } else
        qDebug() << "Show all packages";

    if (!searchLine->text().isEmpty()) {
        foreach(QTreeWidgetItem *item, list) {
            if (nameDescBox->currentText() == tr("Name")) {
                if (!item->text(1).contains(searchLine->text(), Qt::CaseInsensitive)) {
                    list.removeAt(list.indexOf(item));
                }
            } else if (nameDescBox->currentText() == tr("Description")) {
                if (!item->text(7).contains(searchLine->text(), Qt::CaseInsensitive)) {
                    list.removeAt(list.indexOf(item));
                }
            } else if (nameDescBox->currentText() == tr("Name and Description")) {
                if (!item->text(7).contains(searchLine->text(), Qt::CaseInsensitive) &&
                        !item->text(1).contains(searchLine->text(), Qt::CaseInsensitive)) {
                    list.removeAt(list.indexOf(item));
                }
            }
        }
    }


    /* When we are here, we have a list that contains the packages refined
     * by all of our three components. And then we set that list to be
     * visible. */

    for (int i = 0; i < pkgsViewWG->topLevelItemCount(); ++i) {
        QTreeWidgetItem *tmpitm = pkgsViewWG->topLevelItem(i);

        if (list.contains(tmpitm))
            tmpitm->setHidden(false);
        else
            tmpitm->setHidden(true);
    }
}

void MainWindow::refineRepoView()
{
    QList<QListWidgetItem*> list;
    for (int i = 0; i < repoList->count(); ++i)
        list.append(repoList->item(i));

    // Now first: What do we need to refine in the right column?
    if (list.isEmpty() && list.count() >= 0) {
        qDebug() << "Nothing in the view";
        return;
    }

    if (!refineRepoEdit->text().isEmpty()) {
        foreach(QListWidgetItem *item, list) {
            if (!item->text().contains(refineRepoEdit->text(), Qt::CaseInsensitive)) {
                list.removeAt(list.indexOf(item));
            }
        }
    }


    /* When we are here, we have a list that contains the packages refined
     * by all of our three components. And then we set that list to be
     * visible. */

    for (int i = 0; i < repoList->count(); ++i) {
        QListWidgetItem *tmpitm = repoList->item(i);

        if (list.contains(tmpitm))
            tmpitm->setHidden(false);
        else
            tmpitm->setHidden(true);
    }
}

void MainWindow::itemChanged()
{
    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    cancelButton->setDisabled(true);
    if (Backend::instance()->isInstalled(pkgsViewWG->selectedItems().first()->data(0, Qt::UserRole + 1).value<Package>())) {
        removeButton->setEnabled(true);
        installButton->setEnabled(true);
        installButton->setText(tr("Mark for Re&installation"));
        completeRemoveButton->setEnabled(true);
        disconnect(installButton, SIGNAL(clicked()), this, SLOT(installPackage()));
        connect(installButton, SIGNAL(clicked()), SLOT(reinstallPackage()));
    }
    if (!Backend::instance()->isInstalled(pkgsViewWG->selectedItems().first()->data(0, Qt::UserRole + 1).value<Package>())) {
        removeButton->setDisabled(true);
        installButton->setEnabled(true);
        installButton->setText(tr("Mark for &Installation"));
        completeRemoveButton->setDisabled(true);
        disconnect(installButton, SIGNAL(clicked()), this, SLOT(reinstallPackage()));
        connect(installButton, SIGNAL(clicked()), SLOT(installPackage()));
    }
    //if (pkgsViewWG->selectedItems().first()->text(1) == tr("Upgradeable"))

    if (pkgsViewWG->selectedItems().first()->text(8) == tr("Install"))
        installButton->setDisabled(true);
    if (pkgsViewWG->selectedItems().first()->text(8) == tr("Uninstall"))
        removeButton->setDisabled(true);
    if (pkgsViewWG->selectedItems().first()->text(8) == tr("Complete Uninstall"))
        completeRemoveButton->setDisabled(true);
    if (!pkgsViewWG->selectedItems().first()->text(8).isEmpty())
        cancelButton->setEnabled(true);

    showPkgInfo();
    stBar->updateStatusBar();
}

void MainWindow::showPkgInfo()
{
    if (pkgsViewWG->selectedItems().isEmpty() || pkgsViewWG->currentItem() == NULL) {
        return;
    }

    QString description;
    bool isLocal = false;
    Package pkg = pkgsViewWG->currentItem()->data(0, Qt::UserRole + 1).value<Package>();
    Database curdb = Backend::instance()->getPackageDatabase(pkg);

    if (PkgInfos->currentIndex() == 0) {
        QTreeWidgetItem *item = pkgsViewWG->selectedItems().first();
        description.append("<b>");
        description.append(pkg.name());
        description.append(" (");
        description.append(pkg.version());
        description.append(")</b><br><br>");
        description.append(pkg.desc());
        description.append("<br><br>");
        description.append("<b>" + tr("Status: ") + "</b> ");
        if (Backend::instance()->isInstalled(pkg))
            description.append(tr("Installed"));     //FIXME: Icon!!!!
        else
            description.append(tr("Not installed"));
        if (Backend::instance()->isInstalled(pkg)) {
            description.append("<br><b>" + tr("Local Version: ") + "</b> ");
            description.append(Backend::instance()->getPackage(pkg.name(), "local").version());
        }
        if (!isLocal) {
            description.append("<br><b>" + tr("Version in the Repository: ") + "</b> ");
            description.append(pkg.version());
        }

        if (!item->text(8).isEmpty()) {
            description.append("<br><b>" + tr("Action: ") + "</b>");
            description.append(item->text(8));    //FIXME: Icon!!!
        }

        pkgInfo->setHtml(description);
    }

    else if (PkgInfos->currentIndex() == 2) {
        dependenciesWidget->clear();
        foreach(const Package &dep, Backend::instance()->getPackageDependencies(pkg)) {
            dependenciesWidget->addItem(dep.name());
        }
    }

    else if (PkgInfos->currentIndex() == 1) {
        filesWidget->clear();
        filesWidget->header()->hide();
        QStringList files = pkg.files();
        foreach(const QString &file, files) {
            QStringList splitted = file.split('/');
            QTreeWidgetItem *parentItem = 0;
            foreach(const QString &spl, splitted) {
                if (spl.isEmpty())
                    continue;
                if (parentItem) {
                    bool there = false;
                    int j = parentItem->childCount();
                    for (int i = 0; i != j; i++) {
                        if (parentItem->child(i)->text(0) == spl) {
                            there = true;
                            parentItem = parentItem->child(i);
                            continue;
                        }
                    }
                    if (!there)
                        parentItem->addChild(new QTreeWidgetItem(parentItem, (QStringList) spl));
                } else {
                    QList<QTreeWidgetItem*> list = filesWidget->findItems(spl, Qt::MatchExactly);
                    if (!list.isEmpty()) {
                        parentItem = list.first();
                    } else {
                        filesWidget->insertTopLevelItem(0, new QTreeWidgetItem(filesWidget, (QStringList) spl));
                    }
                }
            }
        }
    }
}

void MainWindow::doDbUpdate()
{
    dbdialog = new UpdateDbDialog(this);
    dbActive = true;

    emit actionStatusChanged("dbUpdateStarted");

    stBar->startProgressBar();

    if (isVisible())
        dbdialog->show();

    connect(dbdialog, SIGNAL(killMe()), this, SLOT(finishDbUpdate()));
    connect(dbdialog, SIGNAL(pBar(int)), stBar, SLOT(updateProgressBar(int)));

    dbdialog->doAction();
}

void MainWindow::finishDbUpdate()
{
    if (!dbdialog) {
        //Q_ASSERT_X(1 == 2, "finishDbUpdate", "dbdialog seems not to be valid");
        return;
    }

    disconnect(dbdialog, 0, 0, 0);

    if (dbdialog->dbHasBeenUpdated()) {
        populatePackagesView();
        populateRepoColumn();
        populateGrpsColumn();
    }

    qDebug() << "DB Update Finished";

    stBar->stopProgressBar();

    QStringList list;

    foreach(const Package &pkg, Backend::instance()->getUpgradeablePackages()) {
        list.append(pkg.name());
    }

    if (dbdialog->anyErrors()) {
        emit actionStatusChanged("dbUpdateFinished");

        if (dbdialog->isVisible())
            ShamanDialog::popupDialog(tr("Error"), QString(tr("One or more Databases could not "
                                      "be updated.\nLast error reported was:\n%1"))
                                      .arg(QString::fromLocal8Bit(alpm_strerrorlast())),
                                      this, ShamanProperties::ErrorDialog);
        else if (trayicon)
            trayicon->showMessage(QString(tr("Database Update")), QString(tr("One or more Databases could "
                                  "not be updated.\nLast error reported was:\n%1"))
                                  .arg(QString::fromLocal8Bit(alpm_strerrorlast())));

        stBar->showStBarAction(QString(tr("One or more databases failed to update!")),
                               QPixmap(":/Icons/icons/edit-delete.png"));
    } else {
        emit actionStatusChanged("dbUpdateFinished");
        QSettings *settings = new QSettings();
        if (dbdialog->isHidden() && list.isEmpty() && settings->value("scheduledUpdate/updateDbShowNotify").toBool() &&
                trayicon)
            trayicon->showMessage(QString(tr("Database Update")),
                                  QString(tr("Databases Updated Successfully")));

        stBar->showStBarAction(QString(tr("Databases Updated Successfully")),
                               QPixmap(":/Icons/icons/dialog-ok-apply.png"));
    }

    dbdialog->deleteLater();
    dbActive = false;

    if (list.isEmpty())
        return;

    if (list.contains("pacman")) {
        switch (ShamanDialog::popupQuestionDialog(QString(tr("Pacman Update")),
                QString(tr("Pacman can be upgraded. "
                           "It is advised to process it alone\nto avoid version conflicts.\n"
                           "Do you want to Upgrade Pacman now?")), this)) {
        case QMessageBox::Yes:

            /* Ok, let's set up a special queue for Shaman. */

            cancelAllActions();
            reinstallPackage("pacman");
            widgetQueueToAlpmQueue();

            break;
        case QMessageBox::No:
            /* Well, just pass by */
            break;
        default:
            // should never be reached
            break;
        }


    } else if (list.contains("shaman") || list.contains("kdemod-shaman")) {
        switch (ShamanDialog::popupQuestionDialog(QString(tr("Shaman Update")),
                QString(tr("Shaman can be upgraded. "
                           "It is advised to process it alone\nto avoid version conflicts.\n"
                           "Do you want to Upgrade Shaman now?")), this)) {
        case QMessageBox::Yes:

            /* Ok, let's set up a special queue for Shaman. */

            qDebug() << "Shaman Queue";

            cancelAllActions();

            if (list.contains("kdemod-shaman"))
                reinstallPackage("kdemod-shaman");
            else
                reinstallPackage("shaman");

            widgetQueueToAlpmQueue();

            break;
        case QMessageBox::No:
            /* Well, just pass by */
            break;
        default:
            // should never be reached
            break;
        }

    } else if (!list.isEmpty()) {
        QSettings *settings = new QSettings();

        if (settings->value("scheduledUpdate/addupgradestoqueue").toBool()) {
            addUpgradeableToQueue();
        }

        settings->deleteLater();
    }
}

void MainWindow::showPkgsViewContextMenu()
{
    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    qDebug() << "Let's show a context menu";
    QTreeWidgetItem *item = pkgsViewWG->selectedItems().first();
    QMenu *menu = new QMenu(this);
    QAction *installAction = menu->addAction(QIcon(":/Icons/icons/list-add.png"),
                             tr("Mark for &Installation"));
    connect(installAction, SIGNAL(triggered()), SLOT(installPackage()));
    QAction *removeAction = menu->addAction(QIcon(":/Icons/icons/list-remove.png"),
                                            tr("Mark for &Removal"));
    connect(removeAction, SIGNAL(triggered()), SLOT(removePackage()));
    QAction *upgradeAction = menu->addAction(QIcon(":/Icons/icons/edit-redo.png"),
                             tr("Mark for Upgrade"));
    connect(upgradeAction, SIGNAL(triggered()), SLOT(upgradePackage()));
    QAction *cancelAction = menu->addAction(QIcon(":/Icons/icons/dialog-cancel.png"),
                                            tr("&Cancel Action"));
    connect(cancelAction, SIGNAL(triggered()), SLOT(cancelAction()));

    menu->addSeparator();

    QAction *infoAction = menu->addAction(QIcon(":/Icons/icons/help-about.png"),
                                          tr("Package Information"));
    connect(infoAction, SIGNAL(triggered()), SLOT(showInfoDialog()));


    if (Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()) &&
            Backend::instance()->getUpgradeablePackages().contains(item->data(0, Qt::UserRole + 1).value<Package>())) {
        installAction->setText(tr("Mark for Re&installation"));
        disconnect(installAction, 0, 0, 0);
        connect(installAction, SIGNAL(triggered()), SLOT(reinstallPackage()));
        removeAction->setDisabled(true);
    } else if (!Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>())) {
        removeAction->setDisabled(true);
        upgradeAction->setDisabled(true);
    } else { //Package is marked as installed
        installAction->setText(tr("Mark for Re&installation"));
        disconnect(installAction, 0, 0, 0);
        connect(installAction, SIGNAL(triggered()), SLOT(reinstallPackage()));
        upgradeAction->setDisabled(true);
    }//FIXME: Add completeRemove-action

    if (item->text(8).isEmpty())
        cancelAction->setDisabled(true);
    else if (item->text(8) == tr("Install"))
        installAction->setDisabled(true);
    else if (item->text(8) == tr("Uninstall"))
        removeAction->setDisabled(true);
    else //Upgrade
        upgradeAction->setDisabled(true);


    menu->popup(QCursor::pos());
}

void MainWindow::showRepoViewContextMenu()
{
    if (repoList->selectedItems().isEmpty())
        return;

    //QListWidgetItem *item = repoList->selectedItems().first();
    QMenu *menu = new QMenu(this);
    QAction *installAction = menu->addAction(QIcon(":/Icons/icons/list-add.png"),
                             tr("Mark all for installation"));
    connect(installAction, SIGNAL(triggered()), SLOT(installAllRepoPackages()));
    QAction *reinstallAction = menu->addAction(QIcon(":/Icons/icons/list-add.png"),
                               tr("Mark all for reinstallation"));
    connect(reinstallAction, SIGNAL(triggered()), SLOT(reinstallAllRepoPackages()));
    QAction *removeAction = menu->addAction(QIcon(":/Icons/icons/list-remove.png"),
                                            tr("Mark all for removal"));
    connect(removeAction, SIGNAL(triggered()), SLOT(removeAllRepoPackages()));
    QAction *cancelAction = menu->addAction(QIcon(":/Icons/icons/dialog-cancel.png"),
                                            tr("Cancel all actions"));
    connect(cancelAction, SIGNAL(triggered()), SLOT(cancelAllRepoActions()));

    menu->popup(QCursor::pos());
}

void MainWindow::cancelAllActions()
{
    foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(QString(), Qt::MatchRegExp | Qt::MatchWildcard)) {
        if (!item->text(8).isEmpty())
            item->setText(8, QString());

        item->setIcon(2, QIcon());
    }

    stBar->updateStatusBar();
}

void MainWindow::installAllRepoPackages()
{
    qDebug() << "InstallAllRepoPackages";
    if (repoList->selectedItems().isEmpty())
        return;
    qDebug() << "InstallAllRepoPackages1";

    if (!repoList->findItems(tr("All Groups"), Qt::MatchExactly).isEmpty()) {
        QString tmp = repoList->selectedItems().first()->text();
        tmp.append(" ");
        tmp.prepend(" ");
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(tmp, (Qt::MatchFlags)Qt::MatchContains, 6)) {
            installPackage(item->text(1));
        }
    } else {
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(repoList->selectedItems().first()->text(),
                Qt::MatchExactly, 5)) {
            installPackage(item->text(1));
        }
    }

    stBar->updateStatusBar();
}

void MainWindow::reinstallAllRepoPackages()
{
    qDebug() << "InstallAllRepoPackages";
    if (repoList->selectedItems().isEmpty())
        return;
    qDebug() << "InstallAllRepoPackages1";

    if (!repoList->findItems(tr("All Groups"), Qt::MatchExactly).isEmpty()) {
        QString tmp = repoList->selectedItems().first()->text();
        tmp.append(" ");
        tmp.prepend(" ");
        qDebug() << "Hehe";
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(tmp, (Qt::MatchFlags)Qt::MatchContains, 6)) {
            if (Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()))
                reinstallPackage(item->text(1));
        }
    } else {
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(repoList->selectedItems().first()->text(),
                Qt::MatchExactly, 5)) {
            if (Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()))
                reinstallPackage(item->text(1));
        }
    }

    stBar->updateStatusBar();
}

void MainWindow::removeAllRepoPackages()
{
    if (repoList->selectedItems().isEmpty())
        return;

    if (!repoList->findItems(tr("All Groups"), Qt::MatchExactly).isEmpty()) {
        QString tmp = repoList->selectedItems().first()->text();
        tmp.append(" ");
        tmp.prepend(" ");
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(tmp, (Qt::MatchFlags)Qt::MatchContains, 6)) {
            removePackage(item->text(1));
        }
    } else {
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(repoList->selectedItems().first()->text(),
                (Qt::MatchFlags)Qt::MatchExactly, 5)) {
            removePackage(item->text(1));
        }
    }

    stBar->updateStatusBar();
}

void MainWindow::cancelAllRepoActions()
{
    if (repoList->selectedItems().isEmpty())
        return;

    if (!repoList->findItems(tr("All Groups"), Qt::MatchExactly).isEmpty()) {
        QString tmp = repoList->selectedItems().first()->text();
        tmp.append(" ");
        tmp.prepend(" ");
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(tmp, (Qt::MatchFlags)Qt::MatchContains, 6)) {
            cancelAction(item->text(1));
        }
    } else {
        foreach(QTreeWidgetItem *item, pkgsViewWG->findItems(repoList->selectedItems().first()->text(),
                (Qt::MatchFlags)Qt::MatchContains, 5)) {
            cancelAction(item->text(1));
        }
    }

    stBar->updateStatusBar();
}

void MainWindow::installPackage()
{
    qDebug() << "Install Package";

    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    foreach(QTreeWidgetItem *item, pkgsViewWG->selectedItems()) {
        qDebug() << "Streaming package";

        if (Backend::instance()->isProviderInstalled(item->text(1))) {
            switch (ShamanDialog::popupQuestionDialog(tr("Shaman"),
                    QString(tr("A package providing %1 is already installed.\n"
                               "Do you want to install %1 anyway?")).arg(item->text(1)),
                    this, ShamanProperties::WarningDialog)) {
            case QMessageBox::Yes:
                break;
            case QMessageBox::No:
                return;
                break;
            default:
                break;
            }
        }

        installPackage(item->text(1), item->text(5));
    }

    itemChanged();
}

void MainWindow::reinstallPackage()
{
    qDebug() << "Install Package";

    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    foreach(QTreeWidgetItem *item, pkgsViewWG->selectedItems()) {
        reinstallPackage(item->text(1), item->text(5));
    }

    itemChanged();
}

void MainWindow::reinstallPackage(const QString &package, const QString &repo)
{
    if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).isEmpty()) {
        qDebug() << "Can't find package: " + package;
        return;
    }

    QTreeWidgetItem *item;

    if (repo.isEmpty())
        item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).first();
    else {
        item = NULL;

        foreach(QTreeWidgetItem *ent, pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1)) {
            if (ent->text(5) == repo)
                item = ent;
        }

        if (!item)
            return;
    }

    qDebug() << item->text(1);

    if (item->text(8) == tr("Install"))
        return;
    else {
        item->setText(8, tr("Install"));
        item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
    }
}

void MainWindow::installPackage(const QString &package, const QString &repo)
{
    qDebug() << "Install package: " + package;

    if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).isEmpty()) {
        qDebug() << "Can't find package: " + package;
        return;
    }

    QTreeWidgetItem *item;

    if (repo.isEmpty()) {
        item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).first();
    } else {
        item = NULL;

        foreach(QTreeWidgetItem *ent, pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1)) {
            if (ent->text(5) == repo) {
                item = ent;
            }
        }

        if (!item)
            return;
    }

    qDebug() << item->text(1);

    if (Backend::instance()->isProviderInstalled(package)) {
        return;
    }

    if (item->text(8) == tr("Install") || Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>())) {
        return;
    } else {
        item->setText(8, tr("Install"));
        item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
    }
    qDebug() << item->text(5);


    foreach(const Package &dep, Backend::instance()->getPackageDependencies(item->data(0, Qt::UserRole + 1).value<Package>())) {
        qDebug() << "Found dep" << dep.name();
        installPackage(dep.name());
    }
}

void MainWindow::removePackage()
{
    qDebug() << "Remove Package";

    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    foreach(QTreeWidgetItem *item, pkgsViewWG->selectedItems())
    removePackage(item->text(1), item->text(5));

    itemChanged();
}

void MainWindow::removePackage(const QString &package, const QString &repo)
{
    qDebug() << "Uninstall package: " + package;
    if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).isEmpty()) {
        qDebug() << "Can't find package: " + package;
        return;
    }

    QTreeWidgetItem *item;

    if (repo.isEmpty())
        item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).first();
    else {
        item = NULL;

        foreach(QTreeWidgetItem *ent, pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1)) {
            if (ent->text(5) == repo)
                item = ent;
        }

        if (!item)
            return;
    }

    qDebug() << item->text(1);

    if (!Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()) ||
            item->text(8) == tr("Uninstall"))
        return;
    else {
        item->setText(8, tr("Uninstall"));
        item->setIcon(2, QIcon(":/Icons/icons/list-remove.png"));
    }
    qDebug() << item->text(5);

    foreach(const Package &dep, Backend::instance()->getDependenciesOnPackage(item->data(0, Qt::UserRole + 1).value<Package>())) {
        removePackage(dep.name());
    }
}

void MainWindow::completeRemovePackage()
{
    qDebug() << "Complete Remove Package";

    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    QTreeWidgetItem *item = pkgsViewWG->selectedItems().first();

    qDebug() << item->text(1);

    if (!Backend::instance()->isInstalled(item->data(0, Qt::UserRole + 1).value<Package>()))
        return;
    else {
        item->setText(8, tr("Complete Uninstall"));
        item->setIcon(2, QIcon(":/Icons/icons/edit-delete.png"));
    }

    //Now we remove the on-package-dependencies and the dependencies...

    foreach(const Package &onDep, Backend::instance()->getDependenciesOnPackage(item->data(0, Qt::UserRole + 1).value<Package>())) {
        removePackage(onDep.name());
    }
    foreach(const Package &dep, Backend::instance()->getPackageDependencies(item->data(0, Qt::UserRole + 1).value<Package>())) {
        removePackage(dep.name());
    }

    itemChanged();
}

void MainWindow::cancelAction()
{
    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    foreach(QTreeWidgetItem *item, pkgsViewWG->selectedItems())
    cancelAction(item->text(1), item->text(5));

    itemChanged();
}

void MainWindow::cancelAction(const QString &package, const QString &repo)
{
    qDebug() << "cancel action for: " + package;
    if (pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).isEmpty()) {
        qDebug() << "Can't find package: " + package;
        return;
    }

    QTreeWidgetItem *item;

    if (repo.isEmpty())
        item = pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1).first();
    else {
        item = NULL;

        foreach(QTreeWidgetItem *ent, pkgsViewWG->findItems(package, (Qt::MatchFlags)Qt::MatchExactly, 1)) {
            if (ent->text(5) == repo)
                item = ent;
        }

        if (!item)
            return;
    }

    if (item->text(8).isEmpty())
        return;

    item->setText(8, QString());
    item->setIcon(2, QIcon());

    foreach(const Package &onDep, Backend::instance()->getDependenciesOnPackage(item->data(0, Qt::UserRole + 1).value<Package>())) {
        cancelAction(onDep.name());
    }
    foreach(const Package &dep, Backend::instance()->getPackageDependencies(item->data(0, Qt::UserRole + 1).value<Package>())) {
        cancelAction(dep.name());
    }

}

void MainWindow::startUpgrading()
{
    if (dbdialog) {
        disconnect(dbdialog, 0, 0, 0);

        if (dbdialog->dbHasBeenUpdated()) {
            populatePackagesView();
            populateRepoColumn();
            populateGrpsColumn();
            stBar->updateStatusBar();
        }
    }

    QStringList list;

    foreach(const Package &pkg, Backend::instance()->getUpgradeablePackages()) {
        list.append(pkg.name());
    }

    stBar->stopProgressBar();

    if (list.isEmpty()) {
        emit systemIsUpToDate();

        if (isVisible()) {
            ShamanDialog::popupDialog(tr("System Upgrade"), tr("Your system is up to date!"), this);
        } else {
            trayicon->showMessage(QString(tr("System Upgrade")), QString(tr("Your system is up to date!")));
        }

        stBar->showStBarAction(QString(tr("Your system is up to date!")), QPixmap(":/Icons/icons/dialog-ok-apply.png"));

        qDebug() << "System is up to date";
    } else {
        upgrade(list);
    }

    if (dbdialog) {
        dbdialog->deleteLater();
        dbdialog = 0;
        dbActive = false;
    }
}

void MainWindow::upgrade(const QStringList &packages)
{
    if (packages.contains("pacman")) {
        switch (ShamanDialog::popupQuestionDialog(QString(tr("Pacman Update")), QString(tr("Pacman can be upgraded. "
                "It is advised to process it alone\nto avoid version conflicts.\n"
                "Do you want to Upgrade Pacman now?")), this)) {
        case QMessageBox::Yes:
            /* Ok, let's set up a special queue for Shaman. */

            cancelAllActions();
            reinstallPackage("pacman");
            widgetQueueToAlpmQueue();

            break;
        case QMessageBox::No:
            /* Well, just pass by */
            break;
        default:
            // should never be reached
            break;
        }
    } else if (packages.contains("shaman") || packages.contains("kdemod4-shaman")) {
        switch (ShamanDialog::popupQuestionDialog(QString(tr("Shaman Update")), QString(tr("Shaman can be upgraded. "
                "It is advised to process it alone\nto avoid version conflicts.\n"
                "Do you want to Upgrade Shaman now?")), this)) {
        case QMessageBox::Yes:
            /* Ok, let's set up a special queue for Shaman. */

            cancelAllActions();

            if (packages.contains("kdemod4-shaman"))
                reinstallPackage("kdemod4-shaman");
            else
                reinstallPackage("shaman");

            widgetQueueToAlpmQueue();

            break;
        case QMessageBox::No:
            /* Well, just pass by */
            break;
        default:
            // should never be reached
            break;
        }
    } else {
        /* Something to upgrade! Cool! Let's show our user the
         * upgrade dialog */
        /* Preferences are handled in SysUpgradeDialog, there's
         * a reason for that :)
         */

        qDebug() << "Streaming Upgrades";

        emit upgradesAvailable();

        QSettings *settings = new QSettings();

        if (settings->value("newsreader/userss", true).toBool() &&
                settings->value("newsreader/queuenotifier", true).toBool()) {
            foreach(const QString &ent, packages) {
                if (newsReader->checkUnreadNewsOnPkg(ent)) {
                    switch (ShamanDialog::popupQuestionDialog(QString(tr("News Alert")),
                            QString(tr("There is an unread news about %1.\nDo you want to read it?")
                                   ).arg(ent), this)) {
                    case QMessageBox::Yes:
                        openNewsDialog();
                        return;
                        break;
                    case QMessageBox::No:
                        break;
                    default:
                        // should never be reached
                        break;
                    }
                }
            }
        }

        settings->deleteLater();

        upDl = new SysUpgradeDialog(this);

        connect(upDl, SIGNAL(aborted()), SLOT(upgradeAborted()));
        connect(upDl, SIGNAL(upgradeNow()), SLOT(processQueue()));
        connect(upDl, SIGNAL(addToPkgQueue()), SLOT(addUpgradeableToQueue()));

        upDl->init();
        upActive = true;
    }

}

void MainWindow::upgradeAborted()
{
    upDl->deleteLater();
    upActive = false;
}

void MainWindow::addUpgradeableToQueue()
{
    if (upDl)
        upDl->deleteLater();

    qDebug() << "UpgradeableToQueue";

    if (Backend::instance()->getUpgradeablePackages().isEmpty()) {
        return;
    }

    disconnect(this, SIGNAL(packagesLoaded()), this, SLOT(addUpgradeableToQueue()));

    if (!pkgsViewWG->topLevelItemCount()) {
        connect(this, SIGNAL(packagesLoaded()), this, SLOT(addUpgradeableToQueue()));
        return;
    }

    foreach(const Package &package, Backend::instance()->getUpgradeablePackages()) {
        QTreeWidgetItem *item = pkgsViewWG->findItems(package.name(), Qt::MatchExactly, 1).first();
        item->setIcon(0, QIcon(":/Icons/icons/user-invisible.png"));
        item->setText(8, tr("Upgrade"));
        item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
    }

    if (upDl) {
        upDl->deleteLater();
        upActive = false;
    }
    return;
}

void MainWindow::fullSysUpgrade()
{
    startUpgrading();
}

void MainWindow::upgradePackage()
{
    qDebug() << "Upgrade Package";
    foreach(QTreeWidgetItem *item, pkgsViewWG->selectedItems()) {
        item->setText(8, tr("Upgrade"));    //Look if there are dependencies for the upgrade
        item->setIcon(2, QIcon(":/Icons/icons/list-add.png"));
    }
}

void MainWindow::processQueue()
{
    qDebug() << "Process Queue";

    /* This Function will only do the processing stuff. We'd better
     * keep things modular as possible due to libalpm's design.
     * So the "Process Queue" button does not point here, but
     * to a function that reads the queue and prepares libalpm's
     * transaction.
     */


    /* Now, everything will be done inside our Queue Dialog.
     * So, just create it and let him handle the job.
     */

    qDebug() << "Queue Dialog started";
    qDebug() << Backend::instance()->queue().count();

    queueDl = new QueueDialog(this);

    connect(queueDl, SIGNAL(terminated(bool)), SLOT(queueProcessingEnded(bool)));
    connect(queueDl, SIGNAL(streamTransactionProgress(int)), SIGNAL(streamTransactionProgress(int)));

    bool force = false;

    if (qUi) {
        if (qUi->isInTray()) {
            if (trayicon) {
                trayicon->showMessage(QString(tr("Queue Processing")),
                                      QString(tr("Your Queue is being processed.\nPlease wait.")));
                hide();
                queueDl->hide();
            }
        }

        if (qUi->isTurnOff())
            turnOffSys = true;

        force = qUi->force();

        qUi->deleteLater();
    }

    if (upDl) {
        upDl->deleteLater();
        force = upDl->force();
        queueDl->startUpgrading(force);
    } else {
        queueDl->startProcessing(force);
    }

    emit actionStatusChanged("queueProcessingStarted");

    queueDl->show();

    upActive = false;
    revActive = false;

}

void MainWindow::queueProcessingEnded(bool errors)
{
    emit actionStatusChanged("queueProcessingFinished");

    QSettings *settings = new QSettings();

    if (errors) {
        /* An error has occurred. Just notify the user, since we have already shown a
         * ShamanDialog::popup with error details.
         */

        qDebug() << "Errors occurred, Transaction was not completed";

        if (queueDl->isVisible())
            ShamanDialog::popupDialog(tr("Queue Processed"),
                                      tr("One or more errors occurred, your Queue\nwas not successfully processed"),
                                      this, ShamanProperties::ErrorDialog);
        else if (trayicon)
            trayicon->showMessage(QString(tr("Queue Processed")),
                                  QString(tr("One or more errors occurred, your Queue\n"
                                             "was not successfully processed")));

        stBar->showStBarAction(QString(tr("Error Processing Queue!!")), QPixmap(":/Icons/icons/edit-delete.png"));
    } else {
        /* Everything went fine! Cool then, just notify the user and refine the packages view.
         */

        qDebug() << "Transaction Completed Successfully";

        if (!pkgsViewWG->findItems("pacman", Qt::MatchExactly, 1).first()->text(8).isEmpty()) {
            ShamanDialog::popupDialog(tr("Restart required"),
                                      tr("Pacman or Shaman was updated. Shaman will now quit,\nplease restart it "
                                         "to use the new version"), this, ShamanProperties::WarningDialog);

            qApp->exit(0);
        }

        if (!pkgsViewWG->findItems("shaman", Qt::MatchExactly, 1).isEmpty()) {
            if (!pkgsViewWG->findItems("shaman", Qt::MatchExactly, 1).first()->text(8).isEmpty()) {
                ShamanDialog::popupDialog(tr("Restart required"),
                                          tr("Pacman or Shaman was updated. Shaman will now quit,\nplease restart it "
                                             "to use the new version"), this, ShamanProperties::WarningDialog);

                qApp->exit(0);
            }
        }

        if (!pkgsViewWG->findItems("kdemod4-shaman", Qt::MatchExactly, 1).isEmpty()) {
            if (!pkgsViewWG->findItems("kdemod4-shaman", Qt::MatchExactly, 1).first()->text(8).isEmpty()) {
                ShamanDialog::popupDialog(tr("Restart required"),
                                          tr("Pacman or Shaman was updated. Shaman will now quit,\nplease restart it "
                                             "to use the new version"), this, ShamanProperties::WarningDialog);

                qApp->exit(0);
            }
        }

        if (!pkgsViewWG->findItems("kernel26", Qt::MatchExactly, 1).first()->text(8).isEmpty())
            ShamanDialog::popupDialog(tr("Restart required"), tr("Your Kernel has been updated.\nPlease restart "
                                      "your PC soon to load the new Kernel."), this, ShamanProperties::WarningDialog);

        qApp->processEvents();

        populatePackagesView();
        refinePkgView();
        stBar->updateStatusBar();

        if (queueDl->isVisible() && !settings->value("gui/keepqueuedialogopen", true).toBool())
            ShamanDialog::popupDialog(tr("Queue Processed"), tr("Your Queue was successfully processed!"), this);
        else if (trayicon)
            trayicon->showMessage(QString(tr("Queue Processed")),
                                  QString(tr("Your Queue was successfully processed!!")));

        stBar->showStBarAction(QString(tr("Your Queue was successfully processed!!")),
                               QPixmap(":/Icons/icons/dialog-ok-apply.png"));

        if (turnOffSys) {
            /* Ok, let's go. We need to stream a message through DBus to turn off stuff.
             * KDE3 is not supported since it uses DCOP, sorry, GNOME will come soon.
             */

            qDebug() << "Turning the system off";

            QDBusInterface iface("org.kde.ksmserver", "/KSMServer", "org.kde.KSMServerInterface");

            iface.call("logout", 0, 2, 0);

        }
    }

    turnOffSys = false;

    if (!settings->value("gui/keepqueuedialogopen", true).toBool())
        queueDl->deleteLater();

    settings->deleteLater();

}

void MainWindow::widgetQueueToAlpmQueue()
{
    /* This function takes the queue the user defined in the
     * GUI and "translates" it to a libalpm transaction queue.
     * So THIS is the function that the "Process Queue" buttons
     * should call. processQueue() processes a libalpm queue,
     * so you need to "translate" it first.
     *
     * First of all, we need to know what kind of actions we
     * need.
     */

    QSettings *settings = new QSettings();

    if (settings->value("newsreader/userss", true).toBool() &&
            settings->value("newsreader/queuenotifier", true).toBool()) {
        foreach(QTreeWidgetItem *ent, getInstallPackagesInWidgetQueue() +
                getUpgradePackagesInWidgetQueue() + getRemovePackagesInWidgetQueue()) {
            if (newsReader->checkUnreadNewsOnPkg(ent->text(1))) {
                switch (ShamanDialog::popupQuestionDialog(QString(tr("News Alert")),
                        QString(tr("There is an unread news about %1.\n"
                                   "Do you want to read it?")).arg(ent->text(1)), this)) {
                case QMessageBox::Yes:
                    openNewsDialog();
                    return;
                    break;
                case QMessageBox::No:
                    break;
                default:
                    // should never be reached
                    break;
                }
            }
        }

    }

    settings->deleteLater();

    if (pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 8).isEmpty() &&
            pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 8).isEmpty() &&
            pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 8).isEmpty() &&
            pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 8).isEmpty()) {
        qDebug() << "Nothing in Queue!";
        return;
    }

    qUi = new ReviewQueueDialog(this);

    revActive = true;

    qUi->show();

    connect(qUi, SIGNAL(goProcess()), SLOT(processQueue()));

}

void MainWindow::showSettings()
{
#ifndef KDE4_INTEGRATION
    ConfigDialog *dc = new ConfigDialog(this);
    dc->show();
#else
    KCMultiDialog *md = new KCMultiDialog(this);
    md->addModule("kcmshamangeneral");
    md->addModule("kcmaqpmdatabases");
    md->addModule("kcmaqpm");
    md->exec();
#endif
}

void MainWindow::settingsClosed()
{
    /*qDebug() << "Closing Settings";

    if (configDialog->result() == QDialog::Accepted) {
        populateRepoColumn();

        if (configDialog->doDbUpdate())
            doDbUpdate();

        if (trayicon) {
            trayicon->changeTimerInterval();
            trayicon->resetTimerAt();
        }

        newsReader->setUpdateInterval();
    }

    configDialog->deleteLater();*/
}

void MainWindow::systrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger) {
        if (isHidden()) {
            /* Uh, we have to stop the Timer! */
            emit stopTimer();
            show();
            foreach(QObject *ent, children()) {
                QDialog *dlog = qobject_cast<QDialog *>(ent);
                if (dlog != 0)
                    dlog->show();
            }

        } else {
            emit startTimer();
            hide();
            foreach(QObject *ent, children()) {
                QDialog *dlog = qobject_cast<QDialog *>(ent);
                if (dlog != 0)
                    dlog->hide();
            }
        }
    }
}

void MainWindow::getPackageFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                       tr("Install a Package"), qgetenv("HOME"), tr("Arch Linux Packages (*.pkg.tar.gz)"));

    if (fileName == NULL)
        return;

    installPackageFromFile(fileName);
}

void MainWindow::installPackageFromFile(const QString &filename)
{
    pmpkg_t *pkg;

    // Sanity check
    if (alpm_pkg_load(filename.toUtf8().data(), 1, &pkg) == -1) {
        ShamanDialog::popupDialog(tr("Error"), QString(tr("%1 does not seem\na valid package")).
                                  arg(filename), this, ShamanProperties::ErrorDialog);

        return;
    }

    qDebug() << "Selected" << alpm_pkg_get_name(pkg);

    lpkgDialog = new LocalPackageDialog(this);

    lpkgDialog->loadPackage(pkg, filename);

    lpkgDialog->show();

    qDebug() << "Package Shown";

    connect(lpkgDialog, SIGNAL(queueReady()), SLOT(processQueue()));

}

void MainWindow::showAboutDialog()
{
    QDialog *about = new QDialog(this);
    Ui::aboutDialog ui;

    ui.setupUi(about);

    ui.aboutInfoLabel->setText(QString(tr("<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, "
                                          "li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'Sans Serif'; "
                                          "font-size:10pt; font-weight:400;"
                                          " font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; "
                                          "margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                                          "text-indent:0px;\"><span style=\" font-weight:600;\">A libalpm frontend "
                                          "in Qt</span></p>\n<p style=\"-qt-paragraph-type:empty; "
                                          "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
                                          "-qt-block-indent:0; text-indent:0px; font-weight:600;\">"
                                          "</p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
                                          "margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                                          "License: GPLv2+</p>\n<p style=\" margin-top:0px; margin-bottom:0px; "
                                          "margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                                          "text-indent:0px;\">Libalpm Version: v.%1</p>\n<p style=\""
                                          "-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px;"
                                          " margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                                          "text-indent:0px;\"></p>\n<p style=\" margin-top:0px; margin-bottom:0px;"
                                          " margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                                          "text-indent:0px;\">(C) 2008-2009 Dario Freddi &lt;drf@chakra-project.org&gt;</p>\n"
                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
                                          "margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                                          "(C) 2008 Lukas Appelhans &lt;boom1992@chakra-project.org&gt;</p></body></html>"))
                               .arg(Backend::instance()->getAlpmVersion()));

    ui.headerLabel->setText(QString("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" "
                                    "\"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\""
                                    " content=\"1\" /><style type=\"text/css\">p, li { white-space: pre-wrap; }</style>"
                                    "</head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; "
                                    "font-style:normal;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px"
                                    "; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">"
                                    "Shaman \"%1\" %2 (r %3)</span></p></body></html>").arg(SHAMAN_CODENAME).arg(SHAMAN_VERSION)
                            .arg(SHAMAN_REVISION));

    QPushButton *okb = ui.buttonBox->button(QDialogButtonBox::Ok);

    okb->setText(QObject::tr("Whoa, that's co&ol!"));
    okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));

    connect(ui.websiteButton, SIGNAL(clicked()), SLOT(openUrl()));

    about->setWindowModality(Qt::ApplicationModal);

    about->exec();

    about->deleteLater();
}

void MainWindow::openUrl()
{
    QDesktopServices::openUrl(QUrl("http://shaman.iskrembilen.com/"));
}

void MainWindow::startTrayTimer()
{
    emit startTimer();
}

void MainWindow::streamTransQuestion(Aqpm::Globals::TransactionQuestion event, QVariantMap args)
{
    QString message;
    qDebug() << "Got a question";

    switch (event) {
    case Aqpm::Globals::IgnorePackage:
        if (args.contains("SecondPackage")) {
            message = QString(tr("%1 requires installing %2 from IgnorePkg/IgnoreGroup.\n Install anyway?"))
                      .arg(args["FirstPackage"].toString()).arg(args["SecondPackage"].toString());
        } else {
            message = QString(tr("%1 is in IgnorePkg/IgnoreGroup.\n Install anyway?")).arg(args["FirstPackage"].toString());
        }
        break;
    case Aqpm::Globals::ReplacePackage:
        message = QString(tr("Replace %1 with %2/%3?")).arg(args["OldPackage"].toString())
                  .arg(args["NewPackageRepo"].toString()).arg(args["NewPackage"].toString());
        break;
    case Aqpm::Globals::PackageConflict:
        message = QString(tr("%1 conflicts with %2.\nRemove %2?")).arg(args["OldPackage"].toString())
                  .arg(args["NewPackage"].toString());
        break;
    case Aqpm::Globals::UnresolvedDependencies:
        message = tr("The following package(s) cannot be upgraded due to "
                     "unresolvable dependencies:"
                     "\n%1\n\n"
                     "Do you want to skip the above package(s) for this upgrade?",
                     "", args["Packages"].toStringList().count()).arg(args["Packages"].toStringList().join(", "));
        break;
    case Aqpm::Globals::NewerLocalPackage:
        message = QString(tr("%1-%2: local version is newer.\nUpgrade anyway?")).arg(args["PackageName"].toString()).
                  arg(args["PackageVersion"].toString());
        break;
    case Aqpm::Globals::CorruptedPackage:
        message = QString(tr("File %1 is corrupted.\nDo you want to delete it?")).arg(args["Filename"].toString());
        break;
    default:
        break;
    }

    switch (ShamanDialog::popupQuestionDialog(QString(tr("Transaction Question")), message, this)) {
    case QMessageBox::Yes:
        Backend::instance()->setAnswer(1);
        break;
    case QMessageBox::No:
        Backend::instance()->setAnswer(0);
        break;
    default:
        // should never be reached
        Backend::instance()->setAnswer(-1);
        break;
    }
}

void MainWindow::updateABSTree()
{
    bHandler = new BuildingHandler(this);

    bHandler->updateABSTree();

    connect(bHandler, SIGNAL(outOfScope()), SLOT(terminatedBuildingHandling()));
    connect(bHandler, SIGNAL(buildingFinished()), SIGNAL(buildingFinished()));
    connect(bHandler, SIGNAL(buildingStarted()), SIGNAL(buildingStarted()));
}

void MainWindow::initSourceQueue()
{
    qDebug() << "Starting Building Handler";

    bHandler = new BuildingHandler(this);

    bHandler->validateSourceQueue();

    connect(bHandler, SIGNAL(outOfScope()), SLOT(terminatedBuildingHandling()));
    connect(bHandler, SIGNAL(buildingFinished()), SIGNAL(buildingFinished()));
    connect(bHandler, SIGNAL(buildingStarted()), SIGNAL(buildingStarted()));
}

void MainWindow::terminatedBuildingHandling()
{
    bHandler->deleteLater();
}

QList<QTreeWidgetItem *> MainWindow::getInstallPackagesInWidgetQueue()
{
    return pkgsViewWG->findItems(tr("Install"), Qt::MatchExactly, 8);
}

QList<QTreeWidgetItem *> MainWindow::getUpgradePackagesInWidgetQueue()
{
    return pkgsViewWG->findItems(tr("Upgrade"), Qt::MatchExactly, 8);
}

QList<QTreeWidgetItem *> MainWindow::getRemovePackagesInWidgetQueue()
{
    return pkgsViewWG->findItems(tr("Uninstall"), Qt::MatchExactly, 8) +
           pkgsViewWG->findItems(tr("Complete Uninstall"), Qt::MatchExactly, 8);
}

bool MainWindow::packageExists(const QString &pkg)
{
    if (pkgsViewWG->findItems(pkg, Qt::MatchExactly, 1).isEmpty())
        return false;
    else
        return true;
}

ShamanTrayIcon *MainWindow::getTrayIcon()
{
    return trayicon;
}

void MainWindow::removePackageFromView(const QString &pkgname)
{
    int index = pkgsViewWG->indexOfTopLevelItem(pkgsViewWG->findItems(pkgname, Qt::MatchExactly
                , 1).first());

    delete pkgsViewWG->takeTopLevelItem(index);
}

void MainWindow::removePackageFromView(QTreeWidgetItem *item)
{
    int index = pkgsViewWG->indexOfTopLevelItem(item);

    delete pkgsViewWG->takeTopLevelItem(index);
}

void MainWindow::setProxy()
{
    QSettings *settings = new QSettings();


    if (settings->value("proxy/enabled").toBool() && settings->value("proxy/httpProxy").toBool()) {
        setenv("HTTP_PROXY", settings->value("proxy/proxyServer").toString().toLatin1() + ':' +
               settings->value("proxy/proxyPort").toString().toLatin1(), 1);
        qDebug() << QString("HTTP_PROXY: ") + settings->value("proxy/proxyServer").toString() +
        ':' + settings->value("proxy/proxyPort").toString();
        QNetworkProxy::setApplicationProxy(QNetworkProxy(QNetworkProxy::HttpProxy,
                                           settings->value("proxy/proxyServer").toString(),
                                           settings->value("proxy/proxyPort").toInt()));
    } else {
        unsetenv("HTTP_PROXY");
        qDebug() << "--> UNSETENV HTTP_PROXY";
        QNetworkProxy::setApplicationProxy(QNetworkProxy(QNetworkProxy::NoProxy));
    }


    if (settings->value("proxy/enabled").toBool() && settings->value("proxy/ftpProxy").toBool()) {
        setenv("FTP_PROXY", settings->value("proxy/proxyServer").toString().toLatin1() + ':' +
               settings->value("proxy/proxyPort").toString().toLatin1(), 1);
        qDebug() << QString("FTP_PROXY: ") + settings->value("proxy/proxyServer").toString() + ':' +
        settings->value("proxy/proxyPort").toString();
    } else {
        unsetenv("FTP_PROXY");
        qDebug() << "--> UNSETENV FTP_PROXY";
    }
}

void MainWindow::openNewsDialog()
{
    if (!nView) {
        nView = new NewsViewer(newsReader, this);

        nView->show();
    } else
        nView->show();
}

void MainWindow::openLogViewer()
{
    if (!lView) {
        lView = new LogViewer(this);

        lView->show();
    } else
        lView->show();
}

void MainWindow::showInfoDialog()
{
    if (pkgProp != NULL)
        pkgProp->deleteLater();

    if (pkgsViewWG->selectedItems().isEmpty())
        return;

    pkgProp = new PackageProperties(this);

    pkgProp->setPackage(pkgsViewWG->selectedItems().first()->data(0, Qt::UserRole + 1).value<Package>());

    pkgProp->reloadPkgInfo();

    pkgProp->show();
}

void MainWindow::triggerEditTimer()
{
    editTimer->stop();

    editTimer->start(500);
}

void MainWindow::doStreamPackages()
{
    QStringList packages;

    foreach(const Database &db, Backend::instance()->getAvailableDatabases()) {
        foreach(const Package &package, Backend::instance()->getPackagesFromDatabase(db)) {
            packages.append(package.name());
        }
    }

    emit streamPackages(packages);
}
