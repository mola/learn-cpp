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

    exec();

    std::cout << __func__ << " : Finished" << std::endl;
}

int  Worker::sum() const
{
    return mSum;
}

void  Worker::dosum()
{
    std::cout << __func__ << " : " << currentThreadId() << std::endl;

    for (int i = mA; i < mB; i++)
    {
        mSum += i;
        msleep(10);
    }

    std::cout << "Worker done : " << mSum << std::endl;
}
