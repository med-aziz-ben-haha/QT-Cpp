#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connexion
{private:

public:
    QSqlDatabase db;
    Connexion();
    bool createconnect();
    void closeconnection();
};

#endif // CONNECTION_H
