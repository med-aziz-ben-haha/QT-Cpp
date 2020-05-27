#include "courantepargne.h"
#include "ui_courantepargne.h"
#include"epargne.h"
#include"couraant.h"
#include"conx.h"
#include"staticc.h"

#include <QMessageBox>
courantepargne::courantepargne(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::courantepargne)
{
    ui->setupUi(this);
}

courantepargne::~courantepargne()
{
    delete ui;
}


//compte courant

void courantepargne::on_CreerCC_3_clicked()
{QString Seuil_rouge = ui->Seuil_Rouge_5->text();
    QString nb_echeance= ui->nb_echeance_5->text();
    QString nb_credit= ui->nb_credit_5->text();
    QString RIB= ui->RIB_9->text();
   QString Solde= ui->Solde_2->text();
   QString Cin= ui->comboBox_2->currentText();
   int a,b,c,d,e;
           bool test4=true;
           bool test5=true;
           bool test6=true;
           bool test7=true;
           bool test8=true;

           for (a=0;a<Seuil_rouge.length();a++) {
               if (Seuil_rouge[a]=="a" || Seuil_rouge[a]=="z" || Seuil_rouge[a]=="e" || Seuil_rouge[a]=="r" || Seuil_rouge[a]=="t" || Seuil_rouge[a]=="y"  )  {
                   test4=false;
                   }
           }
           if (Seuil_rouge.length()!=4)
                  test4=false;

           for (b=0;b<nb_echeance.length();b++) {
               if (nb_echeance[b]=="a" || nb_echeance[b]=="z" || nb_echeance[b]=="e" || nb_echeance[b]=="r" || nb_echeance[b]=="t" || nb_echeance[b]=="y"  )  {
                   test5=false;
                   }
           }
           if (nb_echeance.length()!=4)
                  test5=false;

           for (c=0;c<nb_credit.length();c++) {
               if (nb_credit[c]=="a" || nb_credit[c]=="z" || nb_credit[c]=="e" || nb_credit[c]=="r" || nb_credit[c]=="t" || nb_credit[c]=="y"  )  {
                   test6=false;
                   }
           }
           if (nb_credit.length()!=4)
                  test6=false;

           for (d=0;d<nb_credit.length();d++) {
               if (RIB[d]=="a" || RIB[d]=="z" || RIB[d]=="e" || RIB[d]=="r" || RIB[d]=="t" || RIB[d]=="y"  )  {
                   test7=false;
                   }
           }
           if (RIB.length()!=15)
                  test7=false;

           for (e=0;e<Solde.length();e++) {
               if (Solde[e]=="a" || Solde[e]=="z" || Solde[e]=="e" || Solde[e]=="r" || Solde[e]=="t" || Solde[e]=="y"  )  {
                   test8=false;
                   }
           }
           if (Solde.length()!=6)
                  test8=false;
           if ( test4 && test5 && test6 && test7 && test8  )
           {
    couraant c(Seuil_rouge,nb_echeance,nb_credit,RIB,Solde,Cin);
    bool test= c.ajouterCourant();
    if(test)
    {
        ui->tableView_6->setModel(tmpcour.afficherCourant());//refresh
        QMessageBox::information(nullptr, QObject::tr("Créer un compte cournat"),
        QObject::tr("compte créé.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

    }
   else
    {
        QMessageBox::critical(nullptr, QObject::tr("Créer un compte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }}
    if (test4==false)
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                     QObject::tr("Erreur ! il faut 4 chiffres dans seuil_rouge \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   if (test5==false)
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                  QObject::tr("Erreur ! il faut 4 chiffres dans nombre d'echeances \n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    if (test6==false)
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                     QObject::tr("Erreur ! il faut 4 chiffres dans le nombre de crédit  \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    if (test7==false)
       QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                   QObject::tr("Erreur ! il faut 15 chiffres dans RIB \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
     if (test8==false)
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                      QObject::tr("Erreur ! il faut 6 chiffres dans le solde  \n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}



void courantepargne::on_SupprimerCC_3_clicked()
{
    bool res ;
        couraant c;
        QString q ;
        QModelIndex index ;
        QModelIndexList selection = ui->tableView_6->selectionModel()->selectedRows();
        for (int i =0;i<selection.count();i++)
        {
            index=selection.at(i);
            q=QVariant(ui->tableView_6->model()->index(index.row(),0).data()).toString();
            res =c.supprimerCourant(q);
                if (res == QDialog::Accepted)
                {
                        ui->tableView_6->setModel(tmpcour.afficherCourant());
                        QMessageBox::information(nullptr, QObject::tr("Supprimer un compte courant"),
                                                 QObject::tr("compte courant supprimé.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                                         }
    }
}

void courantepargne::on_Modifier_3_clicked()
{bool test=tmpcour.modifierCourant(ui->Seuil_Rouge_6->text(),ui->nb_credit_6->text(),ui->nb_echeance_6->text(),ui->Solde_3->text());
    if(test)
  {
        ui->tableView_6->setModel(tmpcour.afficherCourant());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un compte courant"),
                    QObject::tr("Compte courant modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte courant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void courantepargne::on_trier_5_clicked()
{
    QString mode="ASC";
        if (ui->checkBox_5->checkState()==false)
            mode="DESC";

    ui->tableView_6->setModel(tmpcour.trierCourant(ui->comboBox_5->currentText(),mode));
}
void courantepargne::on_Afficher1_3_clicked()
{
ui->tableView_6->setModel(tmpcour.afficherCourant());
}
void courantepargne::on_pushButton_2_clicked()
{
    Staticc Staticc;
      Staticc.setModal(true);
      Staticc.exec();
}

void courantepargne::on_lineEdit_9_selectionChanged()
{
    QString str=ui->lineEdit_9->text();
        ui->tableView_6->setModel(tmpcour.rechercheCourant(str));
}

void courantepargne::on_lineEdit_9_textChanged(const QString &arg1)
{
    ui->tableView_6->setModel(tmpcour.rechercheCourant(arg1));
}
//compte epargne





void courantepargne::on_Creer_3_clicked()
{QString RIB = ui->RIB_11->text();
    QString Taux_annuel= ui->Taux_annuel_5->text();
QString Solde= ui->solde_2->text();
QString Cin= ui->comboBox_3->currentText();
 int i,j,w;
 bool test1=true;
bool test2=true;
bool test3=true;
 for (i=0;i<RIB.length();i++) {
     if (RIB[i]=="a" || RIB[i]=="z" || RIB[i]=="e" || RIB[i]=="r" || RIB[i]=="t" || RIB[i]=="y"  )  {
         test1=false;
         }
 }
 if (RIB.length()!=15)
        test1=false;
 for (j=0;j<Taux_annuel.length();j++) {
     if (Taux_annuel[j]=="a" || Taux_annuel[j]=="z" || Taux_annuel[j]=="e" || Taux_annuel[j]=="r"|| Taux_annuel[j]=="t"|| Taux_annuel[j]=="y" )    {
         test2=false;
         }
 }
 if (Taux_annuel.length()!=4)
        test2=false;
 for (w=0;w<Solde.length();w++) {
     if (Solde[w]=="a" || Solde[w]=="z" || Solde[w]=="e" || Solde[w]=="r"|| Solde[w]=="t"|| Solde[w]=="y"  )    {
         test3=false;
         }
 }
 if (Solde.length()!=6)
        test3=false;
 if ( test1 && test2 && test3 )
{
    epargne c(RIB,Taux_annuel,Solde,Cin);
    bool test= c.creerCompte();
    if(test)
    {
        ui->tableView_7->setModel(tmpcomp.afficherCompte());//refresh
        QMessageBox::information(nullptr, QObject::tr("Créer un compte"),
        QObject::tr("compte créé.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

    }
  else
    {
        QMessageBox::critical(nullptr, QObject::tr("Créer un compte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
        if (test1==false)
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                         QObject::tr("Erreur ! il faut 15 chiffres dans RIB \n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
     if (test2==false)
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                      QObject::tr("Erreur ! il faut 4 chiffres dans Taux annuel \n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
        if (test3==false)
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte"),
                         QObject::tr("Erreur ! il faut 6 chiffres dans le solde  \n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void courantepargne::on_Modifer2_3_clicked()
{
    bool test=tmpcomp.modifierCompte(ui->Taux_annuel_6->text(),ui->Solde_3->text());
        if(test)
      {
            ui->tableView_7->setModel(tmpcomp.afficherCompte());//refresh
      QMessageBox::information(nullptr, QObject::tr("Ajouter un compte epargne"),
                        QObject::tr("compte epargne modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un compte epargne"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void courantepargne::on_SupprimerC_3_clicked()
{
    bool res ;
       epargne c;
       QString q ;
       QModelIndex index ;
       QModelIndexList selection = ui->tableView_7->selectionModel()->selectedRows();
       for (int i =0;i<selection.count();i++)
       {
           index=selection.at(i);
           q=QVariant(ui->tableView_7->model()->index(index.row(),0).data()).toString();
           res = c.supprimerCompte(q) ;
               if (res == QDialog::Accepted)
               {
                       ui->tableView_7->setModel(tmpcomp.afficherCompte());
                       QMessageBox::information(nullptr, QObject::tr("Supprimer un compte"),
                                                QObject::tr("compte supprimé.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                                        }
}
}

void courantepargne::on_Afficher_3_clicked()
{
ui->tableView_7->setModel(tmpcomp.afficherCompte());
}

void courantepargne::on_trier_6_clicked()
{
    QString mode="ASC";
        if (ui->checkBox_6->checkState()==false)
            mode="DESC";
    // ui->comboBox->currentText();
    ui->tableView_7->setModel(tmpcomp.trierCompte(ui->comboBox_6->currentText(),mode));
}

void courantepargne::on_lineEdit_10_selectionChanged()
{
    QString str=ui->lineEdit_10->text();
        ui->tableView_7->setModel(tmpcomp.rechercheCompte(str));
}
//creer

void courantepargne::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox_2->currentText();
    QSqlQuery query;
    query.prepare("select * from CLIENT where CIN='"+cin+"'" );
    if (query.exec())
    {while(query.next())
         {  /* ui->Seuil_Rouge_5->setText(query.value(0).toString());
        ui->nb_credit_5->setText(query.value(1).toString());
        ui->nb_echeance_5->setText(query.value(2).toString());
        ui->RIB_9->setText(query.value(2).toString());
       ui->Solde_2->setText(query.value(2).toString());*/
        }}else {
        QMessageBox::critical(nullptr, QObject::tr("false"),
                    QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
}



//compte courant
void courantepargne::on_pushButton_5_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select CIN from CLIENT");
        ui->comboBox_2->setModel(model);
}


//CREER EP
void courantepargne::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox_3->currentText();
    QSqlQuery query;
    query.prepare("select * from CLIENT where CIN='"+cin+"'" );
    if (query.exec())
    {while(query.next())
         {  // ui->Taux_annuel_5->setText(query.value(0).toString());


        }}else {
        QMessageBox::critical(nullptr, QObject::tr("false"),
                    QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

//compte epargne
void courantepargne::on_pushButton_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select CIN from CLIENT");
        ui->comboBox_3->setModel(model);
}



//modi courant
void courantepargne::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString rib=ui->comboBox->currentText();
    QSqlQuery query;
    query.prepare("select * from COMPTE_COURANT where RIB='"+rib+"'" );
    if (query.exec())
    {while(query.next())
         {  // ui->Taux_annuel_5->setText(query.value(0).toString());


        }}else {
        QMessageBox::critical(nullptr, QObject::tr("false"),
                    QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void courantepargne::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select RIB from COMPTE_COURANT");
        ui->comboBox->setModel(model);
}
//modi epargne

void courantepargne::on_comboBox_4_currentIndexChanged(const QString &arg1)
{
    QString rib=ui->comboBox_4->currentText();
    QSqlQuery query;
    query.prepare("select * from COMPTE where RIB='"+rib+"'" );
    if (query.exec())
    {while(query.next())
         {  // ui->Taux_annuel_5->setText(query.value(0).toString());


        }}else {
        QMessageBox::critical(nullptr, QObject::tr("false"),
                    QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void courantepargne::on_pushButton_4_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select RIB from COMPTE");
        ui->comboBox_4->setModel(model);
}
