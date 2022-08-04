#include <iostream>

using namespace std;

class A
{
public:
    virtual string  name() = 0;
};

class B: public A
{
public:
    string  name()
    {
        return "B";
    }
};

class C: public B
{
public:
};

int  main()
{
    B *b = new C;
    A *a = b;

    cout << "Hello World!" << a->name() << endl;

    return 0;
}
