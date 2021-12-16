#ifndef DEFICIENCY_H
#define DEFICIENCY_H

#include <QDialog>

namespace Ui {
class deficiency;
}

class deficiency : public QDialog
{
    Q_OBJECT

public:
    explicit deficiency(QWidget *parent = nullptr);
    ~deficiency();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deficiency *ui;
};

#endif // DEFICIENCY_H
