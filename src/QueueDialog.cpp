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

#include "QueueDialog.h"

#include "ShamanDialog.h"
#include "ui_transactionDialog.h"

#include <aqpm/Backend.h>
#include <aqpm/Globals.h>

#include <QDebug>
#include <QMessageBox>
#include <QTime>
#include <QSettings>

using namespace std;
using namespace Aqpm;

QueueDialog::QueueDialog( QWidget *parent )
        : QDialog( parent ),
        errors( false )
{
    setupUi( this );
    textEdit->hide();
    setWindowModality( Qt::WindowModal );

    connect( Backend::instance(), SIGNAL( streamTransEvent( Aqpm::Globals::TransactionEvent, QVariantMap ) ),
             SLOT( changeStatus( Aqpm::Globals::TransactionEvent, QVariantMap ) ) );
    connect( Backend::instance(), SIGNAL(logMessageStreamed(QString)),
             this, SLOT(handleAlpmMessage(QString)));
    connect( Backend::instance(), SIGNAL( streamDlProg( const QString&, int, int, int, int, int ) ),
             SLOT( updateProgressBar( const QString&, int, int, int, int, int ) ) );
    connect( abortTr, SIGNAL( clicked() ), SLOT( abortTransaction() ) );
    connect( showDetails, SIGNAL( toggled( bool ) ), SLOT( adjust( bool ) ) );

    qDebug() << "Queue signals connected";

    transLabel->setPixmap( QIcon( ":/Icons/icons/edit-redo.png" ).pixmap( 22 ) );
    textEdit->append( QString( tr( "<br><b> * Validating Transaction</b><br>" ) ) );

    actionDetail->setText( actionDetail->text() + QChar( '\n' ) );

    progressBar->setRange( 0, 1 );
    progressBar->setValue( 0 );
    adjustSize();
    status = 0;
}

QueueDialog::~QueueDialog()
{
}

void QueueDialog::adjust( bool tgld )
{
    if ( tgld )
        textEdit->show();
    else {
        textEdit->hide();
        resize( minimumSize() );
    }

    adjustSize();
}

void QueueDialog::startProcessing( bool force )
{
    QList<pmtransflag_t> flags;

    flags.append(PM_TRANS_FLAG_ALLDEPS);
    if (force) {
        flags.append(PM_TRANS_FLAG_FORCE);
    }

    Backend::instance()->processQueue(flags);

    connect( Backend::instance(), SIGNAL( operationFinished(bool) ), SLOT( cleanup(bool) ) );
}

void QueueDialog::startUpgrading(bool force)
{
    QList<pmtransflag_t> flags;

    flags.append(PM_TRANS_FLAG_ALLDEPS);

    if (force) {
        flags.append(PM_TRANS_FLAG_FORCE);
    }

    Backend::instance()->fullSystemUpgrade(flags);

    connect( Backend::instance(), SIGNAL( operationFinished(bool) ), SLOT( cleanup(bool) ) );
}

void QueueDialog::showCurrentTransaction()
{
    connect( Backend::instance(), SIGNAL( operationFinished(bool) ), SLOT( cleanup(bool) ) );
}

