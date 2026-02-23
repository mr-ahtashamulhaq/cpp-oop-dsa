#include <iostream>
using namespace std;
int main()
{
    char menu;
    int option;
    float square,triangle,rectangle,circle,parallelogram;
    const float pi = 3.14;
    
    do{
        cout<<"Of which you want to calculate area?"<<endl;
        cout<<"[1] Square"<<endl;
        cout<<"[2] Triangle"<<endl;
        cout<<"[3] Rectangle"<<endl;
        cout<<"[4] Circle"<<endl; 
        cout<<"[5] Parralelogram"<<endl;
        cout<<"Your Choice: ";
        cin>>option;
        
        switch (option){
        case 1:
        {
            float side;
            cout<<"enter the 1 Side of Square : ";
            cin>>side;
            square = side * side;
            cout<<"The area of square is = "<<square<<endl;
            break;
        }
        case 2:
        {
            float base, height;
            cout<<"Enter the height of Triangle: ";
            cin>>height;
            cout<<"Enter the base of Triangle: ";
            cin>>base;
            triangle = 0.5 * base * height;
            cout<<"The Area of triangle is = "<<triangle<<endl;
            break;

        }
        case 3:
        {
            float length, width;
            cout<<"Enter the length of rectangle: ";
            cin>>length;
            cout<<"Enter the width of rectangle: ";
            cin>> width;
            rectangle = length * width;
            cout<<"The Area of rectangle is = "<<rectangle<<endl;
            break;
        }
        case 4:
        {
            float radius;
            cout<<"Enter the radius of circle : ";
            cin>>radius;
            circle = pi * (radius*radius);
            cout<<"The area of circle is = "<<circle<<endl;
            break;
        }
        case 5:
        {
            float base , height;
            cout<<"Enter the height of parllelogram : ";
            cin>>height;
            cout<<"Enter the base of parallelogram : ";
            cin>>base;
            parallelogram = height*base;
            cout<<"The area of parralelogram is = "<<parallelogram<<endl;
            break;
        }
        default:
        {
            cout<<"invalid input! please choose from given options."<<endl;

        }
    }
        cout<<"\n Do you want to continue? (y/n) : ";
        cin>>menu;

    }while(menu == 'y' || menu == 'Y');
    return 0;
}
