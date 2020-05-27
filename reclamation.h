#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Reclamation
{
public:
    Reclamation();
    Reclamation(int,QString,QString,QDate,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    QDate get_dateR();
    QString get_objet();
    QString get_mail();
    QString get_message();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QDate,QString,QString,QString);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * trier(const QString &critere, const QString &mode );
    QSqlQueryModel * afficherid();
private:
    QString nom,prenom,objet,mail,message;
    int idreclamation;
    QDate dateR;
};

#endif // RECLAMATION_H
