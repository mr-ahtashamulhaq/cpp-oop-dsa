#include <iostream>
using namespace std;
int main() 
{
    int book_find;
    bool book_available=0;
    int book_id[10]={1000,1010,1020,1030,1040,1050,1060,1070,1080,1090};
    cout<<"Enter book ID to find : ";
    cin>>book_find;
    
    for(int i=0;i<10;i++)
    {
        if(book_id[i]==book_find)
        {
            book_available=1;
            break;
        }
    }
    if(book_available)
    cout<<"Book is available.";
    else
    cout<<"Book is not available.";
    
    
    return 0;
}