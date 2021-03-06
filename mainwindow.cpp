#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "work_space.h"
#include <QMessageBox>
#include <QPixmap>
#include "gestion_coli_courrier.h"

// include the header of your workspace here

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->label_3);
    QPixmap log_pic(":/res/img/1200px-La_Poste_tunisienne_2011.svg.png");
   int  width_log_pic = ui ->label_pic ->width();
   int  height_log_pic = ui ->label_pic ->height();
    ui ->label_pic->setPixmap(log_pic.scaled(width_log_pic,height_log_pic,Qt::KeepAspectRatio));

    QPixmap bg_pic(":/res/img/bg.png");
   int  width_bg_pic = ui ->label_4 ->width();
   int  height_bg_pic = ui ->label_4 ->height();
    ui ->label_4->setPixmap(bg_pic.scaled(width_bg_pic,height_bg_pic));

    m_speech = new QTextToSpeech(this);
    if (login_times==0){
  m_speech->say("Database initialised successfully!");
login_times++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::user () const{

     return ui->lineEdit_userID->text();
 }

void MainWindow::on_pushButton_submit_clicked()
{
    QString userID;


    //extract userId and password
tmp=user();
    userID=user();
    QString given_password= ui->lineEdit_password->text();

    //check if userid is a number
    bool num ;
    int a=userID.toInt(&num,10);
    a++;

    //check if user is in default list
    QString users="adminRH adminCL"; // you add your ID in format admin(first 2 letters of your departement name)
    bool user_ex = users.contains(userID);

    //check if password is in default list
    QString password ="ADM-RH ADM-CL"; // you add your password in format ADM-(first 2 letters of your departement name)
    bool pass_ex = password.contains(given_password);


QSqlQuery qry;
 int count=0;
if(qry.exec( "select * from EMPLOYE where CIN='"+userID+"'and MDP='"+given_password+"'" ))
{

    while(qry.next()) {

        count++;
    }

if (count<1)
    ui->statusbar->showMessage("UserID and Password don't match",3000);

}
if(count==1 || (user_ex && pass_ex)){
close();

//open RH Space
/*
 ---------------pour tester------------
 username : 09870668
 mdp : EMP-RH-09870668

 ou bien

 username : adminRH
 mdp : ADM-RH
 --------------------------------------
*/

if (given_password.mid(4,2)=="RH"){ //given_password.mid(4,2)=="XX" -> XX are the 1st 2 letters of your departement name uppercased
work_space *ws;
ws = new work_space();
ws->setWindowTitle("Rapid Post");
ws->show();
}

//open Coli lettre Space
/*
 ---------------pour tester------------
 username : 12345678
 mdp : EMP-CL-12345678

 ou bien

 username : adminCL
 mdp : ADM-CL
 --------------------------------------
*/

if (given_password.mid(4,2)=="CL"){//given_password.mid(4,2)=="XX" -> XX are the 1st 2 letters of your departement name uppercased
Gestion_Coli_Courrier *cl;
cl = new Gestion_Coli_Courrier();
cl->setWindowTitle("Rapid Post");
cl->show();
}





}//end test login
    else if( userID.length()!= 8 )
           ui->statusbar->showMessage("Check the userID input format",3000);
    else if( given_password.length()<4 )
           ui->statusbar->showMessage("Password too short",3000);


}

