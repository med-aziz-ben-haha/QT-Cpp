#include "conge.h"
#include "global.h"
#include "addconge.h"
#include <QMessageBox>

conge::conge()
{

}

conge::conge(QString id,QString etat,QString date_debut,QString date_fin,QString commentaire,QString duree,QString raison)
{
  this->id=id;
  this->etat=etat;
  this->date_debut=date_debut;
  this->date_fin=date_fin;
  this->commentaire=commentaire;
  this->duree=duree;
    this->raison=raison;
}

bool conge::ajouter()
{

QSqlQuery query;


query.prepare("INSERT INTO DEMANDE_CONGE (ID, ID_EMPLOYE, DATE_DEBUT, DATE_FIN, COMMENTAIRE ,ETAT,DUREE,RAISON) "
                    "VALUES (:id, :id_emp, :dd, :df , :c , :e, :d, :r)");
query.bindValue(":id", id);
query.bindValue(":id_emp",tmp);
query.bindValue(":dd", date_debut);
query.bindValue(":df", date_fin);
query.bindValue(":c", commentaire);
query.bindValue(":e", etat);
query.bindValue(":d", duree);
query.bindValue(":r", raison);

return    query.exec();
}

QSqlQueryModel * conge::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID,ID_EMPLOYE,RAISON,DATE_DEBUT,DATE_FIN,DUREE,COMMENTAIRE from DEMANDE_CONGE where ETAT=0 and ID_EMPLOYE != '"+tmp+"'");

    return model;
}

QSqlQueryModel * conge::afficher_accep()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID,ID_EMPLOYE,RAISON,DATE_DEBUT,DATE_FIN,DUREE,COMMENTAIRE from DEMANDE_CONGE where ETAT=1 ");

    return model;
}

QSqlQueryModel * conge::afficher_emp()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID,ID_EMPLOYE,RAISON,DATE_DEBUT,DATE_FIN,DUREE,COMMENTAIRE from DEMANDE_CONGE where ETAT=0 and ID_EMPLOYE='"+tmp+"'");

    return model;
}

QSqlQueryModel * conge::afficher_accep_emp()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID,ID_EMPLOYE,RAISON,DATE_DEBUT,DATE_FIN,DUREE,COMMENTAIRE from DEMANDE_CONGE where ETAT=1 and ID_EMPLOYE='"+tmp+"'");

    return model;
}


bool conge::supprimer()
{
QSqlQuery query;
query.prepare("Delete from DEMANDE_CONGE where ID = :id ");
query.bindValue(":id", sel_cong);
return    query.exec();
}

bool conge::supprimer_rh()
{
QSqlQuery query;
query.prepare("UPDATE DEMANDE_CONGE SET ETAT=-1 WHERE ID = :id ");
query.bindValue(":id", sel_cong_rh);
return    query.exec();
}


bool conge::accept_cong()
{
QSqlQuery query;
query.prepare("UPDATE DEMANDE_CONGE SET ETAT=1 WHERE ID = '"+sel_cong_rh+"'");
return    query.exec();
}


