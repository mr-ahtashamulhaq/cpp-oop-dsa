#include <iostream>
using namespace std;
int main() 
{
    int voters;
    int cand_1=0,cand_2=0,cand_3=0,cand_4=0,cand_5=0;
    cout<<"Enter no of voters : ";
    cin>>voters;
    char votes[voters];

    cout<<"Press A to vote Canditate 1\n"<<"Press B to vote Canditate 2\n"<<"Press C to vote Canditate 3\n"<<"Press D to vote Canditate 4\n"<<"Press E to vote Canditate 5\n";
    for(int i=0;i<voters;i++)
    {
        cin>>votes[i];
    }
    
    for(int i=0; i<voters;i++)
    {
        switch(votes[i])
        {
        case 'a': cand_1++; break;
        case 'A': cand_1++; break;
        case 'b': cand_2++; break;
        case 'B': cand_2++; break;
        case 'c': cand_3++; break;
        case 'C': cand_3++; break;
        case 'd': cand_4++; break;
        case 'D': cand_4++; break;
        case 'e': cand_5++; break;
        case 'E': cand_5++; break;
        }
    }
    int cand[5]={cand_1,cand_2,cand_3,cand_4,cand_5};
    int largest=cand[0];
    int largest_i;

    for(int j=0;j<5;j++)
    {
        if(cand[j]>largest)
        {
            largest=cand[j];
            largest_i=j;
        }
    }
    for(int i=0; i<5; i++)
    {
        cout<<"Canditate "<<i+1<<" got "<<cand[i]<<" votes."<<endl;
    }
    cout<<"\n Candidate "<<largest_i+1<<" won the election with "<<largest<<" votes.";
    
    return 0;
}