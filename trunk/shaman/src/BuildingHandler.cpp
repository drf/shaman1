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

#include "BuildingHandler.h"

#include <QIcon>
#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QString>

#include "MainWindow.h"
#include "AlpmHandler.h"
#include "ABSHandler.h"
#include "BuildingDialog.h"
#include "QueueDialog.h"
#include "EditPBuild.h"
#include "ShamanTrayIcon.h"
#include "ShamanDialog.h"

BuildingHandler::BuildingHandler( MainWindow *mW, AlpmHandler *aH )
        : mWin( mW ),
        aHandle( aH )
{
}

BuildingHandler::~BuildingHandler()
{
}

void BuildingHandler::updateABSTree()
{
    if ( !aHandle->isInstalled( "abs" ) ) {
        switch ( ShamanDialog::popupQuestionDialog( QString( tr( "Error" ) ), QString( tr( "You need to have ABS "
                 "installed to use Shaman's\nbuilding feature. Do you want to install it now?" ) ), mWin ) ) {
        case QMessageBox::Yes:
            mWin->cancelAllActions();
            mWin->installPackage( "abs" );
            mWin->widgetQueueToAlpmQueue();
            break;
        case QMessageBox::No:
            break;
        default:
            // should never be reached
            break;
        }

        return;
    }


    emit buildingStarted();

    buildDialog = new BuildingDialog( aHandle, mWin );
    connect( buildDialog, SIGNAL( nullifyPointer() ), SLOT( ABSUpdateEnded() ) );

    buildDialog->show();

    connect( buildDialog->reduceButton, SIGNAL( clicked() ), SLOT( reduceBuildingInTray() ) );

    buildDialog->updateABSTree();
}

