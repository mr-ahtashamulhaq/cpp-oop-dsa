#include <iostream>
using namespace std;
int main() 
{
    for (int row=1; row<=5;row++)
        {
            for(int spa=1;spa<=5-row;spa++)
                {
                    cout<<" ";
                }
                
            for(int col=1; col<=row*2-1; col++)
                {
                    cout<<"*";
                    
                }
                
             cout<<endl; 
        }

    for (int row=4; row>=1;row--)
        {
            for(int spa=1;spa<=5-row;spa++)
                {
                    cout<<" ";
                }
            for (int col=1;col<=row *2-1; col++)
                {
                cout<<"*";
                }
                
            
                cout<<endl;
 
        }
     

    return 0;
}