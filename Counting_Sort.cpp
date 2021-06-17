#include <bits/stdc++.h>
using namespace std;

vector<int> counting_sort(const vector<int> &a)
{
    int n = a.size(), k = *max_element(a.begin(), a.end());
    vector<int> count(k + 1, 0);
    vector<int> output(n);
    for (auto &x : a)
        count[x]++;
    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i]; //just use predecrement instead of this
        count[a[i]]--;
    }
    return output;
}

int main()
{
    int n;
    cout << "Enter the number of elements:\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements\n";
    for (auto &x : a)
        cin >> x;
    vector<int> b = counting_sort(a);
    cout << "\nThe sorted array is :\n";
    for (auto &x : b)
        cout << x << " ";
}
