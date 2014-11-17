#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QString Shout(void);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};


class Cat
{
public:
    QString Shout(void);
};


#endif // DIALOG_H
