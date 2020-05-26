/********************************************************************************
** Form generated from reading UI file 'stat_etat.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_ETAT_H
#define UI_STAT_ETAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_stat_etat
{
public:
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *stat_etat)
    {
        if (stat_etat->objectName().isEmpty())
            stat_etat->setObjectName(QString::fromUtf8("stat_etat"));
        stat_etat->resize(679, 479);
        horizontalFrame = new QFrame(stat_etat);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(10, 10, 661, 461));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        retranslateUi(stat_etat);

        QMetaObject::connectSlotsByName(stat_etat);
    } // setupUi

    void retranslateUi(QDialog *stat_etat)
    {
        stat_etat->setWindowTitle(QCoreApplication::translate("stat_etat", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stat_etat: public Ui_stat_etat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_ETAT_H
