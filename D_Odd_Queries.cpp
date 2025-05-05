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
        ll n,q,x;
        cin >> n>> q;
        vti psum(n+1);
        int count=0;
        fr(i,1,n+1){
            cin >> x;
            count+=x;
            psum[i] = count;
        }
        while (q--) {
            ll l,r,k;
            cin >>l >>r >> k;
            int ans=psum[n]-(psum[r]-psum[l-1])+k*(r-l+1);
            if(ans%2==0)cout<<"NO"<<nl;
            else cout<<"YES"<<nl;
            
        }
    }

}