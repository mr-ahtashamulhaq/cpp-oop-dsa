#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // ifstream readFile("Sample.txt");
  // cout << "read cursor pos: " << readFile.tellg() << endl;
  // char ch;
  // readFile.get(ch);
  // cout << ch << endl;
  // cout << "read cursor pos: " << readFile.tellg() << endl;
  // readFile.get(ch);
  // cout << "read cursor pos: " << readFile.tellg() << endl;
  // cout << ch << endl;

  //   ofstream writeFile("Sample.txt", ios::app);
  //   cout << "write cursor pos: " << writeFile.tellp() << endl;

  ifstream readFile("Sample.txt");
  readFile.seekg(8);

  ofstream writeFile("Sample.txt",ios::in | ios::out);
  writeFile.seekp(-8,ios::end);
  writeFile<<"Osama";
  


  return 0;
}