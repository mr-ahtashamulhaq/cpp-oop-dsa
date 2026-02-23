#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() 
{
    ifstream readFile("sample.txt");
    ofstream writeFile("result.txt");

    int linecount = 1;
    string line;
    while (getline(readFile, line))
    {
        if(linecount != 4 and linecount != 5 and linecount != 6)
        {
            writeFile<<line<<endl;
        }
        linecount++;
    }
    cout<<linecount;
    readFile.close();
    writeFile.close();
    remove("Sample.txt");
    rename("result.txt","Sample.txt");
    return 0;
}