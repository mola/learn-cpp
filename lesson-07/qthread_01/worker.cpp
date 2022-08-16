#include "worker.h"
#include <iostream>

Worker::Worker(QObject *parent):
    QThread{parent}
{
    std::cout << __func__ << " : " << currentThreadId() << std::endl;
}

void  Worker::run()
{
    std::cout << __func__ << " : " << currentThreadId() << std::endl;

    for (int i = mA; i < mB; i++)
    {
        mSum += i;
        msleep(10);
    }

    std::cout << __func__ << " : Finished" << std::endl;
}
