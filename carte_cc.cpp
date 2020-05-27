#include "carte_cc.h"
#include <QDebug>

carte_cc::carte_cc()
{
num_carte=0;
solde=0;
type="";
RIB="";

code_conf="";
code_int="";

}
carte_cc::carte_cc(int num_carte,int solde,QString type,QDate date_fin,QDate date_debut,QString code_conf,QString code_int,QString RIB)
{
  this->num_carte=num_carte;
    this->solde=solde;
  this->type=type;
    this->RIB=RIB;
  this->date_debut=date_debut;
    this->date_fin=date_fin;
    this->code_conf=code_conf;
    this->code_int=code_int;
}
int carte_cc::get_num_carte(){return  num_carte;}
int carte_cc::get_solde(){return solde;}
QString carte_cc::get_type(){return  type;}
QString carte_cc::get_RIB(){return  RIB;}
QString carte_cc::get_code_conf(){return code_conf;}
QString carte_cc::get_code_int(){return code_int;}

QSqlQueryModel * carte_cc::afficher()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from carte_cc   ");

        return model;

}
bool carte_cc::ajout()
{
QSqlQuery query;
QString res= QString::number(num_carte);
QString res1= QString::number(solde);
QString res0= (type);
QDate res2= (date_debut);
QDate res3=(date_fin);
QString res4=(code_conf);
QString res5=(code_int);
QString ress=(RIB);
query.prepare("INSERT INTO CARTE_CC (NUM_CARTE,SOLDE,TYPE,DATE_DEBUT,DATE_FIN,CODE_CONF,CODE_INT,RIB) "
                    "VALUES (:num_carte,:solde,:type,:date_debut,:date_fin,:code_conf,:code_int,:RIB)");
query.bindValue(":num_carte", res);
query.bindValue(":solde", res1);
query.bindValue(":type", res0);
query.bindValue(":date_debut", res2);
query.bindValue(":date_fin", res3);
query.bindValue(":code_conf", res4);
query.bindValue(":code_int", res5);
query.bindValue(":RIB", ress);
return    query.exec();
}

bool carte_cc::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from carte_cc where NUM_CARTE = :num_carte ");
query.bindValue(":num_carte", res);
return    query.exec();
}

bool carte_cc::ajouter(QString &res,int ss)
{int final;
QSqlQuery query;
QSqlQuery query1;

//while (query.next())int solde=query.value(3).toInt();
query1.prepare("select * from carte_cc where NUM_CARTE LIKE '"+res+"%' ");
query1.exec();
while (query1.next()) solde=query1.value(3).toInt();
qDebug() <<solde;
final=solde+ss;

QString ses= QString::number(final);

query.prepare("update carte_cc set solde="+ses+" where NUM_CARTE LIKE '"+res+"%'");


query.bindValue(":solde", ses);

return    query.exec();
}
bool carte_cc::retirer(QString &res,int ss)
{int final;
QSqlQuery query;
QSqlQuery query1;

//while (query.next())int solde=query.value(3).toInt();
query1.prepare("select * from carte_cc where(NUM_CARTE LIKE '"+res+"%') ");
query1.exec();
while (query1.next()) solde=query1.value(3).toInt();
final=solde-ss;
QString ses= QString::number(final);

query.prepare("update carte_cc set solde="+ses+" where (NUM_CARTE LIKE '"+res+"%')");


query.bindValue(":solde", ses);

return    query.exec();
}
QSqlQueryModel * carte_cc::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from carte_cc where (NUM_CARTE LIKE '"+id+"%')");


    return model;
}

QSqlQueryModel *  carte_cc::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from carte_cc order by "+critere+" "+mode+"");


    return model;
}
