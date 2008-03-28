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

#include "QueueDialog.h"

#include "ShamanDialog.h"
#include "callbacks.h"
#include "AlpmHandler.h"
#include "ui_transactionDialog.h"

#include <iostream>
#include <alpm.h>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QProcess>
#include <QFile>
#include <QDir>
#include <QWaitCondition>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QSettings>
#include <fcntl.h>

/* libarchive */
#include <archive.h>
#include <archive_entry.h>

extern CallBacks CbackReference;
extern QMutex mutex;
extern QWaitCondition wCond;

using namespace std;

QueueDialog::QueueDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
  aHandle(hnd),
  scrRun(false),
  errors(false)
{
	setupUi(this);
	textEdit->hide();
	setWindowModality(Qt::WindowModal);
	
	qRegisterMetaType<pmtransevt_t>("pmtransevt_t");
	
	connect(&CbackReference, SIGNAL(streamTransEvent(pmtransevt_t, void*, void*)),
			SLOT(changeStatus(pmtransevt_t, void*, void*)));
	connect(&CbackReference, SIGNAL(logMsgStreamed(const QString&)), 
			SLOT(handleAlpmMessage(const QString&)));
	connect(aHandle, SIGNAL(preparingTransactionError(const QString&)), 
			SLOT(handlePreparingError(const QString&)));
	connect(aHandle, SIGNAL(committingTransactionError(const QString&)), 
				SLOT(handleCommittingError(const QString&)));
	connect(abortTr, SIGNAL(clicked()), SLOT(abortTransaction()));
	
	qDebug() << "Queue signals connected";
	
	transLabel->setPixmap(QIcon(":/Icons/icons/edit-redo.png").pixmap(22));
	textEdit->append(QString(tr("<br><b> * Validating Transaction</b><br>")));
	
	progressBar->setRange(0, 1);
	progressBar->setValue(0);
	adjustSize();
	status = 0;
}

QueueDialog::~QueueDialog()
{
}

TrCommitThread::TrCommitThread(AlpmHandler *aH)
{
	aHandle = aH;
}

void QueueDialog::startProcessing()
{	
	cTh = new TrCommitThread(aHandle);
	
	cTh->start();
	
	connect(cTh, SIGNAL(finished()), SLOT(cleanup()));
}

void TrCommitThread::run()
{
	aHandle->processQueue();
}

