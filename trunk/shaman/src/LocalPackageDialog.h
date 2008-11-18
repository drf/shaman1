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

#ifndef LOCALPACKAGEDIALOG_H
#define LOCALPACKAGEDIALOG_H

#include "ui_fromFileDialog.h"
#include "AlpmHandler.h"

class LocalPackageDialog : public QDialog, private Ui::LocalPackage
{
        Q_OBJECT

    public:
        explicit LocalPackageDialog( AlpmHandler *aH, QWidget *parent = 0 );
        virtual ~LocalPackageDialog();

        void loadPackage( pmpkg_t *pkg, const QString &fname );

    private slots:
        void adjust( bool tgld );

        void showDetails();
        void goInstall();

    signals:
        void queueReady();

    private:
        AlpmHandler *aHandle;
        pmpkg_t *package;
        QString filename;

};

#endif /*LOCALPACKAGEDIALOG_H_*/
