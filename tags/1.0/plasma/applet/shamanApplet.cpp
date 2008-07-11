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
#include <QPainter>
#include <QGraphicsSceneDragDropEvent>

#include <KIcon>
#include <KDebug>

#include <plasma/svg.h>
#include <plasma/applet.h>
#include <plasma/theme.h>
#include <plasma/dataengine.h>

#define TOP_MARGIN 0
#define MARGIN 20
#define SPACING 30

ShamanApplet::ShamanApplet(QObject *parent, const QVariantList &args)
  : Plasma::Applet(parent, args),
    m_dbus(QDBusConnection::systemBus())
{
    setHasConfigurationInterface(false);
    setAspectRatioMode(Plasma::IgnoreAspectRatio);
    setBackgroundHints(Applet::DefaultBackground);
    
    //connect(Plasma::Theme::defaultTheme(), SIGNAL(themeChanged()), this, SLOT(themeRefresh()));
}

ShamanApplet::~ShamanApplet()
{
    //m_engine->disconnectSource("Shaman", this);
    
    delete m_view;
}

void ShamanApplet::init()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
    
    m_layout = new QGraphicsLinearLayout();
    m_layout->setSpacing(SPACING);
    m_layout->setOrientation(Qt::Vertical);

    /*m_form = new QGraphicsWidget(this);
    m_form->setContentsMargins(MARGIN, TOP_MARGIN, MARGIN, MARGIN);
    m_form->setLayout(m_layout);*/

    if(formFactor() == Plasma::Vertical || formFactor() == Plasma::Horizontal) {
        m_layout->setContentsMargins(0, 0, 0, 0);
        setBackgroundHints(NoBackground);
    }
    else {
        m_layout->setContentsMargins(MARGIN, TOP_MARGIN, MARGIN, MARGIN);
        setMinimumSize(QSize(300, 300));
    }
    setLayout(m_layout);

    m_engine = dataEngine("shaman");
    
    if ( m_engine ) 
    {
        m_engine->connectSource("Shaman", this);
        m_engine->setProperty("refreshTime", 2000);
    }
    else 
        kDebug() << "Shaman Engine could not be loaded";
    
    setAcceptDrops(true);
}

/*QSizeF ShamanApplet::contentSizeHint() const
{
    return effectiveSizeHint(Qt::PreferredSize, geometry().size());
}

void ShamanApplet::constraintsEvent(Plasma::Constraints constraints)
{
    if (constraints & Plasma::SizeConstraint) {
        if (m_layout) {
            resize(geometry().size());
        }
    }
}*/

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

            if( data["onDownloading"].toBool() )
                emit dlProgress(data["CurrentItemProcessed"].toString(),
                        data["TotalDlPercent"].toInt(),
                        data["TotalDlSpeed"].toInt());
            else
                emit transProgress(data["transactionPercent"].toInt());
        }
        else
            loadView(ShamanApplet::IdleType);
    }

    m_error = data["error"].toBool();
}

void ShamanApplet::loadView(uint type)
{
    if ( type != m_viewType ) 
    {
        if ( m_view )
        {
            kDebug() << "Deleting old view";
            delete m_view;
        }

        kDebug() << "Creating new View";
        
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

        kDebug() << "New View Created";

        m_viewType = type;

        kDebug() << "Updating Geometry...";

        m_layout->updateGeometry();

        kDebug() << "Done.";
    }    
}

void ShamanApplet::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    kDebug() << "Drop happened";
    
    IdleView *idleview = qobject_cast<IdleView *>(m_view);
    
    if ( !idleview )
    {
        event->ignore();
        return;
    }
    
    if ( KUrl::List::canDecode(event->mimeData()) ) 
    {
        const KUrl::List urls = KUrl::List::fromMimeData(event->mimeData());
        if ( urls.count() > 0 )
        {
            event->accept();
            
            foreach ( const KUrl& url, urls )
            {
                idleview->installPackageFromFile(url.path());
            }
        }
    }
}

#include "shamanApplet.moc"
