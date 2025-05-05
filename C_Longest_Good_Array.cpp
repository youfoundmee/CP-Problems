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
        int l, r;
        cin >> l >> r;
        int diff = r - l;

        double sqrt_term = sqrt(1 + 8.0 * diff);
        int k = static_cast<int>((-1 + sqrt_term) / 2);
        if (k * (k + 1) > 2 * diff)
        {
            k--;
        }

        cout << k + 1 << endl;
    }

}
