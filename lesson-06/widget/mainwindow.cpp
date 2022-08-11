#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLayout>
#include <QTimer>
#include <QPushButton>

#include <iostream>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mTimer = new QTimer;
    mTimer->setInterval(100);
    mTimer->start();
    connect(mTimer, &QTimer::timeout, this, &MainWindow::timeout);

    mPushButton = new QPushButton();
    mPushButton->setText("Salam");

    layout()->addWidget(mPushButton);

    connect(mPushButton, &QPushButton::clicked, this, &MainWindow::changeName);
    mETimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::changeName()
{
    QList<int>  ii;

    for (int i = 0; i < 10000000; i++)
    {
        ii.append(i);
    }

    mPushButton->setText("Hello" + QString::number(mCounter++));
}

void  MainWindow::timeout()
{
    std::cout << "TCounter :: " << mETimer.nsecsElapsed() << std::endl;
    mETimer.restart();
}
