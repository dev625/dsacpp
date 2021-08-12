#include <bits/stdc++.h>
using namespace std;

/*
A derived class with 2 base classes and these 2 base classes
have one common base class is called multipath inheritance.
An ambiguity can arise in this type of inheritance.
*/

class ClassA
{
public:
    int a;
};

class ClassB : public ClassA
{
public:
    int b;
};

class ClassC : public ClassA
{
public:
    int c;
};

class ClassD : public ClassB, public ClassC
{
public:
    int d;
};

int main()
{

    ClassD obj;
    //obj.a = 10; error of ambiguity
    obj.ClassB::a = 10;
    obj.ClassC::a = 100;

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;
    cout << "\n A from Class B : " << obj.ClassB::a;
    cout << "\n A from Class C : " << obj.ClassC::a;
    cout << "\n B : " << obj.b;
    cout << "\n C : " << obj.c;
    cout << "\n D : " << obj.d;
}