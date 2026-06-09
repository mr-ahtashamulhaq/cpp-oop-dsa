#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
/*
REMOVE DUPLICATES FROM A BINARY TREE
Start Traversing tree using Queue, for each element before inserting it in vector check if it is already exist
if it exist don't add it move to next iteration.
after making vector , make a new BTree and make old BTree root equal to new B Tree root.
*/
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree
{
private:
    Node* root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
            }

            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    void removeDuplicates()
    {
        if (root == NULL)
            return;

        queue<Node*> q;
        q.push(root);

        vector<int> values;

        while (!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            bool found = false;

            for (int v : values)
            {
                if (v == temp->data)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                values.push_back(temp->data);
            }

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        BinaryTree newTree;

        for (int v : values)
        {
            newTree.insert(v);
        }

        root = newTree.root;
    }

    void levelOrder()
    {
        if (root == NULL)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        cout << endl;
    }
};

int main()
{
    BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(20);
    bt.insert(40);
    bt.insert(10);
    bt.insert(50);

    cout << "Before removing duplicates: ";
    bt.levelOrder();

    bt.removeDuplicates();

    cout << "After removing duplicates: ";
    bt.levelOrder();

    return 0;
}