#ifndef WORK_SPACE_H
#define WORK_SPACE_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "conge.h"
#include "connexion.h"
#include "conge.h"

#include "stat_cong.h"
#include "stat_emp.h"
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include "mytestmodel.h"
#include "smtp.h"
#include "client.h"
#include <QTextTableFormat>
#include <QTextToSpeech>

#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class work_space;
}

class work_space : public QMainWindow
{
    Q_OBJECT

public:
    explicit work_space(QWidget *parent = nullptr);
    ~work_space();
QSortFilterProxyModel *proxy_emp,*proxy_cong_emp,*proxy_cong_rh,*proxy_cong_accept_emp,*proxy_cong_accept_rh;
Connexion conn;
QTimer *timer;
QTimer *chrono;
int heure_tr=0,mm=0,ss=50,extra=0,heure_stand=0;
 QString emp;
int conge_rest=0,duree=0;
public slots:
void show_tables();
void work_counter();



public slots:
    void appendMessage(const QString &from, const QString &message);


private slots:

    void on_actionajouter_triggered();
    void on_actionsupprimer_triggered();
    void on_actionAccepter_cong_triggered();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_ajout_conge_clicked();
    void on_tabdemande_rh_pressed(const QModelIndex &index);
    void on_actionsupprimer_cong_triggered();
    void on_supp_conge_clicked();
    void on_tabdemande_pressed(const QModelIndex &index);
    void on_actiondeconnecter_triggered();
    void on_tabdemande_doubleClicked();
    void on_tabdemande_rh_doubleClicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_stat_courrant_clicked();
    void on_stat_demande_clicked();
    void on_pushButton_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_3_clicked();

    void chat();
    void returnPressed();
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);
    void show_chat();

    void sendMail();
       void mailSent(QString);
       void browse();

       void on_import_excel_clicked();



       void on_actionopen_music_triggered();

private:
Ui::work_space *ui;
    conge tmp_con;
stat_cong  *ws;
stat_emp *se;
   QStandardItemModel *model;
Client client;
QString myNickName;
    QTextTableFormat tableFormat;

    QStringList files;

       QTextToSpeech *m_speech;
};

#endif // WORK_SPACE_H