void BuildingHandler::validateSourceQueue()
{
    if ( !aHandle->isInstalled( "abs" ) ) {
        switch ( ShamanDialog::popupQuestionDialog( QString( tr( "Error" ) ), QString( tr( "You need to have ABS "
                 "installed to use Shaman's\nbuilding feature. Do you want to install it now?" ) ), mWin ) ) {
        case QMessageBox::Yes:
            mWin->cancelAllActions();
            mWin->installPackage( "abs" );
            mWin->widgetQueueToAlpmQueue();
            break;
        case QMessageBox::No:
            break;
        default:
            // should never be reached
            break;
        }

        emit outOfScope();

        return;
    }

    if ( mWin->getInstallPackagesInWidgetQueue().isEmpty() &&
            mWin->getRemovePackagesInWidgetQueue().isEmpty() &&
            mWin->getUpgradePackagesInWidgetQueue().isEmpty() ) {
        qDebug() << "Nothing in Queue";
        emit outOfScope();
        return;
    } else if ( !mWin->getRemovePackagesInWidgetQueue().isEmpty() ) {
        ShamanDialog::popupDialog( tr( "Error" ), QString( tr( "You can not remove packages when processing\n"
                                   "your queue from Source" ) ), mWin, ShamanProperties::WarningDialog );

        emit outOfScope();
        return;
    }

    foreach( QTreeWidgetItem *itm, mWin->getInstallPackagesInWidgetQueue() + mWin->getUpgradePackagesInWidgetQueue() ) {
        if ( itm->text( 5 ).compare( "core" ) && itm->text( 5 ).compare( "extra" ) && itm->text( 5 ).compare( "community" )
                && itm->text( 5 ).compare( "unstable" ) && itm->text( 5 ).compare( "testing" ) ) {
            ShamanDialog::popupDialog( tr( "Error" ), QString( tr( "Some of your packages do not belong to Arch\n"
                                       "Linux's official repository. Shaman is able to\nbuild packages from official sources only." ) ), mWin,
                                       ShamanProperties::WarningDialog );

            emit outOfScope();
            return;
        }
    }

    reviewBQueue = new QDialog( mWin );

    revBuildUi = new Ui::reviewBuildingDialog();

    revBuildUi->setupUi( reviewBQueue );
    revBuildUi->treeWidget->hide();

    reviewBQueue->adjustSize();

    connect( revBuildUi->showPackages, SIGNAL( toggled( bool ) ), SLOT( adjust( bool ) ) );

    QSettings *settings = new QSettings();

    if ( settings->value( "absbuilding/wizardbuild" ).toBool() )
        revBuildUi->depsWizardBox->setChecked( true );

    if ( settings->value( "absbuilding/reviewoutput" ).toBool() )
        revBuildUi->noProcessBox->setChecked( true );

    settings->deleteLater();

    reviewBQueue->setWindowModality( Qt::ApplicationModal );
    reviewBQueue->setAttribute( Qt::WA_DeleteOnClose, true );

    revBuildUi->infoLabel->setText(( mWin->getUpgradePackagesInWidgetQueue().size() +
                                     QString( tr( "You are about to install <b>%n package(s)</b> "
                                                  "from source. Building from source<br>can give some advantages, however is very slow.<br>If "
                                                  "you are not sure about that, you would probably prefer to process<br>your queue from binary files. "
                                                  "Before you continue, you are advised to<br>review your configuration to improve your building performance.", "",
                                                  mWin->getUpgradePackagesInWidgetQueue().size() + mWin->getInstallPackagesInWidgetQueue().size() ) )
                                   ) );

    if ( !mWin->getInstallPackagesInWidgetQueue().isEmpty() ) {
        QTreeWidgetItem *itm = new QTreeWidgetItem( revBuildUi->treeWidget, QStringList( tr( "To be Installed" ) ) );
        revBuildUi->treeWidget->addTopLevelItem( itm );
    }
    if ( !mWin->getUpgradePackagesInWidgetQueue().isEmpty() ) {
        QTreeWidgetItem *itm = new QTreeWidgetItem( revBuildUi->treeWidget, QStringList( tr( "To be Upgraded" ) ) );
        revBuildUi->treeWidget->addTopLevelItem( itm );
    }


    foreach( QTreeWidgetItem *itm, mWin->getInstallPackagesInWidgetQueue() ) {
        aHandle->addSyncToQueue( itm->text( 1 ) );
        QTreeWidgetItem *itmL = revBuildUi->treeWidget->findItems( tr( "To be Installed" ), Qt::MatchExactly, 0 ).first();
        new QTreeWidgetItem( itmL, QStringList( itm->text( 1 ) ) );
    }

    foreach( QTreeWidgetItem *itm, mWin->getUpgradePackagesInWidgetQueue() ) {
        aHandle->addSyncToQueue( itm->text( 1 ) );
        QTreeWidgetItem *itmL = revBuildUi->treeWidget->findItems( tr( "To be Upgraded" ), Qt::MatchExactly, 0 ).first();
        new QTreeWidgetItem( itmL, QStringList( itm->text( 1 ) ) );
    }

    connect( revBuildUi->binaryButton, SIGNAL( clicked() ), reviewBQueue, SLOT( close() ) );
    connect( revBuildUi->binaryButton, SIGNAL( clicked() ), mWin, SLOT( widgetQueueToAlpmQueue() ) );
    connect( revBuildUi->abortButton, SIGNAL( clicked() ), reviewBQueue, SLOT( close() ) );
    connect( revBuildUi->sourceButton, SIGNAL( clicked() ), reviewBQueue, SLOT( close() ) );
    connect( revBuildUi->sourceButton, SIGNAL( clicked() ), SLOT( startSourceProcessing() ) );
    connect( revBuildUi->pBuildButton, SIGNAL( clicked() ), SLOT( openPBuildDialog() ) );

    reviewBQueue->show();
}

void BuildingHandler::adjust( bool tgld )
{
    if ( tgld )
        revBuildUi->treeWidget->show();
    else {
        revBuildUi->treeWidget->hide();
        reviewBQueue->resize( reviewBQueue->minimumSize() );
    }

    reviewBQueue->adjustSize();
}


void BuildingHandler::openPBuildDialog()
{
    QStringList targets;

    foreach( QTreeWidgetItem *itm, mWin->getUpgradePackagesInWidgetQueue() )
    targets.append( itm->text( 1 ) );

    foreach( QTreeWidgetItem *itm, mWin->getInstallPackagesInWidgetQueue() )
    targets.append( itm->text( 1 ) );

    pBuildEditor = new EditPBuild( targets, reviewBQueue );

    pBuildEditor->exec();

    pBuildEditor->deleteLater();
}

