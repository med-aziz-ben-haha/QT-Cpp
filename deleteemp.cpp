#include "deleteemp.h"
#include "ui_deleteemp.h"

deleteemp::deleteemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteemp)
{
    ui->setupUi(this);
}

deleteemp::~deleteemp()
{
    delete ui;
}

//configure ok and cancel
void deleteemp::on_buttonBox_accepted()
{
accept();
}

void deleteemp::on_buttonBox_rejected()
{
    reject();
}


//get informations from form
QString deleteemp::cin() const {

    return ui->cindelete->toPlainText();
}
