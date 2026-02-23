#include <iostream>
#include <string>

using namespace std;
class Calculator {
public:
  void calculate(int a, int b) {
    cout << "both int parameter" << a + b << endl;
  }
  void calculate(double a, int b) {
    cout << "float and int parameter" << a + b << endl;
  }
  void calculate(int a, int b, int c) {
    cout << "all int parameter" << a + b + c << endl;
  }
  void calculate(string a, string b) {
    cout << "stirng  parameter" << a + " " + b << endl;
  }
  void calculate(int a, int b, int c, int d) {
    cout << "all int 4 parameter" << a + b + c + d << endl;
  }
};

int main() {
  Calculator c1;
  c1.calculate(4, 3);
  c1.calculate(4.9, 3);
  c1.calculate("osama", "Gull");

  return 0;
}