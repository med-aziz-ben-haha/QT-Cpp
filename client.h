#ifndef CLIENT_H
#define CLIENT_H
#include <QVector>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtWidgets/QMainWindow>
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
#include <QtWidgets/QGridLayout>
QT_CHARTS_USE_NAMESPACE
class Client
{public:
    Client();
    Client(int,QString,QString,QString,QString,int,int,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QString get_adresse();
    QString get_mail();
    int get_tel();
    int get_nbp();
    int get_cin();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString ,QString,int,int,int);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * trier(const QString &critere, const QString &mode );
    bool modif1(QString arg,int id_client,QString attribut);
    bool modif2(QString arg,int id_client,int attribut);
    bool supp(QString arg,int id_client);
    QSqlQueryModel * afficherid();
private:
    QString nom,prenom,adresse,mail;
    int idclient,tel,nbp,cin;
};

#endif // CLIENT_H
