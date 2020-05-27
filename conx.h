#ifndef CONX_H
#define CONX_H
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>

class conx
{
private:
    QSqlDatabase db;
public:
    conx();
    bool createconnect();
    void fermerconexion();
};

#endif // CONX_H
