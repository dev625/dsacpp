#include <bits/stdc++.h>
using namespace std;

class Accumulator
{
private:
    int m_value;

public:
    Accumulator()
    {
        m_value = 0;
    }
    void add(int val)
    {
        m_value += val;
    }

    friend void reset(Accumulator &acc);
};

void reset(Accumulator &acc)
{
    acc.m_value = 0;
}

int main()
{
    Accumulator acc;
    acc.add(5); //add 5 to accumulator
    reset(acc); //reset the acc to 5
    return 0;
}