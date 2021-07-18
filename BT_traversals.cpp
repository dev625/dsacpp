#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data)
        {
            this->data = data;
            left = right = nullptr;
        }
};

void rec_inorder(Node* node) //left --> node --> right\
{
    if(node == nullptr)
        return;
    rec_inorder(node->left);
    cout << node->data << " ";
    rec_inorder(node->right);
}

void rec_preorder(Node* node) //node --> left -->right
{
    if(node == nullptr)
        return;
    cout << node->data << " ";
    rec_preorder(node->left);
    rec_preorder(node->right);
}

void rec_postorder(Node* node)   //left --> right --> node
{
    if(node==nullptr)
        return;
    rec_postorder(node->left);
    rec_postorder(node->right);
    cout << node->data << " ";
}
int main()
{
    Node* root    = new Node(1);
    root -> left  = new Node(2);
    root -> right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    rec_inorder(root);
    cout << "\n";
    rec_preorder(root);
    cout << "\n";
    rec_postorder(root);
    cout << "\n";
}