#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"
//Utilized for file input, output.
#include <QFile>
#include <vector>
#include <QTextStream>
#include <QPixmap>
#include <QStyle>

#include <QMainWindow>

#include "vitaminc.h"
#include "vitamina.h"
#include "vitamink.h"
#include "vitaminb.h"
#include "vitamind.h"
#include "vitamine.h"

#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setting the background image of the mainwindow.
    try{
    QPixmap bkgnd(":/imagess/img/honorsBackground3.jpeg");

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


    //Grabbing element from QVector testing.
    QVector <QString> buttons = {"Exit"};
    ui->pushButton->setText(buttons.at(0));

    //Vector with all button names.
    QVector <QString> buttonNames ={"About QT", "Vitamin A", "Vitamin B", "Vitamin C",
                                    "Vitamin D", "Vitamin K", "Vitamin E","The Importance",
                                    "Deficiency", "The Vitamins", "Click on a vitamin to learn more!",
                                    "VitaminVerse by - Camilo", "Learn about the Vitamins",
                                    "Why fulfill your vitamins: "
                                   };

    ui->pushButton_2->setText(buttonNames.at(0));
    //QPushButton *button2 = ui->pushButton_2;
    //button2->setText("Hello");
    ui->pushButton_3->setText(buttonNames.at(1));
    ui->pushButton_4->setText(buttonNames.at(2));
    ui->pushButton_5->setText(buttonNames.at(3));
    ui->pushButton_6->setText(buttonNames.at(4));
    ui->pushButton_7->setText(buttonNames.at(5));
    ui->pushButton_8->setText(buttonNames.at(6));
    ui->pushButton_9->setText(buttonNames.at(7));
    ui->pushButton_10->setText(buttonNames.at(8));
    ui->pushButton_11->setText(buttonNames.at(9));
    ui->pushButton_12->setText(buttonNames.at(10));
    ui->pushButton_13->setText(buttonNames.at(11));
    ui->pushButton_14->setText(buttonNames.at(12));
    ui->pushButton_15->setText(buttonNames.at(13));


    //Setting clickable label, will take you to a link provided.
    ui->label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label->setOpenExternalLinks((true));
    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<a href=\"https://ods.od.nih.gov/factsheets/list-VitaminsMinerals/index.html\"> Source: NIH, Office of Dietary Supplements </a>");

    ui->pushButton_16->setText("Bonus Quiz");
    ui->pushButton_17->setText("Go to Quiz");
    ui->pushButton_18->setText("About Me");

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Will prompt the user with a question, whether they are sure they want to exit the app or not.
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Exit","Are you sure you would like to exit the application?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
        }
    else{
        qDebug() << "User did not exit.";
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    VitaminA = new VITAMINa(this);
    VitaminA->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    VitaminB = new vitaminB(this);
    VitaminB->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    VitaminC = new vitaminC(this);
    VitaminC->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    VitaminD = new vitaminD(this);
    VitaminD->show();
}


void MainWindow::on_pushButton_8_clicked()
{
    VitaminE = new vitaminE(this);
    VitaminE->show();
}


void MainWindow::on_pushButton_7_clicked()
{
    VitaminK = new vitaminK(this);
    VitaminK->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(this,"About QT");
}


void MainWindow::on_pushButton_10_clicked()
{

   /* QFile file("C:/Users/romer/Documents/CSC211H/deficiency.txt");

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this,"Warning","Deficiency file not open");
            cout<<"Not open";


}*/

    Deficiency = new deficiency(this);
    Deficiency->show();


}


void MainWindow::on_pushButton_9_clicked()
{
    Importance = new importance(this);
    Importance->show();
}


void MainWindow::on_pushButton_12_clicked()
{
    QMessageBox::information(this,"Guide","Click on one of the vitamins below!");
}


void MainWindow::on_pushButton_17_clicked()
{
    QUIZ = new quiz(this);
    QUIZ->show();
}


void MainWindow::on_pushButton_18_clicked()
{
    AboutMe = new aboutMe(this);
    AboutMe->show();
}

