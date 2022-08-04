#include <string>

enum TypeSchool
{
    Ebtedayee  = 1,
    Rahnamayee = 2,
    Dabirestan = 3
};

class School
{
public:
    TypeSchool   getGrade();

    std::string  getGradeString();

    TypeSchool  grade;

private:
};
