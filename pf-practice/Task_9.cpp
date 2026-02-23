#include <iostream>
using namespace std;
int main() 
{
    int n_student;
    cout<<"Enter number of students : ";
    cin>>n_student;

    int score[n_student];
    cout<<"Enter Marks of students:";
    for(int i=0; i<n_student; i++)
    {
        cin>>score[i];
    }

    for(int j=1; j<n_student;j++)
    {
        int element=score[j];
        int to_check=j-1;

        while(to_check>=0 && score[to_check] > element)
        {
            score[to_check +1] = score[to_check];
            to_check--;

        }
        score[to_check + 1] = element;
    }

    cout<<"Here is the sorted list of scores in accending order : ";
    for(int i=0; i<n_student;i++)
    cout<<score[i]<<" ";

    cout<<"\nHighest score : "<<score[n_student -1]<<endl;
    cout<<"Second Highest score : "<<score[n_student -2]<<endl;
    cout<<"Third Highest score : "<<score[n_student -3]<<endl;

    return 0;
}