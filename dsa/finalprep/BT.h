#pragma once
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

class BinaryTree
{
    public:
    Node* root;
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

            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();

                if(!temp->left)
                {
                    temp->left = newNode;
                    return;
                }
                else
                {
                    q.push(temp->left);
                }

                if(!temp -> right )
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

        void display()
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

                cout<<temp->data<<" ";
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

        void deleteNode(int delval)
        {
            if(root == NULL)
            {
                cout<<"Tree is Empty! "<<endl;
                return; 
            }

            queue <Node*> q;
            Node* target = NULL;
            Node* last = NULL;

            q.push(root);
            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();

                if(temp->data == delval)
                {
                    target = temp;
                }
                
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }

                last = temp;
            }

            if(target)
            {
                int X = last->data;
                deleteLast(root, last);
                target->data = X;
            }
        }

private:
        void deleteLast(Node* root, Node* last)
        {
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();
                if(temp->left)
                {
                    if(temp->left == last)
                    {
                        delete temp->left;
                        temp->left = NULL;
                        return;
                    }
                    else
                    {
                        q.push(temp->left);
                    }
                }

                if(temp->right)
                {
                    if(temp->right == last)
                    {
                        delete temp->right;
                        temp->right = NULL;
                        return;
                    }
                    else
                    {
                        q.push(temp->right);
                    }
                }
            }
        }
};