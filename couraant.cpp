#include "couraant.h"
#include <QDebug>
#include <QSqlQuery>
#include "conx.h"
//Constructeur
couraant::couraant()
{
    Seuil_rouge="";
    nb_credit="";
    nb_echeance="";
    RIB="";
    Solde="";
    Cin="";
}

//Constructeur
couraant::couraant(QString Seuil_rouge,QString nb_credit,QString nb_echeance,QString RIB,QString Solde,QString Cin)
{   this->Seuil_rouge=Seuil_rouge;
    this->nb_credit=nb_credit;
    this->nb_echeance=nb_echeance;
    this->RIB=RIB;
    this->Solde=Solde;
    this->Cin=Cin;

}
QString couraant::get_Seuil_rouge(){return Seuil_rouge;}
QString couraant::get_nb_credit(){return nb_credit;}
QString couraant::get_nb_echeance(){return nb_echeance;}
QString couraant::get_RIB(){return RIB;}
QString couraant::get_Solde(){return Solde;}
QString couraant::get_Cin(){return Cin;}
//Ajouter compte_courant
bool couraant::ajouterCourant(){
    QSqlQuery query;
    QString resultat3=(Seuil_rouge);
    QString resultat4=(nb_credit);
    QString resultat5=(nb_echeance);
    QString resultat6=(RIB);
    QString resultat8=(Solde);
    QString resultatw=(Cin);
    query.prepare("INSERT INTO COMPTE_COURANT (SEUILROUGE,NBCREDIT,NBECHEANCE,RIB,SOLDE,CIN)"
                        "VALUES (:Seuil_rouge,:nb_credit,:nb_echeance,:RIB,:Solde,:Cin)");
    query.bindValue(":Seuil_rouge", resultat3);
    query.bindValue(":nb_credit", resultat4);
    query.bindValue(":nb_echeance", resultat5);
    query.bindValue(":RIB", resultat6);
    query.bindValue(":Solde", resultat8);
    query.bindValue(":Cin",resultatw);

    return    query.exec();

}

//Afficher compte_courant
QSqlQueryModel * couraant::afficherCourant()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from COMPTE_COURANT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("SEUILROUGE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBCREDIT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBECHEANCE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("RIB"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("SOLDE"));
return model;
}

//Supprimer compte_courant
bool couraant::supprimerCourant(QString Seuil_rouge){
    QString tail ;
        QSqlQuery q;
        tail = "DELETE FROM COMPTE_COURANT WHERE SEUILROUGE=:SEUILROUGE";
        q.prepare(tail);
        q.bindValue(":SEUILROUGE",Seuil_rouge);
        return q.exec();
}

//Modifier compte courant
bool couraant::modifierCourant(QString Seuil_rouge, QString nb_credit, QString nb_echeance,QString Solde)
{

    QSqlQuery qry;
        qry.prepare("UPDATE COMPTE_COURANT set SEUILROUGE=(?),NBCREDIT=(?),NBECHEANCE=(?),SOLDE=(?) WHERE RIB=(?) ");

        qry.addBindValue(Seuil_rouge);
        qry.addBindValue(nb_credit);
        qry.addBindValue(nb_echeance);
        qry.addBindValue(Solde);

   return  qry.exec();
}

//Rechercher compte courant
QSqlQueryModel * couraant::rechercheCourant(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from COMPTE_COURANT where (RIB LIKE '"+id+"%')");



    return model;
}
//Trier compte courant
QSqlQueryModel *  couraant::trierCourant(const QString &critere, const QString &mode ){
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;


model->setQuery("select * from COMPTE_COURANT order by "+critere+" "+mode+"");



    return model;
}

