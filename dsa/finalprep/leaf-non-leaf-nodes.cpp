#include<iostream>
#include<string>
#include "BT.h"
#include <queue>
using namespace std;

// Find Display All Leaf Nodes
void displayAllLeafNodes(Node* root)
{
    if (root == NULL)
            {
                cout<<"Tree is Empty!"<<endl;
                return; 
            }

            queue<Node*> q;
            q.push(root);

            bool found = false;
            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();

                if(!temp->left && !temp->right)
                {
                    cout<<temp->data<<" ";
                }

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp -> right )
                {
                    q.push(temp->right);
                }
                          
            }
    
}

//  Display All Non-Leaf Nodes
void displayAllNonLeafNodes(Node* root)
{
    if (root == NULL)
            {
                cout<<"Tree is Empty!"<<endl;
                return; 
            }

            queue<Node*> q;
            q.push(root);

            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();

                if(temp->left || temp->right)
                {
                    cout<<temp->data<<" ";
                }

                if(temp->left)
                    q.push(temp->left);

                if(temp -> right )
                    q.push(temp->right);
            }
    
}
// SUM of all leaf nodes
int sumOfLeafNodes(Node* root)
{
    if(root == NULL)
    {
        cout<<"Tree is Empty!"<<endl;
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    int sum = 0;

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL && temp->right == NULL)
        {
            sum += temp->data;
        }

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    return sum;
}

// SUM of Parent Nodes
int sumOfParentNodes(Node* root)
{
    if(root == NULL)
    {
        cout<<"Tree is Empty!"<<endl;
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    int sum = 0;

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp->left != NULL || temp->right != NULL)
        {
            sum += temp->data;
        }

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    return sum;
}
// COUNT Leaf Nodes
int countLeafNodes(Node* root)
{
    if(root == NULL)
    {
        cout<<"Tree is Empty!"<<endl;
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    int count = 0;

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp->left == NULL && temp->right == NULL)
        {
            count++;
        }

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    return count;
}

// FIRST AND LAST LEAF NODE
void firstAndLastLeaf(Node* root)
{
    if(root == NULL)
    {
        cout<<"Tree is Empty!"<<endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    int firstLeaf;
    int lastLeaf;

    bool found = false;

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(!temp->left && !temp->right)
        {
            if(found == false)
            {
                firstLeaf = temp->data;
                found = true;
            }

            lastLeaf = temp->data;
        }

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    cout<<"First Leaf : "<<firstLeaf<<endl;
    cout<<"Last Leaf : "<<lastLeaf<<endl;
}

// Sum of Left subtree
int sumLeftSubtree(Node* root)
{
    if(root == NULL || root->left == NULL)
    {
        return 0;
    }

    queue<Node*> q;
    q.push(root->left);

    int sum = 0;

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        sum += temp->data;

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    return sum;
}
int main()
{
    BinaryTree BT;

    BT.insert(7);
    BT.insert(3);
    BT.insert(5);
    BT.insert(2);
    BT.insert(1);

    BT.display();
    cout<<endl;

    displayAllLeafNodes(BT.root);
    cout<<endl;
    displayAllNonLeafNodes(BT.root);
    
    return 0;
}