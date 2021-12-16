#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vitaminc.h"
#include "vitamina.h"
#include "vitaminb.h"
#include "vitamind.h"
#include "vitamine.h"
#include "vitamink.h"
#include "importance.h"
#include "deficiency.h"
#include "aboutme.h"
#include "quiz.h"
#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

                  //inherits from QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::MainWindow *ui;
     //pointing to objects
    VITAMINa *VitaminA;
    vitaminB *VitaminB;
    vitaminC *VitaminC;
    vitaminD *VitaminD;
    vitaminE *VitaminE;
    vitaminK *VitaminK;
    importance *Importance;
    deficiency *Deficiency;
    quiz *QUIZ;
    aboutMe *AboutMe;

};
#endif // MAINWINDOW_H
