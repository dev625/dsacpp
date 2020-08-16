#include <iostream>
#include <queue>
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

void Right_View(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> Q;
    Q.push(root);
    while (1)
    {
        int Node_Count = Q.size();
        if (Node_Count == 0)
        {
            break;
        }
        Node *temp = Q.back();
        cout << temp->data << " ";
        while (Node_Count > 0)
        {
            Node *foo = Q.front();
            Q.pop();
            if (foo->left)
                Q.push(foo->left);
            if (foo->right)
                Q.push(foo->right);
            Node_Count--;
        }
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
    root->left->right->right = new Node(8);
    Right_View(root);
}