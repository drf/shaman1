/***************************************************************************
 *   Copyright (C) 2009 by Dario Freddi                                    *
 *   drf54321@gmail.com                                                    *
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

#include "ErrorHandler.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QIcon>
#include <QDebug>
#include <QVBoxLayout>

ErrorHandler::ErrorHandler(QWidget *parent)
        : QObject(parent)
        , m_parent(parent)
{
}

ErrorHandler::~ErrorHandler()
{
}

void ErrorHandler::spawnErrorDialog(Aqpm::Globals::Errors code, const QVariantMap &args)
{
    qDebug() << "Creating Error Dialog";

    QDialog *dlog = new QDialog(m_parent);
    QLabel *lbl = new QLabel(dlog);
    QTextEdit *txtEd = new QTextEdit(dlog);
    QDialogButtonBox *but = new QDialogButtonBox(dlog);
    QVBoxLayout *lay = new QVBoxLayout();
    QString detailedMessage;
    QString shortMessage;


    if (code == Aqpm::Globals::UnsatisfiedDependencies) {
        shortMessage = tr("There has been an error while preparing the transaction.");
        detailedMessage = tr("Some dependencies can not be satisfied");
        detailedMessage.append("\n\n");

        foreach(QString ent, args["UnsatisfiedDeps"].toMap().keys()) {
            detailedMessage.append(tr("%1: requires %2").arg(ent)
                                   .arg(args["UnsatisfiedDeps"].toMap()[ent].toString()));
            detailedMessage.append('\n');
        }
    } else if (code == Aqpm::Globals::UnsatisfiedDependencies) {
        shortMessage = tr("There has been an error while preparing the transaction.");
        detailedMessage = tr("Some dependencies create a conflict with already installed packages");
        detailedMessage.append("\n\n");

        foreach(QString ent, args["ConflictingDeps"].toMap().keys()) {
            detailedMessage.append(tr("%1: conflicts with %2").arg(ent)
                                   .arg(args["ConflictingDeps"].toMap()[ent].toString()));
            detailedMessage.append('\n');
        }
    } else if (code == Aqpm::Globals::PrepareError) {
        shortMessage = tr("There has been an error while preparing the transaction.");
        detailedMessage = tr("No further details were given. Last error string was:");
        detailedMessage.append("\n\n");
        detailedMessage.append(args["ErrorString"].toString());
    }
    else if (code == Aqpm::Globals::FileConflictTarget) {
        shortMessage = tr("There has been an error while committing the transaction.");
        detailedMessage = tr("Some files in the packages being processed are conflicting");
        detailedMessage.append("\n\n");

        foreach(QString ent, args["ConflictingTargets"].toMap().keys()) {
            detailedMessage.append(tr("%1 exists in both '%2' and '%3'").arg(ent)
                                   .arg(args["ConflictingTargets"].toMap()[ent].toStringList().at(0))
                                   .arg(args["ConflictingTargets"].toMap()[ent].toStringList().at(1)));
            detailedMessage.append('\n');
        }
    } else if (code == Aqpm::Globals::FileConflictFilesystem) {
        shortMessage = tr("There has been an error while committing the transaction.");
        detailedMessage = tr("Some files in the packages being processed conflict with the local filesystem");
        detailedMessage.append("\n\n");

        foreach(QString ent, args["ConflictingFiles"].toMap().keys()) {
            detailedMessage.append(tr("%1: %2 exists in the filesystem").arg(ent)
                                   .arg(args["ConflictingFiles"].toMap()[ent].toString()));
            detailedMessage.append('\n');
        }
    } else if (code == Aqpm::Globals::CorruptedFile) {
        shortMessage = tr("There has been an error while committing the transaction.");
        detailedMessage = tr("Some downloaded packages are corrupted or invalid");
        detailedMessage.append("\n\n");

        foreach(QString ent, args["Filenames"].toStringList()) {
            detailedMessage.append(tr("%1 is invalid or corrupted").arg(ent));
            detailedMessage.append('\n');
        }
    } else if (code == Aqpm::Globals::CommitError) {
        shortMessage = tr("There has been an error while committing the transaction.");
        detailedMessage = tr("No further details were given. Last error string was:");
        detailedMessage.append("\n\n");
        detailedMessage.append(args["ErrorString"].toString());
    } else if (code == Aqpm::Globals::AddTargetError || code == Aqpm::Globals::DuplicateTarget ||
               code == Aqpm::Globals::PackageIgnored || code == Aqpm::Globals::PackageNotFound) {
        shortMessage = tr("There has been an error while adding a target.");

        detailedMessage = tr("This is probably an internal Shaman error. Please report it to help "
                             "the developers solving it");
    } else if (code == Aqpm::Globals::AuthorizationNotGranted) {
        shortMessage = tr("You seem not authorized to perform this operation");

        detailedMessage = tr("It looks like the system policy prevents you from doing this action, or "
                             "you failed or refused to authenticate. Please contact your system administrator "
                             "for further details");
    } else if (code == Aqpm::Globals::WorkerInitializationFailed) {
        shortMessage = tr("There was a problem initialiting Aqpm");

        detailedMessage = tr("Aqpm, the library underneath Shaman, reported that it could not start a "
                             "privileged operation. This is probably due to a bug in Shaman/Aqpm or to a "
                             "misconfiguration of your system");
    } else if (code == Aqpm::Globals::WorkerDisappeared) {
        shortMessage = tr("There was an error during the transaction");

        detailedMessage = tr("It looks like Aqpm's worker crashed or disappeared. "
                             "This is probably an internal Shaman error. Please report it to help "
                             "the developers solving it");
    } else if (code == Aqpm::Globals::TransactionInterruptedByUser) {
        shortMessage = tr("The transaction was interrupted");

        detailedMessage = tr("The transaction was interrupted");
    }

    lbl->setText(shortMessage);
    txtEd->setText(detailedMessage);

    txtEd->setReadOnly(true);

    QPushButton *okb = but->addButton(QDialogButtonBox::Ok);
    okb->setText(QObject::tr("Ok"));
    okb->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));

    lay->addWidget(lbl);
    lay->addWidget(txtEd);
    lay->addWidget(but);

    dlog->setLayout(lay);
    dlog->setWindowTitle(QString(tr("Error occurred")));
    dlog->setWindowModality(Qt::ApplicationModal);

    connect(but, SIGNAL(accepted()), dlog, SLOT(accept()));

    dlog->exec();

    dlog->deleteLater();
}
