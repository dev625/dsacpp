#include <bits/stdc++.h>
using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents)
    {
        m_cents = cents;
    }
    int getCents() const
    {
        return m_cents;
    }
    friend Cents operator+(const Cents &c1, const Cents &c2);
    friend Cents operator-(const Cents &c1, const Cents &c2);
    friend Cents operator+(const Cents &c1, int val);
    friend Cents operator+(int val, const Cents &c1);
};

//note that this function is not a member function
Cents operator+(const Cents &c1, const Cents &c2)
{
    return Cents(c1.m_cents + c2.m_cents);
}

Cents operator-(const Cents &c1, const Cents &c2)
{
    return Cents(c1.m_cents - c2.m_cents);
}
Cents operator+(const Cents &c1, int val)
{
    return {c1.m_cents + val};
}
Cents operator+(int val, const Cents &c1)
{
    return {c1.m_cents + val};
}

int main()
{
    Cents cents1{6};
    Cents cents2{8};
    Cents centsum{cents1 + cents2};
    Cents centdiff(cents1 - cents2);
    cout << centsum.getCents() << "\n";
    cout << centdiff.getCents() << " \n";
}