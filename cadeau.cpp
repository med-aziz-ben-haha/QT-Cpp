#include "cadeau.h"
#include <QDebug>
#include "conx.h"
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
cadeau::cadeau()
{
    idcadeau=0;
    type="";
    nomcadeau="";
    points=0;
}
cadeau::cadeau(int idcadeau,QString type,QString nomcadeau,int points)
{
  this->idcadeau=idcadeau;
  this->type=type;
  this->nomcadeau=nomcadeau;
  this->points=points;
}
QString cadeau::get_type(){return type;}
QString cadeau::get_nomcadeau(){return  nomcadeau;}
int cadeau::get_idcadeau(){return  idcadeau;}
int cadeau::get_points(){return points;}
bool cadeau::ajouter()
{
QSqlQuery query;
QString res= QString::number(idcadeau);
query.prepare("INSERT INTO cadeau (IDCADEAU, TYPE, NOMCADEAU, POINTS) "
                    "VALUES (:idcadeau, :type, :nomcadeau, :points)");
query.bindValue(":idcadeau", res);
query.bindValue(":type", type);
query.bindValue(":nomcadeau", nomcadeau);
query.bindValue(":points", points);
return    query.exec();
}

QSqlQueryModel * cadeau::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from cadeau");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre de points"));
    return model;
}

bool cadeau::modifier(int id_cadeau,QString type,QString nomcadeau,int points)
{

    QSqlQuery qry;
        qry.prepare("UPDATE cadeau set TYPE=(?),NOMCADEAU=(?),POINTS=(?) where IDCADEAU=(?) ");
        qry.addBindValue(type);
        qry.addBindValue(nomcadeau);
        qry.addBindValue(points);
        qry.addBindValue(id_cadeau);
   return  qry.exec();
}
bool cadeau::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from cadeau where IDCADEAU = :idcadeau ");
query.bindValue(":idcadeau", res);
return    query.exec();
}

QSqlQueryModel * cadeau::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from cadeau where (cadeau LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre de points"));

    return model;
}
QSqlQueryModel * cadeau::afficherid()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select IDCADEAU from cadeau");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCADEAU"));
    return model;
}

QSqlQueryModel *  cadeau::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from cadeau order by "+critere+" "+mode+"");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre de points"));
    return model;
}

