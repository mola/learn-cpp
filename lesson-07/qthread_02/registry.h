#ifndef REGISTRY_H
#define REGISTRY_H

#include <QMutex>
#include <QObject>

class Registry: public QObject
{
    Q_OBJECT

public:
    static Registry* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Registry;
        }

        return instance;
    }

    void  addNumber(int n);

    long  sizeNumber();

signals:

private:
    static Registry *instance;

    explicit Registry(QObject *parent = nullptr);

private:
    QList<int>  mNumbers;
    QMutex      mMutex;
};

#endif // REGISTRY_H
