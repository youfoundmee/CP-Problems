#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vti vector<int>
#define vt vector
#define MOD9 1000000009
#define MOD7 1000000007
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a - 1; i >= b; i--)
#define each(a, x)    \
    for (auto &a : x) \
    1
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define ff first
#define ss second
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multiset<int> ms; 
        fr(i, 0, n)
        {
            int x;
            cin >> x;
            ms.insert(x);
        }
        int sum = 0;
        for (int x : ms)
        {
            sum += x;
        }
        if (sum % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// If you are only reading values and have no intention of modifying them, use const auto& to
// clearly indicate that the values should not be changed. This can prevent accidental modifications and improve code safety.
// int sum = 0;
// for (auto &pair : um)
// {
//     sum += pair.second;
// }
