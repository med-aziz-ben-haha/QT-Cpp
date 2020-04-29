#include "addconge.h"
#include "ui_addconge.h"
#include "global.h"

addconge::addconge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addconge)
{
    ui->setupUi(this);
}

addconge::~addconge()
{
    delete ui;
}

QDate addconge::date_debut() const {
    return ui->datedebut->date();
}
QDate addconge::date_fin() const {
    return ui->datefin->date();

}
QString addconge::commentaire() const {
    return ui->commentaire->toPlainText();
}

QString addconge::raison() const {

    return ui->raison->currentText();
}

//configure ok and cancel
void addconge::on_buttonBox_accepted()
{
accept();
}

void addconge::on_buttonBox_rejected()
{
    reject();
}
void addconge::show_demande() {
    QSqlQuery bery;
    bery.prepare("select * from DEMANDE_CONGE where ID='"+sel_cong+"'");
    bery.exec();
    while(bery.next()){
 ui->commentaire->setText(bery.value(7).toString());
 ui->raison->setCurrentText(bery.value(4).toString());
 ui->datedebut->setDate(QDate::fromString(bery.value(2).toString(),"dd/MM/yyyy"));
 ui->datefin->setDate(QDate::fromString(bery.value(3).toString(),"dd/MM/yyyy"));

    }

}
void addconge::show_demande_rh() {
    QSqlQuery bery;
    bery.prepare("select * from DEMANDE_CONGE where ID='"+sel_cong_rh+"'");
    bery.exec();
    while(bery.next()){
 ui->commentaire->setText(bery.value(4).toString());
 ui->datedebut->setDate(QDate::fromString(bery.value(2).toString(),"dd/MM/yyyy"));
 ui->datefin->setDate(QDate::fromString(bery.value(3).toString(),"dd/MM/yyyy"));
    }

}
