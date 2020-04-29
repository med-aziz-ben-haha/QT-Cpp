#ifndef ADDEMP_H
#define ADDEMP_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class addemp;
}

class addemp : public QDialog
{
    Q_OBJECT

public:
    explicit addemp(QWidget *parent = nullptr);
    ~addemp();

    QString nom() const ;
    QString nationality() const ;
    QString adress() const ;
     QString competence() const ;
    QString zip () const;
    QString phone() const;
     QString title() const;
      QString dep() const;
       QString sexe() const;
        QString etat() const;
        QDate naissance () const;
      QString cin() const;
      QTime debut() const;
    int hour() const;
    int conge() const;
    double hour_sal() const;
void show();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::addemp *ui;
};

#endif // ADDEMP_H
