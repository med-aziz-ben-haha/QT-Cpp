#include "reclamation.h"
#include <QDebug>
#include "stmp.h"
#include "conx.h"
Reclamation::Reclamation()
{
idreclamation=0;
nom="";
prenom="";
objet="";
mail="";
message="";
}
Reclamation::Reclamation(int idreclamation,QString nom,QString prenom,QDate dateR,QString objet,QString mail,QString message)
{
  this->idreclamation=idreclamation;
  this->nom=nom;
  this->prenom=prenom;
  this->dateR=dateR;
  this->objet=objet;
  this->mail=mail;
  this->message=message;
}
QString Reclamation::get_nom(){return  nom;}
QString Reclamation::get_prenom(){return prenom;}
int Reclamation::get_id(){return  idreclamation;}
QDate Reclamation::get_dateR(){return dateR;}
QString Reclamation::get_objet(){return objet;}
QString Reclamation::get_mail(){return mail;}
QString Reclamation::get_message(){return message;}
bool Reclamation::ajouter()
{
QSqlQuery query;
QString res= QString::number(idreclamation);
query.prepare("INSERT INTO RECLAMATION (IDRECLAMATION, NOM, PRENOM,DATER,OBJET,MAIL,MESSAGE) "
                    "VALUES (:idreclamation, :nom, :prenom, :dateR, :objet, :mail, :message)");
query.bindValue(":idreclamation", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":dateR", dateR);
query.bindValue(":objet", objet);
query.bindValue(":mail", mail);
query.bindValue(":message", message);
return    query.exec();
}

QSqlQueryModel * Reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from reclamation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Objet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Message"));
    return model;
}

bool Reclamation::modifier(int id_reclamation,QString nom,QString prenom,QDate dateR,QString objet,QString mail,QString message)
{

    QSqlQuery qry;
        qry.prepare("UPDATE reclamation set NOM=(?),PRENOM=(?),DATER=(?),OBJET=(?),MAIL=(?),MESSAGE=(?) where IDRECLAMATION=(?) ");

        qry.addBindValue(nom);
        qry.addBindValue(prenom);
        qry.addBindValue(dateR);
        qry.addBindValue(objet);
        qry.addBindValue(mail);
        qry.addBindValue(message);
        qry.addBindValue(id_reclamation);
   return  qry.exec();
}

bool Reclamation::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Reclamation where IDRECLAMATION = :idreclamation ");
query.bindValue(":idreclamation", res);
return    query.exec();
}
QSqlQueryModel * Reclamation::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from reclamation where (IDRECLAMATION LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Objet"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mail"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Message"));

    return model;
}

QSqlQueryModel *  Reclamation::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from reclamation order by "+critere+" "+mode+"");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Objet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Message"));
    return model;
}
QSqlQueryModel * Reclamation::afficherid()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select IDRECLAMATION from reclamation");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDRECLAMATION"));
    return model;
}
