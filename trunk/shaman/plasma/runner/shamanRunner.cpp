/*
 *   Copyright (C) 2006 Aaron Seigo <aseigo@kde.org>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License version 2 as
 *   published by the Free Software Foundation
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "shamanRunner.h"

#include <KIcon>
#include <KLocale>

ShamanRunner::ShamanRunner(QObject *parent, const QVariantList &args)
    : Plasma::AbstractRunner(parent, args)
{
    Q_UNUSED(args)
}

ShamanRunner::~ShamanRunner()
{
}

void ShamanRunner::match(Plasma::SearchContext *search)
{
    const QString term = search->searchTerm();
    Plasma::SearchMatch* match = new Plasma::SearchMatch(this);
    match->setType(Plasma::SearchMatch::ExactMatch);
    match->setIcon(KIcon("system-run"));

    if (term.startsWith("install", Qt::CaseInsensitive))
        match->setText(i18n("Install %1", term));
    else if (term.startsWith("remove", Qt::CaseInsensitive)
        match->setText(i18n("Remove %1", term));
    match->setRelevance(1);
    search->addMatch(term, match);
}

void ShamanRunner::exec(const Plasma::SearchContext *search, const Plasma::SearchMatch *action)
{
}

#include "shamanRunner.moc"
