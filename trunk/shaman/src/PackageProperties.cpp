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

#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#define CLBUF_SIZE 4096

PackageProperties::PackageProperties(AlpmHandler *aH, QWidget *parent)
 : QDialog(parent),
 aHandle(aH)
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
	if (size > 1024 * 1024 * 1024)
		s = tr("%1 GiB", "Size is in Gib").arg((double) size / (1024 *1024 * 1024), 0, 'f', 2);
	else if (size > 1024 * 1024)
		s = tr("%1 MiB", "Size is in MiB").arg((double) size / (1024 * 1024), 0, 'f', 2);
	else if (size > 1024)
		s = tr("%1 KiB", "Size is in KiB").arg(size / 1024);
	else
		s = tr("%1 Bytes", "Size is in Bytes").arg(size);

	return s;
}

void PackageProperties::setPackage(pmpkg_t *pkg, bool forceGiven)
{
	curPkg = pkg;
	
	// We can throw a lot more info if the package is local, let's check.
	if(forceGiven && curPkg == NULL)
	    return;
	else if((aHandle->isInstalled(curPkg) || curPkg == NULL) && !forceGiven)
	{
		qDebug() << "Getting info from local database";
		curPkg = aHandle->getPackageFromName(pName, "local");
	}

	if(pName.isEmpty())
	    pName = alpm_pkg_get_name(curPkg);

	setWindowTitle(QString(tr("Shaman - %1 properties")).arg(pName));
}

void PackageProperties::setPackage(const QString &pkgname)
{
	pName = pkgname;
	setPackage(aHandle->getPackageFromName(pkgname, aHandle->getPackageRepo(pkgname)));
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
	
	if (aHandle->isInstalled(curPkg))
		installedLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
	else
		installedLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

	if (aHandle->getUpgradeablePackages().contains(pName))
		upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
	else
		upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

	if (alpm_pkg_has_scriptlet(curPkg))
		scriptletLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
	else
		scriptletLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

	descriptionLabel->setText(alpm_pkg_get_desc(curPkg));
	versionLabel->setText(alpm_pkg_get_version(curPkg));

	time_t now = alpm_pkg_get_builddate(curPkg);
	struct tm *ts = gmtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ts);
	QString bDate(buf);
	if(bDate.startsWith("1970"))
		// LOL @ The Epoch
		builddateLabel->setText(notAvailable);
	else
		builddateLabel->setText(buf);
	
	now = alpm_pkg_get_installdate(curPkg);
	ts = gmtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ts);
	QString iDate(buf);
	if (iDate.startsWith("1970"))
		// LOL @ The Epoch
		installdateLabel->setText(notAvailable);
	else
		installdateLabel->setText(buf);
	
	QString packager(alpm_pkg_get_packager(curPkg));

	if (packager.isEmpty())
		packagerLabel->setText(notAvailable);
	else
		packagerLabel->setText(alpm_pkg_get_packager(curPkg));

	sizeLabel->setText(formatSize(alpm_pkg_get_size(curPkg)));
	providesWidget->addItems(aHandle->getProviders(curPkg));
}

void PackageProperties::populateFileWidget()
{
	treeWidget->clear();
	treeWidget->header()->hide();
	QStringList files = aHandle->getPackageFiles(curPkg);
	foreach (QString file, files)
	{
		QStringList splitted = file.split("/");
		QTreeWidgetItem *parentItem = 0;
		foreach (QString spl, splitted)
		{
			if (spl.isEmpty())
				continue;
			if (parentItem)
			{
				bool there = false;
				int j = parentItem->childCount();
				for (int i = 0;i != j; i++)
				{
					if (parentItem->child(i)->text(0) == spl)
					{
						there = true;
						parentItem = parentItem->child(i);
						continue;
					}
				}
				if (!there)
					parentItem->addChild(new QTreeWidgetItem(parentItem, (QStringList) spl));
			}
			else
			{
				QList<QTreeWidgetItem*> list = treeWidget->findItems(spl, Qt::MatchExactly);
				if (!list.isEmpty())
				{
					parentItem = list.first();
				}
				else
				{
					treeWidget->insertTopLevelItem(0, new QTreeWidgetItem(treeWidget, (QStringList) spl));
				}
			}
		}
	}
}

void PackageProperties::populateDepsWidget()
{
	dependsWidget->clear();
	foreach (QString dep, aHandle->getPackageDependencies(curPkg))
	{
		if (!dep.isEmpty())
			dependsWidget->addItem(dep);
	}

	requiredWidget->clear();
	foreach (QString dep, aHandle->getDependenciesOnPackage(curPkg))
	{
		if (!dep.isEmpty())
			requiredWidget->addItem(dep);
	}
}

void PackageProperties::populateChangelogWidget()
{
	void *fp = NULL;
	QString text;

	if ((fp = alpm_pkg_changelog_open(curPkg)) == NULL) 
	{
		changeLogEdit->setText(QString(tr("Changelog not available for this package")));
	} 
	else 
	{
		/* allocate a buffer to get the changelog back in chunks */
		char buf[CLBUF_SIZE];
		int ret = 0;
		while ((ret = alpm_pkg_changelog_read(buf, CLBUF_SIZE, curPkg, fp)))
		{
			if (ret < CLBUF_SIZE)
			{
				/* if we hit the end of the file, we need to add a null terminator */
				*(buf + ret) = '\0';
			}
			text.append(buf);
		}
		alpm_pkg_changelog_close(curPkg, fp);
		changeLogEdit->setText(text);
	}
}

void PackageProperties::populateLogWidget()
{
	QFile fp(alpm_option_get_logfile());

	QStringList contents;

	if(!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&fp);

	while(!in.atEnd()) 
	{
		QString line = in.readLine();
		contents.append(line);
	}
	
	fp.close();

	QString toShow;
	QString pkgName(pName);

	foreach(QString ent, contents)
	{
		if(!ent.contains(pkgName, Qt::CaseInsensitive))
			continue;
		
		toShow.append(ent + QChar('\n'));
	}

	logEdit->setText(toShow);
}

