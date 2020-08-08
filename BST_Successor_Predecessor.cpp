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

Node* Maximum(Node* root)
{
    if (root->right)
        return Maximum(root->right);
    return root;
}

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

Node* Successor(Node* root, int key)
{
    /*First we search for the node corresponding to this particular key*/
    Node* foo = Search(root, key);

    //When the given key does not exist in the BST
    if (foo==nullptr)
        return nullptr;

    /*Case 1 : If the node has a right subtree, we simply return the minimum value in the right subtree.*/
    if (foo->right!=nullptr)
        return Minimum(foo->right);

    /*Case 2 : If the right subtree is null then we traverse the whole BST from the root node to find
    the given element , the successor of a particular node is the lowest node whose left child is
    either our node in consideration or is an ancestor of our node in consideration.*/
    else
    {
        Node *successor = nullptr;
        Node *ancestor = root;      //we traverse the tree from root to our node 
        while (ancestor!=foo)
        {
            if (foo->data < ancestor->data)
            {
                successor = ancestor;//sucessor only changes when foo lies in the left subtree of ancestor
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

Node* Predecessor(Node*root, int key)
{
    /*First we search for the node corresponding to this particular key*/
    Node* foo = Search(root, key);

    //When the given key does not exist in the BST
    if (foo==nullptr)
        return nullptr;

    /*Case 1 : If the left subtree of node is not null, we return the maximum value
    of the left subtree for finding the predecessor.*/
    if (foo->left!=nullptr)
        return Maximum(foo->left);

    /*Case 2 : If the left subtree is null then we traverse the whole BST from the root node to find
    the given element , the predecessor a particular node is the lowest node whose right child is
    either our node in consideration or is an ancestor of our node in consideration.*/
    else
    {
        Node* predecessor = nullptr;
        Node* ancestor = root;
        while (ancestor!=foo)
        {
            if (foo->data < ancestor->data)
                ancestor = ancestor->left;
            else
            {
                predecessor = ancestor;     //predcessor only changes when foo lies in the right subtree of ancestor
                ancestor = ancestor->right;
            }

        }
        return predecessor;
    }
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
    Node* foo = Successor(root, 25);
    Node* bar = Predecessor(root, 11);
    cout << foo->data << "\n";
    cout << bar->data << "\n";
}