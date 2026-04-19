#include<iostream>
#include<string>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Queue
{
    public:
    Node* front;
    Node* rear;
    Queue()
    {
        front = rear = NULL;
    }
    void Enqueue(int val)
    {
        Node* newNode = new Node(val);
        if(rear == NULL)
        {
            front = rear = newNode;
            return;
        }
        
        rear->next = newNode;
        rear = newNode;
        return;
    }

    void Dequeue()
    {
        if (front == NULL)
        {
            cout<<"Empty QUEUE - Nothing to Dequeu"<<endl;
            return;
        }
        if(front ==  rear) // Only single Node
        {
            front = rear = NULL;
            return;
        }
        Node* temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }

    void display()
    {
        Node* temp = front;
        while(temp != NULL)
        {
            cout<<temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }

};
int main()
{
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.display();

    q.Dequeue();
    q.display();

    q.Dequeue();
    q.Dequeue();
    q.display();

    q.Dequeue();

    return 0;
}