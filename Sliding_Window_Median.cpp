#include <bits/stdc++.h>
using namespace std;

vector<double>sliding_window_median(vector<int>&a,int k)
{
    int n = a.size();
    multiset<int> m (a.begin(),a.begin()+k);
    auto mid = next(m.begin(),k/2);
    vector<double>ans;
    for(int i=k;i<n;i++)
    {
        double curr = double(*mid + *prev(mid,1-k%2))/2;
        ans.push_back(curr);
        m.insert(a[i]); 
        if(a[i]<*mid)
            mid--;
        if(a[i-k]<=*mid)
            mid++;
        m.erase(m.lower_bound(a[i-k]));
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of array elements:\n";
    cin >> n;
    vector<int>a(n);
    cout << "Enter the array elements please:\n";
    for(auto &x : a)
        cin >> x;
    int k;
    cout << "Enter the window size :\n";
    cin >> k;
    vector<double>ans = sliding_window_median(a,k);
    cout << "The corresponding median array is :\n";
    for (auto &x :ans)
    {
        cout << x <<" ";
    }
    
}