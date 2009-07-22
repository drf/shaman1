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

#include "ShamanTreeWidgetItem.h"

ShamanTreeWidgetItem::ShamanTreeWidgetItem()
        : QTreeWidgetItem()
{
}

ShamanTreeWidgetItem::~ShamanTreeWidgetItem()
{
}

bool ShamanTreeWidgetItem::operator<(const QTreeWidgetItem &other) const
{
    int column = treeWidget() ? treeWidget()->sortColumn() : 0;

    if (column == 4)
        return data(column, Qt::UserRole).toInt() < other.data(column, Qt::UserRole).toInt();
    else if (column == 0)
        return data(column, Qt::UserRole).toInt() < other.data(column, Qt::UserRole).toInt();
    else
        return text(column) < other.text(column);
}
