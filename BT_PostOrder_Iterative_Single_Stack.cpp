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

void iterative_postorder(Node *root)
{
    //Check for empty tree
    if (root == nullptr)
        return;
    stack<Node *> A;
    do
    {
        //Move to the leftmost node
        while (root)
        {
            //Push root's right child and then root to stack
            if (root->right)
            {
                A.push(root->right);
            }
            A.push(root);
            //Set root as roots's left child
            root = root->left;
        }
        //Pop an item from stack and set it as root
        root = A.top();
        A.pop();
        if (root->right != nullptr && A.top() == root->right)
        {
            A.pop();            // Remove Right Child from stack
            A.push(root);       // Push root back to stack
            root = root->right; // Change root so that the right
        }                       // child is processed first
        else
        {
            cout << root->data << " ";
            root = nullptr;
        }

    } while (!A.empty());
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
    iterative_postorder(root);
    return 0;
}