#include "coli.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "connexion.h"

//Constructeur
coli::coli()
{
idcoli="";
adresseem="";
adressedest="";
priorite="";
poids=0;
prix=0;
etat="";
avecliv=0;
}
//Constructeur
coli::coli(QString idcoli,QString adresseem,QString adressedest,QString priorite,int poids,int prix,QString etat,int avecliv)
{
    this->idcoli=idcoli;
    this->adresseem=adresseem;
    this->adressedest=adressedest;
    this->priorite=priorite;
    this->poids=poids;
    this->prix=prix;
    this->etat=etat;
    this->avecliv=avecliv;
}

QString coli::get_idcoli(){return idcoli;}

//Ajouter coli
bool coli::ajouterColi()
{
QSqlQuery query;
QString resultat=(idcoli);
query.prepare("INSERT INTO COLI (IDCOLI,ADRESSEEM,ADRESSEDEST,PRIORITE,POIDS,PRIX,ETAT,AVECLIV)"
                    "VALUES (:idcoli,:adresseem,:adressedest,:priorite,:poids,:prix,:etat,:avecliv)");
query.bindValue(":idcoli",resultat);
query.bindValue(":adresseem",adresseem);
query.bindValue(":adressedest",adressedest);
query.bindValue(":priorite",priorite);
query.bindValue(":poids",poids);
query.bindValue(":prix",prix);
query.bindValue(":etat",etat);
query.bindValue(":avecliv",avecliv);
return    query.exec();
}

//Afficher coli
QSqlQueryModel * coli::afficherColi()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from coli");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOLI"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSEEM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSEDEST"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIORITE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("POIDS"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("AVECLIV"));
return model;
}

//Supprimer coli
bool coli::supprimerColi(QString idcoli)
{
    QString header ;
    QSqlQuery q;
    header = "Delete from coli where idcoli = :idcoli";
    q.prepare(header);
    q.bindValue(":idcoli",idcoli);
    return q.exec();
}

//Modifier coli
bool coli::modifierColi(QString idcoli,QString etat,QString avecliv)
{
    QSqlQuery q;
    if ((etat=="En stock") && avecliv=="0")
    {
        QString header;
        header = "update coli set etat='Livre' where idcoli = :idcoli";
        q.prepare(header);
        q.bindValue(":idcoli",idcoli);
    }
    if ((etat=="En stock") && avecliv=="1")
    {
        QString header;
        header = "update coli set etat='En cours' where idcoli = :idcoli";
        q.prepare(header);
        q.bindValue(":idcoli",idcoli);
    }
    if (etat=="En cours")
    {
        QString header;
        header = "update coli set etat='Livre' where idcoli = :idcoli and avecliv=1";
        q.prepare(header);
        q.bindValue(":idcoli",idcoli);
    }
    return q.exec();

}

//rechercher coli
QSqlQueryModel * coli ::recherche (const QString &idcoli)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from coli where (IDCOLI LIKE '"+idcoli+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOLI"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSEEM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSEDEST"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIORITE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POIDS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AVECLIV"));
    return model;
}

//trier coli
QSqlQueryModel *  coli::trier(const QString &critere,const QString &mode)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    //qDebug() <<mode;
    model->setQuery("select * from coli order by "+critere+" "+mode+"");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOLI"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSEEM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSEDEST"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIORITE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POIDS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("AVECLIV"));
    return model;
}

//Ajouter un coli a une livraison
QSqlQueryModel * coli::afficheridcoli()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select idcoli from coli where avecliv=1 and etat='En stock'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}

