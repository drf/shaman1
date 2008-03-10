/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *   Copyright (C) 2008 by Lukas Appelhans				   				   *
 *   l.appelhans@gmx.de							   						   *
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

#include "MainWindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
: QGraphicsView(parent)
{
	setupWidget();
	setupScene();
	drawBackgroundToPixmap();
	
	toggleFullscreen();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupScene()
{
	this->scene = new QGraphicsScene(this);
	this->scene->setSceneRect(0, 0, size().width(), size().height());
	setScene(this->scene);
	this->scene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

void MainWindow::setupWidget()
{
	QRect rect(0, 0, 800, 600);
	rect.moveCenter(QApplication::desktop()->screenGeometry(QApplication::desktop()->primaryScreen()).center());
	this->setGeometry(rect);
	this->setMinimumSize(80, 60);
	setWindowTitle(tr("Tribe - ArchLinux Live Installer"));
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFrameStyle(QFrame::NoFrame);
}

void MainWindow::drawBackgroundToPixmap()
{
    const QRectF r = this->scene->sceneRect();
    this->background = QPixmap(qRound(r.width()), qRound(r.height()));
    this->background.fill(Qt::black);
    QPainter painter(&this->background);
    
    QImage bg(":/Images/images/archtest.png");
    painter.drawImage(0, 0, bg);
}

void MainWindow::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    painter->drawPixmap(QPoint(0, 0), this->background);
}

void MainWindow::enableMask(bool enable)
{
    if (!enable)
        this->clearMask();
    else 
    {
        QPolygon region; 
        region.setPoints(9,
                                // north side:
                                0, 0,
                                800, 0,
                                // east side:
                                // 800, 70,
                                // 790, 90,
                                // 790, 480,
                                // 800, 500,
                                800, 600,
                                // south side:
                                700, 600,
                                670, 590,
                                130, 590,
                                100, 600,
                                0, 600,
                                // west side:
                                // 0, 550,
                                // 10, 530,
                                // 10, 520,
                                // 0, 520,
                                0, 0); 
        this->setMask(QRegion(region));
    }
}

void MainWindow::toggleFullscreen()
{        
    if (this->isFullScreen()){
        this->enableMask(true);
        this->showNormal();
    }
    else {
        this->enableMask(false);
        this->showFullScreen();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    this->resetMatrix();
    this->scale(event->size().width() / 800.0, event->size().height() / 600.0);
    QGraphicsView::resizeEvent(event);
    //QGraphicsItem::setMatrix(this->matrix());

    /*if (this->trolltechLogo){
        const QRectF r = this->scene->sceneRect();
        QRectF ttb = this->trolltechLogo->boundingRect();
        this->trolltechLogo->setPos(int((r.width() - ttb.width()) / 2), 595 - ttb.height());
        QRectF qtb = this->qtLogo->boundingRect();
        this->qtLogo->setPos(802 - qtb.width(), 0);
    }*/
}
