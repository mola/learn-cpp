#include "remover.h"
#include "numkeeper.h"

Remover::Remover(QObject *parent):
    QObject{parent}
{
    clearTimer = new QTimer;

    QObject::connect(clearTimer, &QTimer::timeout, this,
                     []()
    {
        NumKeeper::instance()->sortList();
        NumKeeper::instance()->showList();
        NumKeeper::instance()->removeItem();
        NumKeeper::instance()->removeItem();
        NumKeeper::instance()->showList();
    });
}

Remover::~Remover()
{
}

void  Remover::startTimer()
{
    clearTimer->start(3000);
}
