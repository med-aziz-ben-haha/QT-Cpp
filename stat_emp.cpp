#include "stat_emp.h"
#include "ui_stat_emp.h"


stat_emp::stat_emp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stat_emp)
{
    ui->setupUi(this);
}

stat_emp::~stat_emp()
{
    delete ui;
}

void stat_emp::titre(){
    QSqlQuery q1,q2,q3,q4,q5,q6;
    qreal tot=0,emp=0,adm=0,sai=0,sta=0,con=0;

    q1.prepare("SELECT * FROM EMPLOYE");
    q1.exec();

    q2.prepare("SELECT * FROM EMPLOYE WHERE TITRE='EMP' ");
    q2.exec();

    q3.prepare("SELECT * FROM EMPLOYE WHERE TITRE='ADM' ");
    q3.exec();

    q4.prepare("SELECT * FROM EMPLOYE WHERE TITRE='SAI'");
    q4.exec();

    q5.prepare("SELECT * FROM EMPLOYE WHERE TITRE='STA' ");
    q5.exec();

    q6.prepare("SELECT * FROM EMPLOYE WHERE TITRE='CON' ");
    q6.exec();

    while (q1.next()){tot++;}
    while (q2.next()){emp++;}
    while (q3.next()){adm++;}
    while (q4.next()){sai++;}
    while (q5.next()){sta++;}
    while (q6.next()){con++;}


    emp=emp/tot;
    adm=adm/tot;
    sai=sai/tot;
    sta=sta/tot;
    con=con/tot;


    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Employe",emp);
    series->append("Chef de departement",adm);
    series->append("Saisonier",sai);
    series->append("Stagiaire",sta);
    series->append("Contractuel",con);



    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_1);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(500,500);

 chartView->show();
}

void stat_emp::departement(){
    QSqlQuery q1,q4,q5,q6;
    qreal tot=0,rh=0,cl=0,co=0;

    q1.prepare("SELECT * FROM EMPLOYE");
    q1.exec();

    q4.prepare("SELECT * FROM EMPLOYE WHERE DEPARTEMENT='RH'");
    q4.exec();

    q5.prepare("SELECT * FROM EMPLOYE WHERE DEPARTEMENT='CL' ");
    q5.exec();

    q6.prepare("SELECT * FROM EMPLOYE WHERE DEPARTEMENT='CO' ");
    q6.exec();

    while (q1.next()){tot++;}
    while (q4.next()){rh++;}
    while (q5.next()){cl++;}
    while (q6.next()){co++;}

    rh=rh/tot;
    cl=cl/tot;
    co=co/tot;


    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Lettres & Colis",cl);
    series->append("Comptabilité",co);
    series->append("Resources humaine",rh);

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();

    // Used to display the chart
    chartView = new QChartView(chart,ui->label_2);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(500,500);

    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // Apply palette changes to the application
    qApp->setPalette(pal);

 chartView->show();
}

void stat_emp::sexe(){
    QSqlQuery q1,q4,q6;
    qreal tot=0,h=0,f=0;

    q1.prepare("SELECT * FROM EMPLOYE");
    q1.exec();

    q4.prepare("SELECT * FROM EMPLOYE WHERE SEX='Homme'");
    q4.exec();


    q6.prepare("SELECT * FROM EMPLOYE WHERE SEX='Femme' ");
    q6.exec();

    while (q1.next()){tot++;}
    while (q4.next()){h++;}
    while (q6.next()){f++;}

    h=h/tot;
    f=f/tot;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("Homme");
            QBarSet *set1 = new QBarSet("Femme");

            // Assign values for each bar
            *set0 << h;
            *set1 << f;



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


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_3);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(500,500);

 chartView->show();
}

void stat_emp::etat_conjugal(){
    QSqlQuery q1,q3,q4,q5,q6;
    qreal tot=0,div=0,mar=0,veuf=0,celib=0;

    q1.prepare("SELECT * FROM EMPLOYE");
    q1.exec();

    q3.prepare("SELECT * FROM EMPLOYE WHERE ETAT='Celibataire' ");
    q3.exec();

    q4.prepare("SELECT * FROM EMPLOYE WHERE ETAT='Marrie'");
    q4.exec();

    q5.prepare("SELECT * FROM EMPLOYE WHERE ETAT='Divorce' ");
    q5.exec();

    q6.prepare("SELECT * FROM EMPLOYE WHERE ETAT='Veuf / Veuve' ");
    q6.exec();

    while (q1.next()){tot++;}
    while (q3.next()){celib++;}
    while (q4.next()){mar++;}
    while (q5.next()){div++;}
    while (q6.next()){veuf++;}


    celib=celib/tot;
    mar=mar/tot;
    div=div/tot;
    veuf=veuf/tot;


    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Célibataire",celib);
    series->append("Marrié(e)",mar);
    series->append("Divorcé(e)",div);
    series->append("Veuf / Veuve",veuf);



    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_4);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(500,500);

 chartView->show();
}

void stat_emp::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_N)
    {
        int nextIndex = ui->stackedWidget->currentIndex() + 1;
        if( nextIndex < ui->stackedWidget->count())
               ui->stackedWidget->setCurrentIndex(nextIndex);
        else ui->stackedWidget->setCurrentIndex(0);
    }

    if(event->key() == Qt::Key_P)
    {
        int prevIndex = ui->stackedWidget->currentIndex() - 1;
        if( prevIndex >= 0)
               ui->stackedWidget->setCurrentIndex(prevIndex);
        else ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
    }
}

