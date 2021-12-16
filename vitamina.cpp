#include "vitamina.h"
#include "ui_vitamina.h"

#include <iostream>

#include <QFile>
#include <QTextStream>
#include<QMessageBox>

#include <QPixmap>

using namespace std;

VITAMINa::VITAMINa(QWidget *parent) :
    QDialog(parent , Qt::FramelessWindowHint),
    ui(new Ui::VITAMINa)
{
    ui->setupUi(this);

    //QVector<int> y;

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

    //QPixmap pix("C:/Users/romer/Downloads/VitaminAtitle.jpg");
    //int w = ui->label->width();
    //int h = ui->label->height();
    //ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->pushButton_2->setText("Recommended Amounts");

    ui->label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label->setOpenExternalLinks((true));
    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<a href=\"https://ods.od.nih.gov/factsheets/VitaminA-Consumer/index.html\"> Source: NIH, Office of Dietary Supplements </a>");

    //Accesing file.
    QFile file(":/new/files/whatA.txt");

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
    QFile file2(":/new/files/sourceA.txt");

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
    QFile file3(":/new/files/stageA.txt");

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



    ui->pushButton->setText("Close");
}

VITAMINa::~VITAMINa()
{
    delete ui;
}

void VITAMINa::on_pushButton_clicked()
{
    close();
}

