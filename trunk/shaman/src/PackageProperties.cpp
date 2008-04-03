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

#include <sys/types.h>

PackageProperties::PackageProperties(AlpmHandler *aH, QWidget *parent)
 : QDialog(parent),
 aHandle(aH)
{
	setupUi(this);
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

void PackageProperties::setPackage(pmpkg_t *pkg)
{
	curPkg = pkg;
}

void PackageProperties::setPackage(const QString &pkgname)
{
	curPkg = aHandle->getPackageFromName(pkgname, aHandle->getPackageRepo(pkgname));
}

void PackageProperties::reloadPkgInfo()
{
	populateInfoWidget();
}

void PackageProperties::populateInfoWidget()
{
	char buf[80];
	time_t now = alpm_pkg_get_builddate(curPkg);
	struct tm *ts = gmtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ts);
	
	if (aHandle->isInstalled(curPkg))
		installedLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
	else
		installedLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

	if (aHandle->getUpgradeablePackages().contains(alpm_pkg_get_name(curPkg)))
		upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
	else
		upgradeableLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));

	if (alpm_pkg_has_scriptlet(curPkg))
		scriptletLabel->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
	else
		scriptletLabel->setPixmap(QPixmap(":/Icons/icons/edit-delete.png"));
	
	descriptionLabel->setText(alpm_pkg_get_desc(curPkg));
	versionLabel->setText(alpm_pkg_get_version(curPkg));
	builddateLabel->setText(buf);
	//installdateLabel->setText(alpm_pkg_get_installdate());
	packagerLabel->setText(alpm_pkg_get_packager(curPkg));
	sizeLabel->setText(formatSize(alpm_pkg_get_size(curPkg)));
	providesWidget->addItems(aHandle->getProviders(curPkg));
}
