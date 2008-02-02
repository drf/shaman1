/********************************************************************************
** Form generated from reading ui file 'dbUpdateDialog.ui'
**
** Created: Sat Feb 2 13:05:58 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DBUPDATEDIALOG_H
#define UI_DBUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_dbUpdateDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QLabel *displayAction;
    QProgressBar *totalPBar;
    QProgressBar *dlProgress;

    void setupUi(QWidget *dbUpdateDialog)
    {
    if (dbUpdateDialog->objectName().isEmpty())
        dbUpdateDialog->setObjectName(QString::fromUtf8("dbUpdateDialog"));
    dbUpdateDialog->resize(260, 127);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(dbUpdateDialog->sizePolicy().hasHeightForWidth());
    dbUpdateDialog->setSizePolicy(sizePolicy);
    dbUpdateDialog->setMinimumSize(QSize(260, 127));
    dbUpdateDialog->setMaximumSize(QSize(260, 127));
    layoutWidget = new QWidget(dbUpdateDialog);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(10, 11, 241, 101));
    vboxLayout = new QVBoxLayout(layoutWidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    displayAction = new QLabel(layoutWidget);
    displayAction->setObjectName(QString::fromUtf8("displayAction"));
    displayAction->setLayoutDirection(Qt::LeftToRight);
    displayAction->setAlignment(Qt::AlignCenter);

    vboxLayout->addWidget(displayAction);

    totalPBar = new QProgressBar(layoutWidget);
    totalPBar->setObjectName(QString::fromUtf8("totalPBar"));
    totalPBar->setValue(24);

    vboxLayout->addWidget(totalPBar);

    dlProgress = new QProgressBar(layoutWidget);
    dlProgress->setObjectName(QString::fromUtf8("dlProgress"));
    dlProgress->setValue(24);

    vboxLayout->addWidget(dlProgress);


    retranslateUi(dbUpdateDialog);

    QMetaObject::connectSlotsByName(dbUpdateDialog);
    } // setupUi

    void retranslateUi(QWidget *dbUpdateDialog)
    {
    dbUpdateDialog->setWindowTitle(QApplication::translate("dbUpdateDialog", "Updating Databases", 0, QApplication::UnicodeUTF8));
    displayAction->setText(QApplication::translate("dbUpdateDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    dlProgress->setFormat(QApplication::translate("dbUpdateDialog", "%p%", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(dbUpdateDialog);
    } // retranslateUi

};

namespace Ui {
    class dbUpdateDialog: public Ui_dbUpdateDialog {};
} // namespace Ui

#endif // UI_DBUPDATEDIALOG_H