void QueueDialog::changeStatus( Aqpm::Globals::TransactionEvent event, QVariantMap args )
{
    qDebug() << "Entering Queue Lock, with event " << event;

    QString upgTxt;
    QString addTxt;
    QString remTxt;

    switch ( event ) {
    case Aqpm::Globals::CheckDepsStart:
        actionDetail->setText( QString( tr( "Validating Dependencies..." ) ) );
        textEdit->append( QString( tr( "Validating Dependencies..." ) ) );
        break;
    case Aqpm::Globals::FileConflictsStart:
        actionDetail->setText( QString( tr( "Checking for Conflicts..." ) ) );
        textEdit->append( QString( tr( "Checking for Conflicts..." ) ) );
        break;
    case Aqpm::Globals::ResolveDepsStart:
        actionDetail->setText( QString( tr( "Resolving Dependencies..." ) ) );
        textEdit->append( QString( tr( "Resolving Dependencies..." ) ) );
        break;
    case Aqpm::Globals::InterConflictsStart:
        actionDetail->setText( QString( tr( "Looking for Inter-Conflicts..." ) ) );
        textEdit->append( QString( tr( "Looking for Inter-Conflicts..." ) ) );
        break;
    case Aqpm::Globals::AddStart:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Package Installation Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Installing %1..." ) ).arg( args["PackageName"].toString() ) );
        textEdit->append( QString( tr( "Installing %1..." ) ).arg( args["PackageName"].toString() ) );

        break;
    case Aqpm::Globals::AddDone:
        addTxt = QString( tr( "%1 (%2) installed successfully!" ) ).arg(
                     args["PackageName"].toString() ).arg( args["PackageVersion"].toString() );
        actionDetail->setText( addTxt );
        textEdit->append( addTxt );
        addTxt.append( QChar( '\n' ) );

        break;
    case Aqpm::Globals::RemoveStart:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Package Removal Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Removing %1..." ) ).arg( args["PackageName"].toString() ) );
        textEdit->append( QString( tr( "Removing %1..." ) ).arg( args["PackageName"].toString() ) );
        break;
    case Aqpm::Globals::RemoveDone:
        remTxt = QString( tr( "%1 (%2) removed successfully!" ) ).
                 arg( args["PackageName"].toString() ).arg( args["PackageVersion"].toString() );

        actionDetail->setText( remTxt );
        textEdit->append( remTxt );
        remTxt.append( QChar( '\n' ) );
        break;
    case Aqpm::Globals::UpgradeStart:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Package Upgrading Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Upgrading %1..." ) ).arg( args["PackageName"].toString() ) );
        textEdit->append( QString( tr( "Upgrading %1..." ) ).arg( args["PackageName"].toString() ) );
        break;
    case Aqpm::Globals::UpgradeDone:
        upgTxt = QString( tr( "Upgraded %1 successfully (%2 -> %3)" ) ).arg(args["PackageName"].toString())
                 .arg(args["OldVersion"].toString()).arg(args["NewVersion"].toString() );

        actionDetail->setText( upgTxt );
        textEdit->append( upgTxt );
        upgTxt.append( QChar( '\n' ) );

        break;
    case Aqpm::Globals::IntegrityStart:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Queue Processing Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Checking package integrity..." ) ) );
        textEdit->append( QString( tr( "Checking package integrity..." ) ) );
        break;
    case Aqpm::Globals::DeltaIntegrityStart:
        actionDetail->setText( QString( tr( "Checking delta integrity..." ) ) );
        textEdit->append( QString( tr( "Checking delta integrity..." ) ) );
        break;
    case Aqpm::Globals::DeltaPatchesStart:
        actionDetail->setText( QString( tr( "Applying deltas..." ) ) );
        break;
    case Aqpm::Globals::DeltaPatchStart:
        actionDetail->setText( QString( tr( "Generating %1 with %2... " ) ).arg(args["From"].toString()).
                               arg(args["To"].toString()) );
        break;
    case Aqpm::Globals::DeltaPatchDone:
        actionDetail->setText( QString( tr( "Success!" ) ) );
        break;
    case Aqpm::Globals::DeltaPatchFailed:
        actionDetail->setText( QString( tr( "Failed!" ) ) );
        break;
    case Aqpm::Globals::ScriptletInfo:
        actionDetail->setText(QString(tr("Running package scripts...")));
        textEdit->append(QString("%1").arg(args["Text"].toString().remove('\n')));
        break;
    case Aqpm::Globals::RetrieveStart:
        if ( status != 1 ) {
            status = 1;
            textEdit->append( QString( tr( "<br><b> * Package Downloading Started</b><br>" ) ) );
            startDownload();
        }
        actionDetail->setText( QString( tr( "Starting downloading packages from %1..." ) ).arg(args["Repo"].toString()));
        textEdit->append( QString( tr( "Starting downloading packages from %1..." ) ).arg(args["Repo"].toString()));
        break;
        /* all the simple done events, with fallthrough for each */
    default:
        break;
    }

}

void QueueDialog::updateProgressBar( const QString &c, int bytedone, int bytetotal, int speed,
                                     int listdone, int listtotal )
{
    double bt = (float)bytetotal / 1024.0;
    double bd = (float)bytedone / 1024.0;
    double spd = (float)speed / 1024.0;

    if ( speed == 0 ) {
        return;
    }

    int rsecs = (int)((listtotal - listdone) / (speed));

    QTime remaining = QTime().addSecs(rsecs);

    progressBar->setFormat( QString( tr( "%p% (%1 KB/s, %2 remaining)", "You just have to "
                                         "translate 'remaining' here. Leave everything else as it is." ) ).
                            arg( spd, 0, 'f', 1 ).arg(remaining.toString("hh:mm:ss")) );
    progressBar->setRange( 0, listtotal );
    progressBar->setValue( listdone );


    if ( bytetotal > 2048000 ) {
        actionDetail->setText( QString( tr( "Downloading %1... (%2 MB of %3 MB)" ) ).
                               arg(c.split('-').at(c.split('-').count() - 1)).
                               arg( bd / 1024, 0, 'f', 2 ).arg( bt / 1024, 0, 'f', 2 ) );
    } else {
        actionDetail->setText( QString( tr( "Downloading %1... (%2 KB of %3 KB)" ) ).
                               arg(c.split('-').at(c.split('-').count() - 1)).
                               arg( bd, 0, 'f', 0 ).arg( bt, 0, 'f', 0 ) );
    }
}

