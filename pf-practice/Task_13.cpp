#include <iostream>
#include <ctype.h>
using namespace std;
int main() {

  char message[100];
  cout<<"Enter message : ";
  cin.get(message,100);

  int alphabet=0,num=0,punctuation=0,lower=0,upper=0;

  for(int i=0;message[i]!='\0';i++)
  {
    if(isalpha(message[i]))
      alphabet++;
    if(isdigit(message[i]))
      num++;
    if(ispunct(message[i]))
      punctuation++;
    if(islower(message[i]))
      lower++;
    if(isupper(message[i]))
      upper++;
  }
  cout<<"Total number of alphabetic character : "<<alphabet<<endl;
  cout<<"Total number of numeric digits : "<<num<<endl;
  cout<<"Total number of punctuation mark : "<<punctuation<<endl;
  cout<<"Total number of lower case : "<<lower<<endl;
  cout<<"Total number of upper case : "<<upper<<endl;
  
  
  return 0;
}