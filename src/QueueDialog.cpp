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

#include <alpm.h>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QProcess>
#include <QFile>
#include <QDir>
#include <QWaitCondition>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QSettings>
#include <QTime>

using namespace std;
using namespace Aqpm;

QueueDialog::QueueDialog( QWidget *parent )
        : QDialog( parent ),
        errors( false )
{
    setupUi( this );
    textEdit->hide();
    setWindowModality( Qt::WindowModal );

    connect( Backend::instance(), SIGNAL( streamTransEvent( int, void*, void* ) ),
             SLOT( changeStatus( int, void*, void* ) ) );
    connect( Backend::instance(), SIGNAL( logMsgStreamed( const QString& ) ),
             SLOT( handleAlpmMessage( const QString& ) ) );
    connect( Backend::instance(), SIGNAL( streamDlProg( const QString&, int, int, int, int, int ) ),
             SLOT( updateProgressBar( const QString&, int, int, int, int, int ) ) );
    /*connect( aHandle, SIGNAL( preparingTransactionError( const QString& ) ),
             SLOT( handlePreparingError( const QString& ) ) );
    connect( aHandle, SIGNAL( committingTransactionError( const QString& ) ),
             SLOT( handleCommittingError( const QString& ) ) );*/
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
    flags.append(PM_TRANS_FLAG_NOSCRIPTLET);
    if (force) {
        flags.append(PM_TRANS_FLAG_FORCE);
    }

    Backend::instance()->processQueue(flags);

    connect( Backend::instance(), SIGNAL( operationFinished(bool) ), SLOT( cleanup(bool) ) );
}

