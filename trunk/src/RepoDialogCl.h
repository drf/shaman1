#ifndef REPODIALOGCL_H_
#define REPODIALOGCL_H_

#include <iostream>
#include "../ui_repoDialog.h"
#include <alpm.h>
#include "callbacks.h"
#include <QtGui>
#include <AlpmHandler.h>

class RepoDialogCl : public QDialog, private Ui::repoDialog
{
	Q_OBJECT
	
public:
	RepoDialogCl(AlpmHandler *hnd, QWidget *parent = 0);
	virtual ~RepoDialogCl();
	void cancelAddDialog();
	void applyAddDialog();
	
public slots:
	void handleClick(QAbstractButton *button);
	void openAddDialog();
	
	
private:
	AlpmHandler *aHandle;
	QDialog *addDialog;
};

#endif /*REPODIALOGCL_H_*/
