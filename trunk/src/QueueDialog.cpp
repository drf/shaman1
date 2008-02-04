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
	
	connect(&CbackReference, SIGNAL(streamTransEvent(pmtransevt_t, void*, void*)),
			SLOT(changeStatus(pmtransevt_t, void*, void*)));
	
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
	
	cTh->run();
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
			actionDetail->setText(QString(tr("Installing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
			break;
		case PM_TRANS_EVT_ADD_DONE:
			actionDetail->setText(QString(tr("installed %1 (%2)")).arg(
					alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
			//alpm_logaction(str);
			break;
		case PM_TRANS_EVT_REMOVE_START:
			actionDetail->setText(QString(tr("Removing %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
			break;
		case PM_TRANS_EVT_REMOVE_DONE:
			actionDetail->setText(QString(tr("Removed %1 (%2)")).
					arg(alpm_pkg_get_name((pmpkg_t *)data1)).arg(alpm_pkg_get_version((pmpkg_t *)data1)));
			//alpm_logaction(str);
			break;
		case PM_TRANS_EVT_UPGRADE_START:
			actionDetail->setText(QString(tr("Upgrading %1...")).arg(alpm_pkg_get_name((pmpkg_t *)data1)));
			break;
		case PM_TRANS_EVT_UPGRADE_DONE:
			actionDetail->setText(QString(tr("Upgraded %s (%s -> %s)")).arg(
			         (char *)alpm_pkg_get_name((pmpkg_t *)data1)).arg((char *)alpm_pkg_get_version((pmpkg_t *)data2)).
			         arg((char *)alpm_pkg_get_version((pmpkg_t *)data1)));
			//alpm_logaction(str);
			break;
		case PM_TRANS_EVT_INTEGRITY_START:
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
			actionDetail->setText(QString(tr("Starting downloading packages from core...")).arg((char*)data1));
			if(status == 0)
				startDownload();
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

void QueueDialog::updateProgressBar()
{
	
}

void QueueDialog::startDownload()
{
	
}

void QueueDialog::startProcess()
{
	
}

void QueueDialog::cleanup()
{
	
}
