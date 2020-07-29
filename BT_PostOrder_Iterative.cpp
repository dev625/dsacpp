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


/*Idea is similar to iterative preorder traversals, the reverse of the desired outcome in postorder traversals
is actually similar to the result of the preorder traversals, the difference being in this case
the right subtree is traversed before the left subtree*/

void iterativepostorder(Node* root)
{
    stack <Node*> S1;
    stack <Node*> S2;
    S1.push(root);
    while(!S1.empty())
    {
        Node* temp = S1.top();
        S1.pop();
        S2.push(temp);
        if(temp->left)
            S1.push(temp->left);
        if(temp->right) //since this is pushed later, the right subtree is traversed first
            S1.push(temp->right);
    }
    while(!S2.empty())
    {
        cout << S2.top()->data << " ";
        S2.pop();
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
    iterativepostorder(root);
    return 0;
}