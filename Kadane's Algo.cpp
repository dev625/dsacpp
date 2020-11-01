#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> V(n);
        for (int i = 0; i < n; i++)
            cin >> V[i];
        int best = INT_MIN, sum = 0;
        for (auto x : V)
        {
            sum += x;
            best = max(best, sum);
            sum = max(sum, 0);
        }
        cout << best << "\n";
    }
}