#include<iostream>
using namespace std;
class Person
{
private:
    string name;
    int age;
public:
    Person()
    {
        cout<<"Person"<<endl;
    }
    Person(string name,int a)
    {
        cout<<"Person"<<endl;
        this->name =name;
        age=a;
    }
    ~Person()
    {
        cout<<"~Person"<<endl;
    }
    void show()
    {
        cout<<name<<" "<<age<<endl;
    }
};
int main()
{
    Person p;
    Person p1("Alice",30);
    p1.show();
    return 0;

}
