#include <QDebug>
#include <QSqlQuery>
#include <QDate>
#include "connexion.h"
#include "livraison.h"

//Constructeur
livraison::livraison()
{
idliv="";
lidcoli="";
lidequip="";
}

//Constructeur
livraison::livraison(QString idliv,QString lidcoli,QString lidequip,QDate ldate)
{
    this->idliv=idliv;
    this->lidcoli=lidcoli;
    this->lidequip=lidequip;
    this->ldate=ldate;
}

QString livraison::get_idliv(){return idliv;}
QString livraison::get_lidcoli(){return lidcoli;}
QString livraison::get_lidequip(){return lidequip;}
QDate livraison::get_ldate(){return ldate;}

//Ajouter livraison
bool livraison::ajouterLiv()
{
QSqlQuery query;
QString resultat=(idliv);
query.prepare("INSERT INTO livraison (IDLIV,LIDCOLI,LIDEQUIP,LDATE)"
                    "VALUES (:idliv,:lidcoli,:lidequip,:ldate)");
query.bindValue(":idliv",resultat);
query.bindValue(":lidcoli",lidcoli);
query.bindValue(":lidequip",lidequip);
query.bindValue(":ldate",ldate);


return query.exec();
}
//Afficher livraison
QSqlQueryModel * livraison::afficherLiv()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from livraison");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDLIV"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIDCOLI"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIDEQUIP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LDATE"));
return model;
}
//Supprimer livraison
bool livraison::supprimerLiv(QString idliv)
{
    QString header ;
    QSqlQuery q;
    header = "Delete from livraison where idliv = :idliv";
    q.prepare(header);
    q.bindValue(":idliv",idliv);
    return q.exec();
}

//rechercher livraison
QSqlQueryModel * livraison ::recherche (const QString &idliv)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from livraison where (IDLIV LIKE '"+idliv+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDLIV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIDCOLI"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIDEQUIP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LDATE"));
    return model;
}

bool livraison::modifierLiv(QString lidcoli)
{
    QString header ;
    QSqlQuery q;
    header = "update coli set etat='En cours' where idcoli= :lidcoli";
    q.prepare(header);
    q.bindValue(":lidcoli",lidcoli);
    return q.exec();
}

