#include "quiz.h"
#include "ui_quiz.h"
#include <QDebug>
#include <iostream>
#include "QMessageBox"
#include <QDir>

using namespace std;

quiz::quiz(QWidget *parent) :
    QDialog(parent, Qt::FramelessWindowHint),
    ui(new Ui::quiz)
{
    ui->setupUi(this);

    try{
    QPixmap bkgnd(":/imagess/img/background6.jpg");

    if(bkgnd.isNull()) throw std::string ("ERROR: Image cannot be found.");

    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    }
    catch(std::string message)
    {
        cout<<message<<endl;
    }

    ui->pushButton->setText("Close");
    ui->pushButton_16->setText("How much Vitamin C mg should an Adult take? Type the number only!");
    ui->pushButton_17->setText("What vitamin deficieny causes bleeding gums? Type the letter of the Vitamin only!");
    ui->pushButton_2->setText("Submit");
    ui->pushButton_3->setText("Submit");
    ui->pushButton_4->setText("Show Answer");
    ui->pushButton_5->setText("Show Answer");

}

quiz::~quiz()
{
    delete ui;
}

void quiz::on_pushButton_clicked()
{
    close();
}


void quiz::on_pushButton_2_clicked()
{
    //setting the correct answer.
     QString answer = "90";

    //opening file to write.
    QFile file1("answer1.txt");

    //truncating so the file is empty and clean before new info is stored.
    file1.open(QFile::WriteOnly|QFile::Truncate);

    //Writing to the file, after user clicks submit.
    QTextStream out(&file1);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;


    if(answer == text)
    {
        QMessageBox::about(this,"Result","You are Correct!");
    }
    else
    {
        QMessageBox::critical(this,"Result","You are incorrect.");
    }

    //flush all stream inside of out.
    file1.flush();
    file1.close();


}

//Tells user answer
void quiz::on_pushButton_4_clicked()
{

        QMessageBox::information(this,"Guide","Answer: 90");


}

void quiz::on_pushButton_3_clicked()
{
    //setting the correct answer
    QString answer2 = "C";
    //opening file to write.
    QFile file2("answer2.txt");

    //truncating so the file is empty before new info is stored.
    file2.open(QFile::WriteOnly|QFile::Truncate);

    //Writing to the file, after user clicks submit.
    QTextStream out(&file2);
    QString text = ui->plainTextEdit_2->toPlainText();
    //saving output to text.
    out << text;

    //Tells the user whether they are correct or not!
    if(answer2 == text)
    {
        QMessageBox::about(this,"Result","You are Correct!");
    }
    else
    {
        QMessageBox::critical(this,"Result","You are incorrect.");
    }

    //flush all stream inside of out.
    file2.flush();
    file2.close();
}


//Tells user answer
void quiz::on_pushButton_5_clicked()
{

        QMessageBox::information(this,"Guide","Answer: C");

}

