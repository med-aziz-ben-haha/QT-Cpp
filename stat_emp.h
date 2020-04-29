#ifndef STAT_EMP_H
#define STAT_EMP_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QKeyEvent>

QT_CHARTS_USE_NAMESPACE

#include <QMainWindow>

namespace Ui {
class stat_emp;
}

class stat_emp : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat_emp(QWidget *parent = nullptr);
    ~stat_emp();

    QChartView *chartView ;
    void departement();
    void titre();
    void sexe();
    void etat_conjugal();
    void keyPressEvent(QKeyEvent *);

private slots:
  //  void on_actionnext_page_triggered();

 //   void on_actionprevious_page_triggered();

private:
    Ui::stat_emp *ui;
};

#endif // STAT_EMP_H
