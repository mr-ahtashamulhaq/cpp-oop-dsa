#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
CHECK WHETHER A TREE IS BALANCED OR NOT.
A Tree is balanced For every node if:
 abs ( Height(Left Subtree) - Height(Right Subtree) ) <= 1
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

        void isbalanced()
        {
            if(isBalancedHelper(root))
                cout<<"Tree is Balanced"<<endl;
            else
                cout<<"Tree is Not Balanced"<<endl;
        }

        private:
        int helperdfs(Node* node) // This fuction return height of passing node
        {
            if(node == NULL) return 0;

            int leftheight = helperdfs(node->left);
            int rightheight = helperdfs(node->right);

            return 1 + max(leftheight, rightheight);
        }

        bool isBalancedHelper(Node* node)
        {
            if(node == NULL)
                return true;

            int leftheight = helperdfs(node->left);
            int rightheight = helperdfs(node->right);

            if(abs(leftheight - rightheight) > 1)
                return false;

            return isBalancedHelper(node->left) &&
                   isBalancedHelper(node->right);
        }
};

int main()
{

    return 0;
}