#include <QDebug>
#include <QSqlQuery>
#include "connexion.h"
#include "courrier.h"

//Constructeur
courrier::courrier()
{
idcourrier="";
type="";
adresseem="";
adressedest="";
priorite="";
prix=0;
etat="";
}

//Constructeur
courrier::courrier(QString idcourrier,QString type,QString adresseem,QString adressedest,QString priorite,int prix,QString etat)
{
    this->idcourrier=idcourrier;
    this->type=type;
    this->adresseem=adresseem;
    this->adressedest=adressedest;
    this->priorite=priorite;
    this->prix=prix;
    this->etat=etat;
}

QString courrier::get_idcourrier(){return idcourrier;}

//Ajouter courrier
bool courrier::ajouterCourrier()
{
QSqlQuery query;
QString resultat=(idcourrier);
query.prepare("INSERT INTO COURRIER (IDCOURRIER,TYPE,ADRESSEEM,ADRESSEDEST,PRIORITE,PRIX,ETAT)"
                    "VALUES (:idcourrier,:type,:adresseem,:adressedest,:priorite,:prix,:etat)");

query.bindValue(":idcourrier",resultat);
query.bindValue(":type",type);
query.bindValue(":adresseem",adresseem);
query.bindValue(":adressedest",adressedest);
query.bindValue(":priorite",priorite);
query.bindValue(":prix",prix);
query.bindValue(":etat",etat);

return    query.exec();
}

//Afficher courrier
QSqlQueryModel * courrier::afficherCourrier()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from COURRIER");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOURRIER"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSEEM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSEDEST"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIORITE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
return model;
}

//Supprimer courrier
bool courrier::supprimerCourrier(QString idcourrier)
{
    QString header ;
    QSqlQuery q;
    header = "Delete from courrier where idcourrier = :idcourrier";
    q.prepare(header);
    q.bindValue(":idcourrier",idcourrier);
    return q.exec();
}

//Modifier coli
bool courrier::modifierCourrier(QString idcourrier,QString etat)
{
    QSqlQuery q;
    if (etat=="En attente")
    {
        QString header;
        header = "update courrier set etat='En cours' where idcourrier=:idcourrier and etat='En attente'";
        q.prepare(header);
        q.bindValue(":idcourrier",idcourrier);
    }
    if (etat=="En cours")
    {
        QString header;
        header = "update courrier set etat='Envoye' where idcourrier=:idcourrier and etat='En cours'";
        q.prepare(header);
        q.bindValue(":idcourrier",idcourrier);
    }
    return q.exec();
}

//rechercher courrier
QSqlQueryModel * courrier ::recherche (const QString &idcourrier)

{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from courrier where (IDCOURRIER LIKE '"+idcourrier+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOURRIER"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSEEM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSEDEST"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIORITE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}
//trier courrier
QSqlQueryModel *  courrier::trier(const QString &critere,const QString &mode)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    //qDebug() <<mode;
    model->setQuery("select * from courrier order by "+critere+" "+mode+"");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCOURRIER"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSEEM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSEDEST"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIORITE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}
