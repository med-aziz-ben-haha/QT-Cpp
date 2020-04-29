#include "addemp.h"
#include "global.h"
#include <QMessageBox>
#include <QDate>

#include "ui_addemp.h"

addemp::addemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addemp)
{
    ui->setupUi(this);
}

addemp::~addemp()
{
    delete ui;
}

//configure ok and cancel
void addemp::on_buttonBox_accepted()
{
accept();
}

void addemp::on_buttonBox_rejected()
{
    reject();
}


//get informations from form
QString addemp::nom() const {

    return ui->nom->text();
}
QString addemp::nationality() const {

    return ui->nationality->text();
}
QString addemp::adress() const {

    return ui->adress->text();
}

QDate addemp::naissance() const {

    return ui->naissance->date();
}

QTime addemp::debut() const {

    return ui->starting_time->time();
}

 QString addemp::competence() const {

     return ui->competence->text();
 }
QString addemp::zip () const{

     return ui->zip->text();
 }
QString addemp::phone() const{

    return ui->phone->text();
}
QString addemp::dep() const {

    return ui->dep->currentText();
}

QString addemp::sexe() const {

    return ui->sex->currentText();
}

QString addemp::etat() const {

    return ui->conjugal->currentText();
}

QString addemp::title() const {

    return ui->title->currentText();
}
int addemp::hour() const{

    return ui->hour->value();
}

int addemp::conge() const{

    return ui->conge->value();
}
double addemp::hour_sal() const{

    return ui->hour_sal->value();
}

QString addemp::cin() const{

    return ui->cin->text();
}

void addemp::show() {
    QSqlQuery bery;
    bery.prepare("select * from EMPLOYE where CIN='"+sel_emp+"'");
    bery.exec();
    while(bery.next()){
   ui->cin->setText(bery.value(0).toString());
 ui->nom->setText(bery.value(1).toString());
 ui->adress->setText(bery.value(2).toString());
 ui->zip->setText(bery.value(3).toString());
 ui->nationality->setText(bery.value(4).toString());
 ui->phone->setText(bery.value(5).toString());
 ui->competence->setText(bery.value(10).toString());
 ui->hour->setValue(bery.value(9).toInt());
 ui->conge->setValue(bery.value(13).toInt());
 ui->dep->setCurrentText(bery.value(6).toString());
 ui->title->setCurrentText(bery.value(7).toString());
 ui->sex->setCurrentText(bery.value(14).toString());
 ui->conjugal->setCurrentText(bery.value(15).toString());
 ui->naissance->setDate(QDate::fromString(bery.value(16).toString(),"dd.MM.yyyy"));
 ui->hour_sal->setValue(bery.value(8).toReal());
 ui->starting_time->setTime(QTime::fromString(bery.value(17).toString(),"hh.mm"));
    }

}

