#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
    int age;
    public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    virtual void display() 
    {
        cout << "Person Name: " << name << endl;
        cout << "Person Age: " << age << endl;
    }
};
class Student : public Person
{
    string name;
    int age;
    int rollnum;
    public:
    Student(string n, int a, int r, string pn, int pa) : Person(pn,pa)
    {
        name = n;
        age = a;
        rollnum = r;
    }
    void display() final
    {
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
        cout << "Student Roll Number: " << rollnum << endl;
    }
};
class Employee : public Student
{
    public:
    // void display()
};

int main()
{
    Student s1("Bob", 8, 101, "jenifer", 21);
    Person *ptr = &s1;                          //Base Class Pointer

    ptr->display();
    


    return 0;
}