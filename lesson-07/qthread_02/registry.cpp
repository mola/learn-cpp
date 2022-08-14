#include "registry.h"

Registry *Registry::instance = nullptr;

Registry::Registry(QObject *parent):
    QObject{parent}
{
}

void  Registry::addNumber(int n)
{
    QMutexLocker  m(&mMutex);

    mNumbers.append(n);
}

long  Registry::sizeNumber()
{
    QMutexLocker  m(&mMutex);

    return mNumbers.size();
}
