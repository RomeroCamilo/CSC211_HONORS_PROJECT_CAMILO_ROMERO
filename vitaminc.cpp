#include "vitaminc.h"
#include "ui_vitaminc.h"
#include <QFile>
#include <QTextStream>
#include<QMessageBox>
#include <QPixmap>

#include <iostream>

using namespace std;

vitaminC::vitaminC(QWidget *parent) :
    QDialog(parent , Qt::FramelessWindowHint),
    ui(new Ui::vitaminC)
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


    ui->label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label->setOpenExternalLinks((true));
    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<a href=\"https://ods.od.nih.gov/factsheets/VitaminC-Consumer/index.html\"> Source: NIH, Office of Dietary Supplements </a>");

    //QPixmap pix("C:/Users/romer/Downloads/vitaminLogo.jpg");
    //QPixmap pix2("C:/Users/romer/Downloads/VitaminCtitle.jpg");

    //int w = ui->label->width();
    //int h = ui->label->height();
    //ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    //int w2 = ui->label_2->width();
    //int h2 = ui->label_2->height();
    //ui->label_2->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));

    ui->pushButton_2->setText("Recommended Amounts");


    ui->pushButton->setText("Close");

    //Accesing file.
    QFile file(":/new/files/whatC.txt");

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
    QFile file2(":/new/files/sourceC.txt");

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
    QFile file3(":/new/files/stageC.txt");

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


}

vitaminC::~vitaminC()
{
    delete ui;
}

void vitaminC::on_pushButton_clicked()
{
    close();
}

