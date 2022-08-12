#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
        break;
    case 1:
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        break;
    }
}

void  MainWindow::on_comboAligment_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        ui->lineEdit->setAlignment(Qt::AlignLeft);
        break;
    case 1:
        ui->lineEdit->setAlignment(Qt::AlignCenter);
        break;
    case 2:
        ui->lineEdit->setAlignment(Qt::AlignRight);
        break;
    }
}

void  MainWindow::on_CreateWindow_clicked()
{
    auto         list = this->findChildren<QMainWindow *>();
    QMainWindow *win  = new QMainWindow(this);

    win->setWindowTitle("Ali_" + QString::number(list.size()));
    win->show();
}

void  MainWindow::on_toolButton_clicked()
{
    auto  list = this->findChildren<QMainWindow *>();

    for (auto mw : list)
    {
        auto  pb = new QPushButton(mw->windowTitle());
        ui->vb->addWidget(pb);
        connect(pb, &QPushButton::clicked, this, &MainWindow::closeWindow);
    }
}

void  MainWindow::closeWindow()
{
    QObject *obj  = sender();
    auto     pb   = (QPushButton *)obj;
    QString  wt   = pb->text();
    auto     list = this->findChildren<QMainWindow *>();

    for (auto w : list)
    {
        if (w->windowTitle() == wt)
        {
            w->close();
            w->deleteLater();
        }
    }
}
