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

#define CLBUF_SIZE 4096

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

    if (Backend::instance()->getUpgradeablePackages().contains(curPkg))
        upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
    else
        upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

    if (alpm_pkg_has_scriptlet(curPkg.alpmPackage()))
        scriptletLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
    else
        scriptletLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

    descriptionLabel->setText(curPkg.desc());
    versionLabel->setText(curPkg.version());

    time_t now = alpm_pkg_get_builddate(curPkg.alpmPackage());
    struct tm *ts = gmtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ts);
    QString bDate(buf);
    if (bDate.startsWith("1970"))
        // LOL @ The Epoch
        builddateLabel->setText(notAvailable);
    else
        builddateLabel->setText(buf);

    now = alpm_pkg_get_installdate(curPkg.alpmPackage());
    ts = gmtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ts);
    QString iDate(buf);
    if (iDate.startsWith("1970"))
        // LOL @ The Epoch
        installdateLabel->setText(notAvailable);
    else
        installdateLabel->setText(buf);

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
    QStringList files = Backend::instance()->getPackageFiles(curPkg);
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
    void *fp = NULL;
    QString text;

    if ((fp = alpm_pkg_changelog_open(curPkg.alpmPackage())) == NULL) {
        changeLogEdit->setText(QString(tr("Changelog not available for this package")));
    } else {
        /* allocate a buffer to get the changelog back in chunks */
        char buf[CLBUF_SIZE];
        int ret = 0;
        while ((ret = alpm_pkg_changelog_read(buf, CLBUF_SIZE, curPkg.alpmPackage(), fp))) {
            if (ret < CLBUF_SIZE) {
                /* if we hit the end of the file, we need to add a null terminator */
                *(buf + ret) = '\0';
            }
            text.append(buf);
        }
        alpm_pkg_changelog_close(curPkg.alpmPackage(), fp);
        changeLogEdit->setText(text);
    }
}

void PackageProperties::populateLogWidget()
{
    QFile fp(alpm_option_get_logfile());

    QStringList contents;

    if (!fp.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&fp);

    while (!in.atEnd()) {
        QString line = in.readLine();
        contents.append(line);
    }

    fp.close();

    QString toShow;
    QString pkgName(curPkg.name());

    foreach(const QString &ent, contents) {
        if (!ent.contains(pkgName, Qt::CaseInsensitive))
            continue;

        toShow.append(ent + QChar('\n'));
    }

    logEdit->setText(toShow);
}

