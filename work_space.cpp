#include "work_space.h"
#include "ui_work_space.h"
#include "addemp.h"

#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>

#include "addconge.h"

#include "deleteemp.h"
#include "stat_cong.h"
#include "global.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QtWidgets>

#include "exportexcelobject.h"
#include <QFileDialog>

#include <QApplication>

work_space::work_space(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::work_space)
{
    ui->setupUi(this);

  ui->tabdemande->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tabdemande->verticalHeader()->hide();
  ui->tabdemande_rh->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tabdemande_rh->verticalHeader()->hide();
  ui->tabaccept->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tabaccept->verticalHeader()->hide();
  ui->tabaccept_rh->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tabaccept_rh->verticalHeader()->hide();
  ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->tableView->verticalHeader()->hide();



  //show database content
 QString cnt="hello";
    QSqlQuery berry;
    berry.prepare("select count(*) from DEMANDE_CONGE");
    berry.exec();
     while(berry.next()){
            cnt=berry.value(0).toString();
     }

     count=cnt.toInt();

show_tables();







//get some info from database about connected user
    QSqlQuery bery;
QString time;
    bery.prepare("select * from EMPLOYE where CIN='"+tmp+"'");
    bery.exec();
    while(bery.next()){
  name = bery.value(1).toString();
time=bery.value(11).toString();
conge_rest=bery.value(13).toInt();
heure_stand=bery.value(9).toInt();
    }
chat();
show_chat();

    //conteur heures travaillees
heure_tr=time.split(":").first().toInt();
mm=time.split(":").last().toInt();
    chrono = new QTimer(this);
    connect(chrono,SIGNAL(timeout()),this,SLOT(work_counter()));
    chrono->start(1000);



          //refresh tables content every n seconds
          int n=10;
          timer = new QTimer(this);
          connect(timer,SIGNAL(timeout()),this,SLOT(show_tables()));
          timer->start(1000*n);

          //for email tab
                    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
                    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

                    m_speech = new QTextToSpeech(this);

                  m_speech->say(name+" logged in.");
}




void work_space::show_chat()
{
ui->lineEdit_2->setFocusPolicy(Qt::StrongFocus);
ui->textEdit->setFocusPolicy(Qt::NoFocus);
ui->textEdit->setReadOnly(true);
ui->listWidget->setFocusPolicy(Qt::NoFocus);

connect( ui->lineEdit_2, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
connect( ui->lineEdit_2, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
connect(&client, SIGNAL(newMessage(QString,QString)),
       this, SLOT(appendMessage(QString,QString)));
connect(&client, SIGNAL(newParticipant(QString)),
       this, SLOT(newParticipant(QString)));
connect(&client, SIGNAL(participantLeft(QString)),
       this, SLOT(participantLeft(QString)));

myNickName = client.nickName();
newParticipant(myNickName);
tableFormat.setBorder(0);

}




void work_space::appendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;

    QTextCursor cursor(ui->textEdit->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, tableFormat);
    table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
    table->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar = ui->textEdit->verticalScrollBar();
    bar->setValue(bar->maximum());
}

void work_space::returnPressed()
{
    QString text = ui->lineEdit_2->text();
    if (text.isEmpty())
        return;

    if (text.startsWith(QChar('/'))) {
        QColor color = ui->textEdit->textColor();
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(tr("! Unknown command: %1")
                         .arg(text.left(text.indexOf(' '))));
        ui->textEdit->setTextColor(color);
    } else {
        client.sendMessage(text);
        appendMessage(myNickName, text);
    }

    ui->lineEdit_2->clear();
}

void work_space::newParticipant(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QColor color = ui->textEdit->textColor();
    ui->textEdit->setTextColor(Qt::gray);
    ui->textEdit->append(tr("* %1 has joined").arg(nick));
    ui->textEdit->setTextColor(color);
    ui->listWidget->addItem(nick);
}

void work_space::participantLeft(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QList<QListWidgetItem *> items = ui->listWidget->findItems(nick,
                                                           Qt::MatchExactly);
    if (items.isEmpty())
        return;

    delete items.at(0);
    QColor color = ui->textEdit->textColor();
    ui->textEdit->setTextColor(Qt::gray);
   ui-> textEdit->append(tr("* %1 has left").arg(nick));
   ui-> textEdit->setTextColor(color);
}

void work_space::chat()
{
QNetworkConfigurationManager manager;
if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
    // Get saved network configuration
    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
    settings.endGroup();

    // If the saved network configuration is not currently discovered use the system default
    QNetworkConfiguration config = manager.configurationFromIdentifier(id);
    if ((config.state() & QNetworkConfiguration::Discovered) !=
        QNetworkConfiguration::Discovered) {
        config = manager.defaultConfiguration();
    }

    QNetworkSession *networkSession = new QNetworkSession(config,this);
    networkSession->open();
    networkSession->waitForOpened();

    if (networkSession->isOpen()) {
        // Save the used configuration
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice) {
            id = networkSession->sessionProperty(
                    QLatin1String("UserChoiceConfiguration")).toString();
        } else {
            id = config.identifier();
        }

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }
}


}

