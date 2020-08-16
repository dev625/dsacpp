#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void printLevelOrder(node *root)
{
    //base case
    if (root == nullptr)
        return;
    //create an empty queue for level order traversal
    queue<node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    printLevelOrder(root);
}