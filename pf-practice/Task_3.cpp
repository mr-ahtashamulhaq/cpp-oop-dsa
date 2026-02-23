#include <iostream>
using namespace std;
int main()
{
  int num;
  int sum = 0;
  cout << "Enter multidigit number for sum "<<endl;
  cin >> num;

  while (num > 0)
  {
      sum += num % 10;
      num = num / 10;
  }
  cout << "the sum of digits = " << sum << endl;

    return 0;
}
