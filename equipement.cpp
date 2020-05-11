#include <QDebug>
#include <QSqlQuery>
#include "connexion.h"
#include "equipement.h"

//Constructeur
equipement::equipement()
{
idequip="";
type="";
dispo=0;
}

//Constructeur
equipement::equipement(QString idequip,QString type,int dispo)
{
    this->idequip=idequip;
    this->type=type;
    this->dispo=dispo;
}

QString equipement::get_idequip(){return idequip;}

//Ajouter equipement
bool equipement::ajouterEquip()
{
QSqlQuery query;
QString resultat=(idequip);
query.prepare("INSERT INTO equipement (IDEQUIP,TYPE,DISPO)"
                    "VALUES (:idequip,:type,:dispo)");
query.bindValue(":idequip",resultat);
query.bindValue(":type",type);
query.bindValue(":dispo",dispo);

return query.exec();
}
//Afficher equipement
QSqlQueryModel * equipement::afficherEquip()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from equipement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEQUIP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DISPO"));
return model;
}
//Supprimer equipement
bool equipement::supprimerEquip(QString idequip)
{
    QString header ;
    QSqlQuery q;
    header = "Delete from equipement where idequip = :idequip";
    q.prepare(header);
    q.bindValue(":idequip",idequip);
    return q.exec();
}
//rechercher equipement
QSqlQueryModel * equipement ::recherche (const QString &idequip)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from equipement where (IDEQUIP LIKE '"+idequip+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDEQUIP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DISPO"));
    return model;
}


//Ajouter un equip a une livraison
QSqlQueryModel * equipement::afficheridequip()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select idequip from equipement where dispo=1");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}

