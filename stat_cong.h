#ifndef STAT_CONG_H
#define STAT_CONG_H

#include <QMainWindow>

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

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_cong;
}

class stat_cong : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat_cong(QWidget *parent = nullptr);
    ~stat_cong();
    QChartView *chartView ;
    QChartView* demande();
    QChartView* accepte();

private:
    Ui::stat_cong *ui;
};

#endif // STAT_CONG_H
