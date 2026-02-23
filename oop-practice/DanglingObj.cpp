#include <iostream>
#include <string>
using namespace std;

class Base {
public:
  virtual void work() { cout << "Base work\n"; }

  virtual ~Base() { cout << "Base destructor\n"; } //Virtual Desructor
};

class Derived : public Base {
public:
  void work() { cout << "Child work\n"; }
  ~Derived() { cout << "Derived destructor\n"; }
};

int main() {

  Base *ptr = new Derived();
  ptr->work();

  delete ptr;

  return 0;
}