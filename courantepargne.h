#ifndef COURANTEPARGNE_H
#define COURANTEPARGNE_H
#include <QObject>
#include <QMainWindow>
#include"epargne.h"
#include"couraant.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class courantepargne; }
QT_END_NAMESPACE

class courantepargne : public QDialog
{
    Q_OBJECT

public:
    courantepargne(QWidget *parent = nullptr);
    ~courantepargne();


private slots:
    // compte courant
    void on_CreerCC_3_clicked();

    void on_Afficher1_3_clicked();

    void on_SupprimerCC_3_clicked();

    void on_Modifier_3_clicked();

    void on_trier_5_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_9_selectionChanged();

    void on_lineEdit_9_textChanged(const QString &arg1);
    // compte epargne


    void on_Creer_3_clicked();

    void on_Modifer2_3_clicked();

    void on_SupprimerC_3_clicked();

    void on_Afficher_3_clicked();

    void on_trier_6_clicked();

    void on_lineEdit_10_selectionChanged();



    void on_comboBox_2_currentIndexChanged(const QString &arg1);





    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_5_clicked();


    void on_pushButton_3_clicked();



    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::courantepargne *ui;
    epargne tmpcomp;
    couraant tmpcour;
};
#endif // COURANTEPARGNE_H
