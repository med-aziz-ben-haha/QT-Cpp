#include "courantepargne.h"
#include"dialog.h"
#include "gestionclient.h"
#include <QMessageBox>
#include <QtDebug>
#include"conx.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    courantepargne w;
    Dialog w1;
    gestionclient w2;
    conx c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        w1.show();
        w2.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                            QObject::tr("connection successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
