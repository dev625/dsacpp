#include <bits/stdc++.h>
using namespace std;

/*
A derived class does not inherit access to private data
members, however it does inherit a full parent object.
*/

class A
{
public:
    int x;

protected:
    int y;

private:
    int z;
};

class B : public A
{
    //x is public
    //y is protected
    //z is not accessible from B
};

class C : protected A
{
    //x is public
    //y is protected
    //z is not accessible from B
};

class D : private A
{
    //x is private
    //y is private
    //z is not accessible from D
};
