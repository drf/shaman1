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

#include "configDialog.h"

#include "AlpmHandler.h"

ConfigDialog::ConfigDialog(AlpmHandler *handler, QWidget *parent)
  : QDialog(parent),
    m_handler(handler)
{
    setupUi(this);
    connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(changeWidget(int)));
}

ConfigDialog::~ConfigDialog()
{
}

void ConfigDialog::addPage(int position, QWidget *newWidget, const QString &title, const QIcon &icon)
{
    listWidget->insertItem(position, new QListWidgetItem(icon, title));
    stackedWidget->insertWidget(position, newWidget);
}

void ConfigDialog::changeWidget(int position)
{
    stackedWidget->setCurrentIndex(position);
}