void BuildingHandler::startSourceProcessing()
{
    if ( queueDl != NULL ) {
        queueDl->deleteLater();
        queueDl = NULL;
    } else if ( revBuildUi->depsWizardBox->isChecked() ) {
        processBuildWizard();
        return;
    }

    emit buildingStarted();

    buildDialog = new BuildingDialog( aHandle, mWin );
    connect( buildDialog, SIGNAL( nullifyPointer() ), SLOT( nullifyBDialog() ) );

    buildDialog->initBuildingQueue();

    buildDialog->setWindowModality( Qt::WindowModal );
    buildDialog->setAttribute( Qt::WA_DeleteOnClose, true );

    foreach( QTreeWidgetItem *itm, mWin->getInstallPackagesInWidgetQueue() )
    buildDialog->addBuildingQueueItem( itm->text( 1 ) );

    foreach( QTreeWidgetItem *itm, mWin->getUpgradePackagesInWidgetQueue() )
    buildDialog->addBuildingQueueItem( itm->text( 1 ) );

    if ( revBuildUi->noProcessBox->isChecked() )
        buildDialog->waitBeforeProcess( true );

    delete( revBuildUi );

    buildDialog->show();

    connect( buildDialog->reduceButton, SIGNAL( clicked() ), SLOT( reduceBuildingInTray() ) );

    connect( buildDialog, SIGNAL( finishedBuilding( int, const QStringList& ) ), this, SLOT( finishedBuilding( int, const QStringList& ) ) );

    buildDialog->processBuildingQueue();
}

void BuildingHandler::finishedBuilding( int failure, const QStringList &targets )
{
    buildTargets.clear();

    emit buildingFinished();

    if ( failure == 2 ) {
        if ( buildDialog->isHidden() )
            mWin->getTrayIcon()->showMessage( QString( tr( "Package Building" ) ), QString( tr( "Your Packages failed to build!" ) ) );
        else
            ShamanDialog::popupDialog( tr( "Error" ), QString( tr( "Your packages Failed to Build.\n"
                                       "Look at the output for more details." ) ), buildDialog );

        buildDialog->abortButton->setText( QString( tr( "Close" ) ) );
        disconnect( buildDialog->abortButton, SIGNAL( clicked() ), buildDialog, SLOT( abortProcess() ) );
        connect( buildDialog->abortButton, SIGNAL( clicked() ), buildDialog, SLOT( deleteLater() ) );
        buildDialog->processingLabel->setText( QString( tr( "Building Packages Failed!!" ) ) );
        buildDialog->buildingLabel->setText( QString() );

        return;
    } else if ( failure == 1 ) {
        buildDialog->processingLabel->setText( QString( tr( "Building Packages Failed!!" ) ) );
        buildDialog->buildingLabel->setText( QString() );

        switch ( ShamanDialog::popupQuestionDialog( QString( tr( "Error" ) ),
                 QString( tr( "Some packages failed to build.\nDo you want to proceed anyway?" ) ), buildDialog, ShamanProperties::WarningDialog ) ) {
        case QMessageBox::Yes:
            failure = 0;
            break;
        case QMessageBox::No:
            buildDialog->abortButton->setText( QString( tr( "Close" ) ) );
            disconnect( buildDialog->abortButton, SIGNAL( clicked() ), buildDialog, SLOT( abortProcess() ) );
            connect( buildDialog->abortButton, SIGNAL( clicked() ), buildDialog, SLOT( deleteLater() ) );
            break;
        default:
            // should never be reached
            break;
        }
    }

    if ( failure == 0 ) {
        buildTargets = targets;

        if ( buildDialog->reviewOutputFirst() ) {
            buildDialog->reduceButton->setText( QString( tr( "Install Built Packages" ) ) );
            buildDialog->abortButton->setText( QString( tr( "Close Without Installing" ) ) );
            buildDialog->processingLabel->setText( QString( tr( "Packages Built Successfully!" ) ) );
            buildDialog->buildingLabel->setText( QString() );
            if ( buildDialog->isHidden() )
                mWin->getTrayIcon()->showMessage( QString( tr( "Package Building" ) ), QString( tr( "Your Packages have been built successfully, "
                                                  "and are ready to be installed" ) ) );


            disconnect( buildDialog->abortButton, SIGNAL( clicked() ), buildDialog, SLOT( abortProcess() ) );
            connect( buildDialog->abortButton, SIGNAL( clicked() ), buildDialog, SLOT( deleteLater() ) );
            disconnect( buildDialog->reduceButton, SIGNAL( clicked() ), 0, 0 );
            connect( buildDialog->reduceButton, SIGNAL( clicked() ), SLOT( processBuiltPackages() ) );
        } else
            processBuiltPackages();
    }

}

