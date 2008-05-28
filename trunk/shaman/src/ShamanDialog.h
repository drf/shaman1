/***************************************************************************
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

#ifndef SHAMANDIALOG_H
#define SHAMANDIALOG_H

#include <QWidget>
#include <QString>

namespace ShamanProperties {

	enum DialogType {
		ErrorDialog,
		WarningDialog,
		InformationDialog,
		SuccessDialog,
		OtherDialog
	};

}  // namespace ShamanProperties

class ShamanDialog
{
	
	/* This class handles popup dialogs streamed by Shaman. It takes care of giving
	 * them a consistent look, handle creation and immediate deletion, and its
	 * methods are static to allow a flexible usage.
	 */
	
public:
	ShamanDialog();
	virtual ~ShamanDialog();

	static void popupDialog(const QString &title, const QString &text, QWidget *parent,
			ShamanProperties::DialogType dtype = ShamanProperties::InformationDialog);
	static int popupQuestionDialog(const QString &title, const QString &text, QWidget *parent,
			ShamanProperties::DialogType dtype = ShamanProperties::InformationDialog);
	static void popupDialogDontShow(const QString &title, const QString &text, const QString &keyname,
			QWidget *parent, ShamanProperties::DialogType dtype = ShamanProperties::InformationDialog);
};

#endif /*SHAMANDIALOG_H*/
