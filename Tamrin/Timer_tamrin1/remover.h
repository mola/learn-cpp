#ifndef REMOVER_H
#define REMOVER_H

#include <QObject>
#include <QTimer>

class Remover: public QObject
{
    Q_OBJECT

public:
    explicit Remover(QObject *parent = nullptr);

    ~Remover();

    void  startTimer();

private:
    QTimer *clearTimer;
};

#endif // REMOVER_H
