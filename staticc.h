#ifndef STATICC_H
#define STATICC_H

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
class Staticc;
}

class Staticc : public QDialog
{
    Q_OBJECT

public:
    explicit Staticc(QWidget *parent = nullptr);
    ~Staticc();

private:
    Ui::Staticc *ui;
};


#endif // STATICC_H
