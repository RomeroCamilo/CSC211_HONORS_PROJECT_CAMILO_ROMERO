#include "aboutme.h"
#include "ui_aboutme.h"
#include <QFile>
#include <QTextStream>
#include<QMessageBox>
#include <QPixmap>
#include <iostream>

using namespace std;



aboutMe::aboutMe(QWidget *parent) :
    QDialog(parent,  Qt::FramelessWindowHint),
    ui(new Ui::aboutMe)
{
    ui->setupUi(this);
    ui->pushButton->setText("Close");

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

    //Accesing file.
    QFile file(":/new/files/aboutMe.txt");

    //checks if file is open or not.
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this,"Warning","About file not open");
            cout<<"File was not opened. Error..."<<endl;
    }

    //printing text from file into plainTextEdit.
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    //close the file after reading.
    file.close();
}

aboutMe::~aboutMe()
{
    delete ui;
}

void aboutMe::on_pushButton_clicked()
{
    close();
}