void work_space::show_tables()
{

//table emp
    QSqlQuery * querry=new QSqlQuery(conn.db);
    QSqlQueryModel * modal=new QSqlQueryModel();
    querry->prepare("select CIN,NOM,MOBILE,DEPARTEMENT,TITRE,HEURE_STANDARD,CONGE,HEURES_TRAVAILLEES,SALAIRE_HORAIRE,COMPETENCE from EMPLOYE ");
    querry->exec();
    modal->setQuery(*querry);
    proxy_emp= new QSortFilterProxyModel(this);
    proxy_emp->setSourceModel(modal);
    proxy_emp->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy_emp->setFilterKeyColumn(-1);
    ui->tableView->setModel(proxy_emp);

//table cong demande (for emp)
proxy_cong_emp = new QSortFilterProxyModel(this);
proxy_cong_emp->setSourceModel(tmp_con.afficher_emp());
ui->tabdemande->setModel(proxy_cong_emp);


//table cong demande (for rh)
proxy_cong_rh = new QSortFilterProxyModel(this);
proxy_cong_rh->setSourceModel(tmp_con.afficher());
ui->tabdemande_rh->setModel(proxy_cong_rh);


//table cong accepte (for emp)
proxy_cong_accept_emp = new QSortFilterProxyModel(this);
proxy_cong_accept_emp->setSourceModel(tmp_con.afficher_accep_emp());
ui->tabaccept->setModel(proxy_cong_accept_emp);

//table cong accept (for rh)
proxy_cong_accept_rh = new QSortFilterProxyModel(this);
proxy_cong_accept_rh->setSourceModel(tmp_con.afficher_accep());
ui->tabaccept_rh->setModel(proxy_cong_accept_rh);

}

work_space::~work_space()
{
    delete ui;
}

void work_space::work_counter()
{
    QString worked_show,worked;
    QSqlQuery query,querry;

   ss++;
   if (ss==60){
       ss=0;
       mm++;

   }
   if (mm==60){
       heure_tr++;
       mm=0;
   }
   worked=QString::number(heure_tr)+":"+QString::number(mm);
  if(ss==59){
   query.prepare("UPDATE EMPLOYE SET HEURES_TRAVAILLEES = :worked WHERE CIN = :id ");
   query.bindValue(":id", tmp);
   query.bindValue(":worked", worked);
 query.exec();}
   worked_show=QString::number(heure_tr)+" : "+QString::number(mm)+" : "+QString::number(ss);
   QString connected="L'employé "+ tmp +" ( "+name+" ) est connecté     ||    "+ worked_show +" ";
          ui->statusBar->showMessage(connected);

          //give day off bonuses
          int extra=heure_tr-heure_stand*20;
          if(extra>=heure_stand*2)
          {
conge_rest++;
              heure_tr-=extra;
              querry.prepare("UPDATE EMPLOYE SET HEURES_TRAVAILLEES = :worked , CONGE = :cong WHERE CIN = :id ");
              querry.bindValue(":id", tmp);
               querry.bindValue(":cong",QString::number(conge_rest) );
              querry.bindValue(":worked",QString::number(heure_stand*20)+":0");
            querry.exec();
          }
}


