#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *Insert(Node *head, int key)
{
    Node *current;
    Node *temp = new Node(key);
    //Special Case for the head end
    if (head == nullptr || head->data >= key)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        current = head;
        while (current->next != nullptr && current->next->data < key)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
    return head;
}

void display(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = nullptr;
    head = Insert(head, 14);
    head = Insert(head, 20);
    head = Insert(head, 13);
    head = Insert(head, 31);
    head = Insert(head, 10);
    display(head);
}