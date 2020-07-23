#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

void display(Node *head)
{
    Node *temp = head;
    while(temp!=nullptr)
    {
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << "\n";
}


Node* reverse(Node *head)
{
    Node *p,*q,*r;
    p = head;
    q = nullptr;
    r = nullptr;
    while(p!=nullptr)
    {
        r = q;
        q = p;
        p=p->next;
        q->next = r;
    }
    return q;
}

int main()
{
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(6);
    display(head);
    head = reverse(head);
    display(head);
}