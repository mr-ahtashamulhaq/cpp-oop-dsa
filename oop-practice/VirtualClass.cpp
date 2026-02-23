#include <iostream>
#include <string>

using namespace std;
class A
{
public:
    A()
    {
        cout << "A's constructor called" << endl;
    }
    
};
class B final : public A
{
public:
    B()
    {   
        cout << "B's constructor called" << endl;
    }

};
class C // : public B
{
public:
    C() 
    {
        cout << "C's constructor called" << endl;
    }

};
int main()
{
    A a;
    B b;
    C c;
    
    return 0;
}