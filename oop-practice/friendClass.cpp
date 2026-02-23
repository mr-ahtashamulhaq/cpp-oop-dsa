#include <iostream>
#include <string>

using namespace std;
class Person
{
    string name;
    int age;
    friend class Student; //Friend Class Declaration Syntax
    public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student
{
    string name;
    int age;
    public:
    Student(string n, int a)
    {
        name = n;
        age = a;
    }
    void display()
    {
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
    }
    void compareAge(Person a)
    {
        if (age > a.age)
        {
            cout << name << " is older than " << a.name << endl;
        } else {
            cout << a.name << " is older than " << name << endl;
        }

    }
};


int main() {
    
    Person p1 ("Alice", 15);
    Student s1 ("jane", 25);
    s1.compareAge(p1);


    return 0;
}