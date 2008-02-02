#include "UpdateDbDialog.h"
#include <AlpmHandler.h>
#include "callbacks.h"

extern CallBacks CbackReference;

UpdateDbDialog::UpdateDbDialog(AlpmHandler *hnd, QDialog *parent)
{	
	setupUi(this);
	
	totalPBar->reset();
	dlProgress->reset();
	actionDone = 0;
	updated = false;
	
	aHandle = hnd;
	
	connect(aHandle, SIGNAL(streamDbUpdatingStatus(char*,int)), this,
				SLOT(updateLabel(char*, int)));
	connect(aHandle, SIGNAL(dbQty(int)), this, SLOT(setPBarRange(int)));
	connect(aHandle, SIGNAL(dbUpdated()), this, SLOT(setUpdated()));
	connect(aHandle, SIGNAL(dbUpdatePerformed()), this, SLOT(updateTotalProg()));
	connect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,float,int,int,float)), 
			this, SLOT(updateDlBar(char*,int,int,float,int,int,float)));
}

UpdateDbDialog::~UpdateDbDialog()
{
	disconnect(aHandle, SIGNAL(streamDbUpdatingStatus(char*,int)), 0, 0);
	disconnect(aHandle, SIGNAL(dbQty(int)), 0, 0);
	disconnect(aHandle, SIGNAL(dbUpdated()), 0, 0);
	disconnect(&CbackReference, SIGNAL(streamTransDlProg(char*,int,int,float,int,int,float)), 0, 0);
}

void UpdateDbDialog::updateLabel(char *repo, int action)
{
	QString toInsert;
	
	switch(action)
	{
	case 0:
		toInsert.append("Checking ");
		break;
	case 1:
		toInsert.append("Downloading ");
		break;
	case 2:
		toInsert.append("Installing ");
		break;
	case 3:
		toInsert.append(repo);
		toInsert.append(" is up to date.");
		dlProgress->setFormat(toInsert);
		break;
	default:
		break;
	}
	
	if(action != 3)
	{
		toInsert.append(repo);
		toInsert.append("...");
	}
	
	displayAction->setText(toInsert);
	
}

void UpdateDbDialog::setPBarRange(int range)
{
	totalPBar->setRange(0, range);
	totalPBar->setValue(0);
}

void UpdateDbDialog::setUpdated()
{
	updated = true;
}

bool UpdateDbDialog::dbHasBeenUpdated()
{
	return updated;
}

void UpdateDbDialog::updateTotalProg()
{
	actionDone++;
	
	totalPBar->setValue(actionDone);
}

void UpdateDbDialog::updateDlBar(char *c, int bytedone, int bytetotal, float speed,
		int i, int j, float k)
{
	QString toInsert;
	
	toInsert.append("%p% at ");
	toInsert.append((int)speed);
	toInsert.append(" KB/s");
	dlProgress->setRange(0, bytetotal);
	dlProgress->setFormat(toInsert);
	dlProgress->setValue(bytedone);
}

void UpdateDbDialog::doAction()
{
	//displayAction->setText("Please Wait...");
	dbth = new UpDbThread(aHandle);
	dbth->start();
	connect(dbth, SIGNAL(finished()), this, SLOT(scopeEnded()));
}

void UpdateDbDialog::scopeEnded()
{
	delete(dbth);
	
	emit killMe();
}

UpDbThread::UpDbThread(AlpmHandler *aH)
{
	aHandle = aH;
}

void UpDbThread::run()
{
	aHandle->updateDatabase();
}
