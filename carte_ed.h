#ifndef CARTE_ED_H
#define CARTE_ED_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class carte_ed
{public:
    carte_ed();
    carte_ed(int,int,QDate,QDate,QString,QString);

    QString get_code_conf();
    QString get_code_int();
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
    QString code_conf,code_int;
    QDate date_debut,date_fin;
int solde,num_carte;

};

#endif
