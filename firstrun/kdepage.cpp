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

#include "kdepage.h"
#include <QLabel>
#include <QVBoxLayout>

KDEPage::KDEPage(QWidget* parent)
: QWizardPage(parent)
{
    setTitle(tr("Perfectly integrated with your desktop"));
    setSubTitle(tr("We focused our efforts in integrating Shaman in KDE at its best"));

    QLabel *lbl = new QLabel(tr("Even if Shaman is a Qt-only application, we are KDE fans, and you should know "
                                "that. So, we made Shaman look better inside your KDE desktop, by using Plasma notifications, "
                                "KDE icons, and some killer features you will surely like: all package downloads through "
                                "Aqpm will follow your KDE network settings (proxy included), and Shaman/Aqpm configuration "
                                "is available in systemsettings, where you have a \"Package Management\" section."));
    lbl->setWordWrap(true);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(lbl);
    setLayout(lay);
}

KDEPage::~KDEPage()
{
    
}

