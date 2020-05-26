/********************************************************************************
** Form generated from reading UI file 'addconge.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONGE_H
#define UI_ADDCONGE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addconge
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *datedebut;
    QLabel *label_3;
    QTextEdit *commentaire;
    QLabel *label_4;
    QDateEdit *datefin;
    QLabel *label_5;
    QComboBox *raison;

    void setupUi(QDialog *addconge)
    {
        if (addconge->objectName().isEmpty())
            addconge->setObjectName(QString::fromUtf8("addconge"));
        addconge->resize(447, 317);
        buttonBox = new QDialogButtonBox(addconge);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(320, 105, 91, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(addconge);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 124, 61, 16));
        label_2 = new QLabel(addconge);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 153, 47, 13));
        datedebut = new QDateEdit(addconge);
        datedebut->setObjectName(QString::fromUtf8("datedebut"));
        datedebut->setGeometry(QRect(100, 120, 151, 22));
        datedebut->setCalendarPopup(true);
        datedebut->setDate(QDate(2020, 1, 1));
        label_3 = new QLabel(addconge);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 190, 71, 16));
        commentaire = new QTextEdit(addconge);
        commentaire->setObjectName(QString::fromUtf8("commentaire"));
        commentaire->setGeometry(QRect(100, 190, 321, 111));
        commentaire->setFrameShape(QFrame::StyledPanel);
        commentaire->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_4 = new QLabel(addconge);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 20, 271, 31));
        datefin = new QDateEdit(addconge);
        datefin->setObjectName(QString::fromUtf8("datefin"));
        datefin->setGeometry(QRect(100, 150, 151, 22));
        datefin->setCalendarPopup(true);
        datefin->setDate(QDate(2020, 1, 1));
        label_5 = new QLabel(addconge);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 97, 47, 13));
        raison = new QComboBox(addconge);
        raison->addItem(QString());
        raison->addItem(QString());
        raison->addItem(QString());
        raison->addItem(QString());
        raison->addItem(QString());
        raison->setObjectName(QString::fromUtf8("raison"));
        raison->setGeometry(QRect(100, 90, 151, 22));

        retranslateUi(addconge);
        QObject::connect(buttonBox, SIGNAL(accepted()), addconge, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addconge, SLOT(reject()));

        QMetaObject::connectSlotsByName(addconge);
    } // setupUi

    void retranslateUi(QDialog *addconge)
    {
        addconge->setWindowTitle(QCoreApplication::translate("addconge", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addconge", "Date debut", nullptr));
        label_2->setText(QCoreApplication::translate("addconge", "Date fin", nullptr));
        datedebut->setDisplayFormat(QCoreApplication::translate("addconge", "d/M/yyyy", nullptr));
        label_3->setText(QCoreApplication::translate("addconge", "Commentaire", nullptr));
        label_4->setText(QCoreApplication::translate("addconge", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#00007f;\">Ajouter Cong\303\251</span></p></body></html>", nullptr));
        datefin->setDisplayFormat(QCoreApplication::translate("addconge", "d/M/yyyy", nullptr));
        label_5->setText(QCoreApplication::translate("addconge", "Type", nullptr));
        raison->setItemText(0, QCoreApplication::translate("addconge", "Annuel", nullptr));
        raison->setItemText(1, QCoreApplication::translate("addconge", "Maladie", nullptr));
        raison->setItemText(2, QCoreApplication::translate("addconge", "Maternite", nullptr));
        raison->setItemText(3, QCoreApplication::translate("addconge", "Naissance / Deces", nullptr));
        raison->setItemText(4, QCoreApplication::translate("addconge", "Exceptionnel", nullptr));

    } // retranslateUi

};

namespace Ui {
    class addconge: public Ui_addconge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONGE_H
