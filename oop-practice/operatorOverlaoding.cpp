#include <iostream>
#include <string>

using namespace std;
class Distance
{
    int meter;
    int centimeter;
    public:
    Distance(){}
    Distance(int m, int c)
    {
        meter = m;
        centimeter = c;
    }
    Distance operator +(Distance d) //operator overloading
    {
        int totalmeter = meter + d.meter;
        int totalcenti = centimeter + d.centimeter;
        Distance temp(totalmeter, totalcenti);
        return temp;

    }
    void operator ++(int) //Post increment
    {
        meter++;
        centimeter++;
    }
    void operator ++() //Pre increment
    {
        meter++;
        centimeter++;
    }
    void display()
    {
        cout<<"Meter: "<<meter<<endl;
        cout<<"Centimeter: "<<centimeter<<endl;
    }
};
int main()
{

    Distance d1(5, 10);
    Distance d2(3, 7);
    Distance d3 = d1 + d2;
    d3.display();
    cout<<endl;
    d1 ++;
    d1.display();
    cout<<endl;
    ++d2;
    d2.display();
    return 0;
}