void work_space::on_actionajouter_triggered()
{

    addemp ad(this);

    int res=ad.exec();
    if (res == QDialog::Rejected )
        return;

    //save form imput in variables
    QString nom,adresse,nationalite,competence,mobile,zip,title,dep,cin,mdp,sexe,etat,naissance,temp,worked;
    int hour,conge;
    double hour_sal;
    nom=ad.nom();
    sexe=ad.sexe();
    etat=ad.etat();
    adresse=ad.adress();
    nationalite=ad.nationality();
    competence=ad.competence();
    mobile=ad.phone();
    zip=ad.zip();
    hour=ad.hour();
    hour_sal=ad.hour_sal();
    dep=ad.dep();
    title=ad.title();
    cin=ad.cin();
    naissance=ad.naissance().toString("dd.MM.yyyy");
    temp=ad.debut().toString("hh.mm");
    conge=ad.conge();

    mdp=title+"-"+dep+"-"+cin;

    //insert employee in database
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE "
    "(CIN,NOM,ADRESSE,ZIP,NATIONALITE,MOBILE,DEPARTEMENT,TITRE,SALAIRE_HORAIRE,HEURE_STANDARD,COMPETENCE,HEURES_TRAVAILLEES,MDP, CONGE,SEX,ETAT,NAISSANCE,DEBUT) "
    "VALUES (:cin, :nom, :adr, :zip, :nat, :mob, :dep, :tit, :sal_h, :hs, :comp,0, :mdp, :conge,:sex,:etat,:naiss,:time)");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":adr",adresse);
    query.bindValue(":zip", zip);
    query.bindValue(":nat", nationalite);
    query.bindValue(":mob", mobile);
    query.bindValue(":dep", dep);
    query.bindValue(":tit", title);
    query.bindValue(":sal_h", hour_sal );
    query.bindValue(":hs", hour );
    query.bindValue(":comp", competence);

    query.bindValue(":mdp", mdp);
    query.bindValue(":conge", conge);
    query.bindValue(":sex", sexe);
    query.bindValue(":etat", etat);
    query.bindValue(":naiss", naissance);
query.bindValue(":time", temp);
    query.exec();

    //show database content

  show_tables();


}



void work_space::on_actionsupprimer_triggered()
{
    deleteemp de(this);

    int res=de.exec();
    if (res == QDialog::Rejected )
        return;
QString cin;
cin=de.cin();

       Connexion conn;

QSqlQuery quer;

quer.prepare("Delete from EMPLOYE where CIN in ("+cin+")");
quer.exec();

//show database content

show_tables();
}

void work_space::on_actionAccepter_cong_triggered()
{
    int cr=0;
    conge ac;
    QSqlQuery bery,query;
    bery.prepare("select * from DEMANDE_CONGE where ID='"+sel_cong_rh+"'");
    bery.exec();
    while(bery.next()){
 duree=bery.value(6).toInt();
 emp=bery.value(1).toString();
    }
ac.accept_cong();

query.prepare("select * from EMPLOYE where CIN='"+emp+"'");
query.exec();
while(query.next()){
cr=query.value(13).toInt();
}

  QSqlQuery querry;
  int new_cong;
  new_cong=cr-duree;
querry.prepare("UPDATE EMPLOYE SET CONGE = :cong WHERE CIN = :id ");
querry.bindValue(":id", emp);
 querry.bindValue(":cong",QString::number(new_cong) );
querry.exec();
show_tables();
}


void work_space::on_tableView_doubleClicked(const QModelIndex &index)
{
  addemp ad(this);

  sel_emp=ui->tableView->model()->data(index).toString();


ad.show();
int res=ad.exec();
if (res == QDialog::Rejected )
  return;

QString nom,adresse,nationalite,competence,mobile,zip,title,dep,cin,mdp,sexe,etat,naissance,temp,worked;
int hour,conge;
double hour_sal;
nom=ad.nom();
sexe=ad.sexe();
etat=ad.etat();
adresse=ad.adress();
nationalite=ad.nationality();
competence=ad.competence();
mobile=ad.phone();
zip=ad.zip();
hour=ad.hour();
hour_sal=ad.hour_sal();
dep=ad.dep();
title=ad.title();
cin=ad.cin();
naissance=ad.naissance().toString("dd.MM.yyyy");
temp=ad.debut().toString("hh.mm");
conge=ad.conge();

mdp=title+"-"+dep+"-"+cin;

//insert employee in database
QSqlQuery query;
query.prepare("UPDATE EMPLOYE SET "
"NOM = :nom,ADRESSE = :adr,ZIP = :zip,NATIONALITE = :nat,MOBILE = :mob,DEPARTEMENT = :dep,TITRE = :tit,SALAIRE_HORAIRE = :sal_h"
",HEURE_STANDARD = :hs,COMPETENCE = :comp,MDP = :mdp, CONGE = :conge,SEX = :sex,ETAT = :etat,NAISSANCE = :naiss,DEBUT = :time "
"WHERE CIN='"+sel_emp+"'");

query.bindValue(":nom", nom);
query.bindValue(":adr",adresse);
query.bindValue(":zip", zip);
query.bindValue(":nat", nationalite);
query.bindValue(":mob", mobile);
query.bindValue(":dep", dep);
query.bindValue(":tit", title);
query.bindValue(":sal_h", hour_sal );
query.bindValue(":hs", hour );
query.bindValue(":comp", competence);

query.bindValue(":mdp", mdp);
query.bindValue(":conge", conge);
query.bindValue(":sex", sexe);
query.bindValue(":etat", etat);
query.bindValue(":naiss", naissance);
query.bindValue(":time", temp);
query.exec();

//show database content

show_tables();



}

