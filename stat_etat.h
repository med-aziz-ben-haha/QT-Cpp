#ifndef STAT_ETAT_H
#define STAT_ETAT_H

#include <QDialog>
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
class stat_etat;
}

class stat_etat : public QDialog
{
    Q_OBJECT

public:
    explicit stat_etat(QWidget *parent = nullptr);
    ~stat_etat();

private:
    Ui::stat_etat *ui;
};

#endif // STAT_ETAT_H
