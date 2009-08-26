/***************************************************************************
 *   Copyright (C) 2009 by Dario Freddi                                    *
 *   drf@chakra-project.org                                                *
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

#ifndef MIRRORWIDGET_H
#define MIRRORWIDGET_H

#include <QWidget>

#include <aqpm/Configuration.h>

namespace Ui {
    class MirrorWidget;
}

class MirrorWidget : public QWidget
{
    Q_OBJECT

public:
    MirrorWidget(Aqpm::Configuration::MirrorType type, QWidget *parent = 0);

    void reloadMirrors();
    QString mirror() const;
    void setMirror(const QString &mirror);
    Aqpm::Configuration::MirrorType type() const;

Q_SIGNALS:
    void mirrorSelectionChanged(const QString &mirror);
    void prefer();
    void defer();
    void remove();

private:
    Ui::MirrorWidget *m_ui;
    Aqpm::Configuration::MirrorType m_type;
};

#endif // MIRRORWIDGET_H
