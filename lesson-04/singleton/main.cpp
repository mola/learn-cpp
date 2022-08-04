#include <iostream>
#include <memory>
#include <vector>


#include "registry.h"
#include "runner.h"

Registry *Registry::mInstamce = nullptr;

using namespace std;

class A
{
public:
    A(int size)
    {
    }
};

typedef std::shared_ptr<A> APtr;

int  main()
{
    APtr  B;

    Registry::instance();

    Runner  AA;

    Registry::instance()->setProperty("A", "20");
    Registry::instance()->setProperty("B", "20");

    Runner  BB;
}
