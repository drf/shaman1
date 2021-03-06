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

#ifndef SYSUPGRADEDIALOG_H
#define SYSUPGRADEDIALOG_H

#include <iostream>
#include "ui_upgradeDialog.h"
#include <alpm.h>

#include <QDialog>

class SysUpgradeDialog : public QDialog, private Ui::upgradeDialog
{
    Q_OBJECT

public:
    explicit SysUpgradeDialog(QWidget *parent = 0);
    ~SysUpgradeDialog();

    bool force();

    void init();

private slots:
    void abort();
    void initSysUpgrade();
    void addPkg();
    void adjust(bool tgld);

signals:
    void aborted();
    void upgradeNow();
    void addToPkgQueue();

};

#endif /*SYSUPGRADEDIALOG_H*/
