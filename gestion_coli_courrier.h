#ifndef GESTION_COLI_COURRIER_H
#define GESTION_COLI_COURRIER_H

#include <QMainWindow>
#include "connexion.h"
#include "coli.h"
#include "courrier.h"
#include "equipement.h"
#include "livraison.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_Coli_Courrier; }
QT_END_NAMESPACE

class Gestion_Coli_Courrier : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_Coli_Courrier(QWidget *parent = nullptr);
    ~Gestion_Coli_Courrier();
private slots:

    void on_ajoutercoli_clicked();
    void on_suppcoli_clicked();
    void on_Load_1_clicked();
    void on_tri_coli_clicked();

    void on_ajoutercourrier_clicked();
    void on_suppcourrier_clicked();
    void on_Load_2_clicked();
    void on_tri_coli_2_clicked();

    void on_ajouterequip_clicked();
    void on_supp_equip_clicked();
    void on_Load_3_clicked();

    void on_ajouterliv_clicked();
    void on_supp_liv_clicked();
    void on_Load_4_clicked();
    void on_refresh_clicked();


    void on_recherche_3_textChanged(const QString &arg1);

    void on_recherche_2_textChanged(const QString &arg1);

    void on_recherche_textChanged(const QString &arg1);

    void on_recherche_4_textChanged(const QString &arg1);

    void on_PDF_2_clicked();

    void on_PDF_clicked();

    void on_Modifiercoli_clicked();

    void on_ModifierCourrier_clicked();

    void on_EXCEL1_clicked();

    void on_EXCEL_2_clicked();

    void on_stat1_clicked();

    void on_stat2_clicked();

private:
    Ui::Gestion_Coli_Courrier *ui;
    coli tmpcoli;
    courrier tmpcourrier;
    equipement tmpequip;
    livraison tmpliv;


};
#endif // GESTION_COLI_COURRIER_H
