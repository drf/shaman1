#ifndef SYSUPGRADEDIALOG_H_
#define SYSUPGRADEDIALOG_H_

#include <iostream>
#include "../ui_upgradeDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

class SysUpgradeDialog : public QDialog, private Ui::upgradeDialog
{
	Q_OBJECT
	
public:
	SysUpgradeDialog(AlpmHandler *hnd, QWidget *parent = 0);
	virtual ~SysUpgradeDialog();
	
private slots:
	void abort();
	void initSysUpgrade();
	void addPkg();
	
signals:
	void aborted();
	void upgradeNow();
	void addToPkgQueue();
	
private:
	AlpmHandler *aHandle;
};

#endif /*SYSUPGRADEDIALOG_H_*/
