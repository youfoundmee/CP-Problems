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
#define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vt<ll> a(n);
        fr(i, 0, n) cin >> a[i];
        
        fr(i,0,n){
            bool flag = 1;
            fr(j,0,n){
                if(i==j)continue;
                if(abs(a[i]-a[j])%k==0) {
                    flag=0;
                    break;
                }
            }
            if(flag){
                cout<<"YES"<<nl;
                cout<<i+1<<nl;
                break;
            }
            if(i==n-1){
                cout<<"NO"<<nl;
            }

        }
    }
}