#include <iostream>
using namespace std;
constexpr int MAX{100};
class Stack
{
    int top;
    public:
        int arr[MAX];
        Stack()
        { top =-1;}
        bool push(int x);
        int pop();
        int peek();
        bool isempty();
        bool isfull();
};

bool Stack::push(int x)
{
    if(top==MAX-1)
    {
        cout << "Stack Overflow\n";
        return false;
    }
    else
    {
        arr[++top] = x;
        cout << x<<" pushed into stack\n";
        return true;
    }
}
int Stack::pop()
{
    if(top==-1)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    else
    {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek()
{
    if(top==-1)
    {
        cout << "Stack is Empty\n";
        return -1;
    }
    else
        return arr[top];
}

bool Stack::isempty()
{
    return(top==-1);
}

bool Stack::isfull()
{
    return(top==MAX-1);
}

int main()
{
    Stack s;
    s.push(10);
    s.push(12);
    s.push(13);
    int x = s.pop();
    int y = s.pop();
    int z = s.pop();
    cout << x << " " << y << " "<< z <<"\n";
    s.pop();
    cout << s.isempty();
}