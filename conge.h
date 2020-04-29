#ifndef CONGE_H
#define CONGE_H

#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"
class conge
{
public:
    conge();
conge(QString,QString,QString,QString,QString,QString,QString);

Connexion conn;
    bool ajouter();
 QSqlQueryModel * afficher();
 QSqlQueryModel * afficher_emp();
 QSqlQueryModel * afficher_accep();
 QSqlQueryModel * afficher_accep_emp();
    bool supprimer();
       bool supprimer_rh();
    bool accept_cong();


    QString id,date_debut,date_fin,commentaire,etat,duree,raison;

};

#endif // CONGE_H

