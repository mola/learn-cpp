#include "numkeeper.h"
#include <iostream>

NumKeeper *NumKeeper::sInstance = nullptr;

NumKeeper::NumKeeper()
{
}

NumKeeper::~NumKeeper()
{
    _numLists.clear();
}

void  NumKeeper::addItem(int &num)
{
    _numLists.append(num);
    std::cout << "added Num = " << num << std::endl;
}

void  NumKeeper::removeItem()
{
    std::cout << "Removed Num =" << _numLists.first() << std::endl;

    _numLists.removeFirst();
}

void  NumKeeper::sortList()
{
    std::sort(_numLists.begin(), _numLists.end());
}

void  NumKeeper::showList()
{
    std::cout << "NumeList ={ ";

    for (auto i : _numLists)
    {
        std::cout << i << ",";
    }

    std::cout << " }" << std::endl;
}
