#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int> Q)
{
    while (!Q.empty())
    {
        cout << Q.top() << " ";
        Q.pop();
    }
    cout << "\n";
}

void showpq1(priority_queue<int, vector<int>, greater<int>> A)
{
    while (!A.empty())
    {
        cout << A.top() << " ";
        A.pop();
    }
}

int main()
{
    //max heap for priority queue
    priority_queue<int> Q;
    Q.push(10);
    Q.push(30);
    Q.push(20);
    Q.push(5);
    Q.push(1);
    cout << "\nSize of the queue is : " << Q.size() << "\n";
    cout << "The top of this queue is : " << Q.top() << "\n";
    showpq(Q);
    //min heap for priority queue
    priority_queue<int, vector<int>, greater<int>> Q1;
    Q1.push(10);
    Q1.push(30);
    Q1.push(20);
    Q1.push(5);
    Q1.push(1);
    cout << "\nSize of the queue is : " << Q1.size() << "\n";
    cout << "The top of this queue is : " << Q1.top() << "\n";
    showpq1(Q1);
}