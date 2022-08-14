#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "worker.h"

#include <iostream>

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

void  MainWindow::finishing()
{
    auto  w = (Worker *)sender();

    std::cout << " Sum : " << w->sum() << std::endl;

    delete w;
}

void  MainWindow::on_btnStartThread_clicked()
{
    Worker *w = new Worker();

    connect(w, &Worker::finished, this, &MainWindow::finishing);
    w->setRange(1000, 1100);
    w->start();

    auto  pb = new QPushButton("Do sum");

    ui->verticalLayout->addWidget(pb);
    connect(pb, &QPushButton::clicked, w, &Worker::dosum, Qt::QueuedConnection);
}
