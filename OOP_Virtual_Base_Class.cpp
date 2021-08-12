#include <bits/stdc++.h>
using namespace std;

/*
Virtual base classes are used in virtual inheritance
in a way of preventing multiple instances of a given class
appearing in an inheritance hierarchy when using multiple
inheritances.

Consider this:
                A
             /     \
            B        C
             \     /
                D

Data member/function of class A are inherited twice to class
D. One through class B and one through class . When any data/function 
of class A is accessed by object of class D ,ambuiguity arises as to 
which data/function member would be called. This confuses the compiler
and it displays an error.

One way to resolve this is using the scope resolution operator :: 

Another way is to use virtual base class.
*/

class A
{
public:
    int a;
    A()
    {
        a = 10;
        cout << "Hello from A!\n";
    }
};

class B : public virtual A
{
};

class C : public virtual A
{
};

class D : public B, public C
{
};

/*
    class A has just one data member which is public. This class
    is virtually inherited in class B and class C. Now class B
    and class C becomes virtual base class and no duplication of data
    member a is done.

*/

int main()
{
    D obj;
    cout << "a= " << obj.a << "\n";
    pow(2, 3);
}