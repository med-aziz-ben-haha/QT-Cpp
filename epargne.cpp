#include "epargne.h"
#include <QDebug>
#include <QSqlQuery>
#include"conx.h"
//Constructeur
epargne::epargne()
{
        RIB="";
        Taux_annuel="";
        Solde="";
        Cin="";

}

//Constructeur
epargne::epargne(QString RIB,QString Taux_annuel,QString Solde,QString Cin){
    this->RIB=RIB;
    this->Taux_annuel=Taux_annuel;
    this->Solde=Solde;
    this->Cin=Cin;

}

QString epargne::get_RIB(){return RIB;}
QString epargne::get_Taux_annuel(){return Taux_annuel;}
QString epargne::get_Solde(){return Solde;}
QString epargne::get_Cin(){return Cin;}
//Ajouter compte epargne
bool epargne::creerCompte(){
    QSqlQuery query;
    QString resultat=(RIB);
    QString resultat1=(Taux_annuel);
    QString resultat7=(Solde);
     QString resultatx=(Cin);

    query.prepare("INSERT INTO COMPTE (RIB,TAUXANNUEL,SOLDE,CIN)"
                        "VALUES (:RIB,:Taux_annuel,:Solde,:Cin)");
    query.bindValue(":RIB", resultat);
    query.bindValue(":Taux_annuel", resultat1);
    query.bindValue(":Solde", resultat7);
    query.bindValue(":Cin", resultatx);

    return    query.exec();
}

//Afficher compte epargne

QSqlQueryModel * epargne::afficherCompte(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Compte");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("RIB"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TAUXANNUEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOLDE"));
    return model;
}

//Supprimer compte epargne
bool epargne::supprimerCompte(QString RIB){

    QString header ;
        QSqlQuery q;
        header = "DELETE FROM COMPTE WHERE RIB=:RIB";
        q.prepare(header);
        q.bindValue(":RIB",RIB);
        return q.exec();

}

//Modifier compte epargne
bool epargne::modifierCompte( QString Taux_annuel, QString Solde){

    QSqlQuery qry;
        qry.prepare("UPDATE COMPTE set TAUXANNUEL=(?),SOLDE=(?) WHERE RIB=:RIB ");

       // qry.addBindValue(RIB);
        qry.addBindValue(Taux_annuel);
        qry.addBindValue(Solde);
   return  qry.exec();
}
//Rechercher compte epargne

QSqlQueryModel * epargne::rechercheCompte(const QString &id){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from COMPTE where (RIB LIKE '"+id+"%')");
    return model;


}

//Trier compte epargne
QSqlQueryModel *  epargne::trierCompte(const QString &critere, const QString &mode){
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug() <<critere;
     qDebug() <<mode;
model->setQuery("select * from COMPTE order by "+critere+" "+mode+"");



    return model;
}
