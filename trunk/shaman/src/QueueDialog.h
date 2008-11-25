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

#include <iostream>
#include "ui_transactionDialog.h"
#include <alpm.h>

#include <QProcess>

class RootProcess;

class QueueDialog : public QDialog, private Ui::transactionDialog
{
        Q_OBJECT

    public:
        explicit QueueDialog( QWidget *parent = 0 );
        ~QueueDialog();
        void startProcessing( bool force );
        bool isScriptletRunning();

    public slots:
        void abortTransaction();

    private slots:
        void writeLineProgress();
        void writeLineProgressErr();

        void updateProgressBar( char *c, int bytedone, int bytetotal, int speed,
                                int listdone, int listtotal, int speedtotal );
        void updateProgressBar( pmtransprog_t event, char *pkgname, int percent,
                                int howmany, int remain );
        void startDownload();
        void startProcess();
        void cleanup(bool success);

        void handlePreparingError( const QString &msg );
        void handleCommittingError( const QString &msg );

        void handleAlpmMessage( const QString &msg );

        void changeStatus( pmtransevt_t event, void *data1, void *data2 );

        void finishedScriptletRunning( int eC, QProcess::ExitStatus eS );

        void adjust( bool tgld );

    signals:
        void terminated( bool errors );
        void streamTransactionProgress( int percent );

    private:
        bool runScriptlet( int action, const QString &p1N, const QString &p1V,
                           const QString &pA, const QString &p2V );

        bool unpackPkg( const QString &pathToPkg, const QString &pathToEx, const QString &file );
        bool checkScriptlet( const QString &path, const QString &action );

    private:
        RootProcess *proc;
        int status;
        QString cwd;
        bool scrRun;
        bool errors;
};

#endif /*QUEUEDIALOG_H*/
