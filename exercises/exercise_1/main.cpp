#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
    }

    void  setName(const string &newName)
    {
        name = newName;
    }

    const string & getName()
    {
        return name;
    }

private:
    string  name;
};

class Zoo
{
public:
    Zoo()
    {
    }

    void  add(Animal *animal)
    {
        count++;
        cout << "Animal_" << count << " = " << animal->getName() << endl;
        z[count] = *animal;
    }

    int  getCount()
    {
        return count;
    }

private:
    int     count { 0 };
    Animal  z[5];
};

int  main()
{
    Animal *_animal1 = new Animal();

    _animal1->setName("Zebra");
    Animal *_animal2 = new Animal();

    _animal2->setName("Dog");

    Zoo *_zoo = new Zoo;
    _zoo->add(_animal1);
    _zoo->add(_animal2);

    std::cout << "Animal counts = " << _zoo->getCount() << endl;

    return 0;
}
