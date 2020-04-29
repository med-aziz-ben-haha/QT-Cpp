/********************************************************************************
** Form generated from reading UI file 'stat_cong.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_CONG_H
#define UI_STAT_CONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stat_cong
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *stat_cong)
    {
        if (stat_cong->objectName().isEmpty())
            stat_cong->setObjectName(QString::fromUtf8("stat_cong"));
        stat_cong->resize(800, 600);
        centralwidget = new QWidget(stat_cong);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stat_cong->setCentralWidget(centralwidget);
        menubar = new QMenuBar(stat_cong);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        stat_cong->setMenuBar(menubar);
        statusbar = new QStatusBar(stat_cong);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        stat_cong->setStatusBar(statusbar);

        retranslateUi(stat_cong);

        QMetaObject::connectSlotsByName(stat_cong);
    } // setupUi

    void retranslateUi(QMainWindow *stat_cong)
    {
        stat_cong->setWindowTitle(QCoreApplication::translate("stat_cong", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stat_cong: public Ui_stat_cong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_CONG_H
