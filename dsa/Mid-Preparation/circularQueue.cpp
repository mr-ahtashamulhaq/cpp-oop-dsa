#include<iostream>
#include<string>
using namespace std;
class CircularQueue
{
    public:
    int cap, currSize, front, rear;
    int* array;
    CircularQueue(int size)
    {
        cap = size;
        array = new int[cap];
        front = 0;
        rear = -1;
        currSize = 0;
    }

    void push(int data)
    {
        if(currSize >= cap)
        {
            cout<<"MAX capacity reached"<<endl;
            return;
        }
        rear = (rear + 1 ) % cap;
        array[rear] = data;
        currSize++;
    }
    void pop()
    {
        if(currSize <= 0)
        {
            cout<<"QUEUE is Empty."<<endl;
            return;
        }
        front = (front+1)  % cap;
        currSize--;
    }
    void display()
    {
        int i = front;
        int count = 0;

        while(count < currSize)
        {
            cout<<array[i]<<" ";
            i = (i + 1) % cap;
            count++;
        }
        cout<<endl;
    }

};
int main()
{
    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.display(); 

    q.pop();
    q.display();

    q.push(40);
    q.push(50);
    q.display(); 

    q.pop();
    q.pop();
    q.pop();
    q.display(); 

    return 0;
}