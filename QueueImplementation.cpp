#include <iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue(int size);
        ~Queue();
        bool isFull();
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        void display();
};

//queue constructor
Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}

Queue::~Queue()
{
    delete []Q;
}

bool Queue::isEmpty()
{
    if(front==rear)
        return true;
    return false;
}

bool Queue::isFull()
{
    if(rear==size-1)
        return true;
    return false;
}

void Queue::enqueue(int x)
{
    if(isFull())
        cout << "Queue Overflow\n";
    else
    {
        Q[++rear] = x;
    }
}

int Queue::dequeue()
{
    if(isEmpty())
        cout << "Queue Underflow\n";
    else
        return Q[++front];
}

void Queue::display()
{
    int i;
    for(i=front+1;i<=rear;i++)
    {
        cout << Q[i];
        if(i<rear)
        {
            cout << " <- ";
        }
    }
    cout << endl;
}

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(10);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    
}