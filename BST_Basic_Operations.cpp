//Basic BST Operations are Search,Maximum,Minimum,Predecessor and Successor
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node*left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* Search(Node*root, int key)
{
    if (root==nullptr||root->data==key)
        return root;
    if (key<root->data)
        return Search(root->left, key);
    return Search(root->right, key);
}

Node* Search_Iterative(Node*root, int key)
{
    Node* temp = root;
    while (temp!=nullptr && temp->data!=key)
    {
        if (key<temp->data)
            temp=temp->left;
        else
            temp = temp->right;
    }
    return temp;
}

Node* Maximum_Recursive(Node* root)
{
    if (root->right)
        return Maximum_Recursive(root->right);
    return root;
}

Node* Minimum_Recursive(Node* root)
{
    if (root->left)
        return Minimum_Recursive(root->left);
    return root;
}

Node* Maximum_Iterative(Node* root)
{
    Node* x = root;
    while (x->right!=nullptr)
        x = x->right;
    return x;
}

Node* Minimum_Iterative(Node* root)
{
    Node* x = root;
    while (x->left!=nullptr)
        x = x->left;
    return x;
}


int main()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(17);
    root->right->right = new Node(25);
    root->left->left->left = new Node(6);
    root->left->right->left = new Node(11);
    root->right->left->left = new Node(16);
    root->right->right->right = new Node(27);
    Node *foo = Search_Iterative(root, 6);
    cout << foo->data << "\n";
    Node* min = Minimum_Recursive(root);
    cout << min->data <<"\n";
    Node* max = Maximum_Iterative(root);
    cout << max->data << "\n";
}