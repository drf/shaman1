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

#ifndef PACKAGEPROPERTIES_H
#define PACKAGEPROPERTIES_H

#include "ui_pkgProperties.h"

#include <QDialog>

class PackageProperties : public QDialog, private Ui::pkgProperties
{
        Q_OBJECT

    public:
        explicit PackageProperties( QWidget *parent = 0 );
        virtual ~PackageProperties();

        void setPackage( const QString &pkgname );

        void reloadPkgInfo();

        static QString formatSize( unsigned long size );

        void setPackage( pmpkg_t *pkg, bool forceGiven = false );

    private:

        void populateFileWidget();
        void populateDepsWidget();
        void populateRequiredWidget();
        void populateInfoWidget();
        void populateLogWidget();
        void populateChangelogWidget();

    private:
        pmpkg_t *curPkg;
        QString pName;
};

#endif /*PACKAGEPROPERTIES_H*/
