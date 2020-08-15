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

class HashTable
{
public:
    Node **HT;
    HashTable();
    int hash(int key);
    void Insert(int key);
    int Search(int key);
    ~HashTable();
};

HashTable::HashTable()
{
    HT = new Node *[10];
    for (int i = 0; i < 10; i++)
    {
        HT[i] = nullptr;
    }
}

int HashTable::hash(int key)
{
    return key % 10;
}

void HashTable::Insert(int key)
{
    int h_idx = hash(key);
    Node *temp = new Node(key);
    //Case : No nodes int the linked list
    if (HT[h_idx] == nullptr)
    {
        HT[h_idx] = temp;
    }
    else
    {
        Node *curr = HT[h_idx];
        while (curr->next != nullptr && curr->next->data < key)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

int HashTable::Search(int key)
{
    int h_idx = hash(key);
    Node *p = HT[h_idx];
    while (p)
    {
        if (p->data == key)
        {
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable()
{
    for (int i = 0; i < 10; i++)
    {
        Node *p = HT[i];
        while (HT[i])
        {
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete[] HT;
}

int main()
{
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(A) / sizeof(A[0]);
    HashTable H;
    for (int i = 0; i < n; i++)
    {
        H.Insert(A[i]);
    }
    int key = 6;
    int value = H.Search(6);
    cout << "Successful Search\n";
    cout << key << " " << value << " \n";
    key = 95;
    value = H.Search(key);
    cout << "Unsuccessful Search\n";
    cout << key << " " << value << " \n";
    return 0;
}