void work_space::on_ajout_conge_clicked()
{
    bool valid=false;
    addconge ac(this);

    int res=ac.exec();
    if (res == QDialog::Rejected )
        return;
      count+=1;
    QString con= QString::number(count);

    QString id= "c"+con+"-"+tmp;
    QString etat;
    QString date_debut,date_fin,commentaire,duree,raison;
     long long int diff;
    raison=ac.raison();

    //DETERMINER DATE FIN
    //en cas de maternite
    if (raison=="Maternite"){
        etat="1";
        date_fin= ac.date_debut().addMonths(2).toString("dd/MM/yyyy");
        diff = ac.date_debut().daysTo(ac.date_debut().addMonths(2));
        duree= QString::number(diff);
        valid=true;
    //message
    }
    //en cas de deces ou de naissance
    if (raison=="Naissance / Deces"){
        etat="1";
        date_fin= ac.date_debut().addDays(6).toString("dd/MM/yyyy");
        duree="6";
valid=true;
    //message
    }
    // en cas de maladie
   if (raison=="Maladie"){
        etat="0";
    date_fin= ac.date_fin().toString("dd/MM/yyyy");
    diff = ac.date_debut().daysTo(ac.date_fin());
    duree= QString::number(diff);
    valid=true;
    //message
  }
    // en cas conge annuel
    if (raison=="Annuel"){
        diff=ac.date_debut().daysTo(ac.date_fin());
if (ac.date_debut().month()>=7 && ac.date_debut().month()<=9 && ac.date_fin().month()>=7 && ac.date_fin().month()<=9
        &&  diff <= conge_rest ) {
    etat="0";
    date_fin= ac.date_fin().toString("dd/MM/yyyy");
    duree= QString::number(diff);
    valid=true;
}
    }
    //en cas de conge exceptionnel
    if (raison=="Exceptionnel"){
        diff = ac.date_debut().daysTo(ac.date_fin());
        if (conge_rest>=diff){
      etat="0";
      date_fin= ac.date_fin().toString("dd/MM/yyyy");
      duree= QString::number(diff);
      valid=true;
        }

    }

    date_debut= ac.date_debut().toString("dd/MM/yyyy");
    commentaire= ac.commentaire();
if (valid == true){
    conge c(id,etat,date_debut, date_fin,commentaire,duree,raison);
    c.ajouter();
}

show_tables();


}

void work_space::on_tabdemande_rh_pressed(const QModelIndex &index)
{
    sel_cong_rh=ui->tabdemande_rh->model()->data(index).toString();

}

void work_space::on_actionsupprimer_cong_triggered()
{
    conge ac;
ac.supprimer_rh();
show_tables();
}

void work_space::on_supp_conge_clicked()
{
    conge ac;
ac.supprimer();
show_tables();
}

void work_space::on_tabdemande_pressed(const QModelIndex &index)
{
    sel_cong=ui->tabdemande->model()->data(index).toString();

}

void work_space::on_actiondeconnecter_triggered()
{
     m_speech->say("Disconnected");
    close();
        MainWindow *ws;
    ws = new MainWindow();
    ws->setWindowTitle("Rapid Post");
    ws->show();


}

void work_space::on_tabdemande_doubleClicked()
{

    addconge ac(this);

  ac.show_demande();
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;

  QString date_debut,date_fin,commentaire,duree,raison;
  QString etat="0";
  date_fin= ac.date_fin().toString("dd/MM/yyyy");
  date_debut= ac.date_debut().toString("dd/MM/yyyy");
  commentaire= ac.commentaire();
  raison=ac.raison();
 long long int diff = ac.date_debut().daysTo(ac.date_fin());
  duree= QString::number(diff);
  QSqlQuery query;


  query.prepare("UPDATE DEMANDE_CONGE SET RAISON = :raison , DATE_DEBUT='"+date_debut+"', DATE_FIN='"+date_fin+"', commentaire='"+commentaire+"',DUREE='"+duree+"' WHERE ID='"+sel_cong+"'");
  query.bindValue(":raison", raison);
  query.exec();


}

void work_space::on_tabdemande_rh_doubleClicked()
{
    addconge ac(this);

  ac.show_demande_rh();
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;
}

void work_space::on_lineEdit_textChanged(const QString &arg1)
{
    proxy_emp->setFilterFixedString(arg1);
}

void work_space::on_stat_courrant_clicked()
{

    ws = new stat_cong();

    ws->setWindowTitle("statistique congés - Accepté(s)");
    ws->setCentralWidget(ws->accepte());
    ws->show();
}

