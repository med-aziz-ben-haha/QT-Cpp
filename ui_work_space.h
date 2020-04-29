/********************************************************************************
** Form generated from reading UI file 'work_space.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORK_SPACE_H
#define UI_WORK_SPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_work_space
{
public:
    QAction *actionajouter;
    QAction *actionsupprimer;
    QAction *actiondeconnecter;
    QAction *actionAccepter_cong;
    QAction *actionsupprimer_cong;
    QAction *actionopen_music;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *import_excel;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *tab_2;
    QTableView *tabdemande;
    QTableView *tabaccept;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *supp_conge;
    QPushButton *ajout_conge;
    QWidget *tab_3;
    QLineEdit *lineEdit_3;
    QTableView *tabdemande_rh;
    QTableView *tabaccept_rh;
    QLineEdit *lineEdit_4;
    QLabel *demandes_rh;
    QLabel *courrants_rh;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_8;
    QPushButton *stat_courrant;
    QPushButton *stat_demande;
    QWidget *tab_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *tab_5;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QLineEdit *file;
    QPushButton *browseBtn;
    QTextEdit *msg;
    QPushButton *sendBtn;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *work_space)
    {
        if (work_space->objectName().isEmpty())
            work_space->setObjectName(QString::fromUtf8("work_space"));
        work_space->resize(739, 541);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        work_space->setFont(font);
        actionajouter = new QAction(work_space);
        actionajouter->setObjectName(QString::fromUtf8("actionajouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/img/user-add-icon---shine-set-add-new-user-add-user-30.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionajouter->setIcon(icon);
        actionsupprimer = new QAction(work_space);
        actionsupprimer->setObjectName(QString::fromUtf8("actionsupprimer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/img/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsupprimer->setIcon(icon1);
        actiondeconnecter = new QAction(work_space);
        actiondeconnecter->setObjectName(QString::fromUtf8("actiondeconnecter"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/img/Windows-Log-Off-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiondeconnecter->setIcon(icon2);
        actionAccepter_cong = new QAction(work_space);
        actionAccepter_cong->setObjectName(QString::fromUtf8("actionAccepter_cong"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/img/Add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAccepter_cong->setIcon(icon3);
        actionsupprimer_cong = new QAction(work_space);
        actionsupprimer_cong->setObjectName(QString::fromUtf8("actionsupprimer_cong"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/img/delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsupprimer_cong->setIcon(icon4);
        actionopen_music = new QAction(work_space);
        actionopen_music->setObjectName(QString::fromUtf8("actionopen_music"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/img/unnamed (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen_music->setIcon(icon5);
        actionopen_music->setVisible(true);
        centralwidget = new QWidget(work_space);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 711, 461));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(480, 30, 191, 24));
        lineEdit->setClearButtonEnabled(true);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 420, 591, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        import_excel = new QPushButton(layoutWidget);
        import_excel->setObjectName(QString::fromUtf8("import_excel"));

        horizontalLayout->addWidget(import_excel);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(132, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 71, 651, 331));
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView->horizontalHeader()->setStretchLastSection(false);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 201, 31));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 30, 24, 24));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/res/img/unnamed.png);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabdemande = new QTableView(tab_2);
        tabdemande->setObjectName(QString::fromUtf8("tabdemande"));
        tabdemande->setGeometry(QRect(20, 70, 651, 161));
        tabdemande->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tabdemande->setSortingEnabled(true);
        tabdemande->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabaccept = new QTableView(tab_2);
        tabaccept->setObjectName(QString::fromUtf8("tabaccept"));
        tabaccept->setGeometry(QRect(20, 280, 651, 151));
        tabaccept->setSortingEnabled(true);
        tabaccept->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 240, 271, 31));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 30, 191, 31));
        supp_conge = new QPushButton(tab_2);
        supp_conge->setObjectName(QString::fromUtf8("supp_conge"));
        supp_conge->setGeometry(QRect(590, 40, 75, 23));
        ajout_conge = new QPushButton(tab_2);
        ajout_conge->setObjectName(QString::fromUtf8("ajout_conge"));
        ajout_conge->setGeometry(QRect(510, 40, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(510, 20, 161, 24));
        tabdemande_rh = new QTableView(tab_3);
        tabdemande_rh->setObjectName(QString::fromUtf8("tabdemande_rh"));
        tabdemande_rh->setGeometry(QRect(20, 50, 651, 161));
        tabdemande_rh->setSortingEnabled(true);
        tabdemande_rh->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabaccept_rh = new QTableView(tab_3);
        tabaccept_rh->setObjectName(QString::fromUtf8("tabaccept_rh"));
        tabaccept_rh->setGeometry(QRect(20, 260, 651, 151));
        tabaccept_rh->setSortingEnabled(true);
        tabaccept_rh->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(510, 230, 161, 24));
        demandes_rh = new QLabel(tab_3);
        demandes_rh->setObjectName(QString::fromUtf8("demandes_rh"));
        demandes_rh->setGeometry(QRect(30, 10, 191, 31));
        courrants_rh = new QLabel(tab_3);
        courrants_rh->setObjectName(QString::fromUtf8("courrants_rh"));
        courrants_rh->setGeometry(QRect(30, 220, 141, 31));
        layoutWidget_2 = new QWidget(tab_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 430, 591, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_6 = new QPushButton(layoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_2->addWidget(pushButton_7);

        horizontalSpacer_4 = new QSpacerItem(132, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_8 = new QPushButton(layoutWidget_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);

        stat_courrant = new QPushButton(tab_3);
        stat_courrant->setObjectName(QString::fromUtf8("stat_courrant"));
        stat_courrant->setGeometry(QRect(480, 230, 24, 24));
        stat_courrant->setStyleSheet(QString::fromUtf8("background-image: url(:/res/img/unnamed.png);"));
        stat_demande = new QPushButton(tab_3);
        stat_demande->setObjectName(QString::fromUtf8("stat_demande"));
        stat_demande->setEnabled(true);
        stat_demande->setGeometry(QRect(480, 20, 24, 24));
        stat_demande->setContextMenuPolicy(Qt::NoContextMenu);
        stat_demande->setAutoFillBackground(false);
        stat_demande->setStyleSheet(QString::fromUtf8("background-image: url(:/res/img/unnamed.png);"));
        stat_demande->setIconSize(QSize(21, 21));
        stat_demande->setAutoDefault(true);
        stat_demande->setFlat(false);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        layoutWidget1 = new QWidget(tab_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(17, 10, 651, 441));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(textEdit);

        listWidget = new QListWidget(layoutWidget1);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(180, 16777215));
        listWidget->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_4->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        rcpt = new QLineEdit(tab_5);
        rcpt->setObjectName(QString::fromUtf8("rcpt"));
        rcpt->setGeometry(QRect(20, 20, 651, 20));
        subject = new QLineEdit(tab_5);
        subject->setObjectName(QString::fromUtf8("subject"));
        subject->setGeometry(QRect(20, 54, 651, 20));
        file = new QLineEdit(tab_5);
        file->setObjectName(QString::fromUtf8("file"));
        file->setGeometry(QRect(20, 90, 571, 23));
        browseBtn = new QPushButton(tab_5);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));
        browseBtn->setGeometry(QRect(597, 89, 75, 24));
        msg = new QTextEdit(tab_5);
        msg->setObjectName(QString::fromUtf8("msg"));
        msg->setGeometry(QRect(20, 126, 651, 291));
        sendBtn = new QPushButton(tab_5);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(20, 420, 651, 23));
        tabWidget->addTab(tab_5, QString());
        work_space->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(work_space);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("border-top-color: rgb(0, 0, 0);\n"
"color: rgb(0, 170, 0);"));
        work_space->setStatusBar(statusBar);
        toolBar = new QToolBar(work_space);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        work_space->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionajouter);
        toolBar->addAction(actionsupprimer);
        toolBar->addSeparator();
        toolBar->addAction(actionAccepter_cong);
        toolBar->addAction(actionsupprimer_cong);
        toolBar->addSeparator();
        toolBar->addAction(actionopen_music);
        toolBar->addAction(actiondeconnecter);

        retranslateUi(work_space);

        tabWidget->setCurrentIndex(0);
        stat_demande->setDefault(false);


        QMetaObject::connectSlotsByName(work_space);
    } // setupUi

    void retranslateUi(QMainWindow *work_space)
    {
        work_space->setWindowTitle(QCoreApplication::translate("work_space", "MainWindow", nullptr));
        actionajouter->setText(QCoreApplication::translate("work_space", "ajouter employ\303\251", nullptr));
#if QT_CONFIG(shortcut)
        actionajouter->setShortcut(QCoreApplication::translate("work_space", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsupprimer->setText(QCoreApplication::translate("work_space", "supprimer", nullptr));
#if QT_CONFIG(shortcut)
        actionsupprimer->setShortcut(QCoreApplication::translate("work_space", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actiondeconnecter->setText(QCoreApplication::translate("work_space", "Se deconnecter", nullptr));
#if QT_CONFIG(tooltip)
        actiondeconnecter->setToolTip(QCoreApplication::translate("work_space", "deconnecter", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actiondeconnecter->setShortcut(QCoreApplication::translate("work_space", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAccepter_cong->setText(QCoreApplication::translate("work_space", "Accepter cong\303\251", nullptr));
#if QT_CONFIG(tooltip)
        actionAccepter_cong->setToolTip(QCoreApplication::translate("work_space", "Accepter cong\303\251", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAccepter_cong->setShortcut(QCoreApplication::translate("work_space", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsupprimer_cong->setText(QCoreApplication::translate("work_space", "supprimer cong\303\251", nullptr));
#if QT_CONFIG(tooltip)
        actionsupprimer_cong->setToolTip(QCoreApplication::translate("work_space", "supprimer cong\303\251", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionsupprimer_cong->setShortcut(QCoreApplication::translate("work_space", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionopen_music->setText(QCoreApplication::translate("work_space", "open_music", nullptr));
#if QT_CONFIG(tooltip)
        actionopen_music->setToolTip(QCoreApplication::translate("work_space", "open_music", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionopen_music->setShortcut(QCoreApplication::translate("work_space", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        lineEdit->setPlaceholderText(QCoreApplication::translate("work_space", "Recherche", nullptr));
        import_excel->setText(QCoreApplication::translate("work_space", "Importer Excel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("work_space", "Exporter  Excel", nullptr));
        pushButton_4->setText(QCoreApplication::translate("work_space", "Imprimer", nullptr));
        label->setText(QCoreApplication::translate("work_space", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">Liste Employes</span></p></body></html>", nullptr));
        pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("work_space", "Employ\303\251s", nullptr));
        label_3->setText(QCoreApplication::translate("work_space", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">Demandes accept\303\251es</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("work_space", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">Mes demandes</span></p></body></html>", nullptr));
        supp_conge->setText(QCoreApplication::translate("work_space", "supprimer", nullptr));
        ajout_conge->setText(QCoreApplication::translate("work_space", "ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("work_space", "Mes demandes et cong\303\251s", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("work_space", "Recherche", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("work_space", "Recherche", nullptr));
        demandes_rh->setText(QCoreApplication::translate("work_space", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">Demandes</span></p></body></html>", nullptr));
        courrants_rh->setText(QCoreApplication::translate("work_space", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">Courrants</span></p></body></html>", nullptr));
        pushButton_6->setText(QCoreApplication::translate("work_space", "Exporter  PDF", nullptr));
        pushButton_7->setText(QCoreApplication::translate("work_space", "Exporter  Excel", nullptr));
        pushButton_8->setText(QCoreApplication::translate("work_space", "Imprimer", nullptr));
        stat_courrant->setText(QString());
        stat_demande->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("work_space", "G\303\251rer les cong\303\251s", nullptr));
        label_2->setText(QCoreApplication::translate("work_space", "Message:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("work_space", "Local Chat", nullptr));
        rcpt->setPlaceholderText(QCoreApplication::translate("work_space", "recipient", nullptr));
        subject->setPlaceholderText(QCoreApplication::translate("work_space", "subject", nullptr));
        file->setPlaceholderText(QCoreApplication::translate("work_space", "attachement here", nullptr));
        browseBtn->setText(QCoreApplication::translate("work_space", "Browse ...", nullptr));
        msg->setPlaceholderText(QCoreApplication::translate("work_space", "type your message here ...", nullptr));
        sendBtn->setText(QCoreApplication::translate("work_space", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("work_space", "E-mail", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("work_space", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class work_space: public Ui_work_space {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORK_SPACE_H
