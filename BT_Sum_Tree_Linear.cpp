#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

/*O(n) method to check whether a tree is a sumtree or not

1. If the node is a leaf nodes then sum of subtree rooted
with this node is equal to value of this node.
2. If the node is not a leaf node then sum of usbtree rooted 
with this node is twice the value of this node.
*/

bool isleaf(Node *x)
{
    if (x == nullptr)
        return false;
    if (x->left == nullptr && x->right == nullptr)
        return true;
    return false;
}

bool check(Node *root)
{
    int left, right;
    //if node is null or leaf then it is a sum tree
    if (root == nullptr || isleaf(root))
        return true;
    if (check(root->left) && check(root->right))
    {
        //Get the sum of nodes in left subtree
        if (root->left == nullptr)
            left = 0;
        else if (isleaf(root->left))
            left = root->left->data;
        else
            left = 2 * (root->left->data);
        //Get the sum of nodes in the right subtree
        if (root->right == nullptr)
            right = 0;
        else if (isleaf(root->right))
            right = root->right->data;
        else
            right = 2 * (root->right->data);
        /*If the root's data is equal to sum of nodes
        in left and right subtrees the return true
        else return false. */
        return (root->data = left + right);
    }
    return false;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(6);
    root->right = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->right->left = new Node(1);
    root->right->right = new Node(3);
    cout << check(root);
}
