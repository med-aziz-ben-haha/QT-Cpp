#include "carte_ce.h"

#include <QDebug>

carte_ce::carte_ce()
{
num_carte=0;
solde=0;
type="";
RIB="";



}
carte_ce::carte_ce(int num_carte,int solde,QString type,QDate date_fin,QDate date_debut,QString RIB)
{
  this->num_carte=num_carte;
    this->solde=solde;
  this->type=type;
  this->date_debut=date_debut;
    this->date_fin=date_fin;
this->RIB=RIB;
}
int carte_ce::get_num_carte(){return  num_carte;}
int carte_ce::get_solde(){return solde;}
QString carte_ce::get_type(){return  type;}
QString carte_ce::get_RIB(){return  RIB;}

QSqlQueryModel * carte_ce::afficher()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from carte_ce   ");

        return model;

}
bool carte_ce::ajout()
{
QSqlQuery query;
QString res= QString::number(num_carte);
QString res1= QString::number(solde);
QString res0= (type);
QDate res2= (date_debut);
QDate res3=(date_fin);
QString resz= (RIB);
query.prepare("INSERT INTO CARTE_CE (NUM_CARTE,SOLDE,TYPE,DATE_DEBUT,DATE_FIN,RIB) "
                    "VALUES (:num_carte,:solde,:type,:date_debut,:date_fin,:RIB)");
query.bindValue(":num_carte", res);
query.bindValue(":solde", res1);
query.bindValue(":type", res0);
query.bindValue(":date_debut", res2);
query.bindValue(":date_fin", res3);
query.bindValue(":RIB", resz);
return    query.exec();
}

bool carte_ce::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from carte_ce where NUM_CARTE = :num_carte ");
query.bindValue(":num_carte", res);
return    query.exec();
}

bool carte_ce::ajouter(QString &res,int ss)
{int final;
QSqlQuery query;
QSqlQuery query1;

//while (query.next())int solde=query.value(3).toInt();
query1.prepare("select * from carte_ce where(NUM_CARTE LIKE '"+res+"%') ");
query1.exec();
while (query1.next()) solde=query1.value(3).toInt();
final=solde+ss;
QString ses= QString::number(final);

query.prepare("update carte_ce set solde="+ses+" where (NUM_CARTE LIKE '"+res+"%')");


query.bindValue(":solde", ses);

return    query.exec();
}
bool carte_ce::retirer(QString &res,int ss)
{int final;
QSqlQuery query;
QSqlQuery query1;

//while (query.next())int solde=query.value(3).toInt();
query1.prepare("select * from carte_ce where(NUM_CARTE LIKE '"+res+"%') ");
query1.exec();
while (query1.next()) solde=query1.value(3).toInt();
final=solde-ss;
QString ses= QString::number(final);

query.prepare("update carte_ce set solde="+ses+" where (NUM_CARTE LIKE '"+res+"%')");


query.bindValue(":solde", ses);

return    query.exec();
}
QSqlQueryModel * carte_ce::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from carte_ce where (NUM_CARTE LIKE '"+id+"%')");


    return model;
}

QSqlQueryModel *  carte_ce::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from carte_ce order by "+critere+" "+mode+"");


    return model;
}
