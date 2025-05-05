#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vti vector<ll>
#define vt vector
#define MOD9 1000000009
#define MOD7 1000000007
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a - 1; i >= b; i--)
#define each(a, x)    \
    for (auto &a : x) \
    1
#define all(x) (x).begin(), (x).end()
#define pii pair<ll, ll>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vti minarray;
        ll mini = INT_MAX;
        while (n--)
        {
            ll m;
            cin >> m;
            vti a(m);
            fr(i, 0, m) cin >> a[i];
            sort(all(a));
            mini = min(mini, a[0]);
            minarray.pb(a[1]);
        }
        cout << accumulate(all(minarray), 0LL) + mini - *min_element(all(minarray)) << nl;
    }
}