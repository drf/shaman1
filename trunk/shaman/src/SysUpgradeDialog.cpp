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

#include "SysUpgradeDialog.h"

#include <iostream>
#include <alpm.h>

#include <aqpm/Backend.h>

#include <QSettings>
#include <QDebug>

SysUpgradeDialog::SysUpgradeDialog( QWidget *parent )
        : QDialog( parent )
{
    setupUi( this );
}

SysUpgradeDialog::~SysUpgradeDialog()
{
    disconnect( abortButton, 0, 0, 0 );
    disconnect( addToQueue, 0, 0, 0 );
    disconnect( goUpgrading, 0, 0, 0 );
}

void SysUpgradeDialog::init()
{
    QSettings *settings = new QSettings();

    if ( settings->value( "gui/actionupgrade" ).toString() == "add" )
        addPkg();
    else if ( settings->value( "gui/actionupgrade" ).toString() == "upgrade" )
        initSysUpgrade();
    else {
        QStringList data;

        setWindowModality( Qt::ApplicationModal );

        data = Backend::instance()->getUpgradeablePackagesAsStringList();

        int n = data.size();

        upgradeMessage->setText( QString( tr( "<b>Upgradeable package(s): %n</b> "
                                              "You can either<br> upgrade "
                                              "immediately or add it to the current Queue"
                                              "<br> and process it later.", "", n ) ) );

        QTreeWidgetItem *itm = new QTreeWidgetItem( treeWidget, QStringList( tr( "To be Upgraded" ) ) );
        treeWidget->addTopLevelItem( itm );

        foreach( const QString &pkg, Backend::instance()->getUpgradeablePackagesAsStringList() ) {
            new QTreeWidgetItem( itm, QStringList() << QString( pkg + " (" +
                                 Backend::instance()->getPackageVersion( pkg, "local" ) + "-->" +
                                 Backend::instance()->getPackageVersion( pkg, Backend::instance()->getPackageRepo( pkg, true ) ) + QChar( ')' ) ) );
        }

        itm->setExpanded( true );

        connect( abortButton, SIGNAL( clicked() ), SLOT( abort() ) );
        connect( addToQueue, SIGNAL( clicked() ), SLOT( addPkg() ) );
        connect( goUpgrading, SIGNAL( clicked() ), SLOT( initSysUpgrade() ) );
        connect( showPackages, SIGNAL( toggled( bool ) ), SLOT( adjust( bool ) ) );

        //treeWidget->hide();
        adjustSize();

        show();
    }

    settings->deleteLater();
}

void SysUpgradeDialog::abort()
{
    emit aborted();
}

void SysUpgradeDialog::addPkg()
{
    QSettings *settings = new QSettings();

    if ( checkBox->isChecked() )
        settings->setValue( "gui/actionupgrade", "add" );

    settings->deleteLater();

    emit addToPkgQueue();
}

void SysUpgradeDialog::initSysUpgrade()
{
    QSettings *settings = new QSettings();

    if ( checkBox->isChecked() )
        settings->setValue( "gui/actionupgrade", "upgrade" );

    Backend::instance()->fullSystemUpgrade();

    qDebug() << "Upgrade signal sent";

    settings->deleteLater();

    emit upgradeNow();
}

void SysUpgradeDialog::adjust( bool tgld )
{
    if ( tgld )
        treeWidget->show();
    else {
        treeWidget->hide();
        resize( minimumSize() );
    }

    adjustSize();
}

bool SysUpgradeDialog::force()
{
    return forceBox->isChecked();
}
