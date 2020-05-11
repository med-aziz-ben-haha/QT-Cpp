#ifndef COURRIER_H
#define COURRIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"

class courrier
{
    public:
    QString type,adresseem,adressedest,priorite,etat;
    int prix;

    courrier();
    courrier(QString,QString,QString,QString,QString,int,QString);
    QString get_idcourrier();
    QSqlQueryModel *afficherCourrier();
    bool ajouterCourrier();
    bool supprimerCourrier(QString idcourrier);
    bool modifierCourrier(QString idcourrier,QString etat);

    QSqlQueryModel * recherche (const QString &idcourrier);
    QSqlQueryModel * trier(const QString &critere,const QString &mode );

    private:
    QString idcourrier;
};
#endif // COURRIER_H
