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
#include "shamanApplet.h"

#include <QAction>

#include <KIcon>

#include <plasma/layouts/hboxlayout.h>
#include <plasma/widgets/icon.h>

ShamanApplet::ShamanApplet(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args)
{
    setDrawStandardBackground(true);
} 

ShamanApplet::~ShamanApplet()
{
}

void ShamanApplet::init()
{
    m_layout = new Plasma::HBoxLayout(this);
    updateDB = new Plasma::Icon(KIcon("view-refresh"), tr("Update Database"), this);
    m_layout->addItem(updateDB);
    upgradeSystem = new Plasma::Icon(KIcon("edit-redo.png"), tr("Upgrade System"), this);
    m_layout->addItem(upgradeSystem);
}

#include "shamanApplet.moc"
