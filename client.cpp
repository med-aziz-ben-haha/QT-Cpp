#include "client.h"
#include <QDebug>
#include "conx.h"
#include <QVector>
#include "QWindow"
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
Client::Client()
{
idclient=0;
nom="";
prenom="";
adresse="";
mail="";
tel=0;
nbp=0;
cin=0;
}
Client::Client(int idclient,QString nom,QString prenom,QString adresse,QString mail,int tel,int nbp,int cin)
{
  this->idclient=idclient;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->mail=mail;
  this->tel=tel;
  this->nbp=nbp;
  this->cin=cin;
}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_id(){return  idclient;}
QString Client::get_adresse(){return adresse;}
QString Client::get_mail(){return mail;}
int Client::get_tel(){return tel;}
int Client::get_nbp(){return nbp;}
int Client::get_cin(){return cin;}
bool Client::ajouter()
{
QSqlQuery query;
QString res= QString::number(idclient);
query.prepare("INSERT INTO Client (IDCLIENT, NOM, PRENOM,ADRESSE,MAIL,TEL,NBP,CIN) "
                    "VALUES (:idclient, :nom, :prenom, :adresse, :mail, :tel, :nbp, :cin)");
query.bindValue(":idclient", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":mail", mail);
query.bindValue(":tel", tel);
query.bindValue(":nbp", nbp);
query.bindValue(":cin", cin);
return    query.exec();
}

QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-mail"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Téléphone"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nombre de points"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

bool Client::modifier(int id_client,QString nom,QString prenom,QString adresse,QString mail,int tel,int nbp,int cin)
{

    QSqlQuery qry;
        qry.prepare("UPDATE client set NOM=(?),PRENOM=(?),ADRESSE=(?),MAIL=(?),TEL=(?),NBP=(?),CIN=(?) where IDCLIENT=(?) ");
        qry.addBindValue(nom);
        qry.addBindValue(prenom);
        qry.addBindValue(adresse);
        qry.addBindValue(mail);
        qry.addBindValue(tel);
        qry.addBindValue(nbp);
        qry.addBindValue(cin);
        qry.addBindValue(id_client);
   return  qry.exec();
}

bool Client::modif1(QString arg,int id_client,QString attribut)
{

    QSqlQuery qry;
        qry.prepare("UPDATE client set "+arg+"=(?) where IDCLIENT=(?) ");
        qDebug()<<attribut;
        qDebug()<<arg;
        qDebug()<<id_client;
        qry.addBindValue(attribut);
        qry.addBindValue(id_client);

   return  qry.exec();
}

/*bool Client::modif2(QString arg,int id_client,int attribut)
{

    QSqlQuery qry;
        qry.prepare("UPDATE client set '"+attribut+"'=(?) where IDCLIENT=(?) ");
        qry.addBindValue(arg);
        qry.addBindValue(id_client);
   return  qry.exec();
}
*/

bool Client::supp(QString arg,int id_client)
{

    QSqlQuery qry;
        qry.prepare("UPDATE client set "+arg+"=NULL where IDCLIENT=(?) ");
        qDebug()<<arg;
        qDebug()<<id_client;
        qry.addBindValue(id_client);

   return  qry.exec();
}

bool Client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Client where IDCLIENT = :idclient ");
query.bindValue(":idclient", res);
return    query.exec();
}

QSqlQueryModel * Client::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from client where (IDCLIENT LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nombre de points"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

QSqlQueryModel *  Client::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from client order by "+critere+" "+mode+"");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-mail"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Téléphone"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nombre de points"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

QSqlQueryModel * Client::afficherid()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select IDCLIENT from client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT"));
    return model;
}


