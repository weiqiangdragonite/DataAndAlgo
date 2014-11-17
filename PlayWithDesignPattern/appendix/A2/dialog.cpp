#include <QMessageBox>

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::Shout()
{
    return "miao ~";
}

QString Cat::Shout()
{
    return "miao ~";
}

void Dialog::on_pushButton_clicked()
{
    Cat cat = new Cat();
    QMessageBox msg_box;
    msg_box.setWindowTitle(" ");
    msg_box.setText(cat.Shout());
    msg_box.exec();
}
