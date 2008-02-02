#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iostream>
#include <QtGui>
#include <QWidget>
#include <alpm.h>
#include <alpm_list.h>
#include "../ui_MainWindow.h"
#include "AlpmHandler.h"
#include "StringUtils.h"
#include "UpdateDbDialog.h"

class MainWindow : public QMainWindow, private Ui::MainWindow, private StringUtils
{
	Q_OBJECT
	
public:
	MainWindow(AlpmHandler *handler, QApplication *appl, QMainWindow *parent = 0);
	virtual ~MainWindow();
	bool removePackagesView();
	bool removeRepoColumn();
	void refinePkgView(char *repo, char *searches);
	void doUpdView();
	
private:
	void loadDbUpdateDialog();
	void removeDbUpdateDialog();
	
public slots:
	bool populatePackagesView();
	void changePackagesView(QListWidgetItem *itm);
	bool populateRepoColumn();
	void showPkgInfo();
	void doDbUpdate();
	void finishDbUpdate();
	
signals:
	void updateDB();
	
private:
	alpm_list_t *currentpkgs;
	AlpmHandler *aHandle;
	UpdateDbDialog *dbdialog;
	QApplication *app;

};

class UpPkgViewThread : public QThread
{
public:
	UpPkgViewThread(MainWindow *mW);
	void run();
private:
	MainWindow *mainWin;
};

#endif /*MAINWINDOW_H_*/
