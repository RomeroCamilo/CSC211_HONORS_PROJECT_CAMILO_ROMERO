#ifndef VITAMIND_H
#define VITAMIND_H

#include <QDialog>

namespace Ui {
class vitaminD;
}

class vitaminD : public QDialog
{
    Q_OBJECT

public:
    explicit vitaminD(QWidget *parent = nullptr);
    ~vitaminD();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vitaminD *ui;
};

#endif // VITAMIND_H
