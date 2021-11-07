/*
Author : Devesh Lohumi
लहरों से डर कर नौका पार नहीं होती,
कोशिश करने वालों की हार नहीं होती।
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr long long int MOD = 1000000007;
#define IGNORE cin.ignore(32767, '\n')
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<long long, long long>

class node
{
public:
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void printLevelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (1)
    {
        int n = q.size();
        if (n == 0)
            break;
        while (n--)
        {
            node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << "\n";
    }
}

node *make_bst(const vector<int> &a, int left, int right)
{
    if (left > right)
        return nullptr;
    int mid = left + (right - left) / 2;
    node *root = new node(a[mid]);
    root->left = make_bst(a, left, mid - 1);
    root->right = make_bst(a, mid + 1, right);
    return root;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    sort(all(a));
    node *root = make_bst(a, 0, n - 1);
    printLevelOrder(root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t{1};
    while (t--)
    {
        solve();
    }
}
