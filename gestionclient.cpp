#include "gestionclient.h"
#include "ui_gestionclient.h"
#include "client.h"
#include "reclamation.h"
#include "cadeau.h"
#include "stmp.h"
#include "stat_client.h"
#include "QWindow"
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QMessageBox>
#include <QDebug>
QT_CHARTS_USE_NAMESPACE
gestionclient::gestionclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionclient)
{
ui->setupUi(this);
connect(ui->Envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));
ui->tabclient->setModel(tmpclient.afficher());
ui->tabreclamation->setModel(tmpreclamation.afficher());
ui->tabcadeau->setModel(tmpcadeau.afficher());
ui->comboBox_4->setModel(tmpclient.afficherid());
ui->comboBox_5->setModel(tmpclient.afficherid());
ui->comboBox_6->setModel(tmpreclamation.afficherid());
ui->comboBox_7->setModel(tmpreclamation.afficherid());
ui->comboBox_13->setModel(tmpclient.afficherid());
ui->comboBox_14->setModel(tmpcadeau.afficherid());
}

gestionclient::~gestionclient()
{
    delete ui;
}

void gestionclient::on_pb_ajouter_clicked()
{
    int idclient = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString mail= ui->lineEdit_mail->text();
    int tel= ui->lineEdit_tel->text().toInt();
    int nbp= ui->lineEdit_nbp->text().toInt();
    int cin= ui->lineEdit_8->text().toInt();
    int i,j,w;
   bool test1=false;
   bool test2=true;
   bool test3=true;
   bool test4=false;
   for (i=0 ; i<mail.length();i++)
   {
        if (mail[i]=="@")
   {
         test1=true;
   }
        }
   for (j=0;j<nom.length();j++) {
       if (nom[j]=="0" || nom[j]=="1" || nom[j]=="2" || nom[j]=="3" || nom[j]=="4" || nom[j]=="5" || nom[j]=="6" || nom[j]=="7" || nom[j]=="8" || nom[j]=="9")
          {
           test2=false;
           }
   }
   for (w=0;w<prenom.length();w++) {
       if (prenom[w]=="0" || prenom[w]=="1" || prenom[w]=="2" || prenom[w]=="3" || prenom[w]=="4" || prenom[w]=="5" || prenom[w]=="6" || prenom[w]=="7" || prenom[w]=="8" || prenom[w]=="9")
          {
           test3=false;
           }
   }
   if (ui->lineEdit_tel->text().length()==8)
   {
       test4=true;
   }
        if (test1 && test2 && test3 && test4)
            {
  Client c(idclient,nom,prenom,adresse,mail,tel,nbp,cin);
  bool test=c.ajouter();
  if(test)
{

      ui->tabclient->setModel(tmpclient.afficher());
      ui->comboBox_4->setModel(tmpclient.afficherid());
      ui->comboBox_5->setModel(tmpclient.afficherid());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
        else if (test1==false)
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("Erreur ! Email incorrect \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        else if (test2==false)
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("Erreur ! pas de chiffres dans le nom \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        else if (test3==false)
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("Erreur ! Pas de chiffres dans le prenom \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        else if (test4==false)
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                        QObject::tr("Erreur ! Telephone incorrect. Il faut 8 chiffres \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
void gestionclient::on_pb_modifier_clicked()
{
    bool test=tmpclient.modifier(ui->comboBox_5->currentText().toInt(),ui->lineEdit_nom_2->text(),ui->lineEdit_prenom_2->text(),ui->lineEdit_adresse_2->text(),ui->lineEdit_mail_2->text(),ui->lineEdit_tel_2->text().toInt(),ui->lineEdit_nbp_2->text().toInt(),ui->lineEdit_4->text().toInt());
    if(test)
  {
        ui->tabclient->setModel(tmpclient.afficher());
        ui->comboBox_4->setModel(tmpclient.afficherid());
        ui->comboBox_5->setModel(tmpclient.afficherid());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("Client modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionclient::on_pb_supprimer_clicked()
{
int id = ui->comboBox_4->currentText().toInt();
bool test=tmpclient.supprimer(id);
if(test)
{ui->tabclient->setModel(tmpclient.afficher());
 ui->comboBox_4->setModel(tmpclient.afficherid());
 ui->comboBox_5->setModel(tmpclient.afficherid());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Client supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestionclient::on_pb_ajouter_2_clicked()
{
    int idreclamation = ui->lineEdit_id_4->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    QString prenom= ui->lineEdit_prenom_3->text();
    QDate dateR= ui->dateTimeEdit->date();
    QString objet=ui->lineEdit_objet->text();
    QString mail= ui->lineEdit_mail_3->text();
    QString message= ui->textEdit->toPlainText();

  int i,j,w;
 bool test1=false;
 bool test2=true;
 bool test3=true;
 for (i=0 ; i<mail.length();i++)
 {
      if (mail[i]=="@")
 {
       test1=true;
 }
      }
 for (j=0;j<nom.length();j++) {
     if (nom[j]=="0" || nom[j]=="1" || nom[j]=="2" || nom[j]=="3" || nom[j]=="4" || nom[j]=="5" || nom[j]=="6" || nom[j]=="7" || nom[j]=="8" || nom[j]=="9")
        {
         test2=false;
         }
 }
 for (w=0;w<prenom.length();w++) {
     if (prenom[w]=="0" || prenom[w]=="1" || prenom[w]=="2" || prenom[w]=="3" || prenom[w]=="4" || prenom[w]=="5" || prenom[w]=="6" || prenom[w]=="7" || prenom[w]=="8" || prenom[w]=="9")
        {
         test3=false;
         }
 }
 if (test1 && test2 && test3)
 {
  Reclamation r(idreclamation,nom,prenom,dateR,objet,mail,message);
  bool test=r.ajouter();
  if(test)
{
      ui->tabreclamation->setModel(tmpreclamation.afficher());
      ui->comboBox_6->setModel(tmpreclamation.afficherid());
      ui->comboBox_7->setModel(tmpreclamation.afficherid());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une réclamation"),
                  QObject::tr("Réclamation ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une réclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void gestionclient::on_pb_modifier_2_clicked()
{
    bool test=tmpreclamation.modifier(ui->comboBox_6->currentText().toInt(),ui->lineEdit_nom_4->text(),ui->lineEdit_prenom_4->text()
       ,ui->dateTimeEdit_2->date(),ui->lineEdit_objet_2->text(),ui->lineEdit_mail_4->text(),ui->textEdit_2->toPlainText());
    if(test)
  {
        ui->comboBox_6->setModel(tmpreclamation.afficherid());
        ui->comboBox_7->setModel(tmpreclamation.afficherid());
        ui->tabreclamation->setModel(tmpreclamation.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation"),
                    QObject::tr("Reclamation modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une réclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionclient::on_pb_supprimer_2_clicked()
{
int id = ui->comboBox_7->currentText().toInt();
bool test=tmpreclamation.supprimer(id);
if(test)
{
    ui->comboBox_6->setModel(tmpreclamation.afficherid());
    ui->comboBox_7->setModel(tmpreclamation.afficherid());
    ui->tabreclamation->setModel(tmpreclamation.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une réclamation"),
                QObject::tr("Réclamation supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une réclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void gestionclient::on_rechercher_clicked()
{
    QString str=ui->search->text();
    ui->tabrechercher->setModel(tmpclient.recherche(str));
}
void gestionclient::on_rechercher_2_clicked()
{
    QString str=ui->search_2->text();
    ui->tabrechercher_2->setModel(tmpreclamation.recherche(str));
}




void gestionclient::on_trier_clicked()
{
     QString mode="ASC";
    if (ui->checkBox->checkState()==false)
        mode="DESC";
// ui->comboBox->currentText();
ui->tabclient->setModel(tmpclient.trier(ui->comboBox->currentText(),mode));

}

void gestionclient::on_lineEdit_6_selectionChanged()
{
    QString str=ui->lineEdit_6->text();
        ui->tabreclamation->setModel(tmpreclamation.recherche(str));
}

void gestionclient::on_trier_2_clicked()
{
     QString mode="ASC";
    if (ui->checkBox_2->checkState()==false)
        mode="DESC";
// ui->comboBox->currentText();
ui->tabreclamation->setModel(tmpreclamation.trier(ui->comboBox_2->currentText(),mode));

}

void gestionclient::on_pushButton_2_clicked()
{
    QString t=ui->comboBox_modifier->currentText();
    int q=ui->lineEdit_id_test->text().toInt();
    QString s=ui->lineEdit_test->text();
tmpclient.modif1(t,q,s);
}

void gestionclient::on_pushButton_3_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());
    ui->tabreclamation->setModel(tmpreclamation.afficher());
}

void gestionclient::on_pushButton_clicked()
{
    QString t=ui->comboBox_3->currentText();
    int q=ui->lineEdit->text().toInt();
tmpclient.supp(t,q);
}


void gestionclient::on_pb_ajouter_3_clicked()
{
    int idcadeau = ui->lineEdit_idcadeau->text().toInt();
    QString type= ui->comboBox_9->currentText();
    QString nomcadeau= ui->lineEdit_nomcadeau->text();
    int points = ui->lineEdit_points->text().toInt();
  cadeau ca(idcadeau,type,nomcadeau,points);
  bool test=ca.ajouter();
  if(test)
{
      ui->tabcadeau->setModel(tmpcadeau.afficher());
      ui->comboBox_10->setModel(tmpcadeau.afficherid());
      ui->comboBox_11->setModel(tmpcadeau.afficherid());
QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),
                  QObject::tr("Cadeau ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un cadeau"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionclient::on_pb_modifier_3_clicked()
{
    bool test=tmpcadeau.modifier(ui->comboBox_10->currentText().toInt(),ui->comboBox_12->currentText(),ui->lineEdit_nomcadeau_2->text(),ui->lineEdit_points_2->text().toInt());
    if(test)
  {
        ui->tabcadeau->setModel(tmpcadeau.afficher());
        ui->comboBox_10->setModel(tmpcadeau.afficherid());
        ui->comboBox_11->setModel(tmpcadeau.afficherid());
  QMessageBox::information(nullptr, QObject::tr("Modifier un cadeau"),
                    QObject::tr("Cadeau modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionclient::on_pb_supprimer_3_clicked()
{
    int id = ui->comboBox_11->currentText().toInt();
    bool test=tmpcadeau.supprimer(id);
    if(test)
    {   ui->comboBox_10->setModel(tmpcadeau.afficherid());
        ui->comboBox_11->setModel(tmpcadeau.afficherid());
        ui->tabcadeau->setModel(tmpcadeau.afficher());
        ui->tabcadeau_2->setModel(tmpcadeau.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                    QObject::tr("Cadeau supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionclient::on_pushButton_7_clicked()
{
    ui->tabcadeau->setModel(tmpcadeau.afficher());
}

void gestionclient::on_pushButton_afficher_clicked()
{
    Client c;
    ui->tabclient_2->setModel(c.afficher());
}

void gestionclient::on_pushButton_affecter_clicked()
{
int nb=0;
int point=0;
int id = ui->comboBox_13->currentText().toInt();
int idcadeau =ui->comboBox_14->currentText().toInt();
QSqlQuery nbp;
QSqlQuery points;
QSqlQuery query;
nbp.prepare("SELECT * from client where IDCLIENT = :id");
nbp.bindValue(":id", id);
nbp.exec();
if (nbp.next())
nb=nbp.value(6).toInt();
qDebug()<<nb;
points.prepare("SELECT * from cadeau where IDCADEAU = :idcadeau");
points.bindValue(":idcadeau", idcadeau);
points.exec();
if (points.next())
point=points.value(3).toInt();
qDebug()<<point;
//int nb=nbp.value(6).toInt();
//int point=points.value(3).toInt();
    bool test=false;
    if (nb > point)
{
     test=true;
     nb = nb - point;
     qDebug()<<nb;
 query.prepare("UPDATE client set NBP= :nb where IDCLIENT= :id");
 query.bindValue(":id", id);
 query.bindValue(":nb", nb);
 query.exec();
 bool test2=tmpcadeau.supprimer(idcadeau);
 if (test2)
 {
     ui->comboBox_10->setModel(tmpcadeau.afficherid());
             ui->comboBox_11->setModel(tmpcadeau.afficherid());
             ui->tabcadeau->setModel(tmpcadeau.afficher());
             ui->tabcadeau_2->setModel(tmpcadeau.afficher());
             ui->comboBox_13->setModel(tmpclient.afficherid());
             ui->comboBox_14->setModel(tmpcadeau.afficherid());//refresh
             QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                         QObject::tr("Cadeau supprimé.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
 {
             QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
 }
     QMessageBox::information(nullptr, QObject::tr("Affecter un cadeau"),
                       QObject::tr("Cadeau affecté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Affecter un cadeau"),
                    QObject::tr("Erreur ! Nombre de points insuffisants.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestionclient::on_pushButton_4_clicked()
{
    cadeau c;
    ui->tabcadeau_2->setModel(c.afficher());
}

void gestionclient::on_lineEdit_5_textChanged(const QString &arg1)
{
        ui->tabclient->setModel(tmpclient.recherche(arg1));
}
void gestionclient::sendMail()
{
    Smtp* smtp = new Smtp("alainbouvierr@gmail.com", "wowloldiablo12","smtp.gmail.com",465,3000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("Test", ui->lineEdit_2->text() , ui->lineEdit_3->text(),ui->textEdit_3->toPlainText());

}

void gestionclient::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void gestionclient::on_Envoyer_clicked()
{
   connect(ui->Envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));
    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
}



void gestionclient::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->tabreclamation->setModel(tmpreclamation.recherche(arg1));
}

void gestionclient::on_lineEdit_7_textChanged(const QString &arg1)
{
    ui->tabcadeau->setModel(tmpcadeau.recherche(arg1));
}

void gestionclient::on_trier_3_clicked()
{
    QString mode="ASC";
   if (ui->checkBox_3->checkState()==false)
       mode="DESC";
// ui->comboBox->currentText();
ui->tabcadeau->setModel(tmpcadeau.trier(ui->comboBox_8->currentText(),mode));
}

void gestionclient::stat()
{


    /*QSqlQuery q1,q2,q3;
    qreal a=0,b=0,c=0;
    q1.prepare("SELECT * FROM CLIENT");
    q1.exec();
    q2.prepare("SELECT * FROM CLIENT WHERE NBP<300");
    q2.exec();
    q3.prepare("SELECT * FROM CLIENT WHERE NBP>300");
    q3.exec();
    while(q1.next()){a++;}
    while(q2.next()){b++;}
    while(q3.next()){c++;}
    b=b/a;
    c=c/a;
    QBarSet *set0 = new QBarSet("Client");
    QBarSet *set1 = new QBarSet("Fidele");
    // Assign values for each bar
    *set0 << b;
    *set1 << c;
    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();
    // 2. Stacked bar chart
    series->append(set0);
    series->append(set1);
    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();
    // Add the chart
    chart->addSeries(series);
    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    // 1. Bar chart
    chart->setAxisX(axis, series);
    // Used to change the palette
    QPalette pal = qApp->palette();
    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));
    // Apply palette changes to the application
    qApp->setPalette(pal);
    chartView = new QChartView(chart,ui->label_54);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(350,350);
chartView->show();*/
}

void gestionclient::on_pushButton_5_clicked()
{
    stat_client stat_etat;
        stat_etat.setModal(true);
        stat_etat.exec();
}

void gestionclient::on_pushButton_6_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQueryModel *model1 = new QSqlQueryModel();
        model->setQuery("select IDCLIENT from CLIENT");
        ui->comboBox_13->setModel(model);
        model1->setQuery("select IDCADEAU from CADEAU");
            ui->comboBox_14->setModel(model1);
}

void gestionclient::on_pushButton_8_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select IDCLIENT from CLIENT");
    ui->comboBox_5->setModel(model);
}

void gestionclient::on_pushButton_9_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select IDCLIENT from CLIENT");
    ui->comboBox_4->setModel(model);
}

void gestionclient::on_pushButton_10_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select IDRECLAMATION from RECLAMATION");
    ui->comboBox_7->setModel(model);
}

void gestionclient::on_pushButton_11_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select IDCADEAU from CADEAU");
    ui->comboBox_10->setModel(model);
}

void gestionclient::on_pushButton_12_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select IDCADEAU from CADEAU");
    ui->comboBox_11->setModel(model);
}

void gestionclient::on_pushButton_13_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());
    ui->tabreclamation->setModel(tmpreclamation.afficher());
}

void gestionclient::on_pushButton_14_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select IDRECLAMATION from RECLAMATION");
    ui->comboBox_6->setModel(model);
}
