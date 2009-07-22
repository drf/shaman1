/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                *
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

#include "NewsViewer.h"

#include "ShamanDialog.h"

#include <QUrl>
#include <QDesktopServices>
#include <QDebug>

#include "ArchLinuxNewsReader.h"

NewsViewer::NewsViewer(ArchLinuxNewsReader *nR, QWidget *parent)
        : QDialog(parent),
        newsHandler(nR)
{
    setupUi(this);

    treeWidget->hideColumn(4);
    treeWidget->setHeaderLabels(QStringList() << QString() << QString());

    connect(newsHandler, SIGNAL(fetchingStarted()), SLOT(fetching()));
    connect(newsHandler, SIGNAL(fetchingFinished()), SLOT(fetching()));
    connect(newsHandler, SIGNAL(fetchingFinished()), SLOT(populateView()));
    connect(newsHandler, SIGNAL(fetchingFailed()), SLOT(fetching()));
    connect(newsHandler, SIGNAL(fetchingFailed()), SLOT(fetchingError()));

    label->setHidden(true);
    label->setText(QString(tr("Please wait, fetching items...")));

    asReadButton->setEnabled(false);
    openButton->setEnabled(false);

    connect(asReadButton, SIGNAL(clicked()), SLOT(markAsRead()));
    connect(openButton, SIGNAL(clicked()), SLOT(openInBrowser()));
    connect(treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), SLOT(openInBrowser()));
    connect(refreshButton, SIGNAL(clicked()), SLOT(refreshView()));

    treeWidget->setColumnWidth(0, 30);
    treeWidget->setColumnWidth(1, 30);

    connect(treeWidget, SIGNAL(itemSelectionChanged()), SLOT(itemChanged()));

    populateView();

    connect(closeButton, SIGNAL(clicked()), SLOT(deleteLater()));
    setAttribute(Qt::WA_DeleteOnClose);
}

NewsViewer::~NewsViewer()
{
}

void NewsViewer::populateView()
{
    QList<ArchLinuxNews::ArchNews> entries = newsHandler->getAllEntries();

    QTreeWidgetItem *itm;

    while ((itm = treeWidget->takeTopLevelItem(0)) != NULL)
        delete(itm);

    if (entries.isEmpty())
        return;

    foreach(const ArchLinuxNews::ArchNews &ent, entries) {
        qDebug() << "Adding News item";

        itm = new QTreeWidgetItem(treeWidget);

        if (ent.nRead) {
            itm->setIcon(0, QIcon(":/Icons/icons/mail-mark-read.png"));
            itm->setText(4, "read");
        } else {
            itm->setIcon(0, QIcon(":/Icons/icons/mail-mark-unread-new.png"));
            itm->setText(4, "unread");
        }

        if (ent.nNew)
            itm->setIcon(1, QIcon(":/Icons/icons/mail-message-new.png"));

        itm->setText(2, ent.title);
        itm->setText(3, ent.link);
    }
}

void NewsViewer::itemChanged()
{
    if (treeWidget->selectedItems().isEmpty()) {
        asReadButton->setEnabled(false);
        openButton->setEnabled(false);
        return;
    }

    asReadButton->setEnabled(true);
    openButton->setEnabled(true);

    if (treeWidget->selectedItems().first()->text(4) == "unread")
        asReadButton->setText(QString(tr("Mark as Read")));
    else
        asReadButton->setText(QString(tr("Mark as Unread")));
}

void NewsViewer::markAsRead()
{
    if (treeWidget->selectedItems().isEmpty())
        return;

    if (treeWidget->selectedItems().first()->text(4) == "unread")
        newsHandler->markAsRead(treeWidget->selectedItems().first()->text(2), true);
    else
        newsHandler->markAsRead(treeWidget->selectedItems().first()->text(2), false);

    treeWidget->selectedItems().first()->setIcon(1, QIcon());

    populateView();
}

void NewsViewer::openInBrowser()
{
    if (treeWidget->selectedItems().isEmpty())
        return;

    //markAsRead();

    QTreeWidgetItem *item = treeWidget->selectedItems().first();

    QDesktopServices::openUrl(QUrl(item->text(3)));
}

void NewsViewer::refreshView()
{
    newsHandler->fetch();
}

void NewsViewer::fetching()
{
    qDebug() << "Fetching Status Changed";

    if (label->isHidden()) {
        label->setHidden(false);

        asReadButton->setEnabled(false);
        openButton->setEnabled(false);
        refreshButton->setEnabled(false);
    } else {
        label->setHidden(true);

        asReadButton->setEnabled(true);
        openButton->setEnabled(true);
        refreshButton->setEnabled(true);
    }
}

void NewsViewer::fetchingError()
{
    ShamanDialog::popupDialog(tr("Error"), QString(tr("Could not fetch the RSS feed! Error reported was:")
                              + QChar('\n') + newsHandler->getHttpError()), this, ShamanProperties::ErrorDialog);
}
