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

#include "ErrorView.h"

#include "AbstractView.h"

#include <plasma/widgets/icon.h>

#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QProcess>
#include <QPushButton>

#include <KIcon>

ErrorView::ErrorView(Plasma::Applet *parent, const QString &message)
: AbstractView(parent)
{
    m_layout = static_cast <QGraphicsLinearLayout *> (parent->layout());
    if (m_layout)
    {
        m_icon = new Plasma::Icon(KIcon("dialog-warning"), "");

        QLabel *errorLabel = new QLabel();
        errorLabel->setStyleSheet("background-color: transparent; color: white");
        errorLabel->setText(message);
        errorLabel->setAlignment(Qt::AlignCenter);

        QPushButton *launchButton = new QPushButton(KIcon("kget"), "Launch Shaman");
        launchButton->setAutoFillBackground(false);

        m_proxyErrorLabel = new QGraphicsProxyWidget(parent);
        m_proxyErrorLabel->setWidget(errorLabel);

        m_proxyLaunchButton = new QGraphicsProxyWidget(parent);
        m_proxyLaunchButton->setWidget(launchButton);

        m_layout->addItem(m_icon);
        m_layout->addItem(m_proxyErrorLabel);
        m_layout->addItem(m_proxyLaunchButton);

        connect(launchButton, SIGNAL(clicked()), SLOT(launchShaman()));
    }
}

ErrorView::~ErrorView()
{
}

void ErrorView::launchShaman()
{
    QProcess *shamanProcess = new QProcess(this);
    shamanProcess->startDetached("shaman");
}
