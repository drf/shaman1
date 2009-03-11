/***************************************************************************
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                                                    *
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

#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include "ui_configDialog.h"
#include <QThread>
#include <QProcess>
#include <QPointer>

namespace ShamanProperties
{

enum MirrorType {
    OfficialMirrors,
    KDEModMirrors
};

}  // namespace ShamanProperties

class CleanThread : public QThread
{
        Q_OBJECT

    public:
        CleanThread( int act );
        void run();

    signals:
        void success( int act );
        void failure( int act );

    private:
        int action;
};


class ConfigDialog : public QDialog, public Ui::ConfigDialog
{

        Q_OBJECT

    public:
        explicit ConfigDialog( QWidget *parent = 0 );
        ~ConfigDialog();
        bool doDbUpdate();

    signals:
        void setProxy();

    private slots:
        void changeWidget( int position );
        void openAddDialog();
        void openEditDialog();
        void removeThirdParty();
        void performManteinanceAction();
        void cleanProc( int eC, QProcess::ExitStatus eS );
        void mantProgress();
        void showSuccess( int act );
        void showFailure( int act );
        void cleanThread();
        void saveConfiguration();
        void addMirror();
        void addKDEModMirror();
        void obfuscateSupfiles( bool state );
        void obfuscateDBUpdate( bool state );
        void obfuscateDBUpdateAt( bool state );
        void obfuscateRSSUpdate( bool state );

    private:
        void setupRepos();
        void setupGeneral();
        void setupPacman();
        void setupABS();
        void setupAdvanced();
        void saveSettings();
        QStringList getMirrorList( ShamanProperties::MirrorType type = ShamanProperties::OfficialMirrors );

    private:
        QPointer<QDialog> addDialog;
        QPointer<CleanThread> cTh;
        QPointer<RootProcess> mantProc;
        bool upDb;
};

#endif /*CONFIGDIALOG_H*/
