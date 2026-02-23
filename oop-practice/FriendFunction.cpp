#include <iostream>
#include <string>

using namespace std;

class Person 
{
    string name;
    int age;
    friend void compareAge(Person,Person);
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
void compareAge(Person a, Person b)
{
    if (a.age > b.age)
    {
        cout<<"Person "<<a.name<< " is older"<<endl;
    }
    else
    {
        cout<<"Person "<<b.name<< " is older"<<endl;
    }
}

int main()
{
    Person p1("Alice", 30);
    Person p2("Bob", 25);
    compareAge(p1 , p2);
    
    return 0;
}