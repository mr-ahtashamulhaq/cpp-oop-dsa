#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    // ofstream file("Sample.txt");
    // if(!file)
    // {
    //     cout<<"File creation failed!"<<endl;
    // }
    // else
    // {
    //     file<<"Hello Pakistan"<<endl;
    //     file<<"Here is Osama";
    //     string s = "tomprrow is our exam.";
    //     int a = 89;
    //     file<<a<<endl;
    //     file<<s;
    //     for(int i =0 ; i<5 ; i++)
    //     {
    //         file<<i<<endl;
    //     }
    //     cout<<"Block executed successfully.";
    // }
    
    ifstream readFile("sample.txt");
    if(! readFile.is_open())
    {
        cout<<"Error opening file";
    }
    else
    {
        // char ch;
        // int count= 0;
        // while(readFile.get(ch))
        // {
        //     count++;
        //     cout<<ch;
        // }
        // cout<<"\nTotal characters: "<<count;
        //---------------------------------------------------------
        // string word;
        // int wordcount = 0;
        // while(readFile>>word)
        // {
        //     wordcount++;
        //     cout<<word<<endl;
        // }
        // cout<<"\nTotal words: "<<wordcount;
        //---------------------------------------------------------
        string line;
        int linecount = 0;
        while (getline(readFile, line))
        {
            cout<<line;
            linecount++;
        }
        cout<<"\nTotal lines: "<<linecount;
    }
    return 0;
}