void QueueDialog::changeStatus( int evt, void *data1, void *data2 )
{
    pmtransevt_t event = (pmtransevt_t)evt;

    qDebug() << "Entering Queue Lock, with event " << event;

    QString upgTxt;
    QString addTxt;
    QString remTxt;

    switch ( event ) {
    case PM_TRANS_EVT_CHECKDEPS_START:
        actionDetail->setText( QString( tr( "Validating Dependencies..." ) ) );
        textEdit->append( QString( tr( "Validating Dependencies..." ) ) );
        break;
    case PM_TRANS_EVT_FILECONFLICTS_START:
        actionDetail->setText( QString( tr( "Checking for Conflicts..." ) ) );
        textEdit->append( QString( tr( "Checking for Conflicts..." ) ) );
        break;
    case PM_TRANS_EVT_RESOLVEDEPS_START:
        actionDetail->setText( QString( tr( "Resolving Dependencies..." ) ) );
        textEdit->append( QString( tr( "Resolving Dependencies..." ) ) );
        break;
    case PM_TRANS_EVT_INTERCONFLICTS_START:
        actionDetail->setText( QString( tr( "Looking for Inter-Conflicts..." ) ) );
        textEdit->append( QString( tr( "Looking for Inter-Conflicts..." ) ) );
        break;
    case PM_TRANS_EVT_ADD_START:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Package Installation Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Installing %1..." ) ).arg( alpm_pkg_get_name(( pmpkg_t * )data1 ) ) );
        textEdit->append( QString( tr( "Installing %1..." ) ).arg( alpm_pkg_get_name(( pmpkg_t * )data1 ) ) );

        break;
    case PM_TRANS_EVT_ADD_DONE:
        addTxt = QString( tr( "%1 (%2) installed successfully!" ) ).arg(
                     alpm_pkg_get_name(( pmpkg_t * )data1 ) ).arg( alpm_pkg_get_version(( pmpkg_t * )data1 ) );
        actionDetail->setText( addTxt );
        textEdit->append( addTxt );
        addTxt.append( QChar( '\n' ) );
        alpm_logaction( addTxt.toUtf8().data() );

        break;
    case PM_TRANS_EVT_REMOVE_START:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Package Removal Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Removing %1..." ) ).arg( alpm_pkg_get_name(( pmpkg_t * )data1 ) ) );
        textEdit->append( QString( tr( "Removing %1..." ) ).arg( alpm_pkg_get_name(( pmpkg_t * )data1 ) ) );
        break;
    case PM_TRANS_EVT_REMOVE_DONE:
        remTxt = QString( tr( "%1 (%2) removed successfully!" ) ).
                 arg( alpm_pkg_get_name(( pmpkg_t * )data1 ) ).arg( alpm_pkg_get_version(( pmpkg_t * )data1 ) );

        actionDetail->setText( remTxt );
        textEdit->append( remTxt );
        remTxt.append( QChar( '\n' ) );
        alpm_logaction( remTxt.toUtf8().data() );
        break;
    case PM_TRANS_EVT_UPGRADE_START:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Package Upgrading Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Upgrading %1..." ) ).arg( alpm_pkg_get_name(( pmpkg_t * )data1 ) ) );
        textEdit->append( QString( tr( "Upgrading %1..." ) ).arg( alpm_pkg_get_name(( pmpkg_t * )data1 ) ) );
        break;
    case PM_TRANS_EVT_UPGRADE_DONE:
        upgTxt = QString( tr( "Upgraded %1 successfully (%2 -> %3)" ) ).arg(
                     ( char * )alpm_pkg_get_name(( pmpkg_t * )data1 ) ).arg(( char * )alpm_pkg_get_version(( pmpkg_t * )data2 ) ).
                 arg(( char * )alpm_pkg_get_version(( pmpkg_t * )data1 ) );

        actionDetail->setText( upgTxt );
        textEdit->append( upgTxt );
        upgTxt.append( QChar( '\n' ) );
        alpm_logaction( upgTxt.toUtf8().data() );

        break;
    case PM_TRANS_EVT_INTEGRITY_START:
        if ( status != 2 ) {
            status = 2;
            textEdit->append( QString( tr( "<br><b> * Queue Processing Started</b><br>" ) ) );
            startProcess();
        }
        actionDetail->setText( QString( tr( "Checking package integrity..." ) ) );
        textEdit->append( QString( tr( "Checking package integrity..." ) ) );
        break;
    case PM_TRANS_EVT_DELTA_INTEGRITY_START:
        actionDetail->setText( QString( tr( "Checking delta integrity..." ) ) );
        textEdit->append( QString( tr( "Checking delta integrity..." ) ) );
        break;
    case PM_TRANS_EVT_DELTA_PATCHES_START:
        actionDetail->setText( QString( tr( "Applying deltas..." ) ) );
        break;
    case PM_TRANS_EVT_DELTA_PATCH_START:
        actionDetail->setText( QString( tr( "Generating %1 with %2... " ) ).arg(( char * )data1 ).
                               arg(( char * )data2 ) );
        break;
    case PM_TRANS_EVT_DELTA_PATCH_DONE:
        actionDetail->setText( QString( tr( "Success!" ) ) );
        break;
    case PM_TRANS_EVT_DELTA_PATCH_FAILED:
        actionDetail->setText( QString( tr( "Failed!" ) ) );
        break;
    case PM_TRANS_EVT_SCRIPTLET_INFO:
        actionDetail->setText( QString( "%s" ).arg(( char* )data1 ) );
        textEdit->append( QString( "%s" ).arg(( char* )data1 ) );
        break;
    case PM_TRANS_EVT_RETRIEVE_START:
        if ( status != 1 ) {
            status = 1;
            textEdit->append( QString( tr( "<br><b> * Package Downloading Started</b><br>" ) ) );
            startDownload();
        }
        actionDetail->setText( QString( tr( "Starting downloading packages from %1..." ) ).arg(( char* )data1 ) );
        textEdit->append( QString( tr( "Starting downloading packages from %1..." ) ).arg(( char* )data1 ) );
        break;
        /* all the simple done events, with fallthrough for each */
    case PM_TRANS_EVT_FILECONFLICTS_DONE:
        //case PM_TRANS_EVT_EXTRACT_DONE:
    case PM_TRANS_EVT_CHECKDEPS_DONE:
    case PM_TRANS_EVT_RESOLVEDEPS_DONE:
    case PM_TRANS_EVT_INTERCONFLICTS_DONE:
    case PM_TRANS_EVT_INTEGRITY_DONE:
    case PM_TRANS_EVT_DELTA_INTEGRITY_DONE:
    case PM_TRANS_EVT_DELTA_PATCHES_DONE:
        break;
    }

}

void QueueDialog::updateProgressBar( const QString &c, int bytedone, int bytetotal, int speed,
                                     int listdone, int listtotal )
{
    double bt = bytetotal / 1024;
    double bd = bytedone / 1024;

    QTime remaining(0,0,0);

    if ( speed == 0 ) {
        return;
    }

    remaining.addSecs(( listtotal - listdone ) / ( speed * 1024.0 ));

    progressBar->setFormat( QString( tr( "%p% (%1 KB/s, %2 remaining)", "You just have to "
                                         "translate 'remaining' here. Leave everything else as it is." ) ).
                            arg( speed ).arg(remaining.toString()) );
    progressBar->setRange( 0, listtotal );
    progressBar->setValue( listdone );


    if ( bytetotal > 2048000 )
        actionDetail->setText( QString( tr( "Downloading %1... (%2 MB of %3 MB)" ) ).
                               arg( c ).arg( bd / 1024, 0, 'f', 2 ).arg( bt / 1024, 0, 'f', 2 ) );
    else
        actionDetail->setText( QString( tr( "Downloading %1... (%2 KB of %3 KB)" ) ).
                               arg( c ).arg( bd, 0, 'f', 0 ).arg( bt, 0, 'f', 0 ) );
}

