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

#include <iostream>
#include "../ui_transactionDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include "AlpmHandler.h"
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QProcess>
#include <alpm.h>
#include <fcntl.h>

/* libarchive */
#include <archive.h>
#include <archive_entry.h>

extern CallBacks CbackReference;
extern QMutex mutex;

using namespace std;

QueueDialog::QueueDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
  aHandle(hnd)
{
	setupUi(this);
	textEdit->hide();
	setWindowModality(Qt::WindowModal);
	
	qRegisterMetaType<pmtransevt_t>("pmtransevt_t");
	
	connect(&CbackReference, SIGNAL(streamTransEvent(pmtransevt_t, void*, void*)),
			SLOT(changeStatus(pmtransevt_t, void*, void*)));
	
	transLabel->setPixmap(QIcon(":/Icons/icons/edit-redo.png").pixmap(22));
	textEdit->append(QString(tr("<br><b> * Validating Transaction</b><br>")));
	
	progressBar->setRange(0, 1);
	progressBar->setValue(0);
	
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
	printf("LockedQ\n");
	
	pmpkg_t *package;

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
		package = (pmpkg_t *)data1;
		runScriptlet(0, package);
		break;
	case PM_TRANS_EVT_ADD_DONE:
		actionDetail->setText(QString(tr("%1 (%2) installed successfully!")).arg(
				alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
		textEdit->append(QString(tr("%1 (%2) installed successfully!")).arg(
				alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
		//alpm_logaction(str);
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
		runScriptlet(2, (pmpkg_t *)data1);
		break;
	case PM_TRANS_EVT_REMOVE_DONE:
		actionDetail->setText(QString(tr("%1 (%2) removed successfully!")).
				arg(alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
		textEdit->append(QString(tr("%1 (%2) removed successfully!")).
				arg(alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
		//alpm_logaction(str);
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
		runScriptlet(1, (pmpkg_t *)data1);
		break;
	case PM_TRANS_EVT_UPGRADE_DONE:
		actionDetail->setText(QString(tr("Upgraded %1 successfully (%2 -> %3)")).arg(
				(char *)alpm_pkg_get_name((pmpkg_t *)data1)).arg((char *)alpm_pkg_get_version((pmpkg_t *)data1)).
				arg((char *)alpm_pkg_get_version((pmpkg_t *)data2)));
		textEdit->append(QString(tr("Upgraded %1 successfully (%2 -> %3)")).arg(
				(char *)alpm_pkg_get_name((pmpkg_t *)data1)).arg((char *)alpm_pkg_get_version((pmpkg_t *)data1)).
				arg((char *)alpm_pkg_get_version((pmpkg_t *)data2)));
		//alpm_logaction(str);
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
	
	printf("UnlockQ\n");
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
	
	progressBar->setFormat("%p%");
	progressBar->setRange(0, remain);
	progressBar->setValue(howmany);
	
	return;
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
	
	emit terminated(false);
}

bool QueueDialog::runScriptlet(int action, pmpkg_t *package)
{
	if(!alpm_pkg_has_scriptlet(package))
	{
		/* Ok then, nothing to do. */
		qDebug() << "No scriptlet for package " << alpm_pkg_get_name(package);
		return true;
	}
	
	if(action == 0)
	{
		qDebug() << "Executing install scriptlet for package " << alpm_pkg_get_name(package);

		/* Ok, libalpm docet here. */
		
		struct stat buf;
		int clean_tmpdir = 0;
		int retval = 0;

		QString tmpdir("/tmp/alpm_XXXXXX");

		if(mkdtemp(tmpdir.toAscii().data()) == NULL) 
			return false;
		else 
			clean_tmpdir = 1;

		QString scriptfn(tmpdir);
		scriptfn.append("/.INSTALL");
		
		QString pkgpath("/var/cache/pacman/pkg/");
		pkgpath.append(alpm_pkg_get_name(package));
		pkgpath.append("-");
		pkgpath.append(alpm_pkg_get_version(package));
		pkgpath.append("-i686.pkg.tar.gz");
		
		qDebug() << "Extracting:" << pkgpath;

		if(!unpackPkg(pkgpath, tmpdir, QString(".INSTALL")))
		{
			/* Ok then, nothing to do. */
			qDebug() << "Couldn't extract package! Executing Scriptlet failed.";
			return false;
		}
		
		qDebug() << "Ok, running the scriptlet...";
		
		QString cmdline(QString(". %1; %2 %3").arg(scriptfn).arg("pre_install").arg(alpm_pkg_get_version(package)));
		
		proc = new QProcess(this);
		connect(proc, SIGNAL(readyReadStandardOutput()), SLOT(writeLineProgress()));
		connect(proc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(handleScriptletEnding(int,QProcess::ExitStatus)));
		
		proc->setWorkingDirectory(tmpdir);
		
		qDebug() << "Scriptlet commandline is:" << cmdline;
		
		if(proc->execute(cmdline) == 0)
			qDebug() << "Scriptlet Run successfully!!";
		else
			qDebug() << "Scriptlet Error or Scriptlet not found!!";
			
		aHandle->rmrf("/tmp/alpm_XXXXXX");
	}

	else if(action == 1)
	{
		qDebug() << "Executing install scriptlet for package " << alpm_pkg_get_name(package);

		/* Ok, libalpm docet here. */

		struct stat buf;
		int clean_tmpdir = 0;
		int retval = 0;

		QString tmpdir("/tmp/alpm_XXXXXX");

		if(mkdtemp(tmpdir.toAscii().data()) == NULL) 
			return false;
		else 
			clean_tmpdir = 1;

		QString scriptfn(tmpdir);
		scriptfn.append("/.INSTALL");

		QString pkgpath("/var/cache/pacman/pkg/");
		pkgpath.append(alpm_pkg_get_name(package));
		pkgpath.append("-");
		pkgpath.append(alpm_pkg_get_version(package));
		pkgpath.append("-i686.pkg.tar.gz");

		qDebug() << "Extracting:" << pkgpath;

		if(!unpackPkg(pkgpath, tmpdir, QString(".INSTALL")))
		{
			/* Ok then, nothing to do. */
			qDebug() << "Couldn't extract package! Executing Scriptlet failed.";
			return false;
		}

		qDebug() << "Ok, running the scriptlet...";

		QString cmdline(QString(". %1; %2 %3").arg(scriptfn).arg("pre_upgrade").arg(alpm_pkg_get_version(package)));

		proc = new QProcess(this);
		connect(proc, SIGNAL(readyReadStandardOutput()), SLOT(writeLineProgress()));
		connect(proc, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(handleScriptletEnding(int,QProcess::ExitStatus)));

		proc->setWorkingDirectory(tmpdir);

		qDebug() << "Scriptlet commandline is:" << cmdline;

		if(proc->execute(cmdline) == 0)
			qDebug() << "Scriptlet Run successfully!!";
		else
			qDebug() << "Scriptlet Error or Scriptlet not found!!";

		aHandle->rmrf("/tmp/alpm_XXXXXX");
	}
}

bool QueueDialog::unpackPkg(const QString &pathToPkg, const QString &pathToEx, const QString &file)
{
	/* This is a copy-paste from util.c */
	
	int ret = 1;
	mode_t oldmask;
	struct archive *_archive;
	struct archive_entry *entry;
	char expath[4096];
	
	char *ptPkg = (char *)malloc(strlen(pathToPkg.toAscii().data()) * sizeof(char));
	strcpy(ptPkg, pathToPkg.toAscii().data());
	char *ptEx = (char *)malloc(strlen(pathToEx.toAscii().data()) * sizeof(char)); 
	strcpy(ptEx, pathToEx.toAscii().data());
	char *fn = (char *)malloc(strlen(file.toAscii().data()) * sizeof(char));
	strcpy(fn, file.toAscii().data());

	if((_archive = archive_read_new()) == NULL)
	{
		free(ptPkg);
		free(ptEx);
		free(fn);
		return false;
	}

	archive_read_support_compression_all(_archive);
	archive_read_support_format_all(_archive);

	if(archive_read_open_filename(_archive, ptPkg, ARCHIVE_DEFAULT_BYTES_PER_BLOCK) != ARCHIVE_OK)
	{
		free(ptPkg);
		free(ptEx);
		free(fn);
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

		if(fn && strcmp(fn, entryname)) 
		{
			if (archive_read_data_skip(_archive) != ARCHIVE_OK) 
			{
				umask(oldmask);
				archive_read_finish(_archive);
				qDebug() << "Skipping Data Failed";
				free(ptPkg);
				free(ptEx);
				free(fn);
				return false;
			}
			
			continue;
		}
		
		snprintf(expath, PATH_MAX, "%s/%s", ptEx, entryname);
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
			free(ptPkg);
			free(ptEx);
			free(fn);
			return false;
		}

		if(fn)
			break;
	}

	umask(oldmask);
	archive_read_finish(_archive);
	free(ptPkg);
	free(ptEx);
	free(fn);
	return true;
}

void QueueDialog::handleScriptletEnding(int eC, QProcess::ExitStatus estat)
{
	if(eC == 0)
	{
		qDebug() << "Scriptlet Run successfully!!";
		textEdit->append(QString(tr("Scriptlet run successfully!!")));
	}
	else
	{
		qDebug() << "Error running scriptlet!!";
		textEdit->append(QString(tr("Error running scriptlet!!")));
	}
	
	aHandle->rmrf("/tmp/alpm_XXXXXX");
	proc->deleteLater();
}

void QueueDialog::writeLineProgress()
{
	proc->setReadChannel(QProcess::StandardOutput);
	textEdit->append(proc->readLine(1024));
	
	
}
