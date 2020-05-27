#include "carte_ed.h"
#include <QDebug>

carte_ed::carte_ed()
{
num_carte=0;
solde=0;

code_conf="";
code_int="";

}
carte_ed::carte_ed(int num_carte,int solde,QDate date_fin,QDate date_debut,QString code_conf,QString code_int)
{
  this->num_carte=num_carte;
    this->solde=solde;
  this->date_debut=date_debut;
    this->date_fin=date_fin;
    this->code_conf=code_conf;
    this->code_int=code_int;
}
int carte_ed::get_num_carte(){return  num_carte;}
int carte_ed::get_solde(){return solde;}

QString carte_ed::get_code_conf(){return code_conf;}
QString carte_ed::get_code_int(){return code_int;}

QSqlQueryModel * carte_ed::afficher()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from carte_ed   ");

        return model;

}
bool carte_ed::ajout()
{
QSqlQuery query;
QString res= QString::number(num_carte);
QString res1= QString::number(solde);
QDate res2= (date_debut);
QDate res3=(date_fin);
QString res4=(code_conf);
QString res5=(code_int);
query.prepare("INSERT INTO CARTE_ED (NUM_CARTE,SOLDE,DATE_DEBUT,DATE_FIN,CODE_CONF,CODE_INT) "
                    "VALUES (:num_carte,:solde,:date_debut,:date_fin,:code_conf,:code_int)");
query.bindValue(":num_carte", res);
query.bindValue(":solde", res1);
query.bindValue(":date_debut", res2);
query.bindValue(":date_fin", res3);
query.bindValue(":code_conf", res4);
query.bindValue(":code_int", res5);
return    query.exec();
}

bool carte_ed::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from carte_ed where NUM_CARTE = :num_carte ");
query.bindValue(":num_carte", res);
return    query.exec();
}

bool carte_ed::ajouter(QString &res,int ss)
{int final;
QSqlQuery query;
QSqlQuery query1;

//while (query.next())int solde=query.value(3).toInt();
query1.prepare("select * from carte_ed where(NUM_CARTE LIKE '"+res+"%') ");
query1.exec();
while (query1.next()) solde=query1.value(3).toInt();
final=solde+ss;
QString ses= QString::number(final);

query.prepare("update carte_ed set solde="+ses+" where (NUM_CARTE LIKE '"+res+"%')");


query.bindValue(":solde", ses);

return    query.exec();
}
bool carte_ed::retirer(QString &res,int ss)
{int final;
QSqlQuery query;
QSqlQuery query1;

//while (query.next())int solde=query.value(3).toInt();
query1.prepare("select * from carte_ed where(NUM_CARTE LIKE '"+res+"%') ");
query1.exec();
while (query1.next()) solde=query1.value(3).toInt();
final=solde-ss;
QString ses= QString::number(final);

query.prepare("update carte_ed set solde="+ses+" where (NUM_CARTE LIKE '"+res+"%')");


query.bindValue(":solde", ses);

return    query.exec();
}
QSqlQueryModel * carte_ed::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from carte_cc where (NUM_CARTE LIKE '"+id+"%')");


    return model;
}

QSqlQueryModel *  carte_ed::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from carte_cc order by "+critere+" "+mode+"");


    return model;
}
