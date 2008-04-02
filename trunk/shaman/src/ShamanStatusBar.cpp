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
 **************************************************************************/

#include "ShamanStatusBar.h"

#include <QStatusBar>
#include <QTimer>

ShamanStatusBar::ShamanStatusBar(AlpmHandler *aH, QWidget *parent)
 : QStatusBar(parent),
 aHandle(aH)
{
	setUpStatusBar();
}

ShamanStatusBar::~ShamanStatusBar()
{
}

void ShamanStatusBar::setUpStatusBar()
{
	stBarImage = new QLabel();
	stBarText = new QLabel();
	stBarProg = new QProgressBar();
	
	stBarProg->setRange(0,100);
	stBarProg->setFormat("%p%");
	
	addWidget(stBarImage);
	addWidget(stBarText);
	addPermanentWidget(stBarProg);
	
	stBarProg->hide();
	
	updateStatusBar();
}

void ShamanStatusBar::showStBarAction(const QString &text, const QPixmap &pixmap, int timeout)
{
	stBarText->setText(text);
	stBarImage->setPixmap(pixmap);
	
	QTimer::singleShot(timeout * 1000, this, SLOT(clearStBarAction()));
}

void ShamanStatusBar::clearStBarAction()
{
	stBarText->setText(QString());
	stBarImage->setPixmap(QPixmap());
	updateStatusBar();
}

void ShamanStatusBar::updateStatusBar()
{
	QString text = QString(tr("%1 Available Packages, %2 Installed Packages, %3 Upgradeable Packages").
			arg(aHandle->countPackages(Alpm::AllPackages)).arg(aHandle->countPackages(Alpm::InstalledPackages)).
			arg(aHandle->getUpgradeablePackages().count()));
	
	stBarText->setText(text);
}
