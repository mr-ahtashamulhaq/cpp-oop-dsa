#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
HEIGHT OF A BINARY TREE
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
    public:
    Node* root;
        BinaryTree()
        {
            root = NULL;
        }

        void height()
        {
            int h = helperdfs(root);
            cout<<"height : "<<h<<endl;
        }

        private:
        int helperdfs(Node* node)
        {
            if(node == NULL) return 0;

            int leftheight = helperdfs(node->left);
            int rightheight = helperdfs(node->right);

            return 1 + max(leftheight, rightheight);
        }

};