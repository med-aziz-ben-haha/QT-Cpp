#include "stat_client.h"
#include "ui_stat_client.h"
#include <QSqlQuery>
#include <QDebug>
stat_client::stat_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_client)
{
    ui->setupUi(this);

    QSqlQuery q1,q2,q3;
        int n=0;
        qreal test1=0,test2=0;
        q1.prepare("SELECT * FROM CLIENT WHERE NBP<300");
        q1.exec();
        q2.prepare("SELECT * FROM CLIENT WHERE NBP>300");
        q2.exec();
        n=q1.value(6).toInt();
        qDebug() << n;
        while (q1.next()){test1++;}
        while (q2.next()){test2++;}

            // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("Clients ayant moins de 300 points ");
            QBarSet *set1 = new QBarSet("Clients ayant plus de 300 points ");
            // Assign values for each bar
            *set0 << test1 ;
            *set1 << test2 ;

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
            chart->setTitle("Statistiques des points des clients");

            // Define starting animation
            // NoAnimation, GridAxisAnimations, SeriesAnimations
            chart->setAnimationOptions(QChart::AllAnimations);

            // Holds the category titles
            QStringList categories;
            categories << "Points" ;

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
            chartView->setParent(ui->stat);
}

stat_client::~stat_client()
{
    delete ui;
}
