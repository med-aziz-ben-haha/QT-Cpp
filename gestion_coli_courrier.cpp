#include "gestion_coli_courrier.h"
#include "ui_gestion_coli_courrier.h"
#include "connexion.h"
#include "coli.h"
#include "courrier.h"
#include "equipement.h"
#include "livraison.h"
#include "stat_etat.h"
#include <QMessageBox>
#include <QDate>
#include <QDialog>

#include <QApplication>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include "export_excel.h"
#include <QFileDialog>

Gestion_Coli_Courrier::Gestion_Coli_Courrier(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_Coli_Courrier)
{
    ui->setupUi(this);
    ui->Priorite->addItem("Haute");
    ui->Priorite->addItem("Normale");
    ui->Priorite->addItem("Basse");

    ui->Etat->addItem("En stock");
    ui->Etat->addItem("En cours");
    ui->Etat->addItem("Livre");

    ui->etat_2->addItem("En attente");
    ui->etat_2->addItem("En cours");
    ui->etat_2->addItem("Envoye");

    ui->Priorite_2->addItem("Haute");
    ui->Priorite_2->addItem("Normale");
    ui->Priorite_2->addItem("Basse");

    ui->type_courrier->addItem("Personel");
    ui->type_courrier->addItem("Professionel");
    ui->type_courrier->addItem("Administratif");

    ui->comboBox_3->addItem("Moto de livraison");
    ui->comboBox_3->addItem("Voiture");
    ui->comboBox_3->addItem("Autre");

    ui->Prix->setValidator( new QIntValidator(0, 99999999, this) );
    ui->Prix->setMaxLength(8);
    ui->Poids->setValidator( new QIntValidator(0, 99999999, this) );
    ui->Poids->setMaxLength(8);
    ui->prix_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->prix_2->setMaxLength(8);
}

Gestion_Coli_Courrier::~Gestion_Coli_Courrier()
{
    delete ui;
}