void QueueDialog::updateProgressBar( int evt, const QString &pkgname, int percent,
                                     int howmany, int remain )
{
    Q_UNUSED( pkgname );
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

    disconnect( Backend::instance(), SIGNAL( streamDlProg( QString&, int, int, int, int, int ) ), 0, 0 );
    connect( Backend::instance(), SIGNAL( streamTransProgress( int, const QString&, int, int, int ) ),
             SLOT( updateProgressBar( int, const QString&, int, int, int ) ) );
}

void QueueDialog::cleanup(bool success)
{
    disconnect( Backend::instance(), SIGNAL( streamTransProgress( int, const QString&, int, int, int ) ), 0, 0 );
    disconnect( Backend::instance(), SIGNAL( streamTransEvent( int, void*, void* ) ), 0, 0);
    disconnect( Backend::instance(), SIGNAL( logMsgStreamed( const QString& ) ), 0, 0);
    disconnect( Backend::instance(), SIGNAL( streamTransDlProg( const QString&, int, int, int, int, int, int ) ), 0, 0);
    /*connect( aHandle, SIGNAL( preparingTransactionError( const QString& ) ),
                 SLOT( handlePreparingError( const QString& ) ) );
        connect( aHandle, SIGNAL( committingTransactionError( const QString& ) ),
                 SLOT( handleCommittingError( const QString& ) ) );*/
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

void QueueDialog::handlePreparingError( const QString &msg )
{
    qDebug() << "Creating Preparing Error";

    QDialog *dlog = new QDialog( this );
    QLabel *lbl = new QLabel( dlog );
    QTextEdit *txtEd = new QTextEdit( msg, dlog );
    QDialogButtonBox *but = new QDialogButtonBox( dlog );
    QVBoxLayout *lay = new QVBoxLayout();

    lbl->setText( QString( tr( "There has been an error"
                               " while preparing the transaction.\n" ) + QString::fromLocal8Bit( alpm_strerrorlast() ) ) );

    txtEd->setReadOnly( true );

    QPushButton *okb = but->addButton( QDialogButtonBox::Ok );
    okb->setText( QObject::tr( "Ok" ) );
    okb->setIcon( QIcon( ":/Icons/icons/dialog-ok-apply.png" ) );

    lay->addWidget( lbl );
    lay->addWidget( txtEd );
    lay->addWidget( but );

    dlog->setLayout( lay );
    dlog->setWindowTitle( QString( tr( "Queue Processing" ) ) );
    dlog->setWindowModality( Qt::ApplicationModal );

    connect( but, SIGNAL( accepted() ), dlog, SLOT( accept() ) );

    dlog->exec();

    errors = true;

    qDebug() << "Streaming Awakening to Error Thread";
}

void QueueDialog::handleCommittingError( const QString &msg )
{
    qDebug() << "Creating Committing Error";

    QDialog *dlog = new QDialog( this );
    QLabel *lbl = new QLabel( dlog );
    QTextEdit *txtEd = new QTextEdit( msg, dlog );
    QDialogButtonBox *but = new QDialogButtonBox( dlog );
    QVBoxLayout *lay = new QVBoxLayout();

    lbl->setText( QString( tr( "There has been an error"
                               " while committing the transaction.\n" ) + QString::fromLocal8Bit( alpm_strerrorlast() ) ) );

    txtEd->setReadOnly( true );

    QPushButton *okb = but->addButton( QDialogButtonBox::Ok );
    okb->setText( QObject::tr( "Ok" ) );
    okb->setIcon( QIcon( ":/Icons/icons/dialog-ok-apply.png" ) );

    lay->addWidget( lbl );
    lay->addWidget( txtEd );
    lay->addWidget( but );

    dlog->setLayout( lay );
    dlog->setWindowTitle( QString( tr( "Queue Processing" ) ) );
    dlog->setWindowModality( Qt::ApplicationModal );

    connect( but, SIGNAL( accepted() ), dlog, SLOT( accept() ) );

    dlog->exec();

    errors = true;

    qDebug() << "Streaming Awakening to Error Thread";
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
