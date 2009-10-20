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

#include "intropage.h"
#include <QLabel>
#include <QVBoxLayout>

IntroPage::IntroPage(QWidget* parent)
        : QWizardPage(parent)
{
    setTitle(tr("Welcome to Shaman"));

    QLabel *lbl = new QLabel("It looks like it is the first time you are starting Shaman. Shaman is an extremely powerful "
                             "package manager, based upon Aqpm, a library implementing and extending Arch Linux's package "
                             "management library, to provide you an integrated, easy and secure package management system. "
                             "A lot of things are new in this version of Shaman, and there are also some things you surely "
                             "need to know.\n\nWanna take a small tour?");
    lbl->setWordWrap(true);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(lbl);
    setLayout(lay);
}

IntroPage::~IntroPage()
{

}
