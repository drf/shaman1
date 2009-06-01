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

#ifndef QUEUEDIALOG_H
#define QUEUEDIALOG_H

#include "ui_transactionDialog.h"

#include <aqpm/Globals.h>

class QueueDialog : public QDialog, private Ui::transactionDialog
{
        Q_OBJECT

    public:
        explicit QueueDialog( QWidget *parent = 0 );
        ~QueueDialog();
        void startProcessing( bool force );
        void startUpgrading(bool force);

    public slots:
        void abortTransaction();
        void showCurrentTransaction();

    private slots:

        void updateProgressBar( const QString &c, int bytedone, int bytetotal, int speed,
                                int listdone, int listtotal );
        void updateProgressBar( Aqpm::Globals::TransactionProgress evt, const QString &pkgname, int percent,
                                int howmany, int remain );
        void startDownload();
        void startProcess();
        void cleanup(bool success);

        void handleAlpmMessage( const QString &msg );

        void changeStatus( Aqpm::Globals::TransactionEvent evt, QVariantMap args );

        void adjust( bool tgld );

    signals:
        void terminated( bool errors );
        void streamTransactionProgress( int percent );
    private:
        int status;
        bool errors;
};

#endif /*QUEUEDIALOG_H*/
