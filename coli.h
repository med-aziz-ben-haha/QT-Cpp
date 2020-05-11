#ifndef COLI_H
#define COLI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"

class coli
{
    public:
    QString adresseem,adressedest,priorite,etat;
    int poids,prix;
    int avecliv;

    coli();
    coli(QString,QString,QString,QString,int,int,QString,int);
    QString get_idcoli();
    QSqlQueryModel * afficherColi();
    bool ajouterColi();
    bool supprimerColi(QString idcoli);
    bool modifierColi(QString idcoli,QString etat,QString avecliv);

    QSqlQueryModel * recherche(const QString &idcoli);
    QSqlQueryModel * trier(const QString &critere,const QString &mode );
    QSqlQueryModel *afficheridcoli();

private:
    QString idcoli;
};
#endif // COLI_H
