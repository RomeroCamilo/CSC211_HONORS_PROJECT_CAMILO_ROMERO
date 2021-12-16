#include "importance.h"
#include "ui_importance.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

using namespace std;

importance::importance(QWidget *parent) :
    QDialog(parent , Qt::FramelessWindowHint),
    ui(new Ui::importance)
{
    ui->setupUi(this);

    ui->pushButton->setText("Close");

    //setting the background image of the mainwindow.
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

    ui->pushButton_2->setText("What Can Vitamins Do For You? ");

    ui->pushButton_3->setText("Immunity");
    ui->pushButton_4->setText("Metabolism");
    ui->pushButton_5->setText("Strong Bones");

    //Accesing file.
    QFile file(":/new/files/immunity.txt");

    //checks if file is open or not.
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this,"Warning","Deficiency file not open");
            cout<<"File was not opened. Error..."<<endl;
    }

    //printing text from file into plainTextEdit.
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    //close the file after reading.
    file.close();

    //Accesing file.
    QFile file2(":/new/files/metabolism.txt");

    //checks if file is open or not.
    if(!file2.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this,"Warning","Metabolism file not open");
            cout<<"File was not opened. Error..."<<endl;
    }

    //printing text from file into plainTextEdit.
    QTextStream in2(&file2);
    QString text2 = in2.readAll();
    ui->plainTextEdit_2->setPlainText(text2);
    //close the file after reading.
    file2.close();

    //Accesing file.
    QFile file3(":/new/files/strong.txt");

    //checks if file is open or not.
    if(!file3.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this,"Warning","Strong file not open");
            cout<<"File was not opened. Error..."<<endl;
    }

    //printing text from file into plainTextEdit.
    QTextStream in3(&file3);
    QString text3 = in3.readAll();
    ui->plainTextEdit_3->setPlainText(text3);
    //close the file after reading.
    file3.close();


    ui->label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label->setOpenExternalLinks((true));
    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<a href=\"https://www.centrum.com/learn/why-are-vitamins-important/index.html\"> Source: Centrum </a>");



}

importance::~importance()
{
    delete ui;
}

void importance::on_pushButton_clicked()
{
    close();
}

