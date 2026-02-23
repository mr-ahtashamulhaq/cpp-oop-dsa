/*
Write a C++ program that performs the following operations on a text file named sample.txt:
1.	Opens the file and checks for successful access.
2.	Count and display the total number of lines in the file.
3.	Print only the even-numbered lines (e.g., 2nd, 4th, 6th, etc.).
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() 
{
    ifstream readFile("sample.txt");
    if(!readFile.is_open())
    {
        cout<<"Error Opening file."<<endl;
        return 1;
    }
    string line;
    int linecount = 0;
    while(getline(readFile, line))
    {
        linecount++;
        if(linecount % 2 == 0)
        {
            cout<<line<<endl;
        }
    }
    cout<<"Total number of lines: "<<linecount<<endl;


    
    return 0;
}