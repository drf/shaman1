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

#ifndef BUILDINGHANDLER_H
#define BUILDINGHANDLER_H

#include <QStringList>
#include <QDialog>
#include <QPointer>

#include "ui_reviewBuildingDialog.h"

class MainWindow;
class BuildingDialog;
class EditPBuild;
class QueueDialog;

class BuildingHandler : public QObject
{
        Q_OBJECT

    public:
        explicit BuildingHandler( MainWindow *mW );
        virtual ~BuildingHandler();

    public slots:
        void updateABSTree();
        void validateSourceQueue();
        void startSourceProcessing();
        void finishedBuilding( int failure, const QStringList &targets );
        void processBuiltPackages();
        void openPBuildDialog();
        void processBuildWizard();
        void reduceBuildingInTray();
        void ABSUpdateEnded();
        void nullifyBDialog();
        void adjust( bool tgld );

    signals:
        void outOfScope();
        void buildingStarted();
        void buildingFinished();

    private:
        QPointer<BuildingDialog> buildDialog;
        Ui::reviewBuildingDialog *revBuildUi;
        QPointer<EditPBuild> pBuildEditor;
        QPointer<QDialog> reviewBQueue;
        QPointer<QueueDialog> queueDl;
        MainWindow *mWin;

        QStringList installedMakeDepends;
        QStringList installedBinaryPkgs;
        QStringList buildTargets;
};

#endif /*BUILDINGHANDLER_H*/
