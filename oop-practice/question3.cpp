/*
Create a C++ program to work with fractions (like 1/2, 3/4, etc.). You will
design a class named Fraction that stores a numerator and a denominator. Your
program should:

        Dynamically allocate memory for an array of N Fraction objects using the
new operator. Ask the user to input N fractions. Add all the fractions together
using operator overloading (+ operator). Only simplify the final result at the
end, using the Greatest Common Divisor (GCD). Display the final simplified sum.
        Deallocate the dynamically allocated memory using delete [].
        Formula for fraction addition:
            a/b+c/d=(a×d+c×b)/(b×d)

        Numerator: (a * d + c * b)
        Denominator: (b * d)
*/
#include <iostream>
#include <string>

using namespace std;
class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction(int a = 0, int b = 1) {
    numerator = a;
    denominator = b;
  }
  void input() {
    cout << "(Neumerator and denumenator):";
    cin >> numerator;
    cin>> denominator;
  }

  Fraction operator+(Fraction &second) {
    int num =
        (numerator * second.denominator) + (second.numerator * denominator);
    int den = denominator * second.denominator;
    Fraction temp(num, den);
    return temp;
  }
  void display() { cout << numerator << "/" << denominator << endl; }

  int gcd(int a, int b)
  {
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
  }

  void simplified()
  {
    int divisor = gcd(numerator , denominator);
    numerator /= divisor;
    denominator /= divisor;
  }
};
int main() {
  int N;
  cout << "Enter the number of fractions: ";
  cin >> N;

  Fraction *ptrArr = new Fraction[N];
  for (int i = 0; i < N; i++)
  {
    cout << "Fraction " << i + 1;
    ptrArr[i].input();          
    cout << endl;
  }
  Fraction result;
  for (int i = 0; i < N; i++) {
    result = result + ptrArr[i];
  }
  
  result.simplified();
  result.display();



  return 0;
}