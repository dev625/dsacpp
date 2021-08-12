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

class Fare
{
public:
    Fare()
    {
        cout << "Fare of vehicle.\n";
    }
};

class Car : public Vehicle
{
};

class Bus : public Vehicle, public Fare
{
};

/*
Car and Bus Both Inherit from vehicle giving hierarchial
inheritance , bus inherits from both vehicle and fare
giving multiple inheritance.
*/