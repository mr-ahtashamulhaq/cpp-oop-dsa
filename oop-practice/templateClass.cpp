#include <iostream>
#include <string>

using namespace std;
class Student
{
private:
    string name;
    int age;
    float grade;
public:
    Student(){}
    Student(string n, int a, float g) : name(n), age(a), grade(g) {}
    void displayInfo()
    {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};
int main() {

    Student * arr;  //Just address of array first element
    arr = new Student[3];   //Actual 3 Objects on each index
    arr[0] = Student("Alice", 20, 88.5);
    arr[0].displayInfo();

    Student * arr1[3];  //Array which include 3 address of objects - one on each index.
    arr1[0] = new Student("Bob", 19,95);
    arr1[0]->displayInfo();
    return 0;
}