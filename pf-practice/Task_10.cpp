#include <iostream>
using namespace std;
int sum(int books[]){
  int sum=0;
  for(int i=0;i<7;i++)
    {
      sum=sum+books[i];
    }
  return sum;
}
int main()
{
  int books[7];
  cout<<"Enter the number of books sold each day: ";
  for(int i=0;i<7;i++)
    {
      cin>>books[i];
    }
  cout<<"The total number of books sold in a week are: "<<sum(books);

  return 0;
}