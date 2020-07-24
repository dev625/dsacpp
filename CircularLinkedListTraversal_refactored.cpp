#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void push(Node *head, int data)
{
    /*Notes on why this approach does not work : 
    pointer are actually passed by value and over here we are actually changing 
    a copy of the head pointer and not the actual head pointer itself, therefore
    a correct approach would be to pass the address of the head pointer itself.
    To fix this just simply passs the pointer by reference as Node *&head   */
    Node*ptr1 = new Node();
    Node *temp = head;
    ptr1->data = data;
    ptr1->next = head;
    if(head!=nullptr)
    {
        while(temp->next!=head)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;
    head = ptr1;
}
void printList(Node *head)
{
    
    Node *temp = head;
    if(head!=nullptr)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp!=head);
    }
}
int main()
{
    Node *head = nullptr;
    push(head,12);
    push(head,56);
    push(head,2);
    push(head,11);
    cout << "The contents of given circular linked lists are :\n";
    printList(head);
    return 0;
}