void BuildingHandler::processBuiltPackages()
{
    buildDialog->deleteLater();

    if ( !installedMakeDepends.isEmpty() || !installedBinaryPkgs.isEmpty() ) {
        /* Huh, we installed something just to compile the package. Let's
         * see if the user wants installed makedepends to be immediately
         * removed, otherwise we just skip this part.
         */

        QSettings *settings = new QSettings();

        aHandle->initQueue( true, false, true );

        if ( settings->value( "absbuilding/clearmakedepends" ).toBool() && !installedMakeDepends.isEmpty() ) {
            /* Ok, let's cleanup then. We just need a special queue, so we
             * can remove just the stuff that is requesting our list.
             */

            foreach( const QString &rmv, installedMakeDepends )
            aHandle->addRemoveToQueue( rmv );
        }

        /* If some packages failed to build and we installed them from binary
         * we'd better remove them.
         */

        if ( !installedBinaryPkgs.isEmpty() ) {
            foreach( const QString &rmv, installedBinaryPkgs ) {
                bool found = false;

                foreach( const QString &match, buildTargets ) {
                    if ( match.contains( rmv ) )
                        found = true;
                }

                if ( !found )
                    aHandle->addRemoveToQueue( rmv );
            }
        }

        if ( aHandle->getRemoveInQueue().isEmpty() )
            aHandle->initQueue( false, false, true );
    } else
        aHandle->initQueue( false, false, true );

    foreach( const QString &pac, buildTargets )
    aHandle->addFFToQueue( pac );

    installedMakeDepends.clear();
    installedBinaryPkgs.clear();

    mWin->processQueue();

    emit outOfScope();
}

void BuildingHandler::processBuildWizard()
{
    /* We need to install the queue from binary first, then process
     * their makedepends (from binary too). So we have to call a processQueue()
     * and connect it to a slot that actually sends us to the real package
     * building. Nothing so hard after all :)
     */

    QStringList pkgList;
    QStringList binaryList;
    QStringList depsList;

    binaryList.clear();
    depsList.clear();

    foreach( QTreeWidgetItem *itm, mWin->getInstallPackagesInWidgetQueue() )
    pkgList.append( itm->text( 1 ) );

    foreach( QTreeWidgetItem *itm, mWin->getUpgradePackagesInWidgetQueue() )
    pkgList.append( itm->text( 1 ) );

    foreach( const QString &pkg, pkgList ) {
        foreach( const QString &mkdp, ABSHandler::getMakeDepends( pkg ) ) {
            if ( !aHandle->isInstalled( mkdp ) && !pkgList.contains( mkdp, Qt::CaseInsensitive ) )
                //Add to binary queue
            {
                qDebug() << "Makedepend is missing: " << mkdp;
                depsList.append( mkdp );
            }
        }

        if ( !aHandle->isInstalled( pkg ) )
            //Add to binary queue
        {
            qDebug() << "Package is not installed: " << pkg << ", installing it from binary first.";
            binaryList.append( pkg );
        }
    }

    if ( binaryList.isEmpty() && depsList.isEmpty() ) {
        /* Ok, we're probably reinstalling some packages and their makedepends
         * are satisfied, we just have to trigger the compilation
         */

        revBuildUi->depsWizardBox->setChecked( false );
        startSourceProcessing();
    } else {
        /* So, it turns out that we need to install some packages first.
         * We'll start a special Queue, and when it ends, compilation will
         * be immediately triggered. We also need to set up a cleanup
         * Queue, to remove makedepends installed.
         */

        aHandle->initQueue( false, true, false );

        installedMakeDepends = depsList;
        installedBinaryPkgs = binaryList;

        foreach( const QString &syn, binaryList )
        aHandle->addSyncToQueue( syn );

        foreach( const QString &syn, depsList )
        aHandle->addSyncToQueue( syn );

        queueDl = new QueueDialog( aHandle, mWin );

        connect( queueDl, SIGNAL( terminated( bool ) ), SLOT( startSourceProcessing() ) );

        queueDl->startProcessing( false );

        queueDl->show();
    }

}

void BuildingHandler::reduceBuildingInTray()
{
    buildDialog->hide();
    mWin->hide();
}

void BuildingHandler::ABSUpdateEnded()
{
    emit buildingFinished();
    emit outOfScope();
}

void BuildingHandler::nullifyBDialog()
{
}
