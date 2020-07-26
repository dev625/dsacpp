#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x)
        {
            this->data = x;
            this->left = nullptr;
            this->right = nullptr;
        }
};

void recursive_inorder(Node *root)
{
    if(root == nullptr)
        return;
    recursive_inorder(root->left);
    cout << root->data << " ";
    recursive_inorder(root->right);
}

int height(Node *root)
{
    int x,y;
    if(root!=nullptr)
    {
        x = height(root->left);
        y = height(root->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int size(Node *root)
{
    int x,y;
    if(root!=nullptr)
    {
        x = size(root->left);
        y = size(root->right);
        return x+y+1;
    }
    return 0;
}
int leafnodes(Node *root)
{
    int x,y;
    if(root!=nullptr)
    {
        x = leafnodes(root->left);
        y = leafnodes(root->right);
        if(!(root->left||root->right))
            return x+y+1;
        return x+y;
    }
    return 0;
}
int internalnodes(Node *root)
{
    int x,y;
    if(root!=nullptr)
    {
        x = internalnodes(root->left);
        y = internalnodes(root->right);
        if(root->left&&root->right)
            return x+y+1;
        return x+y;
    }
    return 0;
}

int main()
{
    Node *root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(10);
    root->left->left->left = new Node(4);
    root->right->left = new Node(9);
    root->right->right = new Node(11);
    recursive_inorder(root);
    cout<<"\n";
    cout <<"Height of the tree is : " << height(root)<<"\n";
    cout <<"Size of the tree is : " <<size(root)<<"\n";
    cout << "The number of leaf nodes in the tree is : " << leafnodes(root)<<"\n";
    cout << "The number of internal nodes in the tree are : "<<internalnodes(root)<<"\n";
}