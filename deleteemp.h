#ifndef DELETEEMP_H
#define DELETEEMP_H

#include <QDialog>

namespace Ui {
class deleteemp;
}

class deleteemp : public QDialog
{
    Q_OBJECT

public:
    explicit deleteemp(QWidget *parent = nullptr);
    ~deleteemp();
 QString cin() const;
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::deleteemp *ui;
};

#endif // DELETEEMP_H
