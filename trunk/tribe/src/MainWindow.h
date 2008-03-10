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

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QWidget>
#include <QPixmap>
#include <QGraphicsView>

class MainWindow : public QGraphicsView
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	
	void enableMask(bool enable);
	void toggleFullscreen();
	
	QGraphicsScene *scene;
	
protected:
	void drawBackground(QPainter *painter, const QRectF &rect);
	void resizeEvent(QResizeEvent *event);
	
private:
	void setupScene();
	void setupWidget();
	void drawBackgroundToPixmap();
	
	QPixmap background;
};

#endif /*MAINWINDOW_H_*/
