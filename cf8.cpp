#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vti vector<ll> // Changed to long long
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
#define pb push_back
#define nl "\n"

vti func(vti &v){
    multiset<ll>ms;
    vti ans;
    fr(i,0,v.size()){
        while(ms.find(v[i])!=ms.end()){
            ms.erase(v[i]);
            v[i]*=2;
        }
        ms.insert(v[i]);
        ans.pb(ms.size());


    }
    return ans;
}

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
        vti v(n);
        fr(i, 0, n) cin >> v[i];

        vti ans = func(v);

        for (auto i : ans)
            cout << i << " ";
        cout << nl;
    }
}
