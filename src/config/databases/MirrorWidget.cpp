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

#include "MirrorWidget.h"

#include "ui_mirrorWidget.h"

MirrorWidget::MirrorWidget(Aqpm::Configuration::MirrorType type, QWidget *parent)
        : QWidget(parent)
        , m_ui(new Ui::MirrorWidget)
        , m_type(type)
{
    m_ui->setupUi(this);

    reloadMirrors();

    connect(m_ui->deferButton, SIGNAL(clicked()), this, SIGNAL(defer()));
    connect(m_ui->preferButton, SIGNAL(clicked()), this, SIGNAL(prefer()));
    connect(m_ui->removeButton, SIGNAL(clicked()), this, SIGNAL(remove()));
}

void MirrorWidget::reloadMirrors()
{
    m_ui->mirrorBox->clear();

    m_ui->mirrorBox->addItems(Aqpm::Configuration::instance()->getMirrorList(m_type));
}

QString MirrorWidget::mirror() const
{
    return m_ui->mirrorBox->currentText();
}

void MirrorWidget::setMirror(const QString &mirror)
{
    m_ui->mirrorBox->setCurrentIndex(m_ui->mirrorBox->findText(mirror));
}

Aqpm::Configuration::MirrorType MirrorWidget::type() const
{
    return m_type;
}
