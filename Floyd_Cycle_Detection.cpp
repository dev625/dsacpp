/*
We maintain two pointers slow and fast. fast pointers moves twice 
as fast as the slow pointer. So we iterate through the linked list using
these pointers. If these two pointers become equal at some point of time
that implies that there does exist a loop in the linked list.
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
};

ListNode *meetingpoint(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return nullptr;
}

ListNode *findints(ListNode *head)
{
    ListNode *foo = meetingpoint(head);
    if (foo == nullptr)
        return nullptr;
    ListNode *slow = head;
    while (slow != foo)
    {
        slow = slow->next;
        foo = foo->next;
    }
    return slow;
}