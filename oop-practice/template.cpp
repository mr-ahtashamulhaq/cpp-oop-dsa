#include <iostream>
#include <string>
using namespace std;

template <typename A, typename B>

// int = A
// float = A
// String = A
int add(A a , B b)
{
    return a+b;
}

int main()
{
    cout<<add(3,4.5)<<endl;
    cout<<add(3.4,4.5)<<endl;
    // cout<<add('A','B')<<endl;
    
    return 0;
}