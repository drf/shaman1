/***************************************************************************
 *   Copyright (C) 2009 by Dario Freddi                                    *
 *   drf@chakra-project.org                                                *
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

#ifndef SHAMANGENERALCONFIG_H
#define SHAMANGENERALCONFIG_H

#include <QVariantList>

#include <config-shaman1.h>

namespace Ui {
    class ShamanGeneralConfig;
}

#ifndef KDE4_INTEGRATION
#include "config/ConfigModuleBase.h"
#include <QWidget>

class ShamanGeneralConfig : public QWidget, public ConfigModuleBase
#else
#include <kcmodule.h>

class ShamanGeneralConfig : public KCModule
#endif
{
    Q_OBJECT

public:
    ShamanGeneralConfig(QWidget *parent, const QVariantList &args);

    void load();
    void save();
    void defaults();

private Q_SLOTS:
    void performManteinanceAction();
    void mantProgress(const QString &progress);
    void maintenancePerformed(bool success);

private:
    void init();

private:
    Ui::ShamanGeneralConfig *m_ui;
    int m_currentMaint;
};

#endif // SHAMANGENERALCONFIG_H
