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
class LinkedList
{
    public:
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
    
    void addFront(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addBack(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAt(int val, int pos) // 1 - Based Indexing
    {
        Node* newNode = new Node(val);

        
        if (head == NULL || pos == 1)// empty list OR inserting at position 1
        {
            newNode->next = head;
            head = newNode;
            cout<<"Inserted at position: 1"<<endl;
            return;
        }

        int count = 1;
        Node* temp = head;

        while (temp->next != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (count == pos - 1)
            cout<<"Inserted at position: "<<pos<<endl;
        else
            cout<<"Position out of bounds - Inserted at END!"<<endl;
    }

    void deleteFront()
    {
        if (head == NULL)
        {
            cout<<"No linkedList Exist. Nothing to DELETE.";
            return;           
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp; 
    }

    void deleteBack()
    {
        if (head == NULL) // 0 Nodes
        {
            cout<<"No linkedList Exist. Nothing to DELETE.";
            return;           
        }
        if(head->next ==NULL) // Only 1 Node
        {
            Node* temp = head;
            head = NULL;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node* Todelete = temp->next;
        temp->next = NULL;
        Todelete->next = NULL;
        delete Todelete;
    }

    void deletePosition(int pos)
    {
        if (head == NULL)
        {
            cout<<"No linkedList Exist. Nothing to Delete";
            return;
        }

        if (pos == 1) // pos = 1 -> mean delete head
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout<<"DELETED at "<<pos<<endl;
            return;
        }

        int count = 1;
        Node* temp = head;

        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        //check if position exists after traversal
        if (temp == NULL || temp->next == NULL)
        {
            cout<<"Position Not Found! - Nothing to DELETE"<<endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        cout<<"DELETED at: "<<pos<<endl;
    }

    void reverseLinkedList()
    {
        if(head == NULL or head->next == NULL) // 0 or 1 Node -> No need to reverse.
        {
            cout<<"REVERSED!"<<endl;
            return;
        }

        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout<<"Reversed!!"<<endl;
    }

    void mergeWith(LinkedList& list2)
    {
        if(head == NULL)
        {
            head = list2.head;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = list2.head;
    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data <<"->"; 
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    LinkedList list;

    // Add elements
    list.addFront(3);
    list.addFront(1);
    list.addBack(5);
    list.addBack(7);

    list.display();

    // Insert
    list.insertAt(10, 2);
    list.insertAt(20, 10); // out of bounds
    list.display();

    // Delete operations
    list.deleteFront();
    list.deleteBack();
    list.deletePosition(2);
    list.deletePosition(10); // invalid
    list.display();

    // Reverse
    list.reverseLinkedList();
    list.display();

    // Merge
    LinkedList list2;
    list2.addBack(100);
    list2.addBack(200);

    list.mergeWith(list2);
    list.display();

    return 0;
}