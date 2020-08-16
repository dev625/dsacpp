/*Given a binary tree and a key, we insert the key 
into the binary tree at first position available.*/

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void insert(Node *temp, int data)
{
    queue<Node *> Q;
    Q.push(temp);
    //We do level order traversal until we
    //find an empty place
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        if (!temp->left)
        {
            temp->left = new Node(data);
            break;
        }
        else
            Q.push(temp->left);
        if (!temp->right)
        {
            temp->right = new Node(data);
            break;
        }
        else
            Q.push(temp->right);
    }
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
    inorder(root);
    cout << "\n";
    insert(root, 8);
    inorder(root);
}