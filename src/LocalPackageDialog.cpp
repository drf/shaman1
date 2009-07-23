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

#include "LocalPackageDialog.h"

#include <aqpm/Backend.h>

#include "PackageProperties.h"

#include <ActionButton>

using namespace Aqpm;

LocalPackageDialog::LocalPackageDialog(QWidget *parent)
        : QDialog(parent)
{
    setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    PolkitQt::ActionButton *start_Install = new PolkitQt::ActionButton(installButton,
                                                                       "org.chakraproject.aqpm.processqueue",
                                                                       this);
    start_Install->setText(tr("Install Package"));
    connect(start_Install, SIGNAL(clicked(QAbstractButton*, bool)), start_Install, SLOT(activate()));
    connect(start_Install, SIGNAL(activated()), this, SLOT(goInstall()));
    connect(installButton, SIGNAL(clicked()), SLOT(goInstall()));
    connect(cancelButton, SIGNAL(clicked()), SLOT(deleteLater()));
    connect(detailsButton, SIGNAL(clicked()), SLOT(showDetails()));
    connect(showButton, SIGNAL(toggled(bool)), SLOT(adjust(bool)));
}

LocalPackageDialog::~LocalPackageDialog()
{
}

void LocalPackageDialog::loadPackage(const Package &pkg, const QString &fname)
{
    package = pkg;
    filename = fname;

    nameLabel->setText(QString("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
                               "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
                               "p, li { white-space: pre-wrap; }"
                               "</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">"
                               "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                               "<span style=\" font-size:11pt; font-weight:600;\">") + package.name() + " ("  + package.version()
                       + ")</span></p></body></html>");

    descLabel->setText(package.desc());

    if (!Backend::instance()->isInstalled(package)) {
        statusLabel->setText(tr("Package is not installed"));

    } else {
        statusLabel->setText(QString(tr("Version %1 of this package is already installed"))
                             .arg(package.version()));
    }

    QStringList deps;

    foreach(const Package &ent, Backend::instance()->getPackageDependencies(package)) {
        if (!Backend::instance()->isInstalled(ent)) {
            deps.append(ent.name());
        }
    }

    if (deps.isEmpty()) {
        depsLabel->setText(tr("All dependencies are satisfied"));
        showButton->setVisible(false);
    } else {
        depsLabel->setText(QString(tr("%n package(s) will be installed as dependencies", "", deps.count())));
        showButton->setVisible(true);
        showButton->setChecked(false);

        listWidget->clear();
        listWidget->addItems(deps);
    }

    adjust(false);
}

void LocalPackageDialog::showDetails()
{
    PackageProperties *pkgProp = new PackageProperties(this);

    pkgProp->setPackage(package, true);

    pkgProp->reloadPkgInfo();

    pkgProp->exec();
}

void LocalPackageDialog::goInstall()
{
    Backend::instance()->clearQueue();

    Backend::instance()->addItemToQueue(filename, QueueItem::FromFile);

    emit queueReady();

    deleteLater();
}

void LocalPackageDialog::adjust(bool tgld)
{
    if (tgld)
        listWidget->show();
    else {
        listWidget->hide();
        //resize(minimumSize());
    }

    adjustSize();
}
