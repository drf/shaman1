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

#include "PackageProperties.h"

LocalPackageDialog::LocalPackageDialog( AlpmHandler *aH, QWidget *parent )
        : QDialog( parent ),
        aHandle( aH )
{
    setupUi( this );
    setWindowModality( Qt::ApplicationModal );

    connect( installButton, SIGNAL( clicked() ), SLOT( goInstall() ) );
    connect( cancelButton, SIGNAL( clicked() ), SLOT( deleteLater() ) );
    connect( detailsButton, SIGNAL( clicked() ), SLOT( showDetails() ) );
    connect( showButton, SIGNAL( toggled( bool ) ), SLOT( adjust( bool ) ) );
}

LocalPackageDialog::~LocalPackageDialog()
{
}

void LocalPackageDialog::loadPackage( pmpkg_t *pkg, const QString &fname )
{
    package = pkg;
    filename = fname;

    nameLabel->setText( QString( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
                                 "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
                                 "p, li { white-space: pre-wrap; }"
                                 "</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">"
                                 "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                                 "<span style=\" font-size:11pt; font-weight:600;\">" ) + alpm_pkg_get_name( package ) + " ("  + alpm_pkg_get_version( package )
                        + ")</span></p></body></html>" );

    descLabel->setText( QString( alpm_pkg_get_desc( package ) ) );

    if ( !aHandle->isInstalled( package ) ) {
        statusLabel->setText( tr( "Package is not installed" ) );

    } else {
        statusLabel->setText( QString( tr( "Version %1 of this package is already installed" ) )
                              .arg( aHandle->getPackageVersion( alpm_pkg_get_name( package ), "local" ) ) );
    }

    QStringList deps;

    foreach( const QString &ent, aHandle->getPackageDependencies( package ) ) {
        if ( !aHandle->isInstalled( ent ) )
            deps.append( ent );
    }

    if ( deps.isEmpty() ) {
        depsLabel->setText( tr( "All dependencies are satisfied" ) );
        showButton->setVisible( false );
    } else {
        depsLabel->setText( QString( tr( "%n package(s) will be installed as dependencies", "", deps.count() ) ) );
        showButton->setVisible( true );
        showButton->setChecked( false );

        listWidget->clear();
        listWidget->addItems( deps );
    }

    adjust( false );
}

void LocalPackageDialog::showDetails()
{
    PackageProperties *pkgProp = new PackageProperties( aHandle, this );

    pkgProp->setPackage( package, true );

    pkgProp->reloadPkgInfo();

    pkgProp->exec();
}

void LocalPackageDialog::goInstall()
{
    aHandle->initQueue( false, false, true );

    aHandle->addFFToQueue( filename );

    emit queueReady();

    deleteLater();
}

void LocalPackageDialog::adjust( bool tgld )
{
    if ( tgld )
        listWidget->show();
    else {
        listWidget->hide();
        //resize(minimumSize());
    }

    adjustSize();
}
