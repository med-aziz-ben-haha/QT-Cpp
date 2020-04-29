#include "mainwindow.h"
#include "connexion.h"
#include "stat_cong.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Rapid Post");

    Connexion c;
    bool test=c.createconnect();
  if(test)
    {

  w.show();

}
    else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("Database could not initiate.\nConnection failed."), QMessageBox::Cancel);

    return a.exec();
}
