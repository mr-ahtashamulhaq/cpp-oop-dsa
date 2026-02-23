#include <iostream>
using namespace std;
int sum ()
{
  int a,b;
  cout<<"enter first integer number :";
  cin>>a;
  cout<<"enter second integer number :";
  cin>>b;
  return a+b;
}
int main()
{
  int (*funptr)();
  funptr=sum;
  int result=funptr();
  cout<<"sum of numbers is : "<<result;
  


  return 0;
}