/*Alex has a file named sample.txt containing a list of their friends names.
Each name is stored on a new line. Alex wants to analyze the contents of the
file and requires a C++  program to do the following: 1.	Display the
entire content of the file in reverse order. 2.	Count and display the total
number of vowels (a, e, i, o, u) present in the file, considering both uppercase
and lowercase letters.
*/
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

int main() {
  ifstream readFile("sample.txt");
  
  char ch;
  readFile.seekg(-1,ios::end);
  int pos = readFile.tellg();
  int vowel = 0;
  while (readFile.get(ch))
  {
    cout << ch;
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or
        ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') {
      vowel++;
    }
    pos--;
    readFile.seekg(pos);
  }
  cout << "\nTotal number of vowels: " << vowel << endl;

  return 0;
}