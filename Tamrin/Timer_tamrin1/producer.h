#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QTimer>

class Producer: public QObject
{
    Q_OBJECT

public:
    explicit Producer(QObject *parent = nullptr);

    ~Producer();

    void  startTimer();

    int   numGenerator();

private:
    QTimer *adderTimer;
};

#endif // PRODUCER_H
