#ifndef COURAANT_H
#define COURAANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"conx.h"
class couraant
{
public:
    couraant();
    couraant(QString,QString,QString,QString,QString,QString);
    QString get_Seuil_rouge();
    QString get_nb_credit();
    QString get_nb_echeance();
    QString get_RIB();
    QString get_Solde();
    QString get_Cin();
    QSqlQueryModel *afficherCourant();
    bool ajouterCourant();
    bool supprimerCourant(QString Seuil_rouge );
    bool modifierCourant(QString,QString,QString,QString);
    QSqlQueryModel * rechercheCourant(const QString &id);

    QSqlQueryModel * trierCourant(const QString &critere, const QString &mode );
private:
QString Seuil_rouge;
QString nb_credit;
QString nb_echeance;
QString RIB;
QString Solde;
QString Cin;
};

#endif // COURAANT_H

