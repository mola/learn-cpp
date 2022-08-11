#ifndef NUMKEEPER_H
#define NUMKEEPER_H

#include <QList>

class NumKeeper
{
public:
    ~NumKeeper();

    static NumKeeper* instance()
    {
        if (!sInstance)
        {
            sInstance = new NumKeeper();
        }

        return sInstance;
    }

    void  addItem(int &num);

    void  removeItem();

    void  sortList();

    void  showList();

private:
    NumKeeper();

private:
    static NumKeeper *sInstance;
    QList<int>        _numLists;
};

#endif // NUMKEEPER_H
