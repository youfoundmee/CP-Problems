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
#define pii pair<ll, ll>
#define ff first
#define ss second
#define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n,p;
        cin >> n >>p;
        vt<pii> vp(n);
        for(auto &i:vp) cin>>i.ss;
        for(auto &i:vp) cin>>i.ff;

    sort(all(vp));  
    ll cost=p;
    ll count=1;
    while(count<n){
    fr(i,0,n){
        cost+=min(p,vp[i].ff)*min(vp[i].ss,n-count);
        count+=min(vp[i].ss,n-count);
        if (count == n)
        {
            break;
        }
    }
    
    
}
cout<<cost<<nl;
}
}