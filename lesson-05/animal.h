#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <iostream>

class Animal: public QObject
{
    Q_OBJECT

public:
    Animal();

public  slots:
    void  name()
    {
        std::cout << "A " << counter++ << std::endl;
    }

private:
    int  counter;
};


#endif // ANIMAL_H
