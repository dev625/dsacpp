#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left, *right;

public:
    //Default Constructor
    BST();

    //Parameterized Constructor
    BST(int k);

    //Insert Function
    BST *Insert(BST *, int k);

    //Inorder Traversal
    void Inorder(BST *);

    //Search Function
    BST *Search(BST *, int k);
};

//Default Constructor Definition
BST::BST() : data{0}, left{nullptr}, right{nullptr} {}

//Parameterized Constructor Definition
BST::BST(int k) : data{k}, left{nullptr}, right{nullptr} {}

//Insert Function Definition
BST *BST::Insert(BST *root, int k)
{
    if (!root)
    {
        return new BST(k);
    }
    if (k > root->data)
    {
        /*We traverse the right subtree if the data
        /to be inserted is greater than the root value.*/
        root->right = Insert(root->right, k);
    }
    else
    {
        /*We traverse the left subtree if the data
        to be inserted is lesser than the root value.*/
        root->left = Insert(root->left, k);
    }
    return root;
}

BST *BST::Search(BST *root, int key)
{
    if (root == nullptr || root->data == key)
        return root;
    if (key > root->data)
        return Search(root->right, key);
    return Search(root->left, key);
}
void BST::Inorder(BST *root)
{
    if (!root)
        return;
    Inorder(root->left);
    cout << root->data << "\n";
    Inorder(root->right);
}

int main()
{
    BST b;
    BST *root = nullptr;
    root = b.Insert(root, 15);
    b.Insert(root, 25);
    b.Insert(root, 17);
    b.Insert(root, 12);
    b.Insert(root, 8);
    b.Insert(root, 10);
    b.Insert(root, 20);
    b.Inorder(root);
    BST *res = b.Search(root, 10);
    cout << res << " " << res->data << "\n";
    /*Observation : BST Insertion does not always lead to a perfect BST*/
}