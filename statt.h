#ifndef STATT_H
#define STATT_H
#include <QDialog>

#include <QApplication>
#include <QtWidgets/QMainWindow>
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
class statt;
}

class statt : public QDialog
{
    Q_OBJECT

public:
    explicit statt(QWidget *parent = nullptr);
    ~statt();

private:
    Ui::statt *ui;
};


#endif // STATT_H
