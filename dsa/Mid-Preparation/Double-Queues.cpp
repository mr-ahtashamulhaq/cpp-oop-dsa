#include <iostream>
#include <vector>
using namespace std;
class Node
{
    public:
    int id;
    int marks;
    string name;
    Node* next;
    Node(int i, string n, int m)
    {
        marks = m;
        id = i;
        name = n;
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
    void addInList(int i,  string n, int m)
    {
        Node* newNode = new Node(i,n,m);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = newNode;

    }

    void foundPair()
    {
        
        vector<Node*> good;
        vector<Node*> weak;

        Node* temp = head;
        while (temp != NULL)
        {
            if(temp->marks >= 60)
            {
                if(!weak.empty()) //if it is not empty
                {
                    cout<<temp->name <<" - "<<weak.front()->name<<endl;
                    weak.erase(weak.begin());
                }
                else
                {
                    good.push_back(temp);
                }
            }
            else
            {
                if(!good.empty())
                {
                    cout<<good.front()->name<<" - "<<temp->name<<endl;
                    good.erase(good.begin());
                }
                else
                {
                    weak.push_back(temp);
                }
            }
            temp = temp->next;
        }
        int i = 0;
        int j = 0;
        cout<<"\nUNPAIRED:"<<endl;
        while(i < good.size())
        {
            cout<<good[i]->name<<endl;
            i++;
        }
        while(j < weak.size())
        {
            cout<<weak[j]->name<<endl;
            j++;
        }

    }
    void display()
    {
        Node* temp = head;
        while(temp!= NULL)
        {
            cout<<temp->name<<" -> ";
            temp = temp->next;
        }
    }

};
int main() {
    LinkedList list;

    list.addInList(101, "Ali", 75);
    list.addInList(102, "Sara", 45);
    list.addInList(103, "Ahmed", 35);
    list.addInList(104, "Hina", 70);
    list.addInList(105, "Usman", 90);
    list.addInList(106, "Ayesha", 80);

    list.display();
    cout<<endl;
    list.foundPair();

    return 0;
}