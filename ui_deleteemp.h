/********************************************************************************
** Form generated from reading UI file 'deleteemp.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEEMP_H
#define UI_DELETEEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_deleteemp
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *cindelete;

    void setupUi(QDialog *deleteemp)
    {
        if (deleteemp->objectName().isEmpty())
            deleteemp->setObjectName(QString::fromUtf8("deleteemp"));
        deleteemp->resize(537, 126);
        buttonBox = new QDialogButtonBox(deleteemp);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(430, 30, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(deleteemp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 61, 16));
        cindelete = new QTextEdit(deleteemp);
        cindelete->setObjectName(QString::fromUtf8("cindelete"));
        cindelete->setGeometry(QRect(150, 30, 231, 71));

        retranslateUi(deleteemp);
        QObject::connect(buttonBox, SIGNAL(accepted()), deleteemp, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deleteemp, SLOT(reject()));

        QMetaObject::connectSlotsByName(deleteemp);
    } // setupUi

    void retranslateUi(QDialog *deleteemp)
    {
        deleteemp->setWindowTitle(QCoreApplication::translate("deleteemp", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("deleteemp", "ID Employ\303\251", nullptr));
        cindelete->setPlaceholderText(QCoreApplication::translate("deleteemp", "Si vous voulez supprimer plusieurs employ\303\251s en m\303\252me temps veuiller respecter le syntaxe : ID1 , ID2 , ID3 ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteemp: public Ui_deleteemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEEMP_H
