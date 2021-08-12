#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle.\n";
    }
};

class Car : public Vehicle
{
};

int main()
{
    Car obj;
    return 0;
}