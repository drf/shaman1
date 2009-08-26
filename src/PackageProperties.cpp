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
 **************************************************************************/

#include "PackageProperties.h"

#include <aqpm/Backend.h>

#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QDebug>

using namespace Aqpm;

PackageProperties::PackageProperties(QWidget *parent)
        : QDialog(parent)
{
    setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

PackageProperties::~PackageProperties()
{
}

QString PackageProperties::formatSize(unsigned long size)
{
    QString s;
    if (size > 1024 * 1024 * 1024) {
        s = tr("%1 GiB", "Size is in Gib").arg((double) size / (1024 * 1024 * 1024), 0, 'f', 2);
    } else if (size > 1024 * 1024) {
        s = tr("%1 MiB", "Size is in MiB").arg((double) size / (1024 * 1024), 0, 'f', 2);
    } else if (size > 1024) {
        s = tr("%1 KiB", "Size is in KiB").arg(size / 1024);
    } else {
        s = tr("%1 Bytes", "Size is in Bytes").arg(size);
    }

    return s;
}

void PackageProperties::setPackage(const Package &pkg, bool forceGiven)
{
    curPkg = pkg;

    // We can throw a lot more info if the package is local, let's check.
    if (Backend::instance()->isInstalled(curPkg) && !forceGiven) {
        qDebug() << "Getting info from local database";
        curPkg = Backend::instance()->getPackage(pkg.name(), "local");
    }

    setWindowTitle(QString(tr("Shaman - %1 properties")).arg(pkg.name()));
}

void PackageProperties::reloadPkgInfo()
{
    populateInfoWidget();
    populateFileWidget();
    populateDepsWidget();
    populateLogWidget();
    populateChangelogWidget();
}

void PackageProperties::populateInfoWidget()
{
    char buf[80];
    QString notAvailable(QString(tr("N/A", "Stands for: Not Available")));

    if (Backend::instance()->isInstalled(curPkg))
        installedLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
    else
        installedLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

    if (Backend::instance()->getUpgradeablePackages().contains(curPkg)) {
        upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
    } else {
        upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));
    }

    if (curPkg.hasScriptlet()) {
        scriptletLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
    } else {
        scriptletLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));
    }

    descriptionLabel->setText(curPkg.desc());
    versionLabel->setText(curPkg.version());

    if (!curPkg.buildDate().isValid() || curPkg.buildDate().date().year() < 1980) {
        builddateLabel->setText(notAvailable);
    } else {
        builddateLabel->setText(curPkg.buildDate().toString(Qt::SystemLocaleLongDate));
    }

    if (!curPkg.installDate().isValid() || curPkg.installDate().date().year() < 1980) {
        // LOL @ The Epoch
        installdateLabel->setText(notAvailable);
    } else {
        installdateLabel->setText(curPkg.installDate().toString(Qt::SystemLocaleLongDate));
    }

    QString packager(curPkg.packager());

    if (packager.isEmpty())
        packagerLabel->setText(notAvailable);
    else
        packagerLabel->setText(packager);

    sizeLabel->setText(formatSize(curPkg.size()));
    providesWidget->addItems(Backend::instance()->getProviders(curPkg));
}

void PackageProperties::populateFileWidget()
{
    treeWidget->clear();
    treeWidget->header()->hide();
    QStringList files = curPkg.files();
    foreach(const QString &file, files) {
        QStringList splitted = file.split(QChar('/'));
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
                QList<QTreeWidgetItem*> list = treeWidget->findItems(spl, Qt::MatchExactly);
                if (!list.isEmpty()) {
                    parentItem = list.first();
                } else {
                    treeWidget->insertTopLevelItem(0, new QTreeWidgetItem(treeWidget, (QStringList) spl));
                }
            }
        }
    }
}

void PackageProperties::populateDepsWidget()
{
    dependsWidget->clear();
    foreach(const Package &dep, Backend::instance()->getPackageDependencies(curPkg)) {
        dependsWidget->addItem(dep.name());
    }

    requiredWidget->clear();
    foreach(const Package &dep, Backend::instance()->getDependenciesOnPackage(curPkg)) {
        requiredWidget->addItem(dep.name());
    }
}

void PackageProperties::populateChangelogWidget()
{
    QString text = curPkg.retrieveChangelog();

    if (text.isEmpty()) {
        changeLogEdit->setText(tr("Changelog not available for this package"));
    } else {
        changeLogEdit->setText(text);
    }
}

void PackageProperties::populateLogWidget()
{
    logEdit->setText(curPkg.retrieveLoggedActions());
}

