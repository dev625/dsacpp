#include <bits/stdc++.h>
using namespace std;

int Kadane1(const vector<int> &V)
{
    //If the subarray can be empty
    //just init best with 0
    int sum{0}, best{INT_MIN};
    int n = V.size();
    for (int i = 0; i < n; i++)
    {
        sum = max(V[i], sum + V[i]);
        best = max(best, sum);
    }
    return best;
}

int main()
{
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int ans = Kadane1(V);
    cout << ans << "\n";
}