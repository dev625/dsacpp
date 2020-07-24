#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

/*Function to create a note at the beginning of 
a Circular Linked List*/

void push(Node **head, int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head;

    ptr1->data = data;
    ptr1->next = *head;//setting the next of new node to point to the head node

    /*Now what we do is that if the linked list is not 
    null we go till the last element of the linked list,
    ie in this case the one appearing just before the head
    node and we set its next pointer to the temp node.
    And finally we change the head to point at the newly
    created node*/
    if(*head!=nullptr)
    {
        while(temp->next != *head)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;
    *head = ptr1;
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
    push(&head,12);
    push(&head,56);
    push(&head,2);
    push(&head,11);
    cout << "The contents of given circular linked lists are :\n";
    printList(head);
    return 0;
}