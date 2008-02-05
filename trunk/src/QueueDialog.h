#ifndef QUEUEDIALOG_H_
#define QUEUEDIALOG_H_

#include <iostream>
#include "../ui_transactionDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

class TrCommitThread : public QThread
{
public:
	TrCommitThread(AlpmHandler *aH);
	void run();
private:
	AlpmHandler *aHandle;
};


class QueueDialog : public QDialog, private Ui::transactionDialog
{
	Q_OBJECT
	
public:
	QueueDialog(AlpmHandler *hnd, QWidget *parent = 0);
	virtual ~QueueDialog();
	void startProcessing();
	
public slots:
	void changeStatus(pmtransevt_t event, void *data1, void *data2);
	void updateProgressBar(char *c, int bytedone, int bytetotal, int speed,
			int listdone, int listtotal, int speedtotal);
	void updateProgressBar(pmtransprog_t event, char *pkgname, int percent,
	        int howmany, int remain);
	void startDownload();
	void startProcess();
	void cleanup();
	
signals:
	void terminated(bool errors);
	
private:
	AlpmHandler *aHandle;
	TrCommitThread *cTh;
	int status;
};

#endif /*QUEUEDIALOG_H_*/
