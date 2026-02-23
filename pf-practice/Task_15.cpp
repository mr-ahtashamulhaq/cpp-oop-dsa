#include <iostream>
using namespace std;

int average(int marks[], int stu)
{
  int average=0;
  int sum=0;
  for(int i=0;i<stu;i++)
  {
    sum=sum+marks[i];
  }
  average=sum/stu;
  return average;
}

int highest(int marks[], int student)
{
  int highest=marks[0];
  for(int i =1;i<student;i++)
  {
    if(marks[i]>highest)
      highest=marks[i];
  }
  return highest;
}

int lowest(int marks[], int student)
{
  int lowest=marks[0];
  for(int i=1;i<student;i++)
  {
    if(marks[i]<lowest)
      lowest=marks[i];
  }
    return lowest;
}

void pass_fail(int marks[], int student)
{
  int pass=0;
  int fail=0;
  for(int i =0;i<student;i++)
    {
      if(marks[i]>=50)
        pass++;
      else
        fail++;
    }
  cout<<pass<<" students are pass and "<<fail<<" students are fail.";
}

int main()
  {
  int stu;
  cout<<"enter number of students :";
  cin>>stu;

  int marks[stu];
  for(int i=0;i<stu;i++)
  {
    cout<<"enter marks of student "<<i+1<<" :";
    cin>>marks[i];
  }

  cout<<"average marks of students :"<<average(marks,stu)<<endl;
  cout<<"highest marks are : "<<highest(marks,stu)<<endl;
  cout<<"lowest marks are : "<<lowest(marks,stu)<<endl;
  pass_fail(marks, stu);

  return 0;
}