#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QTextToSpeech>
#include "connexion.h"
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit  MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString user() const ;
QString userID;


private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::MainWindow *ui;
QTextToSpeech *m_speech;
};
#endif // MainWindow_H
