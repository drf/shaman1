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

#include "shamanApplet.h"

#include "AbstractView.h"
#include "ErrorView.h"
#include "IdleView.h"
#include "TransactionView.h"

#include <QtDBus/QDBusMessage>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>

#include <KIcon>
#include <KDebug>

#include <plasma/widgets/icon.h>

#define TOP_MARGIN 60
#define MARGIN 10
#define SPACING 4

ShamanApplet::ShamanApplet(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args),
    m_dbus(QDBusConnection::systemBus())
{
    //setDrawStandardBackground(true);//TODO
}

ShamanApplet::~ShamanApplet()
{
}

void ShamanApplet::init()
{
    m_layout = new QGraphicsLinearLayout(this);
    m_layout->setOrientation(Qt::Vertical);
    m_layout->setContentsMargins(MARGIN, TOP_MARGIN, MARGIN, MARGIN);
    m_layout->setSpacing(SPACING);

    m_engine = dataEngine("shaman");
    
    if ( m_engine ) 
    {
        m_engine->connectSource("Shaman", this);
        m_engine->setProperty("refreshTime", 2000);
    }
    else 
        kDebug() << "Shaman Engine could not be loaded";
    
    setLayout(m_layout);
}

void ShamanApplet::dataUpdated(const QString &source, const Plasma::DataEngine::Data &data)
{
    kDebug() << "called";
    
    Q_UNUSED(source)

    if( data["error"].toBool() && !m_error ) 
    {
        m_errorMessage = data["errorMessage"].toString();
        loadView(ShamanApplet::ErrorViewType);
    }
    else if( !data["error"].toBool() ) 
    {
        if( data["onTransaction"].toBool() && data["transactionStatus"].toString() != "idle" )
        {
            kDebug() << "Is on transaction";
            loadView(ShamanApplet::TransactionType);
            
            emit status(data["transactionStatus"].toString());
            emit dlProgress(data["CurrentItemProcessed"].toString(),
                    data["TotalDlPercent"].toInt(),
                    data["TotalDlSpeed"].toInt());
        }
        else
            loadView(ShamanApplet::IdleType);
    }

    m_error = data["error"].toBool();
}

void ShamanApplet::loadView(uint type)
{
    // QSizeF size = geometry().size();

    if ( type != m_viewType ) 
    {
        if ( m_view )
        {
            kDebug() << "Deleting old view";
            delete m_view;
        }

        switch(type)
        {
            case ShamanApplet::ErrorViewType :
                m_view = new ErrorView(this, m_errorMessage);
                break;
            case ShamanApplet::TransactionType :
                m_view = new TransactionView(this, m_dbus);
                break;
            case ShamanApplet::IdleType :
                
            default:
                m_view = new IdleView(this, m_dbus);
                break;
        }

        resize(QSize(m_layout->geometry().width(), m_layout->geometry().height()));
        // updateGeometry();
        m_viewType = type;
    }
//    resize(size);
}

#include "shamanApplet.moc"
