/********************************************************************************
** Form generated from reading UI file 'gestion_coli_courrier.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_COLI_COURRIER_H
#define UI_GESTION_COLI_COURRIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gestion_Coli_Courrier
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTabWidget *loadcoli;
    QWidget *tab;
    QTableView *tableColi;
    QPushButton *suppcoli;
    QPushButton *Modifiercoli;
    QLineEdit *recherche;
    QPushButton *tri_coli;
    QCheckBox *checkBox_2;
    QLabel *label_22;
    QLabel *label_26;
    QComboBox *comboBox_4;
    QPushButton *EXCEL1;
    QPushButton *stat1;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLineEdit *Poids;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_6;
    QCheckBox *Avecliv;
    QLabel *label_2;
    QLineEdit *idcoli;
    QLineEdit *Prix;
    QComboBox *Priorite;
    QTextEdit *Adresseem;
    QTextEdit *Adressedest;
    QComboBox *Etat;
    QPushButton *ajoutercoli;
    QLabel *label_30;
    QWidget *tab_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QTableView *tableView_2;
    QPushButton *ModifierCourrier;
    QPushButton *suppcourrier;
    QPushButton *tri_coli_2;
    QCheckBox *checkBox_3;
    QLineEdit *recherche_2;
    QLabel *label_23;
    QLabel *label_27;
    QComboBox *comboBox_5;
    QPushButton *EXCEL_2;
    QPushButton *stat2;
    QWidget *tab_6;
    QGroupBox *groupBox_3;
    QLabel *label_14;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *IDcourrier;
    QLabel *label_10;
    QLabel *label_8;
    QLineEdit *prix_2;
    QLabel *label_12;
    QComboBox *Priorite_2;
    QComboBox *type_courrier;
    QTextEdit *Adresseem_2;
    QTextEdit *Adressedest_2;
    QComboBox *etat_2;
    QPushButton *ajoutercourrier;
    QLabel *label_31;
    QWidget *tab_7;
    QTabWidget *tabWidget_4;
    QWidget *tab_8;
    QTableView *tableView_3;
    QPushButton *pushButton_11;
    QPushButton *supp_equip;
    QLineEdit *recherche_3;
    QLabel *label_24;
    QLabel *label_28;
    QWidget *tab_9;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lineEdit_2;
    QLabel *label_17;
    QComboBox *comboBox_3;
    QLineEdit *type_equip;
    QPushButton *ajouterequip;
    QLabel *label_32;
    QWidget *tab_10;
    QTabWidget *tabWidget_5;
    QWidget *tab_11;
    QPushButton *pushButton_9;
    QPushButton *supp_liv;
    QTableView *tableView_4;
    QLineEdit *recherche_4;
    QLabel *label_25;
    QLabel *label_29;
    QWidget *tab_12;
    QPushButton *ajouterliv;
    QGroupBox *groupBox_4;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_18;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_idliv;
    QDateEdit *dateTimeEdit;
    QLabel *label_33;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gestion_Coli_Courrier)
    {
        if (Gestion_Coli_Courrier->objectName().isEmpty())
            Gestion_Coli_Courrier->setObjectName(QString::fromUtf8("Gestion_Coli_Courrier"));
        Gestion_Coli_Courrier->resize(862, 539);
        centralwidget = new QWidget(Gestion_Coli_Courrier);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 851, 491));
        tabWidget_2->setStyleSheet(QString::fromUtf8(""));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        loadcoli = new QTabWidget(tab_3);
        loadcoli->setObjectName(QString::fromUtf8("loadcoli"));
        loadcoli->setGeometry(QRect(30, 10, 791, 441));
        loadcoli->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableColi = new QTableView(tab);
        tableColi->setObjectName(QString::fromUtf8("tableColi"));
        tableColi->setGeometry(QRect(10, 70, 761, 281));
        tableColi->setStyleSheet(QString::fromUtf8(""));
        suppcoli = new QPushButton(tab);
        suppcoli->setObjectName(QString::fromUtf8("suppcoli"));
        suppcoli->setGeometry(QRect(730, 360, 41, 41));
        suppcoli->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/delete.png);"));
        Modifiercoli = new QPushButton(tab);
        Modifiercoli->setObjectName(QString::fromUtf8("Modifiercoli"));
        Modifiercoli->setGeometry(QRect(670, 360, 41, 41));
        Modifiercoli->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/modify.png);"));
        recherche = new QLineEdit(tab);
        recherche->setObjectName(QString::fromUtf8("recherche"));
        recherche->setGeometry(QRect(10, 20, 241, 21));
        recherche->setStyleSheet(QString::fromUtf8(""));
        tri_coli = new QPushButton(tab);
        tri_coli->setObjectName(QString::fromUtf8("tri_coli"));
        tri_coli->setGeometry(QRect(730, 20, 31, 31));
        tri_coli->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/tri.png);"));
        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(630, 36, 91, 20));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(260, 20, 31, 21));
        label_22->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/search.png);"));
        label_26 = new QLabel(tab);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(330, -20, 121, 111));
        label_26->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        comboBox_4 = new QComboBox(tab);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(630, 10, 81, 22));
        EXCEL1 = new QPushButton(tab);
        EXCEL1->setObjectName(QString::fromUtf8("EXCEL1"));
        EXCEL1->setGeometry(QRect(330, 350, 61, 61));
        EXCEL1->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/excel.png);"));
        stat1 = new QPushButton(tab);
        stat1->setObjectName(QString::fromUtf8("stat1"));
        stat1->setGeometry(QRect(70, 360, 41, 41));
        stat1->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/stat.png);"));
        loadcoli->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 441, 371));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 141, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        Poids = new QLineEdit(groupBox_2);
        Poids->setObjectName(QString::fromUtf8("Poids"));
        Poids->setGeometry(QRect(170, 240, 231, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 210, 61, 16));
        label_4->setFont(font);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 240, 51, 16));
        label_5->setFont(font);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 270, 47, 13));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        label_7->setFont(font1);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 16));
        label->setFont(font);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 300, 47, 13));
        label_6->setFont(font);
        Avecliv = new QCheckBox(groupBox_2);
        Avecliv->setObjectName(QString::fromUtf8("Avecliv"));
        Avecliv->setGeometry(QRect(170, 330, 161, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        Avecliv->setFont(font2);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 131, 16));
        label_2->setFont(font2);
        idcoli = new QLineEdit(groupBox_2);
        idcoli->setObjectName(QString::fromUtf8("idcoli"));
        idcoli->setGeometry(QRect(170, 20, 231, 20));
        Prix = new QLineEdit(groupBox_2);
        Prix->setObjectName(QString::fromUtf8("Prix"));
        Prix->setGeometry(QRect(170, 270, 231, 20));
        Priorite = new QComboBox(groupBox_2);
        Priorite->setObjectName(QString::fromUtf8("Priorite"));
        Priorite->setGeometry(QRect(170, 210, 231, 22));
        Adresseem = new QTextEdit(groupBox_2);
        Adresseem->setObjectName(QString::fromUtf8("Adresseem"));
        Adresseem->setGeometry(QRect(170, 50, 231, 71));
        Adressedest = new QTextEdit(groupBox_2);
        Adressedest->setObjectName(QString::fromUtf8("Adressedest"));
        Adressedest->setGeometry(QRect(170, 130, 231, 71));
        Etat = new QComboBox(groupBox_2);
        Etat->setObjectName(QString::fromUtf8("Etat"));
        Etat->setGeometry(QRect(170, 300, 231, 22));
        ajoutercoli = new QPushButton(tab_2);
        ajoutercoli->setObjectName(QString::fromUtf8("ajoutercoli"));
        ajoutercoli->setGeometry(QRect(680, 310, 41, 41));
        ajoutercoli->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/add.png);"));
        label_30 = new QLabel(tab_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(610, 0, 171, 141));
        label_30->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        loadcoli->addTab(tab_2, QString());
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_3 = new QTabWidget(tab_4);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(30, 10, 791, 441));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tableView_2 = new QTableView(tab_5);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 70, 761, 281));
        ModifierCourrier = new QPushButton(tab_5);
        ModifierCourrier->setObjectName(QString::fromUtf8("ModifierCourrier"));
        ModifierCourrier->setGeometry(QRect(670, 360, 41, 41));
        ModifierCourrier->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/modify.png);"));
        suppcourrier = new QPushButton(tab_5);
        suppcourrier->setObjectName(QString::fromUtf8("suppcourrier"));
        suppcourrier->setGeometry(QRect(730, 360, 41, 41));
        suppcourrier->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/delete.png);"));
        tri_coli_2 = new QPushButton(tab_5);
        tri_coli_2->setObjectName(QString::fromUtf8("tri_coli_2"));
        tri_coli_2->setGeometry(QRect(730, 20, 31, 31));
        tri_coli_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/tri.png);"));
        checkBox_3 = new QCheckBox(tab_5);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(630, 36, 81, 20));
        recherche_2 = new QLineEdit(tab_5);
        recherche_2->setObjectName(QString::fromUtf8("recherche_2"));
        recherche_2->setGeometry(QRect(10, 20, 241, 21));
        label_23 = new QLabel(tab_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(260, 20, 31, 21));
        label_23->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/search.png);"));
        label_27 = new QLabel(tab_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(330, -20, 121, 111));
        label_27->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        comboBox_5 = new QComboBox(tab_5);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(630, 10, 81, 22));
        EXCEL_2 = new QPushButton(tab_5);
        EXCEL_2->setObjectName(QString::fromUtf8("EXCEL_2"));
        EXCEL_2->setGeometry(QRect(330, 350, 61, 61));
        EXCEL_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/excel.png);"));
        stat2 = new QPushButton(tab_5);
        stat2->setObjectName(QString::fromUtf8("stat2"));
        stat2->setGeometry(QRect(70, 360, 41, 41));
        stat2->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/stat.png);"));
        tabWidget_3->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        groupBox_3 = new QGroupBox(tab_6);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 501, 361));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 270, 47, 13));
        label_14->setFont(font);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 80, 121, 16));
        label_9->setFont(font);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 240, 61, 16));
        label_11->setFont(font);
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 300, 47, 13));
        label_13->setFont(font);
        IDcourrier = new QLineEdit(groupBox_3);
        IDcourrier->setObjectName(QString::fromUtf8("IDcourrier"));
        IDcourrier->setGeometry(QRect(160, 20, 231, 20));
        IDcourrier->setStyleSheet(QString::fromUtf8(""));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 160, 141, 16));
        label_10->setFont(font);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 91, 16));
        label_8->setFont(font);
        prix_2 = new QLineEdit(groupBox_3);
        prix_2->setObjectName(QString::fromUtf8("prix_2"));
        prix_2->setGeometry(QRect(160, 270, 231, 20));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 50, 61, 16));
        label_12->setFont(font);
        Priorite_2 = new QComboBox(groupBox_3);
        Priorite_2->setObjectName(QString::fromUtf8("Priorite_2"));
        Priorite_2->setGeometry(QRect(160, 240, 231, 22));
        type_courrier = new QComboBox(groupBox_3);
        type_courrier->setObjectName(QString::fromUtf8("type_courrier"));
        type_courrier->setGeometry(QRect(160, 50, 231, 22));
        Adresseem_2 = new QTextEdit(groupBox_3);
        Adresseem_2->setObjectName(QString::fromUtf8("Adresseem_2"));
        Adresseem_2->setGeometry(QRect(160, 80, 231, 71));
        Adressedest_2 = new QTextEdit(groupBox_3);
        Adressedest_2->setObjectName(QString::fromUtf8("Adressedest_2"));
        Adressedest_2->setGeometry(QRect(160, 160, 231, 71));
        etat_2 = new QComboBox(groupBox_3);
        etat_2->setObjectName(QString::fromUtf8("etat_2"));
        etat_2->setGeometry(QRect(160, 300, 231, 22));
        ajoutercourrier = new QPushButton(tab_6);
        ajoutercourrier->setObjectName(QString::fromUtf8("ajoutercourrier"));
        ajoutercourrier->setGeometry(QRect(680, 310, 41, 41));
        ajoutercourrier->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/add.png);"));
        label_31 = new QLabel(tab_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(610, 0, 171, 141));
        label_31->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        tabWidget_3->addTab(tab_6, QString());
        tabWidget_2->addTab(tab_4, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget_4 = new QTabWidget(tab_7);
        tabWidget_4->setObjectName(QString::fromUtf8("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(30, 10, 791, 441));
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tableView_3 = new QTableView(tab_8);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(10, 70, 761, 281));
        pushButton_11 = new QPushButton(tab_8);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(670, 360, 41, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/modify.png);"));
        supp_equip = new QPushButton(tab_8);
        supp_equip->setObjectName(QString::fromUtf8("supp_equip"));
        supp_equip->setGeometry(QRect(730, 360, 41, 41));
        supp_equip->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/delete.png);"));
        recherche_3 = new QLineEdit(tab_8);
        recherche_3->setObjectName(QString::fromUtf8("recherche_3"));
        recherche_3->setGeometry(QRect(10, 20, 241, 21));
        label_24 = new QLabel(tab_8);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(260, 20, 31, 21));
        label_24->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/search.png);"));
        label_28 = new QLabel(tab_8);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(330, -20, 121, 111));
        label_28->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        tabWidget_4->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        groupBox = new QGroupBox(tab_9);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 541, 281));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(170, 130, 111, 17));
        checkBox->setFont(font2);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 30, 101, 16));
        label_15->setFont(font);
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 60, 47, 16));
        label_16->setFont(font);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 30, 231, 21));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 130, 91, 16));
        label_17->setFont(font);
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(170, 60, 231, 22));
        type_equip = new QLineEdit(groupBox);
        type_equip->setObjectName(QString::fromUtf8("type_equip"));
        type_equip->setGeometry(QRect(170, 90, 231, 20));
        ajouterequip = new QPushButton(tab_9);
        ajouterequip->setObjectName(QString::fromUtf8("ajouterequip"));
        ajouterequip->setGeometry(QRect(680, 310, 41, 41));
        ajouterequip->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/add.png);"));
        label_32 = new QLabel(tab_9);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(610, 0, 171, 141));
        label_32->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        tabWidget_4->addTab(tab_9, QString());
        tabWidget_2->addTab(tab_7, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        tabWidget_5 = new QTabWidget(tab_10);
        tabWidget_5->setObjectName(QString::fromUtf8("tabWidget_5"));
        tabWidget_5->setGeometry(QRect(30, 10, 791, 441));
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        pushButton_9 = new QPushButton(tab_11);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(670, 360, 41, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/modify.png);"));
        supp_liv = new QPushButton(tab_11);
        supp_liv->setObjectName(QString::fromUtf8("supp_liv"));
        supp_liv->setGeometry(QRect(730, 360, 41, 41));
        supp_liv->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/delete.png);"));
        tableView_4 = new QTableView(tab_11);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setGeometry(QRect(10, 70, 761, 281));
        recherche_4 = new QLineEdit(tab_11);
        recherche_4->setObjectName(QString::fromUtf8("recherche_4"));
        recherche_4->setGeometry(QRect(10, 20, 241, 21));
        label_25 = new QLabel(tab_11);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(260, 20, 31, 21));
        label_25->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/search.png);"));
        label_29 = new QLabel(tab_11);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(330, -20, 121, 111));
        label_29->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        tabWidget_5->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        ajouterliv = new QPushButton(tab_12);
        ajouterliv->setObjectName(QString::fromUtf8("ajouterliv"));
        ajouterliv->setGeometry(QRect(680, 310, 41, 41));
        ajouterliv->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/add.png);"));
        groupBox_4 = new QGroupBox(tab_12);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 30, 571, 281));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 130, 131, 16));
        label_20->setFont(font);
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 100, 121, 16));
        label_19->setFont(font);
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 40, 101, 16));
        label_21->setFont(font);
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 70, 47, 13));
        label_18->setFont(font);
        comboBox = new QComboBox(groupBox_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 70, 231, 22));
        comboBox_2 = new QComboBox(groupBox_4);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(170, 100, 231, 22));
        lineEdit_idliv = new QLineEdit(groupBox_4);
        lineEdit_idliv->setObjectName(QString::fromUtf8("lineEdit_idliv"));
        lineEdit_idliv->setGeometry(QRect(170, 40, 231, 20));
        dateTimeEdit = new QDateEdit(groupBox_4);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(170, 130, 231, 22));
        label_33 = new QLabel(tab_12);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(610, 0, 171, 141));
        label_33->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/avatar.png);"));
        tabWidget_5->addTab(tab_12, QString());
        tabWidget_2->addTab(tab_10, QString());
        Gestion_Coli_Courrier->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gestion_Coli_Courrier);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 862, 21));
        Gestion_Coli_Courrier->setMenuBar(menubar);
        statusbar = new QStatusBar(Gestion_Coli_Courrier);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Gestion_Coli_Courrier->setStatusBar(statusbar);

        retranslateUi(Gestion_Coli_Courrier);

        tabWidget_2->setCurrentIndex(0);
        loadcoli->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_4->setCurrentIndex(0);
        tabWidget_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Gestion_Coli_Courrier);
    } // setupUi

    void retranslateUi(QMainWindow *Gestion_Coli_Courrier)
    {
        Gestion_Coli_Courrier->setWindowTitle(QCoreApplication::translate("Gestion_Coli_Courrier", "Gestion_Coli_Courrier", nullptr));
        suppcoli->setText(QString());
        Modifiercoli->setText(QString());
        recherche->setText(QString());
        recherche->setPlaceholderText(QCoreApplication::translate("Gestion_Coli_Courrier", "Rechercher", nullptr));
        tri_coli->setText(QString());
        checkBox_2->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "D\303\251croissant", nullptr));
        label_22->setText(QString());
        label_26->setText(QString());
        comboBox_4->setItemText(0, QCoreApplication::translate("Gestion_Coli_Courrier", "IDCOLI", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Gestion_Coli_Courrier", "ADRESSEEM", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("Gestion_Coli_Courrier", "ADRESSEDEST", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("Gestion_Coli_Courrier", "PRIORITE", nullptr));
        comboBox_4->setItemText(4, QCoreApplication::translate("Gestion_Coli_Courrier", "POIDS", nullptr));
        comboBox_4->setItemText(5, QCoreApplication::translate("Gestion_Coli_Courrier", "PRIX", nullptr));
        comboBox_4->setItemText(6, QCoreApplication::translate("Gestion_Coli_Courrier", "ETAT", nullptr));
        comboBox_4->setItemText(7, QCoreApplication::translate("Gestion_Coli_Courrier", "AVECLIV", nullptr));

        EXCEL1->setText(QString());
        stat1->setText(QString());
        loadcoli->setTabText(loadcoli->indexOf(tab), QCoreApplication::translate("Gestion_Coli_Courrier", "Dashboard", nullptr));
        groupBox_2->setTitle(QString());
        label_3->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Adresse destinataire</span></p></body></html>", nullptr));
        Poids->setPlaceholderText(QCoreApplication::translate("Gestion_Coli_Courrier", "Veuillez saisir le poid en G", nullptr));
        label_4->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Priorit\303\251</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Poids</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#000000;\">Prix</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">ID coli</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Etat</span></p></body></html>", nullptr));
        Avecliv->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "Avec livraison", nullptr));
        label_2->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" color:#000000;\">Adresse emetteur</span></p></body></html>", nullptr));
        Prix->setPlaceholderText(QCoreApplication::translate("Gestion_Coli_Courrier", "Veuillez saisir le prix en Millime", nullptr));
        ajoutercoli->setText(QString());
        label_30->setText(QString());
        loadcoli->setTabText(loadcoli->indexOf(tab_2), QCoreApplication::translate("Gestion_Coli_Courrier", "Ajouter Coli", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("Gestion_Coli_Courrier", "Gestion des colis", nullptr));
        ModifierCourrier->setText(QString());
        suppcourrier->setText(QString());
        tri_coli_2->setText(QString());
        checkBox_3->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "D\303\251croissant", nullptr));
        recherche_2->setPlaceholderText(QCoreApplication::translate("Gestion_Coli_Courrier", "Rechercher", nullptr));
        label_23->setText(QString());
        label_27->setText(QString());
        comboBox_5->setItemText(0, QCoreApplication::translate("Gestion_Coli_Courrier", "IDCOURRIER", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("Gestion_Coli_Courrier", "TYPE", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("Gestion_Coli_Courrier", "ADRESSEEM", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("Gestion_Coli_Courrier", "ADRESSEDEST", nullptr));
        comboBox_5->setItemText(4, QCoreApplication::translate("Gestion_Coli_Courrier", "PRIORITE", nullptr));
        comboBox_5->setItemText(5, QCoreApplication::translate("Gestion_Coli_Courrier", "PRIX", nullptr));
        comboBox_5->setItemText(6, QCoreApplication::translate("Gestion_Coli_Courrier", "ETAT", nullptr));

        EXCEL_2->setText(QString());
        stat2->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QCoreApplication::translate("Gestion_Coli_Courrier", "Dashboard", nullptr));
        groupBox_3->setTitle(QString());
        label_14->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Prix</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Adresse emetteur</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Priorit\303\251</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Etat</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Adresse destinataire</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt;\">ID courrier</span></p></body></html>", nullptr));
        prix_2->setPlaceholderText(QCoreApplication::translate("Gestion_Coli_Courrier", "Veuillez saisir le prix en Millime", nullptr));
        label_12->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Type</span></p></body></html>", nullptr));
        ajoutercourrier->setText(QString());
        label_31->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QCoreApplication::translate("Gestion_Coli_Courrier", "Ajouter Courrier", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("Gestion_Coli_Courrier", "Gestion des courriers", nullptr));
        pushButton_11->setText(QString());
        supp_equip->setText(QString());
        recherche_3->setText(QString());
        recherche_3->setPlaceholderText(QCoreApplication::translate("Gestion_Coli_Courrier", "Rechercher", nullptr));
        label_24->setText(QString());
        label_28->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_8), QCoreApplication::translate("Gestion_Coli_Courrier", "Dashboard", nullptr));
        groupBox->setTitle(QString());
        checkBox->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "Disponible", nullptr));
        label_15->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">ID \303\251quipement</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Type</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">D\303\251sponibilit\303\251</span></p></body></html>", nullptr));
        ajouterequip->setText(QString());
        label_32->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QCoreApplication::translate("Gestion_Coli_Courrier", "Ajouter un \303\251quipement", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("Gestion_Coli_Courrier", "Gestion des \303\251quipements", nullptr));
        pushButton_9->setText(QString());
        supp_liv->setText(QString());
        recherche_4->setText(QString());
        recherche_4->setPlaceholderText(QCoreApplication::translate("Gestion_Coli_Courrier", "Rechercher", nullptr));
        label_25->setText(QString());
        label_29->setText(QString());
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_11), QCoreApplication::translate("Gestion_Coli_Courrier", "Dashboard", nullptr));
        ajouterliv->setText(QString());
        groupBox_4->setTitle(QString());
        label_20->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Date de la livraison</span></p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">ID Equipement</span></p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">ID Livraison</span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("Gestion_Coli_Courrier", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">ID Coli</span></p></body></html>", nullptr));
        label_33->setText(QString());
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_12), QCoreApplication::translate("Gestion_Coli_Courrier", "Ajouter une livraison", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QCoreApplication::translate("Gestion_Coli_Courrier", "Livraison", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gestion_Coli_Courrier: public Ui_Gestion_Coli_Courrier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_COLI_COURRIER_H
