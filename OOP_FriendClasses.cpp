#include <bits/stdc++.h>
using namespace std;
/*
making an entire class a friend of another class
gives all of the members of the friend class 
access to the private members of the other class.

*/
class Storage
{
private:
    int m_nval;
    double m_dval;

public:
    Storage(int nval, double dval)
    {
        m_nval = nval;
        m_dval = dval;
    }
    friend class Display;
};

class Display
{
private:
    bool m_displayintfirst;

public:
    Display(bool displayintfirst)
    {
        m_displayintfirst = displayintfirst;
    }

    void displayItem(const Storage &storage)
    {
        if (m_displayintfirst)
            cout << storage.m_nval << " " << storage.m_dval << "\n";
        else
            cout << storage.m_dval << " " << storage.m_nval << "\n";
    }
};

int main()
{
    Storage storage(5, 9.21);
    Display disp(false);
    disp.displayItem(storage);
    return 0;
}