void QueueDialog::updateProgressBar( Aqpm::Globals::TransactionProgress evt, const QString &pkgname, int percent,
                                     int howmany, int remain )
{
    Q_UNUSED( evt );

    qDebug() << "Got it: it's " << pkgname << " at percentage " << percent;

    if ( progressBar->value() != remain ) {
        progressBar->setFormat( "%p%" );
        progressBar->setRange( 0, 100 );

        int value = ( int )((( float )remain / ( float )howmany ) * ( float )100 );

        if ( progressBar->value() != value )
            progressBar->setValue( value );

        emit streamTransactionProgress( value );
    }
}

void QueueDialog::startDownload()
{
    transLabel->setPixmap( QIcon( ":/Icons/icons/dialog-ok-apply.png" ).pixmap( 22 ) );
    dlLabel->setPixmap( QIcon( ":/Icons/icons/edit-redo.png" ).pixmap( 22 ) );

    qDebug() << "Package Download detected";

    if ( progressBar->isHidden() )
        progressBar->show();
}

void QueueDialog::startProcess()
{
    transLabel->setPixmap( QIcon( ":/Icons/icons/dialog-ok-apply.png" ).pixmap( 22 ) );
    dlLabel->setPixmap( QIcon( ":/Icons/icons/dialog-ok-apply.png" ).pixmap( 22 ) );
    processLabel->setPixmap( QIcon( ":/Icons/icons/edit-redo.png" ).pixmap( 22 ) );

    disconnect( Backend::instance(), SIGNAL(streamDlProg( const QString&, int, int, int, int, int )), 0, 0 );
    connect( Backend::instance(),
             SIGNAL( streamTransProgress( Aqpm::Globals::TransactionProgress, const QString&, int, int, int ) ),
             this,
             SLOT( updateProgressBar( Aqpm::Globals::TransactionProgress, const QString&, int, int, int ) ) );
}

void QueueDialog::cleanup(bool success)
{
    disconnect( Backend::instance(), SIGNAL( streamTransProgress( Aqpm::Globals::TransactionProgress, const QString&, int, int, int ) ), 0, 0 );
    disconnect( Backend::instance(), SIGNAL( streamTransEvent( Aqpm::Globals::TransactionEvent, QVariantMap ) ), 0, 0);
    disconnect( Backend::instance(), SIGNAL(logMessageStreamed(QString)), 0, 0);
    disconnect( Backend::instance(), SIGNAL(streamDlProg( const QString&, int, int, int, int, int )), 0, 0);
    processLabel->setPixmap( QIcon( ":/Icons/icons/dialog-ok-apply.png" ).pixmap( 22 ) );
    cleanUpLabel->setPixmap( QIcon( ":/Icons/icons/edit-redo.png" ).pixmap( 22 ) );

    actionDetail->setText( QString( tr( "Queue processed, please wait..." ) ) );

    emit terminated( errors && !success );

    cleanUpLabel->setPixmap( QIcon( ":/Icons/icons/dialog-ok-apply.png" ).pixmap( 22 ) );

    if ( errors || !success ) {
        actionDetail->setText( QString( tr( "Queue processing failed!" ) ) );
        textEdit->append( QString( "<br><b> * " + tr( "Queue processing failed!" ) + "</b>" ) );
    } else {
        actionDetail->setText( QString( tr( "Queue processed successfully!" ) ) );
        textEdit->append( QString( "<br><b> * " + tr( "Queue processed successfully!" ) + "</b>" ) );
    }

    QSettings *settings = new QSettings();

    if ( settings->value( "gui/keepqueuedialogopen", true ).toBool() ) {
        disconnect( abortTr, SIGNAL( clicked() ), 0, 0 );
        abortTr->setText( tr( "Close" ) );
        abortTr->setIcon( QIcon( ":/Icons/icons/application-exit.png" ) );
        connect( abortTr, SIGNAL( clicked() ), SLOT( deleteLater() ) );
    }

    settings->deleteLater();
}

void QueueDialog::abortTransaction()
{
    switch ( ShamanDialog::popupQuestionDialog( QString( tr( "Queue Processing" ) ),
             QString( tr( "Would you like to abort Queue Processing?\nThis may damage your system." ) ), this,
             ShamanProperties::WarningDialog ) ) {
    case QMessageBox::Yes:
        errors = true;

        qDebug() << "Interrupting transaction...";

        //aHandle->interruptTransaction();

        //cTh->terminate();

        qDebug() << "Transaction interrupted";

        cleanup(false);

        break;
    case QMessageBox::No:
        break;
    default:
        // should never be reached
        break;
    }
}

void QueueDialog::handleAlpmMessage( const QString &msg )
{
    textEdit->append( QString() );
    QString view( QString( "<p><b><i> ==> " ) + msg + QString( "</b></i></p><br>" ) );

    qDebug() << msg;

    view.remove( QChar( '\n' ) );

    textEdit->insertHtml( view );

    textEdit->moveCursor( QTextCursor::End );
}
