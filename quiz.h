#ifndef QUIZ_H
#define QUIZ_H

#include <QDialog>

#include <iostream>

#include <QFile>
#include <QTextStream>
#include<QMessageBox>

#include <QPixmap>


namespace Ui {
class quiz;
}

class quiz : public QDialog
{
    Q_OBJECT

public:
    explicit quiz(QWidget *parent = nullptr);
    ~quiz();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::quiz *ui;
};

#endif // QUIZ_H
