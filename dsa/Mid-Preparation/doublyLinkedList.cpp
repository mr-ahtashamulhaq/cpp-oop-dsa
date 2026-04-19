#include<iostream>
#include<string>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
class DoublyLinkedList
{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList()
    {
        head = tail =NULL;
    }

    void addFront(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode ->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void addBack(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }

    void deleteFront()
    {
        if(head == NULL || head->next == NULL)
        {
            Node* temp = head; //head and tail will be same at this point
            head = tail = NULL;
            delete temp;
            return;
        }
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;

        temp -> next = NULL;
        delete temp;
    }

    void deleteBack()
    {
        if(head == NULL || head->next == NULL)
        {
            Node* temp = head; //head and tail will be same at this point
            head = tail = NULL;
            delete temp;
            return;
        }

        Node* temp = tail;
        tail = tail -> prev;
        tail -> next = NULL;

        temp -> prev = NULL;
        delete temp;
    }

    void reverseList()
    {
        if(head == NULL || head-> next == NULL)
        {
            return;
        }

        Node* curr = head;
        Node* temp = NULL;

        while(curr != NULL)
        {
            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;


            curr = curr->prev;
        }
        Node* oldHead = head;
        head = tail;
        tail = oldHead;
    }

    void targetSumSorted(int target)
    {
        Node* i = head;
        Node* j = tail;
        while(i != NULL && j != NULL && i!=j && i->prev != j)
        {
            int currsum = i->data + j->data;
            if( currsum == target)
            {
                cout<<"("<<i->data <<","<<j->data<<")"<<endl;
                i = i->next;
                j = j->prev;
            }
            else if(currsum < target)
            {
                i = i->next;
            }
            else
            {
                j = j->prev;
            }
        }

    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data << " <=> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.addBack(1);
    dll.addBack(2);
    dll.addBack(4);
    dll.addBack(5);
    dll.addBack(6);
    dll.addBack(8);
    dll.addBack(9);

    dll.display();
    dll.targetSumSorted(10);

    dll.reverseList();
    dll.display();
    
    return 0;
}