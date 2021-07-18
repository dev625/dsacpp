#include <bits/stdc++.h>
using namespace std;

class Storage;

class Display
{
private:
    bool m_displayintfirst;

public:
    Display(bool displayintfirst)
    {
        m_displayintfirst = displayintfirst;
    }

    void displayItem(const Storage &stor);
    //forward declaration above needed for this declaration line
};

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

    friend void Display::displayItem(const Storage &stor);
};

void Display::displayItem(const Storage &stor)
{
    if (m_displayintfirst)
    {
        cout << stor.m_nval << "  " << stor.m_dval << "\n";
    }
    else
    {
        cout << stor.m_dval << " " << stor.m_nval << "\n";
    }
}

int main()
{
    Storage storage(3, 4.321);
    Display display(false);
    display.displayItem(storage);
    return 0;
}