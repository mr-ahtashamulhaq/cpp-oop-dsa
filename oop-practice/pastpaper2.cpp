#include <iostream>
using namespace std;
class HospitalEmployee {
private:
  string name;
  double salary;
  // Static data member for annual increment rate (in percentage)
  static double annualIncrementRate;

public:
  // Constructor
  HospitalEmployee(string empName, double empSalary) {
    name = empName;
    salary = empSalary;
  }
  // Function to apply annual increment to the salary
  void applyAnnualIncrement() {
    salary += salary * (annualIncrementRate / 100);
  }
  // Function to display employee details
  void display() const {
    cout << "Name: " << name << endl;
    cout << "Salary: $" << salary << endl;
#include <iostream>
    using namespace std;
    class HospitalEmployee {
    private:
      string name;
      double salary;
      // Static data member for annual increment rate (in percentage)
      static double annualIncrementRate;

    public:
      // Constructor
      HospitalEmployee(string empName, double empSalary) {
        name = empName;
        salary = empSalary;
      }
      // Function to apply annual increment to the salary
      void applyAnnualIncrement() {
        salary += salary * (annualIncrementRate / 100);
      }
      // Function to display employee details
      void display() const {
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;