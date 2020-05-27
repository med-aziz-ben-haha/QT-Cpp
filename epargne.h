#ifndef EPARGNE_H
#define EPARGNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "conx.h"
class epargne
{
public:
    epargne();
    epargne(QString,QString,QString,QString);
    QString get_RIB();
    QString get_Taux_annuel();
    QString get_Solde();
    QString get_Cin();
    QSqlQueryModel * afficherCompte();
    bool creerCompte();
    bool supprimerCompte(QString RIB);
     bool modifierCompte(QString,QString);
     QSqlQueryModel * rechercheCompte(const QString &id);

     QSqlQueryModel * trierCompte(const QString &critere, const QString &mode );
private:
QString RIB;
QString Taux_annuel;
QString Solde;
QString Cin;


};

#endif // EPARGNE_H




