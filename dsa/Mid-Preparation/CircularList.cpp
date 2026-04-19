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

class CircularList
{
    public:
    Node* head;
    Node* tail;
    CircularList()
    {
        head = tail= NULL;
    }

    void addFront(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void addBack(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void deleteFront()
    {
        if (head == NULL)
        {
            cout<<"No Circular List Exist. Nothing to DELETE."<<endl;
            return;           
        }

        if (head == tail) //If only single Node
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp; 
    }

    void deleteBack()
    {
        if (head == NULL) // 0 Nodes
        {
            cout<<"No linkedList Exist. Nothing to DELETE."<<endl;
            return;           
        }
        if(head == tail) // Only 1 Node
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
    
        Node* Todelete = temp->next;
        tail = temp;
        tail->next = head;
        delete Todelete;
    }

    void display()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node*temp = head;
        cout<<temp->data <<"->";
        temp = temp -> next;
        while(temp != head)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    CircularList cl;

    // Add elements at back
    cl.addBack(1);
    cl.addBack(2);
    cl.addBack(3);
    cl.addBack(4);
    cl.display();

    // Add elements at front
    cl.addFront(10);
    cl.addFront(20);
    cl.display();

    // Delete front
    cl.deleteFront();
    cl.display();

    // Delete back
    cl.deleteBack();
    cl.display();

    // Delete until single node
    cl.deleteBack();
    cl.deleteBack();
    cl.deleteBack();
    cl.display();

    // Delete last remaining node
    cl.deleteFront();
    cl.display();

    // Try deleting from empty list
    cl.deleteFront();
    cl.deleteBack();

    return 0;
}