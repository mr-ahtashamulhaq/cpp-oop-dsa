#include <iostream>
using namespace std;

void simulatePowerBoost(int health, int speed, int strength)
{
  health+=50;
  speed+=15;
  strength+=20;
  cout<<"\nhealth after boost: "<<health<<endl;
  cout<<"speed after boost: "<<speed<<endl;
  cout<<"strength after boost: "<<strength<<endl;
  
}
int main()
{
  int health;
  int speed;
  int strength;
  cout<<"enter character health: ";
  cin>>health;
  cout<<"enter character speed: ";
  cin>>speed;
  cout<<"enter character strength: ";
  cin>>strength;
  simulatePowerBoost(health, speed, strength);
  cout<<"\noriginal health: "<<health<<endl;
  cout<<"original speed: "<<speed<<endl;
  cout<<"original strength: "<<strength<<endl;
  
  return 0;
}
