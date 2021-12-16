#ifndef VITAMINA_H
#define VITAMINA_H

#include <QDialog>

namespace Ui {
class VITAMINa;
}

class VITAMINa : public QDialog
{
    Q_OBJECT

public:
    explicit VITAMINa(QWidget *parent = nullptr);
    ~VITAMINa();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VITAMINa *ui;
};

#endif // VITAMINA_H
