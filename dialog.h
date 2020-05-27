#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "carte_cc.h"
#include "carte_ce.h"
#include "carte_ed.h"
#include "statt.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_16_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();


    void on_pushButton_11_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_14_clicked();


    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_15_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

private:
    Ui::Dialog *ui;
    carte_cc tmpcarte;
    carte_ce tmpcarte2;
    carte_ed tmpcarte3;

};

#endif // DIALOG_H
