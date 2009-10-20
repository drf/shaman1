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

#include "configurationpage.h"
#include <QLabel>
#include <QVBoxLayout>

ConfigurationPage::ConfigurationPage(QWidget* parent)
        : QWizardPage(parent)
{
    setTitle(tr("Easy and powerful configuration"));
    setSubTitle(tr("Aqpm's new configuration system lets you fine tune every preference for package management"));

    QLabel *lbl = new QLabel(tr("Shaman configuration system was rewritten from scratch, since the old one was "
                                "not perfect and quite unmaintainable. The first main difference is that Shaman, "
                                "just like every other application using Aqpm, is no longer using pacman.conf, but "
                                "aqpm.conf. The syntax is similar to pacman.conf's one, but it's mainly meant to be "
                                "edited using the new configuration UI, that now lets you even order your repository "
                                "to configure their priorities. Of course, you don't have to lose your old habits: "
                                "as you are reading this paragraph, a new aqpm.conf was generated from your pacman.conf, "
                                "if you had one."));
    lbl->setWordWrap(true);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(lbl);
    setLayout(lay);
}

ConfigurationPage::~ConfigurationPage()
{
    
}

