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

#ifndef MAINTENANCEBAR_H
#define MAINTENANCEBAR_H

#include <QToolBar>
#include <QPointer>
#include <QProcess>

class QAction;
class AlpmHandler;
class RootProcess;
class CleanThread;
class QLabel;
class QTextEdit;
class QDialog;
class QPushButton;

class MaintenanceBar : public QToolBar
{
    Q_OBJECT

public:
    explicit MaintenanceBar(QWidget *parent = 0);
    virtual ~MaintenanceBar();

private slots:
    void performAction();
    void openDialog();

    void performed(bool success);

    void mantProgress(const QString &process);

private:
    QPointer<QAction> m_comboBox;

    QPointer<QLabel> statusLabel;
    QPointer<QTextEdit> mantDetails;
    QPointer<QDialog> m_dialog;
    QPointer<QPushButton> m_button;
    int m_currentMaint;
};

#endif /* MAINTENANCEBAR_H */
