#include <iostream>
#include <string>

using namespace std;
class Person
{

    public:
        int cnicnum;
        string name;
        int age;
    Person(){}
    Person(int ci , string n,int a)
    {
        cnicnum=ci;
        name=n;
        age=a;        
    }
    void displayPerson()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"CNIC: "<<cnicnum<<endl;
    }

};
class Student:public Person
{
    public:
        int rollnum;

    Student(int ci, string n, int a, int rn) : Person(ci,n,a)
    {
        rollnum=rn;
    }
    void displayStudent()
    {
        displayPerson();
        cout<<"Roll Number: "<<rollnum<<endl;
    }
    
};
int main()
{
    Student s1(123456789, "Bob", 20, 101);
    s1.displayStudent();
    cout<<endl<<endl<<endl;


    Person p1(123456789, "Bob", 20);
    p1.age = 90;
    p1.displayPerson();
    cout<<endl<<endl<<endl;

    return 0;
}