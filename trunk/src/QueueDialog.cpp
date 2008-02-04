#include <iostream>
#include "../ui_transactionDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

#include "QueueDialog.h"

extern CallBacks CBackReference;

QueueDialog::QueueDialog(AlpmHandler *hnd, QWidget *parent)
: QDialog(parent),
  aHandle(hnd)
{
	setupUi(this);
	setWindowModality(Qt::ApplicationModal);
	
	
}

QueueDialog::~QueueDialog()
{
}