//***********************************CRUD Coli***********************************
void Gestion_Coli_Courrier::on_ajoutercoli_clicked()
{
    QString idcoli=ui->idcoli->text();
    QString adresseem=ui->Adresseem->toPlainText();
    QString adressedest=ui->Adressedest->toPlainText();
    QString priorite=ui->Priorite->currentText();
    int poids=ui->Poids->text().toInt();
    int prix =ui->Prix->text().toInt();
    QString etat = ui->Etat->currentText();
    int avecliv;
    if (ui->Avecliv->isChecked())
    {
        avecliv=1;
    }
    else
    {
        avecliv=0;
    }
//Controle
    bool test1=true;
    if (((etat=="En cours")&&(avecliv==0)) || ((etat=="Livré")&&(avecliv==0)))
    {
        test1=false;
    }
    if (test1)
{

    int reponse=QMessageBox::question(this,"Confirmation","Voulez vous ajouter ce coli ?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
       {
        coli c(idcoli,adresseem,adressedest,priorite,poids,prix,etat,avecliv);
        bool test= c.ajouterColi();
        if(test)
        {
            ui->tableColi->setModel(tmpcoli.afficherColi());//refresh
            QMessageBox::information(nullptr, QObject::tr("Ajouter un coli"),
            QObject::tr("coli ajouté.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un coli"),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
       }
    else if (reponse == QMessageBox::No)
       {
            QMessageBox::critical(this, "Annulation", "L'ajout de ce coli a ete annuler !");
       }
}
    if (test1==false)
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un coli"),
                            QObject::tr("Erreur ! Merci de vérifier les champs  \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_Coli_Courrier::on_suppcoli_clicked()
{
    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer ce coli ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        bool res ;
        coli c;
        QString q ;
        QModelIndex index ;
        QModelIndexList selection = ui->tableColi->selectionModel()->selectedRows();
        for (int i =0;i<selection.count();i++)
        {
            index=selection.at(i);
            q=QVariant(ui->tableColi->model()->index(index.row(),0).data()).toString();
            res = c.supprimerColi(q) ;
                if (res == QDialog::Accepted)
                {
                        ui->tableColi->setModel(tmpcoli.afficherColi());
                        QMessageBox::information(nullptr, QObject::tr("Supprimer un coli"),
                        QObject::tr("coli supprimé.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
                }
        }
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "Annulation", "La suppression de ce coli a ete annuler !");
    }

}

void Gestion_Coli_Courrier::on_Load_1_clicked()
{
    ui->tableColi->setModel(tmpcoli.afficherColi());
}

void Gestion_Coli_Courrier::on_Modifiercoli_clicked()
{
    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment modifier l'etat de ce coli ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        bool res ;
        coli c;
        QString q ;
        QString q2 ;
        QString q3 ;
        QModelIndex index ;
        QModelIndexList selection = ui->tableColi->selectionModel()->selectedRows();
        for (int i =0;i<selection.count();i++)
        {
            index=selection.at(i);
            q=QVariant(ui->tableColi->model()->index(index.row(),0).data()).toString();
            q2=QVariant(ui->tableColi->model()->index(index.row(),6).data()).toString();
            q3=QVariant(ui->tableColi->model()->index(index.row(),7).data()).toString();
            res = c.modifierColi(q,q2,q3) ;
                if (res == QDialog::Accepted)
                {
                        ui->tableColi->setModel(tmpcoli.afficherColi());
                        QMessageBox::information(nullptr, QObject::tr("Modifier un coli"),
                        QObject::tr("coli modifier.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
                }
        }
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "Annulation", "La modification de l'etat de ce coli a ete annuler !");
    }
}

void Gestion_Coli_Courrier::on_stat1_clicked()
{
    stat_etat stat_etat;
    stat_etat.setModal(true);
    stat_etat.exec();
}

void Gestion_Coli_Courrier::on_tri_coli_clicked()
{
    QString mode;
        if (ui->checkBox_2->isChecked())
        {
            mode="DESC";
        }
        else
        {
            mode="ASC";
        }
        ui->tableColi->setModel(tmpcoli.trier(ui->comboBox_4->currentText(),mode));
}

void Gestion_Coli_Courrier::on_recherche_textChanged(const QString &arg1)
{
    ui->tableColi->setModel(tmpcoli.recherche(arg1));
}

//***********************************CRUD Courrier***********************************

void Gestion_Coli_Courrier::on_ajoutercourrier_clicked()
{
    int reponse = QMessageBox::question(this, "Confirmation","Voulez vous ajouter ce courrier ?", QMessageBox ::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QString idcourrier=ui->IDcourrier->text();
            QString type=ui->type_courrier->currentText();
            QString adresseem=ui->Adresseem_2->toPlainText();
            QString adressedest=ui->Adressedest_2->toPlainText();
            QString priorite=ui->Priorite_2->currentText();
            int prix=ui->prix_2->text().toInt();
            QString etat=ui->etat_2->currentText();

            courrier c(idcourrier,type,adresseem,adressedest,priorite,prix,etat);
            bool test= c.ajouterCourrier();
            if(test)
            {
                ui->tableView_2->setModel(tmpcourrier.afficherCourrier());//refresh
                QMessageBox::information(nullptr, QObject::tr("Ajouter un courrier"),
                QObject::tr("courrier ajouté.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
            }
          else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter un courrier"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else if (reponse == QMessageBox::No)
        {
             QMessageBox::critical(this, "Annulation","L'ajout de ce courrier a ete annuler !");
        }
}

void Gestion_Coli_Courrier::on_suppcourrier_clicked()
{
    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer ce courrier ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
    bool res ;
    courrier c;
    QString q ;
    QModelIndex index ;
    QModelIndexList selection = ui->tableView_2->selectionModel()->selectedRows();
    for (int i =0;i<selection.count();i++)
    {
        index=selection.at(i);
        q=QVariant(ui->tableView_2->model()->index(index.row(),0).data()).toString();
        res = c.supprimerCourrier(q) ;
            if (res == QDialog::Accepted)
            {
                    ui->tableView_2->setModel(tmpcourrier.afficherCourrier());
                    QMessageBox::information(nullptr, QObject::tr("Supprimer un courrier"),
                    QObject::tr("courrier supprimé.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
    }
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "Annulation","La suppression de ce courrier a ete annuler !");
    }
}
void Gestion_Coli_Courrier::on_ModifierCourrier_clicked()
{
    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment modifier ce courrier ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
    bool res ;
    courrier c;
    QString q,q2 ;
    QModelIndex index ;
    QModelIndexList selection = ui->tableView_2->selectionModel()->selectedRows();
    for (int i =0;i<selection.count();i++)
    {
        index=selection.at(i);
        q=QVariant(ui->tableView_2->model()->index(index.row(),0).data()).toString();
        q2=QVariant(ui->tableView_2->model()->index(index.row(),6).data()).toString();
        res = c.modifierCourrier(q,q2) ;
            if (res == QDialog::Accepted)
            {
                    ui->tableView_2->setModel(tmpcourrier.afficherCourrier());
                    QMessageBox::information(nullptr, QObject::tr("Modifier un courrier"),
                    QObject::tr("Courrier Modifié.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
    }
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "Annulation","La modification de ce courrier a ete annuler !");
    }
}

void Gestion_Coli_Courrier::on_Load_2_clicked()
{
    ui->tableView_2->setModel(tmpcourrier.afficherCourrier());
}

void Gestion_Coli_Courrier::on_stat2_clicked()
{
    stat_etat stat_etat;
    stat_etat.setModal(true);
    stat_etat.exec();
}

void Gestion_Coli_Courrier::on_tri_coli_2_clicked()
{
    QString mode;
    if (ui->checkBox_3->isChecked())
    {
        mode="DESC";
    }
    else
    {
        mode="ASC";
    }
    ui->tableView_2->setModel(tmpcourrier.trier(ui->comboBox_5->currentText(),mode));
}

void Gestion_Coli_Courrier::on_recherche_2_textChanged(const QString &arg1)
{
 ui->tableView_2->setModel(tmpcourrier.recherche(arg1));
}

//***********************************CRUD Equipement***********************************

void Gestion_Coli_Courrier::on_ajouterequip_clicked()
{
    int reponse = QMessageBox::question(this, "Confirmation","Voulez vous ajouter cet equipement ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QString idequip=ui->lineEdit_2->text();

        QString type;
        if (ui->comboBox_3->currentText()!="Autre")
        {
          type=ui->comboBox_3->currentText();
        }
        if (ui->comboBox_3->currentText()=="Autre")
        {
          type=ui->type_equip->text();
        }

        int dispo;
        if (ui->checkBox->isChecked())
        {
            dispo=1;
        }
        else
        {
            dispo=0;
        }
        equipement e(idequip,type,dispo);
        bool test= e.ajouterEquip();
        if(test)
        {
        ui->tableView_3->setModel(tmpequip.afficherEquip());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
        QObject::tr("Equipement ajouté.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else if (reponse == QMessageBox::No)
    {
         QMessageBox::critical(this, "Annulation","L'ajout de cet équipement a ete annuler !");
    }
}

void Gestion_Coli_Courrier::on_supp_equip_clicked()
{
    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer cet équipement ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
    bool res ;
    equipement e;
    QString q ;
    QModelIndex index ;
    QModelIndexList selection = ui->tableView_3->selectionModel()->selectedRows();
    for (int i =0;i<selection.count();i++)
    {
        index=selection.at(i);
        q=QVariant(ui->tableView_3->model()->index(index.row(),0).data()).toString();
        res = e.supprimerEquip(q) ;
            if (res == QDialog::Accepted)
            {
                    ui->tableView_3->setModel(tmpequip.afficherEquip());
                    QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Equipement supprimé.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
    }
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "Annulation","La suppression de cet équipement a ete annuler !");
    }
}

void Gestion_Coli_Courrier::on_Load_3_clicked()
{
   ui->tableView_3->setModel(tmpequip.afficherEquip());
}

void Gestion_Coli_Courrier::on_recherche_3_textChanged(const QString &arg1)
{
    ui->tableView_3->setModel(tmpequip.recherche(arg1));
}

//***********************************CRUD Livraison***********************************

void Gestion_Coli_Courrier::on_refresh_clicked()
{
    ui->comboBox->setModel(tmpcoli.afficheridcoli());
    ui->comboBox_2->setModel(tmpequip.afficheridequip());
}

void Gestion_Coli_Courrier::on_ajouterliv_clicked()
{
    int reponse = QMessageBox::question(this, "Confirmation","Voulez vous ajouter cette livraison ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QString idliv=ui->lineEdit_idliv->text();
        QString lidcoli=ui->comboBox->currentText();
        QString lidequip=ui->comboBox_2->currentText();
        QDate ldate=ui->dateTimeEdit->date();
        livraison l(idliv,lidcoli,lidequip,ldate);

        bool test= l.ajouterLiv();
        if(test)
        {
            ui->tableView_4->setModel(tmpliv.afficherLiv());//refresh
            QMessageBox::information(nullptr, QObject::tr("Ajouter une livraison"),
            QObject::tr("Livraison ajouté.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

            //Modifier l'etat d'un coli aprés l'ajout
            bool res = l.modifierLiv(lidcoli) ;
            if (res == QDialog::Accepted)
            {
                ui->tableColi->setModel(tmpcoli.afficherColi());
                QMessageBox::information(nullptr, QObject::tr("Modification d'etat"),
                QObject::tr("L'etat de ce coli a ete modifier avec succes.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
            /*
            //Impression
            int reponse = QMessageBox::question(this, "Confirmation","Voulez vous imprimer cette livraison ?",QMessageBox ::Yes|QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                //Fonction imprimer
            }
            else if (reponse == QMessageBox::No)
            {
                 QMessageBox::critical(this, "Annulation", "L'impression de cette livraison a ete annuler !");
            }
            */
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une livraison"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }
    else if (reponse == QMessageBox::No)
    {
         QMessageBox::critical(this, "Annulation", "L'ajout de cette livraison a ete annuler !");
    }
}

void Gestion_Coli_Courrier::on_supp_liv_clicked()
{
    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer cette livraison ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        bool res ;
        livraison l;
        QString q ;
        QModelIndex index ;
        QModelIndexList selection = ui->tableView_4->selectionModel()->selectedRows();
        for (int i =0;i<selection.count();i++)
            {
                index=selection.at(i);
                q=QVariant(ui->tableView_4->model()->index(index.row(),0).data()).toString();
                res = l.supprimerLiv(q) ;
                if (res == QDialog::Accepted)
                {
                    ui->tableView_4->setModel(tmpliv.afficherLiv());
                    QMessageBox::information(nullptr, QObject::tr("Supprimer une livraison"),
                    QObject::tr("livraison supprimé.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
                }
            }
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "Annulation", "La suppression de cette livraison a ete annuler !");
    }
}

void Gestion_Coli_Courrier::on_Load_4_clicked()
{
    ui->tableView_4->setModel(tmpliv.afficherLiv());
}

void Gestion_Coli_Courrier::on_recherche_4_textChanged(const QString &arg1)
{
    ui->tableView_4->setModel(tmpliv.recherche(arg1));
}

//***************************************************************
void Gestion_Coli_Courrier::on_PDF_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableColi->model()->rowCount();
                const int columnCount =ui->tableColi->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<h1>Liste des COLIS</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableColi->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableColi->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableColi->isColumnHidden(column)) {
                                   QString data = ui->tableColi->model()->data(ui->tableColi->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("coli.pdf");
        document->print(&printer);
}

void Gestion_Coli_Courrier::on_PDF_2_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView_2->model()->rowCount();
                const int columnCount =ui->tableView_2->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"

                            "<h1>Liste des ALIMENT</h1>"


                            "<table border=1 cellspacing=0 cellpadding=2>\n";


                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_2->isColumnHidden(column)) {
                                   QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("courrier.pdf");
        document->print(&printer);
}

/*
Push_bouton pour recherche
void Gestion_Coli_Courrier::on_pushButton_2_recherche_4_clicked()
{
    QString idliv= ui->recherche_4->text();
    ui->tableView_4->setModel(tmpliv.recherche(idliv));
}
*/


void Gestion_Coli_Courrier::on_EXCEL1_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableColi);
        //colums to export
        obj.addField(0, "IDCOLI", "char(20)");
        obj.addField(1, "ADRESSEEM", "char(20)");
        obj.addField(2, "ADRESSEDEST", "char(20)");
        obj.addField(3, "PRIORITE", "char(20)");
        obj.addField(4, "POIDS", "char(20)");
        obj.addField(5, "PRIX", "char(20)");
        obj.addField(6, "ETAT", "char(20)");
        obj.addField(7, "AVECLIV", "char(20)");
        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}

void Gestion_Coli_Courrier::on_EXCEL_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableView_2);
        //colums to export
        obj.addField(0, "IDCOURRIER", "char(20)");
        obj.addField(1, "ADRESSEEM", "char(20)");
        obj.addField(2, "ADRESSEDEST", "char(20)");
        obj.addField(3, "PRIORITE", "char(20)");
        obj.addField(4, "TYPE", "char(20)");
        obj.addField(5, "PRIX", "char(20)");
        obj.addField(6, "ETAT", "char(20)");
        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}
