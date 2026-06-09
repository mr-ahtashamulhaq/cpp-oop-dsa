#include<iostream>
#include<string>
#include<queue>
using namespace std;

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

class BST
{
    Node* root;
    BST()
    {
        root = NULL;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);
        
        if(root == NULL)
        {
            root = newNode;
            return;
        }

        Node* parent = NULL;
        Node* current = root;

        while(current != NULL )
        {
            parent = current;

            if(val < current->data)
            {
                current = current->left;
            }
            else if(val > current->data)
            {
                current = current->right;
            }
            else
            {
                return;
            }
        }

        if (val > parent->data)
        {
            parent->right = newNode;
        }
        else
        {
            parent -> left = newNode;
        }
    }

    void DeleteVal(int val)
    {
        root = DeleteNode(root, val);
    }

    private:
    Node* DeleteNode(Node* node, int val) //helper function
    {
        if (node == NULL) return NULL;

        if (val < node->data)
            node->left = DeleteNode(node->left , val);

        else if (val > node->data)
            node->right = DeleteNode(node->right, val);
        
        else
        {
            if (node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node* successor = findMin(node->right);
                node->data = successor->data;
                node->right = DeleteNode(node->right, successor->data);
            }
        }

        return node;
    }

    Node* findMin(Node* node) // Helper function
    {
        while(node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    void update(int oldVal , int newVal)
    {
        DeleteVal(oldVal);
        insert(newVal);
    }
};
int main()
{

    
    return 0;
}