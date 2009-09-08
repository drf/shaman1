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

#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H

#include <QVariantList>

#include <config.h>

namespace Ui {
    class DatabaseConfig;
}

class MirrorWidget;
class ThirdPartyWidget;
class QVBoxLayout;

#ifndef KDE4_INTEGRATION
#include <QWidget>

class DatabaseConfig : public QWidget
#else
#include <kcmodule.h>

class DatabaseConfig : public KCModule
#endif
{
    Q_OBJECT

public:
    DatabaseConfig(QWidget *parent, const QVariantList &args);

    void load();
    void save();
    void defaults();

private:
    void init();

private Q_SLOTS:
    void removeWidget();
    void preferWidget();
    void deferWidget();

    void addArchWidget(const QString &server = QString());
    void addKdemodWidget(const QString &server = QString());
    void addThirdPartyWidget(const QString &name = QString());

    void addMirror();
    void addKdemodMirror();

    void updateDatabaseList();

private:
    Ui::DatabaseConfig *m_ui;
    QList<MirrorWidget*> m_archMirrors;
    QList<MirrorWidget*> m_kdemodMirrors;
    QList<ThirdPartyWidget*> m_thirdParty;
    QVBoxLayout *m_archLay;
    QVBoxLayout *m_kdemodLay;
    QVBoxLayout *m_thirdPartyLay;
};

#endif // DATABASECONFIG_H
