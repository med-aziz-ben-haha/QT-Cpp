#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test_project");
db.setUserName("revolver");//inserer nom de l'utilisateur
db.setPassword("revolver");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
void Connexion::closeconnection(){
    db.close();
}