void work_space::on_stat_demande_clicked()
{

  ws = new stat_cong();

    ws->setWindowTitle("statistique congés - Demande(s)");
 ws->setCentralWidget(ws->demande());
    ws->show();
}

void work_space::on_pushButton_clicked()
{
    se = new stat_emp();

  se->setWindowTitle("statistique Employés");
  se->departement();
  se->sexe();
  se->titre();
  se->etat_conjugal();
  se->show();

}

void work_space::on_pushButton_7_clicked()//export excel demandes acceptees
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tabaccept_rh);

    //colums to export
    obj.addField(0, "ID_Conge", "char(20)");
    obj.addField(1, "ID_Employe", "char(20)");
    obj.addField(2, "Raison", "char(20)");
    obj.addField(3, "Date_Debut", "char(20)");
    obj.addField(4, "Date_Fin", "char(20)");
    obj.addField(5, "Duree", "char(20)");
    obj.addField(6, "Commentaire", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

void work_space::on_pushButton_3_clicked() //export excel employees
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);

    //colums to export
    obj.addField(0, "CIN", "char(20)");
    obj.addField(1, "Nom", "char(20)");
    obj.addField(2, "Mobile", "char(20)");
    obj.addField(3, "Departement", "char(20)");
    obj.addField(4, "Titre", "char(20)");
    obj.addField(5, "Heures_Standards", "char(20)");
    obj.addField(6, "Jours_Conge", "char(20)");
    obj.addField(7, "Heures_Travaillees", "char(20)");
    obj.addField(8, "Salaire_Horaire", "char(20)");
    obj.addField(9, "Competences", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

void work_space::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void work_space::sendMail()
{
    Smtp* smtp = new Smtp("mohamedaziz.benhaha@esprit.tn","7a7a.kaka1998", "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("mohamedaziz.benhaha@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("mohamedaziz.benhaha@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void work_space::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
}

void work_space::on_import_excel_clicked()
{
QStandardItemModel *model = new QStandardItemModel;
    auto filename=QFileDialog::getOpenFileName(this,"import excel file",QDir::rootPath(),"Excel Files(*.csv)");
        if (filename.isEmpty()) return;

        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

        int lineindex = 0;                     // file line counter
          QTextStream in(&file);                 // read to text stream

          while (!in.atEnd()) {

              // read one line from textstream(separated by "\n")
              QString fileLine = in.readLine();

              // parse the read line into separate pieces(tokens) with "," as the delimiter
              QStringList lineToken = fileLine.split(",");

              // load parsed data to model accordingly
              for (int j = 0; j < lineToken.size(); j++) {
                  QString value = lineToken.at(j);
                  QStandardItem *item = new QStandardItem(value);
                  model->setItem(lineindex, j, item);
              }

              //save from model
              QString nom,competence,mobile,title,dep,cin, hour,conge,hour_sal;
              nom=model->index(lineindex,1).data().toString();
              competence=model->index(lineindex,8).data().toString();
              mobile=model->index(lineindex,2).data().toString();
              hour=model->index(lineindex,5).data().toString();
              hour_sal=model->index(lineindex,7).data().toString();
              dep=model->index(lineindex,3).data().toString();
              title=model->index(lineindex,4).data().toString();
              cin=model->index(lineindex,0).data().toString();
              conge=model->index(lineindex,6).data().toString();


              //insert employee in database
              QSqlQuery query;
              query.prepare("INSERT INTO EMPLOYE "
              "(       CIN,   NOM, MOBILE,DEPARTEMENT,TITRE, SALAIRE_HORAIRE,HEURE_STANDARD,HEURES_TRAVAILLEES,CONGE,COMPETENCE) "
              "VALUES (:cin, :nom, :mob, :dep,        :tit, :sal_h,          :hs,     0,                 :conge,           :comp)");
              query.bindValue(":cin", cin);
              query.bindValue(":nom", nom);
              query.bindValue(":mob", mobile);
              query.bindValue(":dep", dep);
              query.bindValue(":tit", title);
              query.bindValue(":sal_h", hour_sal );
              query.bindValue(":hs", hour );
              query.bindValue(":comp", competence);
              query.bindValue(":conge", conge);
              query.exec();


              lineindex++;
          }

           file.close();
           QString message_text=QString::number(lineindex-1)+"lines imported successfully. ";
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                               message_text, QMessageBox::Ok);

           show_tables();
}



void work_space::on_actionopen_music_triggered()
{
    QString filename="C:/Program Files (x86)/Windows Media Player/wmplayer.exe";
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
}
