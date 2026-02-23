#include <iostream>
#include <string>

using namespace std;
class Vehicle // Abstract Class
{
public:
  virtual void display() = 0; // Pure Virtual Function
  void sound() { cout << "Vehicle Sound" << endl; }
};

class Car : public Vehicle // concrete Class
{
public:
  void display() 
  {
    cout << "Car Display" << endl;
  }

  void sound() { cout << "Car Sound" << endl; }
};
int main() {
  Car c1;
  c1.display();
  c1.sound();

  Vehicle *ptr;
  ptr = &c1;
  ptr->display();
  ptr->sound();

  return 0;
}