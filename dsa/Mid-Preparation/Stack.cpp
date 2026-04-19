#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;

class StackArray
{
    public:
    int top;
    int array[MAX];
    
    StackArray()
    {
        top = -1;
    }

    void Push(int val)
    {
        if(top == MAX -1 )
        {
            cout<<"Stack reached maximum limit!"<<endl;
            return;
        }
        array[++top] = val;
    }

    int Pop()
    {
        if(top ==  -1)
        {
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }
        int data = array[top];
        top--;
        return data;
    }
    
    void display()
    {
        for(int i=top; i>=0; i--)
        {
            cout<<array[i]<<" ";
        }
    }
};

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

class StackLinkedList
{
    public:
    Node* top;
    StackLinkedList()
    {
        top = NULL;
    }

    void PUSH(int val)
    {
        Node* newNode = new Node(val);

        newNode->next = top;
        top = newNode;
    }

    int POP()
    {
        if(top == NULL)
        {
            cout<<"Stack is Empty."<<endl;
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    void display()
    {
        if(top == NULL)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }

    }

};
int main()
{
    StackArray st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.display();

    cout<<"\nPopped: "<<st.Pop()<<endl;
    st.display();

    st.Pop();
    st.display();

    /*
    --------------------------------------------------------------------------
    */

    StackLinkedList st1;

    st1.PUSH(10);
    st1.PUSH(20);
    st1.PUSH(30);
    st1.display();   


    cout<<"Popped: "<<st1.POP()<<endl;
    st.display();   

    st1.POP();
    st1.POP();
    st1.display(); 

    st1.POP();

    st1.PUSH(100);
    st1.PUSH(200);
    st1.display();
    return 0;
}