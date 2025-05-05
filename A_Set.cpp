#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD9 1000000009
#define MOD7 1000000007
#define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r, k;
        cin >> l >> r >> k;

        ll upper_bound = r / k;

        ll ans = max(0LL, upper_bound - l + 1);

        cout << ans << nl;
    }

    
}
