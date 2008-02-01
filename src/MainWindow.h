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

class MainWindow : public QMainWindow, private Ui::MainWindow, private StringUtils
{
	Q_OBJECT
	
public:
	MainWindow(AlpmHandler *handler, QMainWindow *parent = 0);
	virtual ~MainWindow();
	bool removePackagesView();
	bool removeRepoColumn();
	
public slots:
	bool populatePackagesView(alpm_list_t *pkgs);
	void changePackagesView(QListWidgetItem *itm);
	bool populateRepoColumn();
	void showPkgInfo(QTreeWidgetItem*);
	
private:
	alpm_list_t *currentpkgs;
	AlpmHandler *aHandle;

};

#endif /*MAINWINDOW_H_*/
