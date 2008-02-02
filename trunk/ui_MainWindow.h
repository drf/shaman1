/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Fri Feb 1 22:57:31 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *actionPackage_Repositories;
    QAction *actionPacman_Preferences;
    QAction *actionPyKMan_Preferences;
    QAction *actionABS_Preferences;
    QAction *actionUpdate_Pacman;
    QAction *actionClean_Cache;
    QAction *actionEmpty_Cache;
    QAction *actionInstall_Package_From_File;
    QAction *actionUpdate_ABS_Tree;
    QAction *actionBuild_and_Install_Selected;
    QAction *actionInstall_Selected;
    QAction *actionBuild_Package;
    QAction *actionBuild_and_Install_Package_From_File;
    QAction *actionAbout;
    QAction *actionKhg;
    QAction *actionUpdate_Database;
    QAction *actionUpgrade_System;
    QAction *actionInstall_Package_From_File_2;
    QAction *actionClean_Cache_2;
    QAction *actionEmpty_Cache_2;
    QAction *actionUpdate_ABS_Tree_2;
    QAction *actionInstall_and_Build_Selected;
    QAction *actionBuild_Package_From_File;
    QAction *actionBuild_and_Install_Package_From_File_2;
    QAction *actionClean_Build_Environment_For_Selected;
    QAction *actionClean_all_Build_Environments;
    QAction *actionQuit;
    QAction *actionProcess_Queue;
    QWidget *centralwidget;
    QTreeWidget *pkgsViewWG;
    QListWidget *repoList;
    QTabWidget *PkgInfos;
    QWidget *tab;
    QTextEdit *pkgInfo;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QMenu *menuActions;
    QMenu *menuInstall_and_Build_from_Source;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(784, 542);
    actionPackage_Repositories = new QAction(MainWindow);
    actionPackage_Repositories->setObjectName(QString::fromUtf8("actionPackage_Repositories"));
    actionPacman_Preferences = new QAction(MainWindow);
    actionPacman_Preferences->setObjectName(QString::fromUtf8("actionPacman_Preferences"));
    actionPyKMan_Preferences = new QAction(MainWindow);
    actionPyKMan_Preferences->setObjectName(QString::fromUtf8("actionPyKMan_Preferences"));
    actionABS_Preferences = new QAction(MainWindow);
    actionABS_Preferences->setObjectName(QString::fromUtf8("actionABS_Preferences"));
    actionUpdate_Pacman = new QAction(MainWindow);
    actionUpdate_Pacman->setObjectName(QString::fromUtf8("actionUpdate_Pacman"));
    actionClean_Cache = new QAction(MainWindow);
    actionClean_Cache->setObjectName(QString::fromUtf8("actionClean_Cache"));
    actionEmpty_Cache = new QAction(MainWindow);
    actionEmpty_Cache->setObjectName(QString::fromUtf8("actionEmpty_Cache"));
    actionInstall_Package_From_File = new QAction(MainWindow);
    actionInstall_Package_From_File->setObjectName(QString::fromUtf8("actionInstall_Package_From_File"));
    actionUpdate_ABS_Tree = new QAction(MainWindow);
    actionUpdate_ABS_Tree->setObjectName(QString::fromUtf8("actionUpdate_ABS_Tree"));
    actionBuild_and_Install_Selected = new QAction(MainWindow);
    actionBuild_and_Install_Selected->setObjectName(QString::fromUtf8("actionBuild_and_Install_Selected"));
    actionInstall_Selected = new QAction(MainWindow);
    actionInstall_Selected->setObjectName(QString::fromUtf8("actionInstall_Selected"));
    actionBuild_Package = new QAction(MainWindow);
    actionBuild_Package->setObjectName(QString::fromUtf8("actionBuild_Package"));
    actionBuild_and_Install_Package_From_File = new QAction(MainWindow);
    actionBuild_and_Install_Package_From_File->setObjectName(QString::fromUtf8("actionBuild_and_Install_Package_From_File"));
    actionAbout = new QAction(MainWindow);
    actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
    actionKhg = new QAction(MainWindow);
    actionKhg->setObjectName(QString::fromUtf8("actionKhg"));
    actionUpdate_Database = new QAction(MainWindow);
    actionUpdate_Database->setObjectName(QString::fromUtf8("actionUpdate_Database"));
    actionUpgrade_System = new QAction(MainWindow);
    actionUpgrade_System->setObjectName(QString::fromUtf8("actionUpgrade_System"));
    actionInstall_Package_From_File_2 = new QAction(MainWindow);
    actionInstall_Package_From_File_2->setObjectName(QString::fromUtf8("actionInstall_Package_From_File_2"));
    actionClean_Cache_2 = new QAction(MainWindow);
    actionClean_Cache_2->setObjectName(QString::fromUtf8("actionClean_Cache_2"));
    actionEmpty_Cache_2 = new QAction(MainWindow);
    actionEmpty_Cache_2->setObjectName(QString::fromUtf8("actionEmpty_Cache_2"));
    actionUpdate_ABS_Tree_2 = new QAction(MainWindow);
    actionUpdate_ABS_Tree_2->setObjectName(QString::fromUtf8("actionUpdate_ABS_Tree_2"));
    actionInstall_and_Build_Selected = new QAction(MainWindow);
    actionInstall_and_Build_Selected->setObjectName(QString::fromUtf8("actionInstall_and_Build_Selected"));
    actionBuild_Package_From_File = new QAction(MainWindow);
    actionBuild_Package_From_File->setObjectName(QString::fromUtf8("actionBuild_Package_From_File"));
    actionBuild_and_Install_Package_From_File_2 = new QAction(MainWindow);
    actionBuild_and_Install_Package_From_File_2->setObjectName(QString::fromUtf8("actionBuild_and_Install_Package_From_File_2"));
    actionClean_Build_Environment_For_Selected = new QAction(MainWindow);
    actionClean_Build_Environment_For_Selected->setObjectName(QString::fromUtf8("actionClean_Build_Environment_For_Selected"));
    actionClean_all_Build_Environments = new QAction(MainWindow);
    actionClean_all_Build_Environments->setObjectName(QString::fromUtf8("actionClean_all_Build_Environments"));
    actionQuit = new QAction(MainWindow);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionProcess_Queue = new QAction(MainWindow);
    actionProcess_Queue->setObjectName(QString::fromUtf8("actionProcess_Queue"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    pkgsViewWG = new QTreeWidget(centralwidget);
    pkgsViewWG->setObjectName(QString::fromUtf8("pkgsViewWG"));
    pkgsViewWG->setGeometry(QRect(170, 0, 611, 271));
    pkgsViewWG->setIndentation(0);
    pkgsViewWG->setRootIsDecorated(true);
    pkgsViewWG->setItemsExpandable(false);
    pkgsViewWG->setSortingEnabled(true);
    repoList = new QListWidget(centralwidget);
    repoList->setObjectName(QString::fromUtf8("repoList"));
    repoList->setGeometry(QRect(0, 0, 161, 451));
    PkgInfos = new QTabWidget(centralwidget);
    PkgInfos->setObjectName(QString::fromUtf8("PkgInfos"));
    PkgInfos->setGeometry(QRect(170, 280, 611, 171));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    pkgInfo = new QTextEdit(tab);
    pkgInfo->setObjectName(QString::fromUtf8("pkgInfo"));
    pkgInfo->setEnabled(true);
    pkgInfo->setGeometry(QRect(0, 0, 601, 131));
    pkgInfo->setAcceptDrops(false);
    pkgInfo->setUndoRedoEnabled(false);
    pkgInfo->setReadOnly(true);
    pkgInfo->setAcceptRichText(false);
    PkgInfos->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    PkgInfos->addTab(tab_2, QString());
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 784, 27));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuSettings = new QMenu(menubar);
    menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    menuActions = new QMenu(menubar);
    menuActions->setObjectName(QString::fromUtf8("menuActions"));
    menuInstall_and_Build_from_Source = new QMenu(menuActions);
    menuInstall_and_Build_from_Source->setObjectName(QString::fromUtf8("menuInstall_and_Build_from_Source"));
    MainWindow->setMenuBar(menubar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setAcceptDrops(true);
    toolBar->setMovable(false);
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindow->setStatusBar(statusBar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuSettings->menuAction());
    menubar->addAction(menuActions->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuFile->addAction(actionQuit);
    menuSettings->addAction(actionPackage_Repositories);
    menuSettings->addAction(actionPacman_Preferences);
    menuSettings->addSeparator();
    menuSettings->addAction(actionABS_Preferences);
    menuSettings->addSeparator();
    menuSettings->addAction(actionPyKMan_Preferences);
    menuHelp->addAction(actionAbout);
    menuActions->addAction(actionUpdate_Database);
    menuActions->addAction(actionUpgrade_System);
    menuActions->addSeparator();
    menuActions->addAction(actionProcess_Queue);
    menuActions->addAction(actionInstall_Package_From_File_2);
    menuActions->addSeparator();
    menuActions->addAction(actionClean_Cache_2);
    menuActions->addAction(actionEmpty_Cache_2);
    menuActions->addSeparator();
    menuActions->addAction(menuInstall_and_Build_from_Source->menuAction());
    menuInstall_and_Build_from_Source->addAction(actionUpdate_ABS_Tree_2);
    menuInstall_and_Build_from_Source->addSeparator();
    menuInstall_and_Build_from_Source->addAction(actionInstall_and_Build_Selected);
    menuInstall_and_Build_from_Source->addSeparator();
    menuInstall_and_Build_from_Source->addAction(actionBuild_Package_From_File);
    menuInstall_and_Build_from_Source->addAction(actionBuild_and_Install_Package_From_File_2);
    menuInstall_and_Build_from_Source->addSeparator();
    menuInstall_and_Build_from_Source->addAction(actionClean_Build_Environment_For_Selected);
    menuInstall_and_Build_from_Source->addAction(actionClean_all_Build_Environments);
    toolBar->addAction(actionUpdate_Database);
    toolBar->addAction(actionUpgrade_System);
    toolBar->addAction(actionProcess_Queue);

    retranslateUi(MainWindow);

    PkgInfos->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionPackage_Repositories->setText(QApplication::translate("MainWindow", "Package Repositories", 0, QApplication::UnicodeUTF8));
    actionPacman_Preferences->setText(QApplication::translate("MainWindow", "Pacman Preferences", 0, QApplication::UnicodeUTF8));
    actionPyKMan_Preferences->setText(QApplication::translate("MainWindow", "PyKMan Preferences", 0, QApplication::UnicodeUTF8));
    actionABS_Preferences->setText(QApplication::translate("MainWindow", "ABS Preferences", 0, QApplication::UnicodeUTF8));
    actionUpdate_Pacman->setText(QApplication::translate("MainWindow", "Update Pacman", 0, QApplication::UnicodeUTF8));
    actionClean_Cache->setText(QApplication::translate("MainWindow", "Clean Cache", 0, QApplication::UnicodeUTF8));
    actionEmpty_Cache->setText(QApplication::translate("MainWindow", "Empty Cache", 0, QApplication::UnicodeUTF8));
    actionInstall_Package_From_File->setText(QApplication::translate("MainWindow", "Install Package From File", 0, QApplication::UnicodeUTF8));
    actionUpdate_ABS_Tree->setText(QApplication::translate("MainWindow", "Update ABS Tree", 0, QApplication::UnicodeUTF8));
    actionBuild_and_Install_Selected->setText(QApplication::translate("MainWindow", "Build and Install Selected", 0, QApplication::UnicodeUTF8));
    actionInstall_Selected->setText(QApplication::translate("MainWindow", "Install Selected", 0, QApplication::UnicodeUTF8));
    actionBuild_Package->setText(QApplication::translate("MainWindow", "Build Package From File", 0, QApplication::UnicodeUTF8));
    actionBuild_and_Install_Package_From_File->setText(QApplication::translate("MainWindow", "Build and Install Package From File", 0, QApplication::UnicodeUTF8));
    actionAbout->setText(QApplication::translate("MainWindow", "About...", 0, QApplication::UnicodeUTF8));
    actionKhg->setText(QApplication::translate("MainWindow", "khg", 0, QApplication::UnicodeUTF8));
    actionUpdate_Database->setText(QApplication::translate("MainWindow", "Update Database", 0, QApplication::UnicodeUTF8));
    actionUpgrade_System->setText(QApplication::translate("MainWindow", "Upgrade System", 0, QApplication::UnicodeUTF8));
    actionInstall_Package_From_File_2->setText(QApplication::translate("MainWindow", "Install Package From File", 0, QApplication::UnicodeUTF8));
    actionClean_Cache_2->setText(QApplication::translate("MainWindow", "Clean Cache", 0, QApplication::UnicodeUTF8));
    actionEmpty_Cache_2->setText(QApplication::translate("MainWindow", "Empty Cache", 0, QApplication::UnicodeUTF8));
    actionUpdate_ABS_Tree_2->setText(QApplication::translate("MainWindow", "Update ABS Tree", 0, QApplication::UnicodeUTF8));
    actionInstall_and_Build_Selected->setText(QApplication::translate("MainWindow", "Install and Build Selected", 0, QApplication::UnicodeUTF8));
    actionBuild_Package_From_File->setText(QApplication::translate("MainWindow", "Build Package From File", 0, QApplication::UnicodeUTF8));
    actionBuild_and_Install_Package_From_File_2->setText(QApplication::translate("MainWindow", "Build and Install Package From File", 0, QApplication::UnicodeUTF8));
    actionClean_Build_Environment_For_Selected->setText(QApplication::translate("MainWindow", "Clean Build Environment For Selected", 0, QApplication::UnicodeUTF8));
    actionClean_all_Build_Environments->setText(QApplication::translate("MainWindow", "Clean all Build Environments", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
    actionProcess_Queue->setText(QApplication::translate("MainWindow", "Process Queue", 0, QApplication::UnicodeUTF8));
    pkgsViewWG->headerItem()->setText(0, QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
    pkgsViewWG->headerItem()->setText(1, QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
    pkgsViewWG->headerItem()->setText(2, QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
    pkgsViewWG->headerItem()->setText(3, QApplication::translate("MainWindow", "Version", 0, QApplication::UnicodeUTF8));
    pkgsViewWG->headerItem()->setText(4, QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
    pkgsViewWG->headerItem()->setText(5, QApplication::translate("MainWindow", "Repo", 0, QApplication::UnicodeUTF8));
    pkgInfo->setHtml(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Welcome in qtPacman</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    PkgInfos->setTabText(PkgInfos->indexOf(tab), QApplication::translate("MainWindow", "Package Information", 0, QApplication::UnicodeUTF8));
    PkgInfos->setTabText(PkgInfos->indexOf(tab_2), QApplication::translate("MainWindow", "Files", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    menuActions->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
    menuInstall_and_Build_from_Source->setTitle(QApplication::translate("MainWindow", "Install and Build from Source", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // UI_MAINWINDOW_H
