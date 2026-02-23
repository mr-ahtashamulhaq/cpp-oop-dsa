#include <iostream>
using namespace std;
int main()
{
    int num; 
    int a = 0, b = 1;
    int count = 0;
    cout << "Enter the number of terms to generate fibonacci series: ";
    cin >> num;
    
    while (count < num)
    {
        cout << a << " ";
        int nextTerm = a + b;
        a = b;
        b = nextTerm;
        count++;
    }
  return 0;
  }
