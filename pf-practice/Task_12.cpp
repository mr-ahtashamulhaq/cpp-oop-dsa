#include <iostream>
using namespace std;
int main()
{
  int matrix1[3][3];
  int matrix2[3][3];
  cout<<"enter the values of first matrix :"<<endl;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
      cin>>matrix1[i][j];

  }
  cout<<"enter the values of second matrix :"<<endl;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
      cin>>matrix2[i][j];

  }

  int sum[3][3];
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
      sum[i][j]=matrix1[i][j]+matrix2[i][j];
  }

  cout<<"The result of sum is : ";
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
      cout<<sum[i][j]<<" ";
    cout<<endl;
  }

  


  return 0;
}