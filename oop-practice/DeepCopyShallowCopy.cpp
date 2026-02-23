#include <iostream>
using namespace std;
class Student
{
    int sapID;
    
    public:
    int* age;
    string name;
        Student (){}
        Student (int s, int a, string n)
        {
            sapID = s;
            name = n;
            age = new int;  //Dynamically Memory allocate
            *age = a;
        }

        void display()
        {
            cout << "SapID: " << sapID << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << *age << endl;
        }

        //DEEP-COPY
        Student (Student &other) //int &a
        {
            sapID  = other.sapID;
            name = other.name;
            age = new int;
            *age = *(other.age);

        }

};
int main()
{
    Student obj(7017, 20, "Sahil");
    obj.display();


    Student obj1(obj);
    // obj1  = obj;
    obj1.name = "Ahtasham";
    *(obj1.age) = 35;


    obj1.display();
    obj.display();



    return 0;
}