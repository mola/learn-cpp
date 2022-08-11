#include <QCoreApplication>
#include <iostream>
#include "producer.h"
#include "remover.h"

int  main(int argc, char *argv[])
{
    QCoreApplication  a(argc, argv);
    Producer         *_producer = new Producer;

    _producer->startTimer();

    Remover *_remover = new Remover;

    _remover->startTimer();

    return a.exec();
}
