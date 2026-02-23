#include <iostream>
using namespace std;
int main()
{
    int stock[7];
    int max=0,min,avg;
    int sum=0;

    for(int i=0; i<7;i++)
    {
        cout<<"Enter Day "<<i+1<<" Stock value : ";
        cin>>stock[i];
    }
    
    for(int i=0;i<7;i++)
    {
        sum+=stock[i];
    }
    avg=sum/7;
    
    for(int i=0;i<7;i++)
    {
        if(stock[i]>max)
        max=stock[i];
    }
    
    min=stock[0];
    for(int j=1; j<7; j++)
    {
        if(stock[j]<min)
        min=stock[j];
    }

    cout<<"Max stock = "<<max<<endl;
    cout<<"Min value = "<<min<<endl;
    cout<<"Average value = "<<avg<<endl;
    
    for(int x=0,y=1;x<6,y<7;x++,y++)
    {
        if(stock[x]<stock[y])
        cout<<"On day "<<x+2<<" Price increased"<<endl;
        else if(stock[x]>stock[y])
        cout<<"On day "<<x+2<<" Price decreased"<<endl;
    }

    return 0;

}