#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

class LinkedList {
public:
  Node *head;
  LinkedList() { head = NULL; }

  void insertAtEnd(int value) {
    Node *newNode = new Node(value);
    if (head == NULL) {
      head = newNode;
      return;
    }
    Node *temp = head;

    while (temp->next != NULL)
      temp = temp->next;

    temp->next = newNode;
  }

  void display() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }

  LinkedList getUnion(LinkedList &other) {
    LinkedList result;

    // copy L1
    Node *t = head;
    while (t != NULL) {
      result.insertAtEnd(t->data);
      t = t->next;
    }

    // attach L2 at end
    t = other.head;
    while (t != NULL) {
      result.insertAtEnd(t->data);
      t = t->next;
    }

    // remove duplicates: outer fixes a value, inner remove dup
    Node *outer = result.head;

    while (outer != NULL) {
      Node *inner = outer;

      while (inner->next != NULL)
      {
        if (inner->next->data == outer->data)
          inner->next = inner->next->next;
        else
          inner = inner->next;
      }
      outer = outer->next;
    }

    return result;
  }

  LinkedList getIntersection(LinkedList &other) {
    LinkedList result;

    Node *i = head;
    while (i != NULL) {
      Node *j = other.head;
      while (j != NULL) {
        if (i->data == j->data) {
          result.insertAtEnd(i->data);
          break;
        }
        j = j->next;
      }
      i = i->next;
    }

    // remove duplicates from result (same logic as union)
    Node *outer = result.head;
    while (outer != NULL) {
      Node *inner = outer;
      while (inner->next != NULL) {
        if (inner->next->data == outer->data)
          inner->next = inner->next->next;
        else
          inner = inner->next;
      }
      outer = outer->next;
    }

    return result;
  }

  Node *mergeSorted(Node *L1, Node *L2) {

    // which head is smaller
    Node *head = NULL;
    if (L1->data <= L2->data)
    {
      head = L1;
      L1 = L1->next;
    }
    else
    {
      head = L2;
      L2 = L2->next;
    }

    Node *last = head; 

    //attatch smaller at last
    while (L1 != NULL && L2 != NULL)
    {
      if (L1->data <= L2->data)
      {
        last->next = L1;
        L1 = L1->next;
      }
      else
      {
        last->next = L2;
        L2 = L2->next;
      }
      last = last->next;
    }

    // one list exhausted, attach the remaining half directly
    if (L1 != NULL)
      last->next = L1;
    if (L2 != NULL)
      last->next = L2;

    return head;
  }
};
int main() {

  LinkedList L1, L2;
  L1.insertAtEnd(12);
  L1.insertAtEnd(5);
  L1.insertAtEnd(9);
  L1.insertAtEnd(4);

  L2.insertAtEnd(4);
  L2.insertAtEnd(8);
  L2.insertAtEnd(12);
  L2.insertAtEnd(1);
  LinkedList unionL = L1.getUnion(L2);
  LinkedList intersectionL = L1.getIntersection(L2);

  cout << "L1: ";
  L1.display();
  cout << "L2: ";
  L2.display();
  cout << "Union: ";
  unionL.display();
  cout << "Intersection: ";
  intersectionL.display();

  LinkedList L3, L4, result;

  L3.insertAtEnd(1);
  L3.insertAtEnd(3);
  L3.insertAtEnd(5);
  L4.insertAtEnd(2);
  L4.insertAtEnd(4);
  L4.insertAtEnd(6);

  cout << endl << endl;
  cout << "L3: ";
  L3.display();
  cout << "L4: ";
  L4.display();

  result.head = result.mergeSorted(L3.head, L4.head);

  cout << "Merged: ";
  result.display();

  return 0;
}