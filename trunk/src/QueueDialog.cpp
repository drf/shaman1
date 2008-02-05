#include <iostream>
#include "../ui_transactionDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

#include "QueueDialog.h"

extern CallBacks CbackReference;

using namespace std;

QueueDialog::QueueDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
  aHandle(hnd)
{
	setupUi(this);
	setWindowModality(Qt::ApplicationModal);
	
	qRegisterMetaType<pmtransevt_t>("pmtransevt_t");
	
	connect(&CbackReference, SIGNAL(streamTransEvent(pmtransevt_t, void*, void*)),
			SLOT(changeStatus(pmtransevt_t, void*, void*)));
	
	checkTransaction->setText(tr("<b>Check transaction validity</b>"));
	
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
	aHandle->performCurrentTransaction();
}

void QueueDialog::changeStatus(pmtransevt_t event, void *data1, void *data2)
{
		
	switch(event) {
		case PM_TRANS_EVT_CHECKDEPS_START:
		  actionDetail->setText(QString(tr("Validating Dependencies...")));
			break;
		case PM_TRANS_EVT_FILECONFLICTS_START:
			actionDetail->setText(QString(tr("Checking for Conflicts...")));
			break;
		case PM_TRANS_EVT_RESOLVEDEPS_START:
			actionDetail->setText(QString(tr("Resolving Dependencies...")));
			break;
		case PM_TRANS_EVT_INTERCONFLICTS_START:
			actionDetail->setText(QString(tr("Looking for Inter-Conflicts...")));
			break;
		case PM_TRANS_EVT_ADD_START:
			if(status == 1)
			{
				status = 2;
				startProcess();
			}
			actionDetail->setText(QString(tr("Installing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
			break;
		case PM_TRANS_EVT_ADD_DONE:
			actionDetail->setText(QString(tr("installed %1 (%2)")).arg(
					alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
			//alpm_logaction(str);
			break;
		case PM_TRANS_EVT_REMOVE_START:
			if(status == 1)
			{
				status = 2;
				startProcess();
			}
			actionDetail->setText(QString(tr("Removing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
			break;
		case PM_TRANS_EVT_REMOVE_DONE:
			actionDetail->setText(QString(tr("Removed %1 (%2)")).
					arg(alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
			//alpm_logaction(str);
			break;
		case PM_TRANS_EVT_UPGRADE_START:
			if(status == 1)
			{
				status = 2;
				startProcess();
			}
			actionDetail->setText(QString(tr("Upgrading %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
			break;
		case PM_TRANS_EVT_UPGRADE_DONE:
			actionDetail->setText(QString(tr("Upgraded %s (%s -> %s)")).arg(
			         (char *)alpm_pkg_get_name((pmpkg_t *)data1)).arg((char *)alpm_pkg_get_version((pmpkg_t *)data2)).
			         arg((char *)alpm_pkg_get_version((pmpkg_t *)data1)));
			//alpm_logaction(str);
			break;
		case PM_TRANS_EVT_INTEGRITY_START:
			if(status == 1)
			{
				status = 2;
				startProcess();
			}
			actionDetail->setText(QString(tr("Checking package integrity...")));
			break;
		case PM_TRANS_EVT_DELTA_INTEGRITY_START:
			actionDetail->setText(QString(tr("Checking delta integrity...")));
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
			break;
		case PM_TRANS_EVT_PRINTURI:
			actionDetail->setText(QString("%s/%s").arg((char*)data1).arg((char*)data2));
			break;
		case PM_TRANS_EVT_RETRIEVE_START:
			actionDetail->setText(QString(tr("Starting downloading packages from %1...")).arg((char*)data1));
			if(status == 0)
			{
				status = 1;
				startDownload();
			}
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
}

void QueueDialog::updateProgressBar(char *c, int bytedone, int bytetotal, int speed,
		int listdone, int listtotal, int speedtotal)
{
	Q_UNUSED(speedtotal);
	progressBar->setFormat(QString("%p% (%1 KB/s)").arg(speed));
	progressBar->setRange(0, listtotal);
	progressBar->setValue(listdone);
	
	double bt = bytetotal/1024;
	double bd = bytedone/1024;
	
	if(bytetotal > 2048)
		actionDetail->setText(QString(tr("Downloading %1... (%2 MB of %3 MB)")).
				arg(c).arg(bd/1024, 0, 'f', 2).arg(bt/1024, 0, 'f', 2));
	else
		actionDetail->setText(QString(tr("Downloading %1... (%2 KB of %3 KB)")).
				arg(c).arg(bd, 0, 'f', 0).arg(bt, 0, 'f', 0));
}

void QueueDialog::startDownload()
{
	checkTransaction->setText(tr("Check transaction validity"));
	downloadPackages->setText(tr("<b>Download Packages</b>"));
	
	connect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 
			SLOT(updateProgressBar(char*,int,int,int,int,int,int)));
}

void QueueDialog::startProcess()
{
	downloadPackages->setText(tr("Download Packages"));
	processingQueue->setText(tr("<b>Process queue</b>"));
	
	disconnect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,int,int,int,int)), 0, 0);
}

void QueueDialog::cleanup()
{
	processingQueue->setText(tr("Process queue"));
	cleaningUp->setText(tr("<b>Cleanup</b>"));
	
	emit terminated(false);
}
