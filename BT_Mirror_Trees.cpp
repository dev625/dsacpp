#include <iostream>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bool Check_Mirror_Method1(Node *root1, Node *root2)
{
    // Base Case : Both nodes are equal if they are empty
    if (root1 == nullptr && root2 == nullptr)
        return true;
    // If both nodes are internal nodes
    if (root1 != nullptr && root2 != nullptr)
    {
        return (root1->data == root2->data &&
                Check_Mirror_Method1(root1->left, root2->right) &&
                Check_Mirror_Method1(root1->right, root2->left));
    }
    // Only one node is null
    return false;
}

bool Check_Mirror_Method2(Node *root1, Node *root2)
{
    //Base Case : Both nodes are equal if they are empty
    if (root1 == nullptr && root2 == nullptr)
        return true;
    // Now it is established that both of them are not null
    // Checking if exactly one of them is null
    if (root1 == nullptr || root2 == nullptr)
        return false;
    /*Both are non empty, we compare them recursively*/
    return (root1->data == root2->data &&
            Check_Mirror_Method2(root1->left, root2->right) &&
            Check_Mirror_Method2(root1->right, root2->left));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return 0;
}