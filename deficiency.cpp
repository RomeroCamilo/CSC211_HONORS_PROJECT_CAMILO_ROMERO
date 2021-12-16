#include "deficiency.h"
#include "ui_deficiency.h"

#include <iostream>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

using namespace std;

deficiency::deficiency(QWidget *parent) :
    QDialog(parent , Qt::FramelessWindowHint),
    ui(new Ui::deficiency)
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

    QPixmap pix(":/imagess/img/vitaminDeficiency2.png");
    ui->label_2->setPixmap(pix.scaled(450,700,Qt::KeepAspectRatio));

    ui->pushButton_2->setText("What is Vitamin Deficiency?");

    ui->label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label->setOpenExternalLinks((true));
    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<a href=\"https://www.mayoclinic.org/diseases-conditions/vitamin-deficiency-anemia/symptoms-causes/syc-20355025/index.html\"> Source: Mayo Clinic </a>");



    //Accesing file.
    QFile file(":/new/files/deficiency.txt");

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

}

deficiency::~deficiency()
{
    delete ui;
}

void deficiency::on_pushButton_clicked()
{
    close();
}

