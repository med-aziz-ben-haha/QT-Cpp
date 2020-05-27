#ifndef carte_cc_H
#define carte_cc_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class carte_cc
{public:
    carte_cc();
    carte_cc(int,int,QString,QDate,QDate,QString,QString,QString);
    QString get_type();

    QString get_code_conf();
    QString get_code_int();
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
    QString type,code_conf,code_int,RIB;
    QDate date_debut,date_fin;
int solde,num_carte;

};

#endif
