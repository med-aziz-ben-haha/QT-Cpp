#ifndef GESTION_CLIENT_H
#define GESTION_CLIENT_H
#include "client.h"
#include "reclamation.h"
#include "cadeau.h"
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class gestionclient;
}
QT_END_NAMESPACE
class gestionclient : public QDialog
{
    Q_OBJECT

public:
    explicit gestionclient(QWidget *parent = nullptr);
    ~gestionclient();
QChartView *chartView ;
private slots:
    void on_pb_ajouter_clicked();
void on_pb_modifier_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_ajouter_2_clicked();
void on_pb_modifier_2_clicked();
    void on_pb_supprimer_2_clicked();
    void on_rechercher_clicked();
    void on_rechercher_2_clicked();
    void on_lineEdit_6_selectionChanged();
    void on_trier_clicked();
    void on_trier_2_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pushButton_7_clicked();
    void on_pushButton_afficher_clicked();

    void on_pushButton_affecter_clicked();
    void on_pushButton_4_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void sendMail();
    void mailSent(QString) ;
    void on_Envoyer_clicked();

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_trier_3_clicked();
    void  stat();


    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::gestionclient *ui;
    Client tmpclient;
    Reclamation tmpreclamation;
    cadeau tmpcadeau;
};

#endif // GESTION_CLIENT_H
