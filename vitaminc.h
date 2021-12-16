#ifndef VITAMINC_H
#define VITAMINC_H

#include <QDialog>

namespace Ui {
class vitaminC;
}

class vitaminC : public QDialog
{
    Q_OBJECT

public:
    explicit vitaminC(QWidget *parent = nullptr);
    ~vitaminC();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vitaminC *ui;
};

#endif // VITAMINC_H
