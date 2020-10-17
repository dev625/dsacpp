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

int dfsutil(Node *node)
{
    //we'll use a modified postorder traversal to solve this problem in linear time
    if (node == nullptr)
        return 0;
    int l = dfsutil(node->left);
    int r = dfsutil(node->right);
    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;
    return max(l, r) + 1;
}

bool isbalanced(Node *node)
{
    return dfsutil(node) != -1;
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
    cout << isbalanced(root) << "\n";
}