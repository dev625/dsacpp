#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 100;
    for (int i = 0; i <=100; i++)
    {
        bitset<8> M(i);
        cout << i << " " << M << " " << __builtin_popcount(i) << "\n";
    }
}