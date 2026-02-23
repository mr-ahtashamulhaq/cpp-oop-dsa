#include <iostream>
using namespace std;
// Composition
class Teacher
{
    public:
    Teacher(string n)
    {
        name = n;
    }
    string name;
    void showteacher()
    {
        cout << "Teacher Name: " << name << endl;
    }
};

class School
{
    public:
    string schoolName;
    Teacher teacherz;   // Object
    

    School(string sn, string tn): teacherz(tn)
    {
        schoolName = sn;
    }
    void showSchool()
    {
        cout<<"School Name "<<schoolName<<endl;
        teacherz.showteacher();

    }

};
int main()
{
    School s1("City school" ,"Mr Ali");
    s1.showSchool();

    return 0;
}