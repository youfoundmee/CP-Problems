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
        vti v(n);
        fr(i,0,n)cin>>v[i];
        if(n==1){ cout<<0<<endl;}
        else {map<ll,ll>mp;
        fr(i,0,n) mp[v[i]]++;
        ll freq=0;
        for(auto &pr:mp){
            freq=max(freq,pr.ss);
        }
        ll ans=0;
        while(freq<n){
            if(freq<n-freq){
                ans++;
                ans+=freq;
                freq*=2;
            }
            else{
                ans++;
                ans+=n-freq;
                freq=n;
            }
            
        }
        cout<<ans<<endl;


        
    }
    }
}