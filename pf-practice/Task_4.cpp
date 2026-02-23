#include <iostream>
using namespace std;
int main()
{
  int usernum;
  bool isPrime;
  cout<<"Enter any number to print all the prime number up to that : ";
  cin >> usernum;
  
  for (int num = 2; num <= usernum; num++)
    { 
        isPrime = true;
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0) 
            {
                isPrime = false;
                break;
            }
       }
      if (isPrime) 
      {
         cout << num << ",";
      }
    }
  return 0;
 }
