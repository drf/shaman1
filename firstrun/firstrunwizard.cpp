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

#include "firstrunwizard.h"
#include "intropage.h"
#include "securitypage.h"

#include <QAbstractButton>

#include <config-shaman1.h>

#ifdef KDE4_INTEGRATION
#include <KIcon>
#endif
#include "configurationpage.h"
#include "kdepage.h"

FirstRunWizard::FirstRunWizard(QWidget* parent, Qt::WindowFlags flags)
        : QWizard(parent, flags)
{
    setWindowTitle(tr("Shaman first run"));

    addPage(new IntroPage);
    addPage(new SecurityPage);
    addPage(new ConfigurationPage);
#ifdef KDE4_INTEGRATION
    addPage(new KDEPage);
#endif

#ifdef KDE4_INTEGRATION
    QAbstractButton *bt = button(CancelButton);
    bt->setIcon(KIcon("dialog-close"));
    setButton(CancelButton, bt);

    bt = button(BackButton);
    bt->setIcon(KIcon("go-previous"));
    setButton(BackButton, bt);

    bt = button(NextButton);
    bt->setIcon(KIcon("go-next"));
    bt->setLayoutDirection(Qt::RightToLeft);
    setButton(NextButton, bt);
#endif

    setButtonText(CancelButton, tr("Skip wizard"));
    setButtonText(NextButton, tr("Next"));
    setButtonText(BackButton, tr("Back"));
}

FirstRunWizard::~FirstRunWizard()
{

}
