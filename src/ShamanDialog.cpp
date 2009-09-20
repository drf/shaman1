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

#include "ShamanDialog.h"

#include <QMessageBox>
#include <QPushButton>
#include <QIcon>
#include <QSettings>
#include <QDialogButtonBox>
#include <QLabel>
#include <QCheckBox>
#include <QBoxLayout>

#include <config-shaman1.h>

#ifdef KDE4_INTEGRATION
#include <kmessagebox.h>
#endif

ShamanDialog::ShamanDialog()
{
}

ShamanDialog::~ShamanDialog()
{
}

void ShamanDialog::popupDialog(const QString &title, const QString &text, QWidget *parent,
                               ShamanProperties::DialogType dtype)
{
    if (parent != NULL) {
        foreach(QObject *ent, parent->children()) {
            QDialog *dlog = qobject_cast<QDialog *>(ent);
            if (dlog)
                dlog->hide();
        }
    }

#ifndef KDE4_INTEGRATION
    QMessageBox *message;

    if (parent == NULL)
        message = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::NoButton);
    else
        message = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::NoButton, parent);

    switch (dtype) {
    case ShamanProperties::InformationDialog:
        message->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
        break;
    case ShamanProperties::SuccessDialog:
        message->setIconPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
        break;
    case ShamanProperties::ErrorDialog:
        message->setIconPixmap(QPixmap(":/Icons/icons/dialog-error.png"));
        break;
    case ShamanProperties::WarningDialog:
        message->setIconPixmap(QPixmap(":/Icons/icons/dialog-warning.png"));
        break;
    case ShamanProperties::OtherDialog:
        message->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
        break;
    default:
        break;
    }

    QPushButton *okb = message->addButton(QMessageBox::Ok);

    okb->setText(QObject::tr("O&k"));
    okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));

    message->exec();

    message->deleteLater();

#else
    switch (dtype) {
    case ShamanProperties::InformationDialog:
    case ShamanProperties::SuccessDialog:
    case ShamanProperties::OtherDialog:
        KMessageBox::information(parent, text, title);
        break;
    case ShamanProperties::ErrorDialog:
        KMessageBox::error(parent, text, title);
        break;
    case ShamanProperties::WarningDialog:
        KMessageBox::sorry(parent, text, title);
        break;
    default:
        break;
    }

#endif

    if (parent != NULL) {
        foreach(QObject *ent, parent->children()) {
            QDialog *dlog = qobject_cast<QDialog *>(ent);
            if (dlog)
                dlog->show();
        }
    }
}

int ShamanDialog::popupQuestionDialog(const QString &title, const QString &text, QWidget *parent,
                                      ShamanProperties::DialogType dtype)
{
    int retval = 0;

    if (parent != NULL) {
        foreach(QObject *ent, parent->children()) {
            QDialog *dlog = qobject_cast<QDialog *>(ent);
            if (dlog)
                dlog->hide();
        }
    }

#ifndef KDE4_INTEGRATION
    QMessageBox *msgBox = new QMessageBox(parent);

    switch (dtype) {
    case ShamanProperties::InformationDialog:
        msgBox->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
        break;
    case ShamanProperties::SuccessDialog:
        msgBox->setIconPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
        break;
    case ShamanProperties::ErrorDialog:
        msgBox->setIconPixmap(QPixmap(":/Icons/icons/dialog-error.png"));
        break;
    case ShamanProperties::WarningDialog:
        msgBox->setIconPixmap(QPixmap(":/Icons/icons/dialog-warning.png"));
        break;
    case ShamanProperties::OtherDialog:
        msgBox->setIconPixmap(QPixmap(":/Icons/icons/help-about.png"));
        break;
    default:
        break;
    }

    msgBox->setWindowTitle(title);

    QPushButton *okb = msgBox->addButton(QMessageBox::Yes);
    QPushButton *nob = msgBox->addButton(QMessageBox::No);

    okb->setText(QObject::tr("&Yes"));
    okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
    nob->setText(QObject::tr("&No"));
    nob->setIcon(QIcon(":/Icons/icons/dialog-cancel.png"));

    msgBox->setDefaultButton(okb);

    msgBox->setWindowModality(Qt::ApplicationModal);

    msgBox->setText(text);

    retval = msgBox->exec();

    if (msgBox->clickedButton() == okb)
        retval = QMessageBox::Yes;
    else
        retval = QMessageBox::No;

    msgBox->deleteLater();
#else
    switch (dtype) {
    case ShamanProperties::InformationDialog:
    case ShamanProperties::SuccessDialog:
    case ShamanProperties::OtherDialog:
        retval = KMessageBox::questionYesNo(parent, text, title);
        break;
    case ShamanProperties::ErrorDialog:
        retval = KMessageBox::warningContinueCancel(parent, text, title);
        break;
    case ShamanProperties::WarningDialog:
        retval = KMessageBox::warningYesNo(parent, text, title);
        break;
    default:
        retval = QMessageBox::No;
        break;
    }

    if (retval == KMessageBox::Yes || retval == KMessageBox::Continue || retval == KMessageBox::Ok) {
        retval = QMessageBox::Yes;
    } else if (retval == KMessageBox::No || retval == KMessageBox::Cancel) {
        retval = QMessageBox::No;
    }
#endif

    if (parent != NULL) {
        foreach(QObject *ent, parent->children()) {
            QDialog *dlog = qobject_cast<QDialog *>(ent);
            if (dlog)
                dlog->show();
        }
    }

    return retval;
}

