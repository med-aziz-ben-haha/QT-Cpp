/********************************************************************************
** Form generated from reading UI file 'addemp.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEMP_H
#define UI_ADDEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addemp
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_16;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *cin;
    QLineEdit *nom;
    QDateEdit *naissance;
    QComboBox *sex;
    QComboBox *conjugal;
    QLineEdit *nationality;
    QLineEdit *adress;
    QLineEdit *zip;
    QLineEdit *phone;
    QLabel *label_10;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_14;
    QLabel *label_9;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_4;
    QComboBox *title;
    QComboBox *dep;
    QDoubleSpinBox *hour_sal;
    QSpinBox *hour;
    QTimeEdit *starting_time;
    QLineEdit *competence;
    QSpinBox *conge;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addemp)
    {
        if (addemp->objectName().isEmpty())
            addemp->setObjectName(QString::fromUtf8("addemp"));
        addemp->resize(580, 360);
        groupBox = new QGroupBox(addemp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 261, 281));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 30, 232, 232));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout->addWidget(label_16);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout->addWidget(label_15);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cin = new QLineEdit(layoutWidget);
        cin->setObjectName(QString::fromUtf8("cin"));

        verticalLayout_2->addWidget(cin);

        nom = new QLineEdit(layoutWidget);
        nom->setObjectName(QString::fromUtf8("nom"));

        verticalLayout_2->addWidget(nom);

        naissance = new QDateEdit(layoutWidget);
        naissance->setObjectName(QString::fromUtf8("naissance"));
        naissance->setCalendarPopup(true);

        verticalLayout_2->addWidget(naissance);

        sex = new QComboBox(layoutWidget);
        sex->addItem(QString());
        sex->addItem(QString());
        sex->setObjectName(QString::fromUtf8("sex"));

        verticalLayout_2->addWidget(sex);

        conjugal = new QComboBox(layoutWidget);
        conjugal->addItem(QString());
        conjugal->addItem(QString());
        conjugal->addItem(QString());
        conjugal->addItem(QString());
        conjugal->setObjectName(QString::fromUtf8("conjugal"));

        verticalLayout_2->addWidget(conjugal);

        nationality = new QLineEdit(layoutWidget);
        nationality->setObjectName(QString::fromUtf8("nationality"));

        verticalLayout_2->addWidget(nationality);

        adress = new QLineEdit(layoutWidget);
        adress->setObjectName(QString::fromUtf8("adress"));

        verticalLayout_2->addWidget(adress);

        zip = new QLineEdit(layoutWidget);
        zip->setObjectName(QString::fromUtf8("zip"));

        verticalLayout_2->addWidget(zip);

        phone = new QLineEdit(layoutWidget);
        phone->setObjectName(QString::fromUtf8("phone"));

        verticalLayout_2->addWidget(phone);


        horizontalLayout->addLayout(verticalLayout_2);

        label_10 = new QLabel(addemp);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 10, 301, 31));
        groupBox_2 = new QGroupBox(addemp);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 60, 271, 231));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 30, 237, 180));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_3->addWidget(label_13);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_3->addWidget(label_14);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_3->addWidget(label_17);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        title = new QComboBox(layoutWidget1);
        title->addItem(QString());
        title->addItem(QString());
        title->addItem(QString());
        title->addItem(QString());
        title->addItem(QString());
        title->setObjectName(QString::fromUtf8("title"));

        verticalLayout_4->addWidget(title);

        dep = new QComboBox(layoutWidget1);
        dep->addItem(QString());
        dep->addItem(QString());
        dep->addItem(QString());
        dep->setObjectName(QString::fromUtf8("dep"));

        verticalLayout_4->addWidget(dep);

        hour_sal = new QDoubleSpinBox(layoutWidget1);
        hour_sal->setObjectName(QString::fromUtf8("hour_sal"));
        hour_sal->setDecimals(3);
        hour_sal->setMaximum(99990000.000000000000000);

        verticalLayout_4->addWidget(hour_sal);

        hour = new QSpinBox(layoutWidget1);
        hour->setObjectName(QString::fromUtf8("hour"));
        hour->setMinimum(1);
        hour->setMaximum(10);
        hour->setValue(8);

        verticalLayout_4->addWidget(hour);

        starting_time = new QTimeEdit(layoutWidget1);
        starting_time->setObjectName(QString::fromUtf8("starting_time"));
        starting_time->setWrapping(false);
        starting_time->setCalendarPopup(false);
        starting_time->setTime(QTime(8, 0, 0));

        verticalLayout_4->addWidget(starting_time);

        competence = new QLineEdit(layoutWidget1);
        competence->setObjectName(QString::fromUtf8("competence"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(competence->sizePolicy().hasHeightForWidth());
        competence->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(competence);

        conge = new QSpinBox(layoutWidget1);
        conge->setObjectName(QString::fromUtf8("conge"));
        conge->setMinimum(20);
        conge->setMaximum(100);
        conge->setValue(45);

        verticalLayout_4->addWidget(conge);


        horizontalLayout_2->addLayout(verticalLayout_4);

        buttonBox = new QDialogButtonBox(addemp);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(370, 320, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(addemp);

        QMetaObject::connectSlotsByName(addemp);
    } // setupUi

    void retranslateUi(QDialog *addemp)
    {
        addemp->setWindowTitle(QCoreApplication::translate("addemp", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("addemp", "Informations G\303\251n\303\251rales", nullptr));
        label_16->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">CIN</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Nom et Prenom</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Date Naissance</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Sexe</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Etat Conjugal</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Nationalit\303\251</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Adresse</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Code postal</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("addemp", "<html><head/><body><p><span style=\" font-weight:600;\">Mobile</span></p></body></html>", nullptr));
        cin->setText(QString());
        naissance->setDisplayFormat(QCoreApplication::translate("addemp", "d/M/yyyy", nullptr));
        sex->setItemText(0, QCoreApplication::translate("addemp", "Homme", nullptr));
        sex->setItemText(1, QCoreApplication::translate("addemp", "Femme", nullptr));

        conjugal->setItemText(0, QCoreApplication::translate("addemp", "Celibataire", nullptr));
        conjugal->setItemText(1, QCoreApplication::translate("addemp", "Marrie", nullptr));
        conjugal->setItemText(2, QCoreApplication::translate("addemp", "Divorce", nullptr));
        conjugal->setItemText(3, QCoreApplication::translate("addemp", "veuf / veuve", nullptr));

        label_10->setText(QCoreApplication::translate("addemp", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#00007f;\">D\303\251tails de l'employ\303\251</span></p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("addemp", "Details De Travail", nullptr));
        label_5->setText(QCoreApplication::translate("addemp", "Title", nullptr));
        label_13->setText(QCoreApplication::translate("addemp", "Departement", nullptr));
        label_7->setText(QCoreApplication::translate("addemp", "Hourly paiment", nullptr));
        label_8->setText(QCoreApplication::translate("addemp", "Working hours/Day", nullptr));
        label_14->setText(QCoreApplication::translate("addemp", "Heure D\303\251but", nullptr));
        label_9->setText(QCoreApplication::translate("addemp", "competences", nullptr));
        label_17->setText(QCoreApplication::translate("addemp", "Jours cong\303\251s", nullptr));
        title->setItemText(0, QCoreApplication::translate("addemp", "EMP", nullptr));
        title->setItemText(1, QCoreApplication::translate("addemp", "ADM", nullptr));
        title->setItemText(2, QCoreApplication::translate("addemp", "SAI", nullptr));
        title->setItemText(3, QCoreApplication::translate("addemp", "STA", nullptr));
        title->setItemText(4, QCoreApplication::translate("addemp", "CON", nullptr));

        dep->setItemText(0, QCoreApplication::translate("addemp", "RH", nullptr));
        dep->setItemText(1, QCoreApplication::translate("addemp", "CL", nullptr));
        dep->setItemText(2, QCoreApplication::translate("addemp", "CO", nullptr));

    } // retranslateUi

};

namespace Ui {
    class addemp: public Ui_addemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEMP_H
