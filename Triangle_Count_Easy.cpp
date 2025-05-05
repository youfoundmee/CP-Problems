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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<int> v(n);
        fr(i, 0, n) cin >> v[i];
        if (n == 0)
        {
            cout << 0 << "\n"; 
            continue;
        }
        sort(all(v));
        vector<pair<ll,ll>>vp;
        fr(i,0,n-1){
            vp.push_back({v[i+1]-v[i]+1,v[i+1]+v[i]-1});
        }
        sort(all(vp));
        ll ans=vp[0].ss-vp[0].ff+1;
        ll mx=vp[0].ss;
        fr(i,1,vp.size()){
            ll x=vp[i].ff;
            ll y=vp[i].ss;
            if(x>mx){
                ans+=y-x+1;
                mx=y;
            }
            else{
                if(y>mx){
                    ans+=y-mx;
                    mx=y;
                }
            }
            
        }
        cout<<ans<<nl;

    }

}