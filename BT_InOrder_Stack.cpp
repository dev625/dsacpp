#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void inorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        /*Reach the left most Node of the 
        curr Node*/
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        /*curr must be nullptr at this point*/
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        /*Now we traverse the right subtree*/
        curr = curr->right;
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
    return 0;
}