#ifndef IMPORTANCE_H
#define IMPORTANCE_H

#include <QDialog>

namespace Ui {
class importance;
}

class importance : public QDialog
{
    Q_OBJECT

public:
    explicit importance(QWidget *parent = nullptr);
    ~importance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::importance *ui;
};

#endif // IMPORTANCE_H
