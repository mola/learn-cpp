#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker: public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = nullptr);

    void  setRange(int a, int b)
    {
        mA = a;
        mB = b;
    }

    int   sum() const;

public slots:
    void  dosum();

signals:
    void  progress(int);

private:
    int            mA;
    int            mB;
    int            mSum = 0;
    QElapsedTimer  mETimer;
};

#endif // WORKER_H
