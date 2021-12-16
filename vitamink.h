#ifndef VITAMINK_H
#define VITAMINK_H

#include <QDialog>

namespace Ui {
class vitaminK;
}

class vitaminK : public QDialog
{
    Q_OBJECT

public:
    explicit vitaminK(QWidget *parent = nullptr);
    ~vitaminK();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vitaminK *ui;
};

#endif // VITAMINK_H
