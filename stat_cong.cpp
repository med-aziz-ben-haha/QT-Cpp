#include "stat_cong.h"
#include "ui_stat_cong.h"

stat_cong::stat_cong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stat_cong)
{
    ui->setupUi(this);
}

stat_cong::~stat_cong()
{
    delete ui;
}


QChartView* stat_cong::accepte(){
    QSqlQuery q1,q2,q3,q4,q5,q6;
    qreal tot=0,annuel=0,maternite=0,maladie=0,exceptionnel=0,deces_naissance=0;

    q1.prepare("SELECT * FROM DEMANDE_CONGE WHERE ETAT='1'");
    q1.exec();

    q2.prepare("SELECT * FROM DEMANDE_CONGE WHERE (ETAT='1' AND RAISON='Annuel') ");
    q2.exec();

    q3.prepare("SELECT * FROM DEMANDE_CONGE WHERE (ETAT='1' AND RAISON='Maternite') ");
    q3.exec();

    q4.prepare("SELECT * FROM DEMANDE_CONGE WHERE (ETAT='1' AND RAISON='Maladie' )");
    q4.exec();

    q5.prepare("SELECT * FROM DEMANDE_CONGE WHERE ( ETAT='1' AND RAISON='Exceptionnel') ");
    q5.exec();

    q6.prepare("SELECT * FROM DEMANDE_CONGE WHERE ( ETAT='1' AND RAISON='Naissance / Deces') ");
    q6.exec();

    while (q1.next()){tot++;}
    while (q2.next()){annuel++;}
    while (q3.next()){maternite++;}
    while (q4.next()){maladie++;}
    while (q5.next()){exceptionnel++;}
    while (q6.next()){deces_naissance++;}


    annuel=annuel/tot;
    maternite=maternite/tot;
    maladie=maladie/tot;
    exceptionnel=exceptionnel/tot;
    deces_naissance=deces_naissance/tot;


    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Annuel",annuel);
    series->append("Maladie",maladie);
    series->append("Maternité",maternite);
    series->append("Naissance / Décés",deces_naissance);
    series->append("Exceptionnel",exceptionnel);

    // Add label, explode and define brush for annuel
    QPieSlice *slice1 = series->slices().at(0);
    slice1->setExploded();
    slice1->setBrush(Qt::green);

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
   chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

QChartView* stat_cong::demande(){
    QSqlQuery q1,q2,q4,q5;
    qreal tot=0,annuel=0,maladie=0,exceptionnel=0;

    q1.prepare("SELECT * FROM DEMANDE_CONGE WHERE ETAT='0'");
    q1.exec();

    q2.prepare("SELECT * FROM DEMANDE_CONGE WHERE (ETAT='0' AND RAISON='Annuel') ");
    q2.exec();

    q4.prepare("SELECT * FROM DEMANDE_CONGE WHERE (ETAT='0' AND RAISON='Maladie' )");
    q4.exec();

    q5.prepare("SELECT * FROM DEMANDE_CONGE WHERE ( ETAT='0' AND RAISON='Exceptionnel') ");
    q5.exec();



    while (q1.next()){tot++;}
    while (q2.next()){annuel++;}
    while (q4.next()){maladie++;}
    while (q5.next()){exceptionnel++;}


    annuel=annuel/tot;
    maladie=maladie/tot;
    exceptionnel=exceptionnel/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Annuel",annuel);
    series->append("Maladie",maladie);
    series->append("Exceptionnel",exceptionnel);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();
    chart->localizeNumbers();


    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