void ShamanDialog::popupDialogDontShow(const QString &title, const QString &text, const QString &keyname,
                                       QWidget *parent, ShamanProperties::DialogType dtype)
{
#ifndef KDE4_INTEGRATION
    QSettings *settings = new QSettings();

    if (!settings->value(keyname, false).toBool()) {
        if (parent != NULL) {
            foreach(QObject *ent, parent->children()) {
                QDialog *dlog = qobject_cast<QDialog *>(ent);
                if (dlog)
                    dlog->hide();
            }
        }

        QDialog *dlog = new QDialog(parent);
        QLabel *lbl = new QLabel(dlog);
        QLabel *icn = new QLabel(dlog);
        QCheckBox *cbx = new QCheckBox(dlog);
        QDialogButtonBox *but = new QDialogButtonBox(dlog);
        QVBoxLayout *lay = new QVBoxLayout();
        QHBoxLayout *hlay = new QHBoxLayout();

        lbl->setText(text);

        switch (dtype) {
        case ShamanProperties::InformationDialog:
            icn->setPixmap(QPixmap(":/Icons/icons/help-about.png"));
            break;
        case ShamanProperties::SuccessDialog:
            icn->setPixmap(QPixmap(":/Icons/icons/dialog-ok-apply.png"));
            break;
        case ShamanProperties::ErrorDialog:
            icn->setPixmap(QPixmap(":/Icons/icons/dialog-error.png"));
            break;
        case ShamanProperties::WarningDialog:
            icn->setPixmap(QPixmap(":/Icons/icons/dialog-warning.png"));
            break;
        case ShamanProperties::OtherDialog:
            icn->setPixmap(QPixmap(":/Icons/icons/help-about.png"));
            break;
        default:
            break;
        }

        hlay->addWidget(icn);
        hlay->addWidget(lbl);

        cbx->setText(QString(QObject::tr("Do not &show this Again")));
        cbx->setChecked(false);

        QPushButton *okb = but->addButton(QDialogButtonBox::Ok);
        okb->setText(QObject::tr("O&k"));
        okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));

        lay->addLayout(hlay);
        lay->addWidget(cbx);
        lay->addWidget(but);

        dlog->setLayout(lay);
        dlog->setWindowTitle(title);
        dlog->setWindowModality(Qt::ApplicationModal);

        QObject::connect(but, SIGNAL(accepted()), dlog, SLOT(accept()));

        dlog->exec();

        if (cbx->isChecked())
            settings->setValue(keyname, true);

        dlog->deleteLater();

        if (parent != NULL) {
            foreach(QObject *ent, parent->children()) {
                QDialog *dlog = qobject_cast<QDialog *>(ent);
                if (dlog)
                    dlog->show();
            }
        }
    }

    settings->deleteLater();

#else
    switch (dtype) {
    case ShamanProperties::InformationDialog:
    case ShamanProperties::SuccessDialog:
    case ShamanProperties::OtherDialog:
        KMessageBox::information(parent, text, title, keyname);
        break;
    case ShamanProperties::ErrorDialog:
        KMessageBox::error(parent, text, title);
        break;
    case ShamanProperties::WarningDialog:
        KMessageBox::sorry(parent, text, title);
        break;
    default:
        break;
    }

#endif
}
