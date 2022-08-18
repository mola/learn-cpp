#include "dialogadduser.h"
#include "ui_dialogadduser.h"

DialogAddUser::DialogAddUser(QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogAddUser)
{
    ui->setupUi(this);
}

DialogAddUser::~DialogAddUser()
{
    delete ui;
}

QString  DialogAddUser::name()
{
    return ui->lineEdit_2->text();
}

QString  DialogAddUser::tel()
{
    return ui->lineEdit_3->text();
}

void  DialogAddUser::setName(QString name)
{
    ui->lineEdit_2->setText(name);
}
