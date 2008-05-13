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

#include "TransactionView.h"

#include <QtDBus/QDBusMessage>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>

#include <QLabel>
#include <QProgressBar>

TransactionView::TransactionView(Plasma::Applet *parent, QDBusConnection dbs)
: AbstractView(parent),
    m_dbus(dbs)
{
    m_layout = static_cast <QGraphicsLinearLayout *> (parent->layout());

    if ( m_layout )
    {
        m_statusLabel = new QGraphicsProxyWidget(parent);
        m_statusLabelWidget = new QLabel(0);
        m_statusLabelWidget->setStyleSheet("background-color: transparent; color: white");
        m_statusLabelWidget->setAlignment(Qt::AlignCenter);
        m_statusLabelWidget->setText("Please Wait...");
        m_statusLabel->setWidget(m_statusLabelWidget);
        m_layout->addItem(m_statusLabel);

        m_progressBar = new QGraphicsProxyWidget(parent);
        m_progressBarWidget = new QProgressBar(0);
        m_progressBarWidget->setStyleSheet("background-color: transparent");
        m_progressBarWidget->setValue(0);
        m_progressBar->setWidget(m_progressBarWidget);
        m_layout->addItem(m_progressBar);
    }
    
    connect(parent, SIGNAL(dlProgress(const QString&,int,int)), SLOT(dlProgress(const QString&,int,int)));
    connect(parent, SIGNAL(status(const QString&)), SLOT(status(const QString&)));
    connect(parent, SIGNAL(transProgress(int)), SLOT(transProgress(int)));
}

TransactionView::~TransactionView()
{
    m_layout->removeItem(m_statusLabel);
    m_layout->removeItem(m_progressBar);
    
    m_statusLabel->setWidget(0);
    m_progressBar->setWidget(0);
    
    delete m_statusLabel;
    delete m_progressBar;
}

void TransactionView::dlProgress(const QString &filename, int totalPercent, int totalSpeed)
{
    Q_UNUSED(totalSpeed);
    
    m_progressBarWidget->setValue(totalPercent);
    m_statusLabelWidget->setText("Downloading " + filename);
}

void TransactionView::transProgress(int percent)
{
    m_progressBarWidget->setValue(percent);
    m_statusLabelWidget->setText("Committing Transaction...");
}

void TransactionView::status(const QString &status)
{
    Q_UNUSED(status);
}

#include "TransactionView.moc"
