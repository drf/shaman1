#ifndef QUEUEDIALOG_H_
#define QUEUEDIALOG_H_

#include <iostream>
#include "../ui_transactionDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

class QueueDialog : public QDialog, private Ui::transactionDialog
{
	Q_OBJECT
	
public:
	QueueDialog(AlpmHandler *hnd, QWidget *parent = 0);
	virtual ~QueueDialog();
	void startProcessing();
	
signals:
	void terminated(bool errors);
	
private:
	AlpmHandler *aHandle;
};

#endif /*QUEUEDIALOG_H_*/
