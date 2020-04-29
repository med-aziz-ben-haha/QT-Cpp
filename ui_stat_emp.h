/********************************************************************************
** Form generated from reading UI file 'stat_emp.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_EMP_H
#define UI_STAT_EMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stat_emp
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLabel *label_1;
    QWidget *page_2;
    QLabel *label_21;
    QLabel *label_2;
    QWidget *page_3;
    QLabel *label_3;
    QLabel *label_20;
    QWidget *page_4;
    QLabel *label_4;
    QLabel *label_30;

    void setupUi(QMainWindow *stat_emp)
    {
        if (stat_emp->objectName().isEmpty())
            stat_emp->setObjectName(QString::fromUtf8("stat_emp"));
        stat_emp->resize(800, 600);
        centralwidget = new QWidget(stat_emp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 811, 601));
        stackedWidget->setAcceptDrops(true);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 461, 51));
        label_1 = new QLabel(page);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(180, 90, 500, 500));
        label_1->setFrameShape(QFrame::NoFrame);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_21 = new QLabel(page_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(190, 20, 461, 51));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 90, 500, 500));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 90, 500, 500));
        label_20 = new QLabel(page_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(190, 20, 461, 51));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 90, 500, 500));
        label_30 = new QLabel(page_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(190, 20, 461, 51));
        stackedWidget->addWidget(page_4);
        stat_emp->setCentralWidget(centralwidget);

        retranslateUi(stat_emp);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(stat_emp);
    } // setupUi

    void retranslateUi(QMainWindow *stat_emp)
    {
        stat_emp->setWindowTitle(QCoreApplication::translate("stat_emp", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("stat_emp", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600; color:#5500ff;\">Titre</span></p></body></html>", nullptr));
        label_1->setText(QString());
        label_21->setText(QCoreApplication::translate("stat_emp", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600; color:#5500ff;\">Departement</span></p></body></html>", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_20->setText(QCoreApplication::translate("stat_emp", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600; color:#5500ff;\">Sexe</span></p></body></html>", nullptr));
        label_4->setText(QString());
        label_30->setText(QCoreApplication::translate("stat_emp", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600; color:#5500ff;\">Etat Conjugal</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stat_emp: public Ui_stat_emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_EMP_H
