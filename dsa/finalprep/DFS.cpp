#include<iostream>
#include<string>
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
class DFS
{
    public:
    void inOrderTraversal(Node* node)
    {
        if(node == NULL)
            return;
        
        inOrderTraversal(node->left);
        cout<<node->data<<" ";
        inOrderTraversal(node->right);
    }

    void preOrderTraversal(Node* node)
    {
        if(node == NULL)
            return;
        
        cout<<node->data<<" ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    
    void postOrderTraversal(Node* node)
    {
        if(node == NULL)
            return;
        
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout<<node->data<<" ";
    }

};
int main()
{
    
    return 0;
}