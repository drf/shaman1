#ifndef UPDATEDBDIALOG_H_
#define UPDATEDBDIALOG_H_

#include <iostream>
#include "../ui_dbUpdateDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

class UpDbThread : public QThread
{
public:
	UpDbThread(AlpmHandler *aH);
	void run();
private:
	AlpmHandler *aHandle;
};

class UpdateDbDialog : public QDialog, private Ui::dbUpdateDialog
{
	Q_OBJECT
	
public:
	UpdateDbDialog(AlpmHandler *hnd, QDialog *parent = 0);
	virtual ~UpdateDbDialog();
	
	bool dbHasBeenUpdated();
	
private slots:
	void updateLabel(char *repo, int action);
	//void updateDlProg(float bytetotal, float bytedled, float speed);
	void updateTotalProg();
	void setPBarRange(int range);
	void setUpdated();
	void doAction();
	void scopeEnded();
	void updateDlBar(char *c, int bytedone, int bytetotal, int speed,
			int i, int j, int k);
	
signals:
	void killMe();
	
private:
	int currentAction;
	char *currentRepo;
	int actionDone;
	bool updated;
	AlpmHandler *aHandle;
	UpDbThread *dbth;
	
};

#endif /*UPDATEDBDIALOG_H_*/
