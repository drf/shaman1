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

#include "finishpage.h"
#include <QLabel>
#include <QVBoxLayout>

FinishPage::FinishPage(QWidget* parent)
        : QWizardPage(parent)
{
    setTitle(tr("Dive in!"));

    QLabel *lbl = new QLabel(tr("What you've seen are just some of the cool features in Shaman, and there's only "
                                "one way to find your favorite one - trying it!\n\nWe sincerely hope you will enjoy"
                                "using Shaman and Aqpm. To report bugs, share your opinion, getting involved, use "
                                "the contacts below:\n\nhttp://chakra-project.org/bbs\n\nshaman@chakra-project.org"));
    lbl->setWordWrap(true);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(lbl);
    setLayout(lay);
}

FinishPage::~FinishPage()
{

}

