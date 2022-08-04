#include "school.h"


using namespace std;

TypeSchool  School::getGrade()
{
    return grade;
}

string  School::getGradeString()
{
    switch (grade)
    {
    case Ebtedayee:
        return "Ebtedayee";
    case Rahnamayee:
        return "Ebtedayee";
    case Dabirestan:
        return "Dabirestan";
    }

    return "Unknwon";
}
