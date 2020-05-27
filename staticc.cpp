#include "staticc.h"
#include "ui_staticc.h"
#include"epargne.h"
#include"couraant.h"
#include <QDialog>
#include <QSqlQuery>

Staticc::Staticc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Staticc)
{
    ui->setupUi(this);
     this->setWindowTitle("Statistiques");
    //***************************************************************
       QSqlQuery q1,q2,q3;
           qreal en_stock=0,en_cours=0;


           q1.prepare("SELECT * FROM COMPTE");
           q1.exec();
           q2.prepare("SELECT * FROM COMPTE_COURANT");
           q2.exec();


           while (q1.next()){en_stock++;}
           while (q2.next()){en_cours++;}



           // Assign names to the set of bars used
           QBarSet *set0 = new QBarSet("Compte epargne ");
           QBarSet *set1 = new QBarSet("Compte courant ");
         //  QBarSet *set2 = new QBarSet("Livré / Envoyé ");

           // Assign values for each bar
           *set0 << en_stock ; //hethouma les variable eli fihom les valeurs
          *set1 << en_cours ;


           // Add all sets of data to the chart as a whole
           // 1. Bar Chart
           QBarSeries *series = new QBarSeries();

           // 2. Stacked bar chart
           //QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
           series->append(set0);
           series->append(set1);


           // Used to define the bar chart to display, title
           // legend,
           QChart *chart = new QChart();

           // Add the chart
           chart->addSeries(series);

           // Set title
           chart->setTitle("compte et compte courant");

           // Define starting animation
           // NoAnimation, GridAxisAnimations, SeriesAnimations
           chart->setAnimationOptions(QChart::AllAnimations);

           // Holds the category titles
           QStringList categories;
           categories <<"";

           // Adds categories to the axes
           QBarCategoryAxis *axis = new QBarCategoryAxis();
           axis->append(categories);
           chart->createDefaultAxes();

           // 1. Bar chart
           chart->setAxisX(axis,series);

           // 2. Stacked Bar chart
           // chart->setAxisY(axis, series);

           // Define where the legend is displayed
           chart->legend()->setVisible(true);
           chart->legend()->setAlignment(Qt::AlignBottom);

           // Used to display the chart
           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);

           // Used to change the palette
           QPalette pal = qApp->palette();

           // Change the color around the chart widget and text
           pal.setColor(QPalette::Window, QRgb(0xffffff));
           pal.setColor(QPalette::WindowText, QRgb(0x404044));

           // Apply palette changes to the application
           qApp->setPalette(pal);
           chartView->setParent(ui->horizontalFrame);

}

Staticc::~Staticc()
{
    delete ui;
}
