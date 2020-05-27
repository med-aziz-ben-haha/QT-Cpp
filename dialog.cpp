#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{

        ui->tabcarte->setModel(tmpcarte.afficher());

}

void Dialog::on_pushButton_2_clicked()
{
    int ss=ui->spinBox->value();
    QString num= ui->lineEdit_5->text();
bool test=tmpcarte.ajouter(num,ss);
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("montant ajouté"),
                QObject::tr("Montant ajouté.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("ajouter montant"),
                QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}



void Dialog::on_pushButton_3_clicked()
{
    int ss=ui->spinBox->value();
     QString num=ui->lineEdit_5->text();
bool test=tmpcarte.retirer(num,ss);
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("montant retiré"),
                QObject::tr("Montant retiré.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("retirer montant"),
                QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_5_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select RIB from COMPTE_COURANT");
        ui->comboBox->setModel(model);

}

void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString num=ui->comboBox->currentText();
    QSqlQuery query;
    query.prepare("select * from COMPTE_COURANT where RIB='"+num+"'" );
    if (query.exec())
    {while(query.next())
         {
       // ui->lineEdit_5->setText(query.value(3).toString());

        }}else {
        QMessageBox::critical(nullptr, QObject::tr("false"),
                    QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void Dialog::on_pushButton_6_clicked()
{
    int num_carte = ui->lineEdit_5->text().toInt();
    int solde = ui->lineEdit_6->text().toInt();
    QString type= ui->lineEdit_8->text();
    QDate date_debut= ui->dateEdit_2->date();
    QDate date_fin= ui->dateEdit->date();
    QString code_conf= ui->lineEdit_4->text();
    QString code_int= ui->lineEdit_7->text();
    QString RIB= ui->comboBox->currentText();
    int i,j,w,a,b;
    bool test1=true;
   bool test2=true;
   bool test3=true;
   bool test4=true;
   bool test5=true;
   for (a=0;a<code_conf.length();a++) {
       if (code_conf[a]=="a" || code_conf[a]=="b" || code_conf[a]=="c" || code_conf[a]=="d")        {
           test1=false;
           }
   }
   if (code_conf.length()!=4)
          test1=false;
   for (b=0;b<code_int.length();b++) {
       if (code_int[b]=="a" || code_int[b]=="b" || code_int[b]=="c" || code_int[b]=="d")        {
           test5=false;
           }
   }
   if (code_int.length()!=4)
          test5=false;
   for (j=0;j<type.length();j++) {
       if (type[j]=="0" || type[j]=="1" || type[j]=="2" || type[j]=="3" || type[j]=="4" || type[j]=="5" || type[j]=="6" || type[j]=="7" || type[j]=="8" || type[j]=="9")
          {
           test2=false;
           }
   }
   for (i=0;i<ui->lineEdit_6->text().length();i++) {
       if (ui->lineEdit_6->text()[i]=="a" || ui->lineEdit_6->text()[i]=="b" || ui->lineEdit_6->text()[i]=="c" || ui->lineEdit_6->text()[i]=="d" || ui->lineEdit_6->text()[i]=="e" || ui->lineEdit_6->text()[i]=="f" || ui->lineEdit_6->text()[i]=="g" || ui->lineEdit_6->text()[i]=="h" || ui->lineEdit_6->text()[i]=="i" || ui->lineEdit_6->text()[i]=="j")
          {
           test3=false;
           }
   }
   for (w=0;w<ui->lineEdit_5->text().length();w++) {
       if (ui->lineEdit_5->text()[w]=="a" || ui->lineEdit_5->text()[w]=="b" || ui->lineEdit_5->text()[w]=="c" || ui->lineEdit_5->text()[w]=="d" || ui->lineEdit_5->text()[w]=="e" || ui->lineEdit_5->text()[w]=="f" || ui->lineEdit_5->text()[w]=="g" || ui->lineEdit_5->text()[w]=="h" || ui->lineEdit_5->text()[w]=="i" || ui->lineEdit_5->text()[w]=="j")
          {
           test4=false;
           }
   }
   if (ui->lineEdit_5->text().length()!=8)
          test4=false;
   if ( test1 && test5 && test2 && test3 && test4)
       {
  carte_cc c(num_carte,solde,type,date_debut,date_fin,code_conf,code_int,RIB);
  bool test=c.ajout();
  if(test)
{ui->tabcarte->setModel(tmpcarte.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("carte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
   } if (test2==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! pas de chiffres dans le type \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    if (test1==false)
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                     QObject::tr("Erreur ! il faut 4chiffres \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    if (test5==false)
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                     QObject::tr("Erreur ! il faut 4chiffres \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   if (test3==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! Pas de lettres dans le solde \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
   if (test4==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! Il faut 8 chiffres \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void Dialog::on_pushButton_8_clicked()
{
int id = ui->lineEdit_5->text().toInt();
bool test=tmpcarte.supprimer(id);
if(test)
{ui->tabcarte->setModel(tmpcarte.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                QObject::tr("carte supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Dialog::on_pushButton_16_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select RIB from COMPTE");
        ui->comboBox_3->setModel(model);
}

void Dialog::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    QString num=ui->comboBox_3->currentText();
    QSqlQuery query;
    query.prepare("select * from COMPTE where RIB='"+num+"'" );
    if (query.exec())
    {while(query.next())
         {
        //ui->lineEdit_18->setText(query.value(0).toString());

        }}else {
        QMessageBox::critical(nullptr, QObject::tr("false"),
                    QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void Dialog::on_pushButton_17_clicked()
{
    int num_carte = ui->lineEdit_18->text().toInt();
    int solde = ui->lineEdit_23->text().toInt();
    QString type= ui->lineEdit_22->text();
    QDate date_debut= ui->dateEdit_3->date();
    QDate date_fin= ui->dateEdit_4->date();
    QString RIB= ui->comboBox_3->currentText();
    int c,d,e;
    bool test6=true;
   bool test7=true;
   bool test8=true;

   for (d=0;d<type.length();d++) {
       if (type[d]=="0" || type[d]=="1" || type[d]=="2" || type[d]=="3" || type[d]=="4" || type[d]=="5" || type[d]=="6" || type[d]=="7" || type[d]=="8" || type[d]=="9")
          {
           test7=false;
           }
   }
   for (c=0;c<ui->lineEdit_23->text().length();c++) {
       if (ui->lineEdit_23->text()[c]=="a" || ui->lineEdit_23->text()[c]=="b" || ui->lineEdit_23->text()[c]=="c" || ui->lineEdit_23->text()[c]=="d" || ui->lineEdit_23->text()[c]=="e" || ui->lineEdit_23->text()[c]=="f" || ui->lineEdit_23->text()[c]=="g" || ui->lineEdit_23->text()[c]=="h" || ui->lineEdit_23->text()[c]=="i" || ui->lineEdit_23->text()[c]=="j")
          {
           test8=false;
           }
   }

   for (e=0;e<ui->lineEdit_18->text().length();e++) {
       if (ui->lineEdit_18->text()[e]=="a" || ui->lineEdit_18->text()[e]=="b" || ui->lineEdit_18->text()[e]=="c" || ui->lineEdit_18->text()[e]=="d" || ui->lineEdit_18->text()[e]=="e" || ui->lineEdit_18->text()[e]=="f" || ui->lineEdit_18->text()[e]=="g" || ui->lineEdit_18->text()[e]=="h" || ui->lineEdit_18->text()[e]=="i" || ui->lineEdit_18->text()[e]=="j")
          {
           test6=false;
           }
   }
   if (ui->lineEdit_18->text().length()!=8)
          test6=false;
   if ( test6 && test7 && test8)
       {
  carte_ce c(num_carte,solde,type,date_debut,date_fin,RIB);
  bool test=c.ajout();
  if(test)
{ui->tabcarte_3->setModel(tmpcarte2.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("carte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

   } if (test7==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! pas de chiffres dans le type \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
   if (test8==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! Pas de lettres dans le solde \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
   if (test6==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! Il faut 8 chiffres \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void Dialog::on_pushButton_18_clicked()
{
int id = ui->lineEdit_18->text().toInt();
bool test=tmpcarte2.supprimer(id);
if(test)
{ui->tabcarte_3->setModel(tmpcarte2.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                QObject::tr("carte supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Dialog::on_pushButton_19_clicked()
{
    int ss=ui->spinBox_3->value();
    QString num=ui->lineEdit_18->text();
bool test=tmpcarte2.retirer(num,ss);
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("montant retiré"),
                QObject::tr("Montant retiré.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("retirer montant"),
                QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}


void Dialog::on_pushButton_20_clicked()
{
    int ss=ui->spinBox_3->value();
    QString num=ui->lineEdit_18->text();
bool test=tmpcarte2.ajouter(num,ss);
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("montant ajouté"),
                QObject::tr("Montant ajouté.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("ajouter montant"),
                QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_21_clicked()
{

        ui->tabcarte_3->setModel(tmpcarte2.afficher());

}



void Dialog::on_pushButton_11_clicked()
{
    QString mode="ASC";
   if (ui->checkBox_2->checkState()==false)
       mode="DESC";
// ui->comboBox->currentText();
ui->tabcarte->setModel(tmpcarte.trier(ui->comboBox_4->currentText(),mode));
}
void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tabcarte->setModel(tmpcarte.recherche(arg1));
}


void Dialog::on_pushButton_4_clicked()
{
    QString mode="ASC";
   if (ui->checkBox->checkState()==false)
       mode="DESC";
// ui->comboBox->currentText();
ui->tabcarte_3->setModel(tmpcarte2.trier(ui->comboBox_2->currentText(),mode));
}

void Dialog::on_pushButton_10_clicked()
{

    int num_carte = ui->lineEdit_21->text().toInt();
    int solde = ui->lineEdit_28->text().toInt();
    QDate date_debut= ui->dateEdit_6->date();
    QDate date_fin= ui->dateEdit_5->date();
    QString code_conf= ui->lineEdit_29->text();
    QString code_int= ui->lineEdit_26->text();
    int f,g,k,l;
    bool test9=true;
   bool test10=true;
   bool test11=true;
   bool test12=true;
   for (f=0;f<ui->lineEdit_28->text().length();f++) {
       if (ui->lineEdit_28->text()[f]=="a" || ui->lineEdit_28->text()[f]=="b" || ui->lineEdit_28->text()[f]=="c" || ui->lineEdit_28->text()[f]=="d" || ui->lineEdit_28->text()[f]=="e" || ui->lineEdit_28->text()[f]=="f" || ui->lineEdit_28->text()[f]=="g" || ui->lineEdit_28->text()[f]=="h" || ui->lineEdit_28->text()[f]=="i" || ui->lineEdit_28->text()[f]=="j")
          {
           test10=false;
           }
   }
   for (k=0;k<code_conf.length();k++) {
       if (code_conf[k]=="a" || code_conf[k]=="b" || code_conf[k]=="c" || code_conf[k]=="d")        {
           test9=false;
           }
   }
   if (code_conf.length()!=4)
          test9=false;
   for (l=0;l<code_int.length();l++) {
       if (code_int[l]=="a" || code_int[l]=="b" || code_int[l]=="c" || code_int[l]=="d")        {
           test12=false;
           }
   }
   if (code_int.length()!=4)
          test12=false;


   for (g=0;g<ui->lineEdit_21->text().length();g++) {
       if (ui->lineEdit_21->text()[g]=="a" || ui->lineEdit_21->text()[g]=="b" || ui->lineEdit_21->text()[g]=="c" || ui->lineEdit_21->text()[g]=="d" || ui->lineEdit_21->text()[g]=="e" || ui->lineEdit_21->text()[g]=="f" || ui->lineEdit_21->text()[g]=="g" || ui->lineEdit_21->text()[g]=="h" || ui->lineEdit_21->text()[g]=="i" || ui->lineEdit_21->text()[g]=="j")
          {
           test11=false;
           }
   }
   if (ui->lineEdit_21->text().length()!=8)
          test11=false;
   if ( test9 && test10 && test11 && test12)
       {
  carte_ed c(num_carte,solde,date_debut,date_fin,code_conf,code_int);
  bool test=c.ajout();
  if(test)
{ui->tabcarte_4->setModel(tmpcarte3.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("carte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

   }
   if (test10==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! Pas de lettres dans le solde \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
   if (test9==false)
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                     QObject::tr("Erreur ! il faut 4chiffres \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    if (test12==false)
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                     QObject::tr("Erreur ! il faut 4chiffres \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   if (test11==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur ! Il faut 8 chiffres \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_12_clicked()
{
    int id = ui->lineEdit_21->text().toInt();
    bool test=tmpcarte3.supprimer(id);
    if(test)
    {ui->tabcarte_4->setModel(tmpcarte3.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("carte supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_22_clicked()
{
    int ss=ui->spinBox_4->value();
    QString num=ui->lineEdit_21->text();
bool test=tmpcarte2.retirer(num,ss);
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("montant retiré"),
                QObject::tr("Montant retiré.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("retirer montant"),
                QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_23_clicked()
{
    int ss=ui->spinBox_4->value();
    QString num=ui->lineEdit_21->text();
bool test=tmpcarte3.ajouter(num,ss);
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("montant ajouté"),
                QObject::tr("Montant ajouté.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("ajouter montant"),
                QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_24_clicked()
{
    ui->tabcarte_4->setModel(tmpcarte3.afficher());
}


void Dialog::on_pushButton_14_clicked()
{
    QString mode="ASC";
   if (ui->checkBox_3->checkState()==false)
       mode="DESC";
// ui->comboBox->currentText();
ui->tabcarte_4->setModel(tmpcarte3.trier(ui->comboBox_5->currentText(),mode));
}



void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tabcarte_3->setModel(tmpcarte2.recherche(arg1));
}

void Dialog::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->tabcarte_4->setModel(tmpcarte3.recherche(arg1));
}

void Dialog::on_pushButton_15_clicked()
{
    statt statt;
      statt.setModal(true);
      statt.exec();
}
void Dialog::on_pushButton_25_clicked()
{
    statt statt;
      statt.setModal(true);
      statt.exec();
}
void Dialog::on_pushButton_26_clicked()
{
    statt statt;
      statt.setModal(true);
      statt.exec();
}
