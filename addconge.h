#ifndef ADDCONGE_H
#define ADDCONGE_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class addconge;
}

class addconge : public QDialog
{
    Q_OBJECT

public:
    explicit addconge(QWidget *parent = nullptr);
    ~addconge();
    QDate date_debut() const ;
    QDate date_fin() const ;
    QString commentaire() const ;
      QString raison() const;
    void show_demande();
      void show_demande_rh();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addconge *ui;
};

#endif // ADDCONGE_H
