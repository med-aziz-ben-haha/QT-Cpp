#include "statt.h"
#include "ui_statt.h"
#include"carte_ce.h"
#include"carte_cc.h"
#include "carte_ed.h"
#include <QDialog>
#include <QSqlQuery>

statt::statt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statt)
{
    ui->setupUi(this);
     this->setWindowTitle("Statistiques");
    //***************************************************************
       QSqlQuery q1,q2,q3;
           qreal en_stock=0,en_cours=0,livre=0;
           //QSqlQuery q4,q5,q6;
          // qreal en_attente2=0,en_cours2=0,envoye2=0;

           q1.prepare("SELECT * FROM carte_cc ");
           q1.exec();
           q2.prepare("SELECT * FROM carte_ce ");
           q2.exec();
           q3.prepare("SELECT * FROM carte_ed ");
           q3.exec();

           while (q1.next()){en_stock++;}
           while (q2.next()){en_cours++;}
          while (q3.next()){livre++;}


           // Assign names to the set of bars used
           QBarSet *set0 = new QBarSet("les cartes du compte courant ");
           QBarSet *set1 = new QBarSet("les cartes du compte epargne ");
           QBarSet *set2 = new QBarSet("les cartes edinar ");

           // Assign values for each bar
         *set0 << en_stock ; //hethouma les variable eli fihom les valeurs
          *set1 << en_cours ;
           *set2 << livre ;

           // Add all sets of data to the chart as a whole
           // 1. Bar Chart
           QBarSeries *series = new QBarSeries();

           // 2. Stacked bar chart
           //QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
           series->append(set0);
           series->append(set1);
           series->append(set2);

           // Used to define the bar chart to display, title
           // legend,
           QChart *chart = new QChart();

           // Add the chart
           chart->addSeries(series);

           // Set title
           chart->setTitle("les cartes les plus utulisés");

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

statt::~statt()
{
    delete ui;
}
