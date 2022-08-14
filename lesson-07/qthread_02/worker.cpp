#include "worker.h"
#include <iostream>

#include <registry.h>

Worker::Worker(QObject *parent):
    QObject{parent}
{
}

int  Worker::sum() const
{
    return mSum;
}

void  Worker::dosum()
{
    int    p = abs(mB - mA);
    float  t = 0;

    mETimer.start();

    for (int i = mA; i < mB; i++)
    {
        mSum += i;

        Registry::getInstance()->addNumber(i);

        std::cout << " Size : M" << Registry::getInstance()->sizeNumber() << std::endl;
        t = (i - mA) / float(p);

        if (mETimer.elapsed() > 15)
        {
            emit  progress(t * 100);
            mETimer.restart();
        }
    }

    emit  progress(100);

    std::cout << "Worker done : " << mSum << std::endl;
}
