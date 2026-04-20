#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    int itemID;
    string itemName;
    int quantity;
    Node* next;

    Node(int id, string name, int qty)
    {
        itemID = id;
        itemName = name;
        quantity = qty;
        next = NULL;
    }
};

class InventoryList
{
    public:
    Node* head;

    InventoryList()
    {
        head = NULL;
    }

    void addBack(int id, string name, int qty)
    {
        Node* newNode = new Node(id, name, qty);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void reorderInventory2()
    {
        InventoryList lowList;
        InventoryList highList;

        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->quantity >= 10)
            {
                highList.addBack(temp->itemID, temp->itemName, temp->quantity);
            }
            else
            {
                lowList.addBack(temp->itemID, temp->itemName, temp->quantity);
            }
            temp = temp->next;
        }
        Node* temp2 = lowList.head;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = highList.head;
        head = lowList.head;
    }

    void reorderInventory()
    {
        if(head == NULL || head->next == NULL)
            return;

        Node* lowHead = NULL;
        Node* lowTail = NULL;

        Node* highHead = NULL;
        Node* highTail = NULL;

        Node* curr = head;

        while(curr != NULL)
        {
            Node* nextNode = curr->next;
            curr->next = NULL; // detach

            if(curr->quantity < 10)
            {
                if(lowHead == NULL)
                {
                    lowHead = lowTail = curr;
                }
                else
                {
                    lowTail->next = curr;
                    lowTail = curr;
                }
            }
            else
            {
                if(highHead == NULL)
                {
                    highHead = highTail = curr;
                }
                else
                {
                    highTail->next = curr;
                    highTail = curr;
                }
            }

            curr = nextNode;
        }

        // Merge lists
        if(lowHead == NULL)
        {
            head = highHead;
        }
        else
        {
            lowTail->next = highHead;
            head = lowHead;
        }
    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<"("<<temp->itemName<<","<<temp->quantity<<") -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};
int main()
{
    InventoryList list;

    list.addBack(1, "Apple", 50);
    list.addBack(2, "Banana", 5);
    list.addBack(3, "Orange", 2);
    list.addBack(4, "Grapes", 15);
    list.addBack(5, "Mango", 8);

    cout<<"Original List:"<<endl;
    list.display();

    list.reorderInventory();

    cout<<"After Reordering:"<<endl;
    list.display();

    return 0;
}