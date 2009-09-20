/***************************************************************************
 *   Copyright (C) 2008 by Lukas Appelhans                                 *
 *   l.appelhans@gmx.de                           *
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

#include "ConfigDialog.h"

#include "ABSHandler.h"
#include "ShamanDialog.h"

#include <aqpm/Backend.h>
#include <aqpm/Configuration.h>
#include <aqpm/ConfigurationParser.h>
#include <aqpm/Maintenance.h>

#include "ConfigModuleBase.h"
#include "databases/DatabaseConfig.h"

#include <config.h>

#include <QLineEdit>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QUrl>
#include <QProcess>
#include <QDebug>
#include <QStackedWidget>

#include <ActionButton>
#include <qlayout.h>

using namespace Aqpm;

ConfigDialog::ConfigDialog(QWidget *parent)
        : QDialog(parent)
{
    setupUi(this);
    stackedWidget = new QStackedWidget(this);
    containerLayout->addWidget(stackedWidget);
    connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(changeWidget(int)));
    connect(this, SIGNAL(accepted()), SLOT(saveConfiguration()));
    setModal(true);
    PolkitQt::ActionButton *but = new PolkitQt::ActionButton(okButton, "org.chakraproject.aqpm.saveconfiguration", this);
    connect(but, SIGNAL(clicked(QAbstractButton*)), but, SLOT(activate()));
    connect(but, SIGNAL(activated()), this, SLOT(accept()));
    but->setText(QObject::tr("O&k"));
    but->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
    PolkitQt::ActionButton *abut = new PolkitQt::ActionButton(applyButton, "org.chakraproject.aqpm.saveconfiguration", this);
    connect(abut, SIGNAL(clicked(QAbstractButton*)), but, SLOT(activate()));
    connect(abut, SIGNAL(activated()), this, SLOT(saveConfiguration()));
    abut->setText(QObject::tr("&Apply"));
    abut->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
    cancelButton->setText(QObject::tr("C&ancel"));

    listWidget->addItem(new QListWidgetItem(QIcon(":/Icons/icons/network-server-database.png"), tr("Repositories")));
    stackedWidget->addWidget(new DatabaseConfig(this, QVariantList()));
}

ConfigDialog::~ConfigDialog()
{
}

void ConfigDialog::changeWidget(int position)
{
    stackedWidget->setCurrentIndex(position);
}

void ConfigDialog::saveConfiguration()
{
    ConfigModuleBase *cmb = dynamic_cast<ConfigModuleBase*>(stackedWidget->currentWidget());
    cmb->save();
}