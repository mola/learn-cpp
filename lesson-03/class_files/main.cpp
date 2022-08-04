#include <iostream>
#include <vector>
#include <map>
#include "school.h"

using namespace std;

int  main()
{
    School          s;
    vector<School>  vs;

    vs.push_back(s);

    for (int i = 0; i < 10; i++)
    {
        vs.push_back(s);
    }

    vector<int>  cc;

    cc.push_back(1);
    cc.push_back(2);
    cc.push_back(3);
    cc.push_back(4);

    vector<int>::iterator  n = cc.begin();

    for (; n < cc.end(); n++)
    {
        *n = *n * 2;
    }

    for (auto s : vs)
    {
        cout << " S : " << s.getGradeString() << std::endl;
    }


    return 0;
}
