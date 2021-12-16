#ifndef VITAMINB_H
#define VITAMINB_H

#include <QDialog>

namespace Ui {
class vitaminB;
}

class vitaminB : public QDialog
{
    Q_OBJECT

public:
    explicit vitaminB(QWidget *parent = nullptr);
    ~vitaminB();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vitaminB *ui;
};

#endif // VITAMINB_H
