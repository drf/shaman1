/***************************************************************************
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                                                    *
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

#ifndef SHAMANAPPLET_H
#define SHAMANAPPLET_H

#include <plasma/applet.h>
#include <plasma/dataengine.h>
#include <QtDBus/QDBusConnection>
#include <QPointer>

namespace Plasma {
    class Svg;
}

class QLineEdit;
class KMenu;
class QProgressBar;
class QLabel;
class QGraphicsLinearLayout;
class AbstractView;

class ShamanApplet : public Plasma::Applet
{
    Q_OBJECT
    
    public:
        enum ViewType {
                ErrorViewType = 1,
                IdleType = 2,
                TransactionType = 3
            };
        
        ShamanApplet(QObject *parent, const QVariantList &args);
        ~ShamanApplet();
        
        void init();
        
        QSizeF contentSizeHint() const;
        void constraintsEvent(Plasma::Constraints constraints);

    public slots:
        void dataUpdated(const QString &name, const Plasma::DataEngine::Data &data);

    private:
        void loadView(uint type);
            
    signals:
        void status(const QString &status);
        void dlProgress(const QString &filename, int totalPercent, int totalSpeed);
        void transProgress(int percent);
    
    private:
        //Plasma::Svg *m_theme;
        Plasma::DataEngine *m_engine;
        QGraphicsLinearLayout *m_layout;
        QGraphicsWidget *m_form;
        QDBusConnection m_dbus;
        QPointer<AbstractView> m_view;
        QString m_errorMessage;
        bool m_error;
        uint m_viewType;
}; 

K_EXPORT_PLASMA_APPLET(shaman, ShamanApplet)

#endif
