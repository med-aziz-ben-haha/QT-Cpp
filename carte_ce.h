#ifndef CARTE_CE_H
#define CARTE_CE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class carte_ce
{public:
    carte_ce();
    carte_ce(int,int,QString,QDate,QDate,QString);
    QString get_type();
    QString get_RIB();
    int get_num_carte();
    int get_solde();
    bool ajouter(QString &num,int ss);
    bool ajout();
    bool retirer(QString &num,int ss);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * trier(const QString &critere, const QString &mode );
private:
    QString type,RIB;
    QDate date_debut,date_fin;
int solde,num_carte;

};

#endif

