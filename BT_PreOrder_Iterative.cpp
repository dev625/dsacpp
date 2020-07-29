#include <iostream>
#include <stack>
using namespace std;

class Node
{
    public:
        int data;
        Node* left,*right;
        Node(int data)
        {
            this->data = data;
            left = right = nullptr;
        } 
};

void iterativepreorder(Node* root)
{
    stack<Node*>A;
    Node* temp = root;
    A.push(temp);
    while(!A.empty())
    {
        Node* foo = A.top();
        A.pop();
        cout << foo->data << " ";
        if(foo->right)
            A.push(foo->right);
        if(foo->left)
            A.push(foo->left);
    }
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right =  new Node(7);
    iterativepreorder(root);
    return 0;
}