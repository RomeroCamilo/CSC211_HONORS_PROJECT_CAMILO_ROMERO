#ifndef VITAMINE_H
#define VITAMINE_H

#include <QDialog>

namespace Ui {
class vitaminE;
}

class vitaminE : public QDialog
{
    Q_OBJECT

public:
    explicit vitaminE(QWidget *parent = nullptr);
    ~vitaminE();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vitaminE *ui;
};

#endif // VITAMINE_H
