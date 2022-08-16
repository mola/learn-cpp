#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker: public QThread
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = nullptr);

    void  setRange(int a, int b)
    {
        mA = a;
        mB = b;
    }


protected:
    void  run();

private:
    int  mA;
    int  mB;
    int  mSum = 0;
};

#endif // WORKER_H
