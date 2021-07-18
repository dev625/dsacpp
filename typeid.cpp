#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 12;
    int arr[5]{};
    int *ad = &a;
    double b = 123.232131;
    float c = 3123.2;
    string f = "ddasdsa";
    vector<int> v{};
    cout << typeid(a).name() << "\n";
    cout << typeid(&a).name() << "\n";
    cout << typeid(b).name() << "\n";
    cout << typeid(&c).name() << "\n";
    cout << typeid(&f).name() << "\n";
    cout << sizeof(ad) << "\n";
    cout << typeid(arr).name() << "\n";
}