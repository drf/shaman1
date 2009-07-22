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

#ifndef TRANSACTIONVIEW_H
#define TRANSACTIONVIEW_H

namespace Plasma
{
class Applet;
class Icon;
}

#include "AbstractView.h"

#include <QtDBus/QDBusConnection>

class QGraphicsLinearLayout;
class QGraphicsProxyWidget;
class QProgressBar;
class QLabel;

class TransactionView : public AbstractView
{
    Q_OBJECT

public:
    TransactionView(Plasma::Applet *parent, QDBusConnection dbs);
    virtual ~TransactionView();

private slots:
    void status(const QString &status);
    void dlProgress(const QString &filename, int totalPercent, int totalSpeed);
    void transProgress(int percent);

private:
    QDBusConnection m_dbus;
    QGraphicsLinearLayout *m_layout;
    QProgressBar *m_progressBarWidget;
    QLabel *m_statusLabelWidget;
    QGraphicsProxyWidget *m_statusLabel;
    QGraphicsProxyWidget *m_progressBar;
};

#endif /*TRANSACTIONVIEW_H*/
