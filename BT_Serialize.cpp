#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool issame(Node *node1, Node *node2)
{
    if (node1 == nullptr && node2 == nullptr)
        return true;
    if (node1 == nullptr || node2 == nullptr)
        return false;
    return node1->data == node2->data && issame(node1->left, node2->left) && issame(node1->right, node2->right);
}

string serialize(Node *node)
{
    if (node == nullptr)
        return "X,";
    string left = serialize(node->left);
    string right = serialize(node->right);
    return to_string(node->data) + "," + left + right;
}

Node *make_tree(queue<string> &q)
{
    string temp = q.front();
    q.pop();
    if (temp == "X")
        return nullptr;
    Node *node = new Node(stoi(temp));
    node->left = make_tree(q);
    node->right = make_tree(q);
    return node;
}

Node *deserialize(const string &s)
{
    stringstream ss(s);
    string temp;
    queue<string> Q;
    while (getline(ss, temp, ','))
        Q.push(temp);
    return make_tree(Q);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->right = new Node(7);
    root->right->left = new Node(8);
    string res = serialize(root);
    Node *dsr = deserialize(res);
    if (issame(root, dsr))
        cout << "Yay, trees are the same,this is working!\n";
    else
        cout << "This is not working :(\n";
}