void QueueDialog::changeStatus(pmtransevt_t event, void *data1, void *data2)
{
	QMutexLocker lock(&mutex);
	
	qDebug() << "Entering Queue Lock";
	
	QString upgTxt;
	QString addTxt;
	QString remTxt;

	switch(event) 
	{
	case PM_TRANS_EVT_CHECKDEPS_START:
		actionDetail->setText(QString(tr("Validating Dependencies...")));
		textEdit->append(QString(tr("Validating Dependencies...")));
		break;
	case PM_TRANS_EVT_FILECONFLICTS_START:
		actionDetail->setText(QString(tr("Checking for Conflicts...")));
		textEdit->append(QString(tr("Checking for Conflicts...")));
		break;
	case PM_TRANS_EVT_RESOLVEDEPS_START:
		actionDetail->setText(QString(tr("Resolving Dependencies...")));
		textEdit->append(QString(tr("Resolving Dependencies...")));
		break;
	case PM_TRANS_EVT_INTERCONFLICTS_START:
		actionDetail->setText(QString(tr("Looking for Inter-Conflicts...")));
		textEdit->append(QString(tr("Looking for Inter-Conflicts...")));
		break;
	case PM_TRANS_EVT_ADD_START:
		if(status != 2)
		{
			status = 2;
			textEdit->append(QString(tr("<br><b> * Package Installation Started</b><br>")));
			startProcess();
		}
		actionDetail->setText(QString(tr("Installing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
		textEdit->append(QString(tr("Installing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));

		if(!alpm_pkg_has_scriptlet((pmpkg_t *)data1))
			qDebug() << "No scriptlet for package " << alpm_pkg_get_name((pmpkg_t *)data1);
		else
		{
			QString p1Name(alpm_pkg_get_name((pmpkg_t *)data1));
			QString p1Ver(alpm_pkg_get_version((pmpkg_t *)data1));
			QString pArch(alpm_pkg_get_arch((pmpkg_t *)data1));
			
			

			runScriptlet(0, p1Name, p1Ver, pArch, "");
		}
		break;
	case PM_TRANS_EVT_ADD_DONE:
		if(!alpm_pkg_has_scriptlet((pmpkg_t *)data1))
			qDebug() << "No scriptlet for package " << alpm_pkg_get_name((pmpkg_t *)data1);
		else
		{
			QString p1Name(alpm_pkg_get_name((pmpkg_t *)data1));
			QString p1Ver(alpm_pkg_get_version((pmpkg_t *)data1));
			QString pArch(alpm_pkg_get_arch((pmpkg_t *)data1));
			
			

			runScriptlet(3, p1Name, p1Ver, pArch, "");
		}

		addTxt = QString(tr("%1 (%2) installed successfully!")).arg(
				alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1));
		actionDetail->setText(addTxt);
		textEdit->append(addTxt);
		addTxt.append(QChar('\n'));
		alpm_logaction(addTxt.toAscii().data());

		break;
	case PM_TRANS_EVT_REMOVE_START:
		if(status != 2)
		{
			status = 2;
			textEdit->append(QString(tr("<br><b> * Package Removal Started</b><br>")));
			startProcess();
		}
		actionDetail->setText(QString(tr("Removing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
		textEdit->append(QString(tr("Removing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));

		if(!alpm_pkg_has_scriptlet((pmpkg_t *)data1))
			qDebug() << "No scriptlet for package " << alpm_pkg_get_name((pmpkg_t *)data1);
		else
		{
			QString p1Name(alpm_pkg_get_name((pmpkg_t *)data1));
			QString p1Ver(alpm_pkg_get_version((pmpkg_t *)data1));
			QString pArch(alpm_pkg_get_arch((pmpkg_t *)data1));
			
			

			runScriptlet(2, p1Name, p1Ver, pArch, "");
		}
		break;
	case PM_TRANS_EVT_REMOVE_DONE:
		if(!alpm_pkg_has_scriptlet((pmpkg_t *)data1))
			qDebug() << "No scriptlet for package " << alpm_pkg_get_name((pmpkg_t *)data1);
		else
		{
			QString p1Name(alpm_pkg_get_name((pmpkg_t *)data1));
			QString p1Ver(alpm_pkg_get_version((pmpkg_t *)data1));
			QString pArch(alpm_pkg_get_arch((pmpkg_t *)data1));
			
			

			runScriptlet(5, p1Name, p1Ver, pArch, "");
		}

		remTxt = QString(tr("%1 (%2) removed successfully!")).
				arg(alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1));
		
		actionDetail->setText(remTxt);
		textEdit->append(remTxt);
		remTxt.append(QChar('\n'));
		alpm_logaction(remTxt.toAscii().data());
		break;
	case PM_TRANS_EVT_UPGRADE_START:
		if(status != 2)
		{
			status = 2;
			textEdit->append(QString(tr("<br><b> * Package Upgrading Started</b><br>")));
			startProcess();
		}
		actionDetail->setText(QString(tr("Upgrading %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
		textEdit->append(QString(tr("Upgrading %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));

		if(!alpm_pkg_has_scriptlet((pmpkg_t *)data1))
			qDebug() << "No scriptlet for package " << alpm_pkg_get_name((pmpkg_t *)data1);
		else
		{

			QString p1Name(alpm_pkg_get_name((pmpkg_t *)data1));
			QString p1Ver(alpm_pkg_get_version((pmpkg_t *)data1));
			QString pArch(alpm_pkg_get_arch((pmpkg_t *)data1));
			
			

			runScriptlet(1, p1Name, p1Ver, pArch, "");
		}
		break;
	case PM_TRANS_EVT_UPGRADE_DONE:
		if(!alpm_pkg_has_scriptlet((pmpkg_t *)data1))
			qDebug() << "No scriptlet for package " << alpm_pkg_get_name((pmpkg_t *)data1);
		else
		{

			QString p1Name(alpm_pkg_get_name((pmpkg_t *)data1));
			QString p1Ver(alpm_pkg_get_version((pmpkg_t *)data1));
			QString pArch(alpm_pkg_get_arch((pmpkg_t *)data1));
			QString p2Ver(alpm_pkg_get_version((pmpkg_t *)data2));

			runScriptlet(4, p1Name, p1Ver, pArch, p2Ver);
		}
		
		upgTxt = QString(tr("Upgraded %1 successfully (%2 -> %3)")).arg(
				(char *)alpm_pkg_get_name((pmpkg_t *)data1)).arg((char *)alpm_pkg_get_version((pmpkg_t *)data2)).
				arg((char *)alpm_pkg_get_version((pmpkg_t *)data1));
		
		actionDetail->setText(upgTxt);
		textEdit->append(upgTxt);
		upgTxt.append(QChar('\n'));
		alpm_logaction(upgTxt.toAscii().data());

		break;
	case PM_TRANS_EVT_INTEGRITY_START:
		if(status != 2)
		{
			status = 2;
			textEdit->append(QString(tr("<br><b> * Queue Processing Started</b><br>")));
			startProcess();
		}
		actionDetail->setText(QString(tr("Checking package integrity...")));
		textEdit->append(QString(tr("Checking package integrity...")));
		break;
	case PM_TRANS_EVT_DELTA_INTEGRITY_START:
		actionDetail->setText(QString(tr("Checking delta integrity...")));
		textEdit->append(QString(tr("Checking delta integrity...")));
		break;
	case PM_TRANS_EVT_DELTA_PATCHES_START:
		actionDetail->setText(QString(tr("Applying deltas...")));
		break;
	case PM_TRANS_EVT_DELTA_PATCH_START:
		actionDetail->setText(QString(tr("Generating %1 with %2... ")).arg((char *)data1).
				arg((char *)data2));
		break;
	case PM_TRANS_EVT_DELTA_PATCH_DONE:
		actionDetail->setText(QString(tr("Success!")));
		break;
	case PM_TRANS_EVT_DELTA_PATCH_FAILED:
		actionDetail->setText(QString(tr("Failed!")));
		break;
	case PM_TRANS_EVT_SCRIPTLET_INFO:
		actionDetail->setText(QString("%s").arg((char*)data1));
		textEdit->append(QString("%s").arg((char*)data1));
		break;
	case PM_TRANS_EVT_PRINTURI:
		actionDetail->setText(QString("%s/%s").arg((char*)data1).arg((char*)data2));
		textEdit->append(QString("%s/%s").arg((char*)data1).arg((char*)data2));
		break;
	case PM_TRANS_EVT_RETRIEVE_START:
		if(status != 1)
		{
			status = 1;
			textEdit->append(QString(tr("<br><b> * Package Downloading Started</b><br>")));
			startDownload();
		}
		actionDetail->setText(QString(tr("Starting downloading packages from %1...")).arg((char*)data1));
		textEdit->append(QString(tr("Starting downloading packages from %1...")).arg((char*)data1));
		break;
		/* all the simple done events, with fallthrough for each */
	case PM_TRANS_EVT_FILECONFLICTS_DONE:
	case PM_TRANS_EVT_EXTRACT_DONE:
	case PM_TRANS_EVT_CHECKDEPS_DONE:
	case PM_TRANS_EVT_RESOLVEDEPS_DONE:
	case PM_TRANS_EVT_INTERCONFLICTS_DONE:
	case PM_TRANS_EVT_INTEGRITY_DONE:
	case PM_TRANS_EVT_DELTA_INTEGRITY_DONE:
	case PM_TRANS_EVT_DELTA_PATCHES_DONE:
		break;
	}
	
	if(!isScriptletRunning())
	{
		wCond.wakeAll();
		qDebug() << "Releasing Queue Lock";
	}
	else
		qDebug() << "Waiting for the scriptlet";
}

void QueueDialog::updateProgressBar(char *c, int bytedone, int bytetotal, int speed,
		int listdone, int listtotal, int speedtotal)
{
	Q_UNUSED(speedtotal);

	double bt = bytetotal/1024;
	double bd = bytedone/1024;

	unsigned int eta_h = 0, eta_m = 0, eta_s = 0;

	eta_s = (listtotal - listdone) / (speedtotal * 1024.0);
	eta_h = eta_s / 3600;
	eta_s -= eta_h * 3600;
	eta_m = eta_s / 60;
	eta_s -= eta_m * 60;

	progressBar->setFormat(QString(tr("%p% (%1 KB/s, %4:%5:%6 remaining)", "You just have to "
			"translate 'remaining' here. Leave everything else as it is.")).
			arg(speed).arg((int)eta_h,2,10,QChar('0')).arg((int)eta_m,2,10,QChar('0')).
			arg((int)eta_s,2,10,QChar('0')));
	progressBar->setRange(0, listtotal);
	progressBar->setValue(listdone);


	if(bytetotal > 2048000)
		actionDetail->setText(QString(tr("Downloading %1... (%2 MB of %3 MB)")).
				arg(c).arg(bd/1024, 0, 'f', 2).arg(bt/1024, 0, 'f', 2));
	else
		actionDetail->setText(QString(tr("Downloading %1... (%2 KB of %3 KB)")).
				arg(c).arg(bd, 0, 'f', 0).arg(bt, 0, 'f', 0));
}

void QueueDialog::updateProgressBar(pmtransprog_t event, char *pkgname, int percent,
        int howmany, int remain)
{
	Q_UNUSED(pkgname);
	Q_UNUSED(event);
	Q_UNUSED(percent);
	 
	if(progressBar->value() != remain)
	{
		progressBar->setFormat("%p%");
		progressBar->setRange(0,100);
		if(progressBar->value() != (int)(((float)remain / (float)howmany) * (float)100))
			progressBar->setValue((int)(((float)remain / (float)howmany) * (float)100));		
	}
}

void QueueDialog::startDownload()
{
	transLabel->setPixmap(QIcon(":/Icons/icons/dialog-ok-apply.png").pixmap(22));
	dlLabel->setPixmap(QIcon(":/Icons/icons/edit-redo.png").pixmap(22));

	connect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 
			SLOT(updateProgressBar(char*,int,int,int,int,int,int)));

	if(progressBar->isHidden())
		progressBar->show();
}

void QueueDialog::startProcess()
{
	transLabel->setPixmap(QIcon(":/Icons/icons/dialog-ok-apply.png").pixmap(22));
	dlLabel->setPixmap(QIcon(":/Icons/icons/dialog-ok-apply.png").pixmap(22));
	processLabel->setPixmap(QIcon(":/Icons/icons/edit-redo.png").pixmap(22));
	
	disconnect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 0, 0);
	qRegisterMetaType<pmtransprog_t>("pmtransprog_t");
	connect(&CbackReference, SIGNAL(streamTransProgress(pmtransprog_t,char*,int,int,int)),
			SLOT(updateProgressBar(pmtransprog_t,char*,int,int,int)));
}

void QueueDialog::cleanup()
{
	QMutexLocker lock(&mutex);
	disconnect(&CbackReference, SIGNAL(streamTransProgress(pmtransprog_t,char*,int,int,int)), 0, 0);
	processLabel->setPixmap(QIcon(":/Icons/icons/dialog-ok-apply.png").pixmap(22));
	cleanUpLabel->setPixmap(QIcon(":/Icons/icons/edit-redo.png").pixmap(22));
	
	actionDetail->setText(QString(tr("Queue processed, please wait...")));
	
	qApp->processEvents();
	
	emit terminated(errors);
	
	if(errors)
	{
		actionDetail->setText(QString(tr("Queue processing failed!")));
		textEdit->append(QString("<br><b> * " + tr("Queue processing failed!") + "</b>"));
	}
	else
	{
		actionDetail->setText(QString(tr("Queue processed successfully!")));
		textEdit->append(QString("<br><b> * " + tr("Queue processed successfully!") + "</b>"));
	}
	
	QSettings *settings = new QSettings();
	
	if(settings->value("gui/keepqueuedialogopen", true).toBool())
	{
		disconnect(abortTr, SIGNAL(clicked()), 0, 0);
		abortTr->setText(tr("Close"));
		abortTr->setIcon(QIcon(":/Icons/icons/application-exit.png"));
		connect(abortTr, SIGNAL(clicked()), SLOT(deleteLater()));
	}
	
	settings->deleteLater();
}

bool QueueDialog::runScriptlet(int action, const QString &p1N, const QString &p1V, 
		const QString &pA, const QString &p2V)
{
	QString realAct;
	
	switch(action)
	{
	case 0:
		realAct = "pre_install";
		break;
	case 1:
		realAct = "pre_upgrade";
		break;
	case 2:
		realAct = "pre_remove";
		break;
	case 3:
		realAct = "post_install";
		break;
	case 4:
		realAct = "post_upgrade";
		break;
	case 5:
		realAct = "post_remove";
		break;
	default:
		qDebug() << "Action invalid!!! What the hell??";
		textEdit->append(QString(tr("Unexpected Error. Shaman might be corrupted.")));
		actionDetail->setText(QString(tr("Unexpected Error. Shaman might be corrupted.")));
		return false;
		break;
	}

	qDebug() << "Executing" << realAct << "scriptlet for package " << p1N;
	textEdit->append(QString(tr("Executing %1 scriptlet for %2...")).arg(realAct).arg(p1N));
	actionDetail->setText(QString(tr("Executing %1 scriptlet for %2...")).arg(realAct).arg(p1N));

	/* Ok, libalpm docet here. */

	int clean_tmpdir = 0;

	QString tmpdir("/tmp/alpm_XXXXXX");

	if(mkdtemp(tmpdir.toAscii().data()) == NULL) 
	{
		return false;
	}
	else 
		clean_tmpdir = 1;

	QString scriptfn(tmpdir);
	scriptfn.append("/.INSTALL");

	QString pkgpath("/var/cache/pacman/pkg/");
	pkgpath.append(p1N);
	pkgpath.append("-");
	pkgpath.append(p1V);
	
	if(pA.compare("i686") && pA.compare("x86_64"))
	{
		QString strtmp = pkgpath;
		QString strtmp64 = pkgpath;
		strtmp.append("-i686.pkg.tar.gz");
		strtmp64.append("-x86_64.pkg.tar.gz");
		if(QFile::exists(strtmp))
			pkgpath.append("-i686");
		else if(QFile::exists(strtmp64))
			pkgpath.append("-x86_64");
	}
	else
	{
		QString strtmp = pkgpath;
		strtmp.append("-");
		strtmp.append(pA);
		strtmp.append(".pkg.tar.gz");

		if(QFile::exists(strtmp))
		{
			pkgpath.append("-");
			pkgpath.append(pA);
		}
	}

	pkgpath.append(".pkg.tar.gz");

	qDebug() << "Extracting:" << pkgpath;

	if(!unpackPkg(pkgpath, tmpdir, QString(".INSTALL")))
	{
		/* Ok then, nothing to do. */
		qDebug() << "Couldn't extract package! Executing Scriptlet failed.";
		textEdit->append(QString(tr("Extracting Scriptlet from package failed!!")));
		actionDetail->setText(QString(tr("Extracting Scriptlet from package failed!!")));
		return false;
	}

	qDebug() << "Ok, running the scriptlet...";

	if(!checkScriptlet(scriptfn, realAct))
	{
		qDebug() << p1N << "doesn't have" << realAct << "scriptlet";
		textEdit->append(QString(tr("Package %1 does not have %2 scriptlet")).arg(p1N).arg(realAct));
		actionDetail->setText(QString(tr("Package %1 does not have %2 scriptlet")).arg(p1N).arg(realAct));
		return true;
	}

	QString cmdline;
	
	if(action != 4)
		cmdline = QString(". %1; %2 %3").arg(scriptfn).arg(realAct).arg(p1V);
	else
		cmdline = QString(". %1; %2 %3 %4").arg(scriptfn).arg(realAct).arg(p1V).
				arg(p2V);

	cwd = QDir::currentPath();
	
	chdir("/");
	
	proc = new RootProcess(this);
	connect(proc, SIGNAL(readyReadStandardOutput()), SLOT(writeLineProgress()));
	connect(proc, SIGNAL(readyReadStandardError()), SLOT(writeLineProgressErr()));
	connect(proc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(finishedScriptletRunning(int,QProcess::ExitStatus)));
	
	qApp->processEvents();
	
	proc->setWorkingDirectory("/");

	qDebug() << "Scriptlet commandline is:" << cmdline;
	
	scrRun = true;
		
	proc->start("sh", QStringList() << "-c" << cmdline);

	return true;
}

bool QueueDialog::unpackPkg(const QString &pathToPkg, const QString &pathToEx, const QString &file)
{
	/* This is a copy-paste from util.c */
	
	mode_t oldmask;
	struct archive *_archive;
	struct archive_entry *entry;
	char expath[4096];

	if((_archive = archive_read_new()) == NULL)
	{
		return false;
	}

	archive_read_support_compression_all(_archive);
	archive_read_support_format_all(_archive);

	if(archive_read_open_filename(_archive, pathToPkg.toAscii().data(), ARCHIVE_DEFAULT_BYTES_PER_BLOCK) != ARCHIVE_OK)
	{
		return false;
	}

	oldmask = umask(0022);
	
	while(archive_read_next_header(_archive, &entry) == ARCHIVE_OK) 
	{
		const struct stat *st;
		const char *entryname; /* the name of the file in the archive */

		st = archive_entry_stat(entry);
		entryname = archive_entry_pathname(entry);

		if(S_ISREG(st->st_mode))
			archive_entry_set_mode(entry, 0644);
		else if(S_ISDIR(st->st_mode))
			archive_entry_set_mode(entry, 0755);

		if(file.toAscii().data() && strcmp(file.toAscii().data(), entryname)) 
		{
			if (archive_read_data_skip(_archive) != ARCHIVE_OK) 
			{
				umask(oldmask);
				archive_read_finish(_archive);
				qDebug() << "Skipping Data Failed";
				return false;
			}
			
			continue;
		}
		
		snprintf(expath, PATH_MAX, "%s/%s", pathToEx.toAscii().data(), entryname);
		archive_entry_set_pathname(entry, expath);

		int readret = archive_read_extract(_archive, entry, 0);
		if(readret == ARCHIVE_WARN) 
		{
			/* operation succeeded but a non-critical error was encountered */
			qDebug() << "Warning extracting " << entryname << " (" << archive_error_string(_archive) << ")";
		} 
		else if(readret != ARCHIVE_OK) 
		{
			qDebug() << "Could not extract " << entryname << " (" << archive_error_string(_archive) << ")";
			umask(oldmask);
			archive_read_finish(_archive);
			return false;
		}

		if(file.toAscii().data())
			break;
	}

	umask(oldmask);
	archive_read_finish(_archive);
	return true;
}

void QueueDialog::finishedScriptletRunning(int eC,QProcess::ExitStatus eS)
{
	Q_UNUSED(eS);
	
	if(eC == 0)
	{
		qDebug() << "Scriptlet Run successfully!!";
		textEdit->append(QString(tr("Scriptlet processed successfully!")));
		actionDetail->setText(QString(tr("Scriptlet processed successfully!")));
	}
	else
	{
		qDebug() << "Scriptlet Error!!";
		textEdit->append(QString(tr("Error processing Scriptlet!!")));
		actionDetail->setText(QString(tr("Error processing Scriptlet!!")));
	}

	chdir(cwd.toAscii().data());

	proc->deleteLater();

	aHandle->rmrf("/tmp/alpm_XXXXXX");
	
	scrRun = false;
	
	wCond.wakeAll();
}

void QueueDialog::writeLineProgress()
{
	if(proc->readChannel() != QProcess::StandardOutput)
		proc->setReadChannel(QProcess::StandardOutput);

	while(!proc->atEnd())
	{
		QString view(proc->readLine(1024));
		
		qDebug() << view;

		textEdit->append(view.remove(QChar('\n')));
		
		if(!view.endsWith(QChar('\n')))
			view.append(QChar('\n'));
		
		alpm_logaction(view.toAscii().data());

		textEdit->moveCursor(QTextCursor::End);
	}
}

void QueueDialog::writeLineProgressErr()
{
	if(proc->readChannel() != QProcess::StandardError)
		proc->setReadChannel(QProcess::StandardError);
	
	while(!proc->atEnd())
	{
		QString view(proc->readLine(1024));

		qDebug() << view;

		textEdit->append(view.remove(QChar('\n')));

		if(!view.endsWith(QChar('\n')))
			view.append(QChar('\n'));

		alpm_logaction(view.toAscii().data());

		textEdit->moveCursor(QTextCursor::End);
	}
}

bool QueueDialog::isScriptletRunning()
{
	return scrRun;
}

bool QueueDialog::checkScriptlet(const QString &path, const QString &action)
{
	QFile fp(path);

	if(!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;

	QTextStream in(&fp);

	if(in.readAll().contains(action))
	{
		fp.close();
		return true;
	}
	else
	{
		fp.close();
		return false;
	}
}

void QueueDialog::abortTransaction()
{
	switch (ShamanDialog::popupQuestionDialog(QString(tr("Queue Processing")), 
			QString(tr("Would you like to abort Queue Processing?\nThis may damage your system.")), this,
			ShamanProperties::WarningDialog)) 
	{
	case QMessageBox::Yes:
		errors = true;
		
		qDebug() << "Interrupting transaction...";
		
		aHandle->interruptTransaction();
		
		cTh->terminate();
		
		qDebug() << "Transaction interrupted";
		
		cleanup();
		
		break;
	case QMessageBox::No:
		break;
	default:
		// should never be reached
		break;
	}
}

void QueueDialog::handlePreparingError(const QString &msg)
{
	qDebug() << "Creating Preparing Error";
	
	QDialog *dlog = new QDialog(this);
	QLabel *lbl = new QLabel(dlog);
	QTextEdit *txtEd = new QTextEdit(msg, dlog);
	QPushButton *but = new QPushButton(dlog);
	QHBoxLayout *hlay = new QHBoxLayout();
	QVBoxLayout *lay = new QVBoxLayout();

	lbl->setText(QString(tr("There has been an error"
			" while preparing the transaction.\n") + alpm_strerrorlast()));

	txtEd->setReadOnly(true);

	but->setText(tr("Ok"));
	but->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
	hlay->insertStretch(0);
	hlay->addWidget(but);
	lay->addWidget(lbl);
	lay->addWidget(txtEd);
	lay->addLayout(hlay);
	dlog->setLayout(lay);
	dlog->setWindowTitle(QString(tr("Queue Processing")));
	dlog->setWindowModality(Qt::ApplicationModal);
	connect(but, SIGNAL(clicked()), dlog, SLOT(accept()));

	dlog->exec();

	errors = true;

	qDebug() << "Streaming Awakening to Error Thread";
	wCond.wakeAll();
}

void QueueDialog::handleCommittingError(const QString &msg)
{
	qDebug() << "Creating Committing Error";
	
	QDialog *dlog = new QDialog(this);
	QLabel *lbl = new QLabel(dlog);
	QTextEdit *txtEd = new QTextEdit(msg, dlog);
	QPushButton *but = new QPushButton(dlog);
	QHBoxLayout *hlay = new QHBoxLayout();
	QVBoxLayout *lay = new QVBoxLayout();

	lbl->setText(QString(tr("There has been an error"
			" while committing the transaction.\n") + alpm_strerrorlast()));

	txtEd->setReadOnly(true);

	but->setText(tr("Ok"));
	but->setIcon(QIcon(":/Icons/icons/dialog-ok-apply.png"));
	hlay->insertStretch(0);
	hlay->addWidget(but);
	lay->addWidget(lbl);
	lay->addWidget(txtEd);
	lay->addLayout(hlay);
	dlog->setLayout(lay);
	dlog->setWindowTitle(QString(tr("Queue Processing")));
	dlog->setWindowModality(Qt::ApplicationModal);
	connect(but, SIGNAL(clicked()), dlog, SLOT(accept()));

	dlog->exec();

	errors = true;
	
	qDebug() << "Streaming Awakening to Error Thread";
	wCond.wakeAll();
}

void QueueDialog::handleAlpmMessage(const QString &msg)
{
	textEdit->append(QString());
	QString view(QString("<p><b><i> ==> ") + msg + QString("</b></i></p><br>"));
	
	qDebug() << msg;
	
	view.remove(QChar('\n'));

	textEdit->insertHtml(view);

	textEdit->moveCursor(QTextCursor::End);
}
