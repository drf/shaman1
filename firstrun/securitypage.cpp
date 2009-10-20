/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "securitypage.h"
#include <QLabel>
#include <QVBoxLayout>

SecurityPage::SecurityPage(QWidget* parent)
        : QWizardPage(parent)
{
    setTitle(tr("Designed to be secure"));
    setSubTitle(tr("Using modern technologies such as PolicyKit, Shaman delivers a secure user experience"));

    QLabel *lbl = new QLabel(tr("When designing the new Shaman, security was one of the primary concerns, and one "
                                "of the things which needed vast improvements against the previous versions. Aqpm, "
                                "the library underneath Shaman, is designed to be run as a standard user, and uses "
                                "privilege elevation through PolicyKit, granting you both authorization fine tuning "
                                "for package management, and total security over the whole process. With Shaman/Aqpm, "
                                "even package download happens as unprivileged user."));
    lbl->setWordWrap(true);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(lbl);
    setLayout(lay);
}

SecurityPage::~SecurityPage()
{

}

