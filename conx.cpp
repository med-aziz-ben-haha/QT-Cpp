#include "conx.h"

conx::conx()
{

}
bool conx::createconnect()
{bool test=false;
 QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
 db.setDatabaseName("Source_Projet2A");
 db.setUserName("Oussama");//inserer nom de l'utilisateur
 db.setPassword("Oussama");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}

void conx::fermerconexion()
{db.close();


}
