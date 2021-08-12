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

class fourWheeler : public Vehicle
{
public:
    fourWheeler()
    {
        cout << "Objects with 4 wheels are vehicles.\n";
    }
};

class Car : public fourWheeler
{
public:
    Car()
    {
        cout << "Car has 4 wheels.\n";
    }
};

int main()
{
    Car obj;
    return 0;
}