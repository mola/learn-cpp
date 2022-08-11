#include "producer.h"
#include <iostream>
#include <QRandomGenerator>
#include "numkeeper.h"

Producer::Producer(QObject *parent):
    QObject{parent}
{
    setObjectName("Producer");
    adderTimer = new QTimer;


    connect(adderTimer, &QTimer::timeout, this,
            [ = ]()
    {
        int a = numGenerator();
        NumKeeper::instance()->addItem(a);
    });
}

Producer::~Producer()
{
}

void  Producer::startTimer()
{
    adderTimer->start(1000);
}

int  Producer::numGenerator()
{
    int  a = QRandomGenerator::global()->bounded(1000);

    return a;
}
