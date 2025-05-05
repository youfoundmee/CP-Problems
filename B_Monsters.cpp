#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vti vector<ll>
#define vt vector
#define MOD9 1000000009
#define MOD7 1000000007
#define pb push_back
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a - 1; i >= b; i--)
#define each(a, x)    \
    for (auto &a : x) \
    1
#define all(x) (x).begin(), (x).end()
#define pii pair<ll, ll>
#define ff first
#define ss second
#define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n>>k;
        vti ans;
        map<ll,vti,greater<int>>mp;
        fr(i,1,n+1){
            ll x;
            cin>>x;
            if(x%k==0)ans.pb(i);
            else mp[x%k].pb(i);
t
        }
        for(auto &x:mp){
            for(auto &y:x.ss)ans.pb(y);

        }
        for(auto x:ans)cout<<x<<" ";
        cout<<nl;



    }

}