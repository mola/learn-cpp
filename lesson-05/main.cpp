#include <QCoreApplication>

#include <iostream>
#include <QObject>
#include <QTimer>
#include <QVariant>
#include "animal.h"

int  main(int argc, char *argv[])
{
    QCoreApplication  a(argc, argv);
    QTimer            timer;
    Animal            animal;
    QString           name = "  A  \n";
    QString           B    = name.trimmed();
    QString           c    = QString("%1,%2").arg(name).arg(2);
    QByteArray        data;

    data.reserve(100);
    data.resize(10);
    data[0] = 0x10;
    data[5] = 0x20;
    data.begin();
    data.end();

    QVariant         B1(1);
    QVariant         B2("name");
    QVariant         B3({ 1, 2, 3 });
    QVariant         B4(5.14);
    QList<QVariant>  ListB;

    ListB.push_back(B1);
    ListB.push_back(B2);
    ListB.push_back(B3);
    ListB.push_back(54.5);

    timer.setInterval(1000);

    timer.start();

    std::cout << "Application sart" << std::endl;

    QObject::connect(&timer, &QTimer::timeout, &animal, &Animal::name);

    int  b = a.exec();

    std::cout << "Application stoped" << std::endl;

    return b;
}
