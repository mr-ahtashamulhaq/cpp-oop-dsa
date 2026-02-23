#include <iostream>
using namespace std;
//Aggregation
class Teacher
{
    public:
    string name;
    Teacher(string n)
    {
        name = n;
    }
    void showteacher()
    {
        cout << "Teacher Name: " << name << endl;
    }
};

class School
{
    public:
    string schoolName;
    Teacher *teacher;   // pointer - store address of Teacher class Object 
    

    School(string sn, Teacher *other)
    {
        schoolName = sn;
        teacher = other;   // Aggregation
    }
    void showSchool()
    {
        cout<<"School Name "<<schoolName<<endl;
        teacher->showteacher();

    }

};
int main()
{
    Teacher t1("Mr. Ali"); //independetnly exit

    School s1("City school" ,&t1 );
    s1.showSchool();


    return 0;
}