#include <iostream>
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

int height(node *node)
{
    int x, y;
    if (node != nullptr)
    {
        x = height(node->left);
        y = height(node->right);
        return max(x, y) + 1;
    }
    return 0;
}

void printGivenLevel(node *root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
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