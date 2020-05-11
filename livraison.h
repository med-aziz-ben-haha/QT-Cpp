#ifndef LIVRAISON_H
#define LIVRAISON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include "connexion.h"

class livraison
{
    public:

    livraison();
    livraison(QString,QString,QString,QDate);
    QString get_idliv();
    QString get_lidequip();
    QString get_lidcoli();
    QDate get_ldate();
    QSqlQueryModel * afficherLiv();
    bool ajouterLiv();
    bool supprimerLiv(QString idliv);
    bool modifierLiv(QString lidcoli);
    QSqlQueryModel * recherche (const QString &idliv);

    private:
    QString idliv;
    QString lidcoli;
    QString lidequip;
    QDate ldate;

};
#endif // LIVRAISON_H
