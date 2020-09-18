#include <iostream>
#include <string>
using namespace std;

void search(const string &a, const string &b)
{
    int p = a.length();
    int q = b.length();
    for (int i = 0; i <= p - q; i++)
    {
        int j;
        for (j = 0; j < q; j++)
        {
            if (a[i + j] != b[j])
                break;
        }
        if (j == q)
            cout << "Pattern Found at index " << i << "\n";
    }
}
int main()
{
    string a = "AABAACAADAABAAABAA";
    string b = "AABA";
    search(a, b);
    return 0;
}