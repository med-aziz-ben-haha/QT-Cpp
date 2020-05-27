#ifndef CADEAU_H
#define CADEAU_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVector>
#include <QApplication>
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
class cadeau
{
public:
    cadeau();
    cadeau(int,QString,QString,int);
    QString get_nomcadeau();
    QString get_type();
    int get_idcadeau();
    int get_points();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * afficherid();
    QSqlQueryModel * trier(const QString &critere, const QString &mode );
private:
    QString type,nomcadeau;
    int idcadeau,points;
};

#endif // CADEAU_H
