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

Node* Minimum(Node* root)
{
    if (root->left)
        return Minimum(root->left);
    return root;
}

Node* Search(Node*root, int key)
{
    if (root==nullptr||root->data==key)
        return root;
    if (key<root->data)
        return Search(root->left, key);
    return Search(root->right, key);
}

void Inorder(Node* node)
{
    if (node==nullptr)
        return;
    Inorder(node->left);
    cout << node->data <<" ";
    Inorder(node->right);
}

void Insert(Node* root, int key)
{
    Node* temp = root;
    Node* y = nullptr;

    /*This while loop below searches for an empty place to Insert the new Node.*/
    while (temp!=nullptr)
    {
        y = temp;
        if (key<temp->data)
            temp =temp->left;
        else
            temp = temp->right;
    }

    if (y==nullptr)                      //Tree is empty initially
        root = new Node(key);
    else if (key<y->data)                //Insert in the left subtree
        y->left = new Node(key);
    else                                 //Insert in the right subtree
        y->right = new Node(key);
}

Node* Delete(Node* root, int key)
{
    if (root==nullptr)
        return root;
    else if (key < root->data)
        root->left = Delete(root->left, key);
    else if (key>root->data)
        root->right = Delete(root->right, key);
    //The node with the particular key is found at this point.
    else
    {
        // Case 1 : No Child
        if (root->left==nullptr&&root->right==nullptr)
        {
            delete root;
            root = nullptr;
        }
        // Case 2 : Single Child
        else if (root->left == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3 : 2 Children
        else
        {
            Node* temp = Minimum(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
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
    Inorder(root);
    cout << "\n";
    Insert(root, 19);
    Inorder(root);
    cout << "\n";
    root = Delete(root, 17);
    Inorder(root);
    cout <<"\n";
}