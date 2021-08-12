#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a vehicle.\n";
    }
};

class FourWheeler
{
public:
    FourWheeler()
    {
        cout << "This is a 4 wheeler vehicle.\n";
    }
};

class Car : public Vehicle, public FourWheeler
{
};

int main()
{
    Car obj;
    return 0;
}