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
    while (t--) {
        ll n,b,c;
        cin >> n>>b >> c;
        
        if(b==0){
            if(c==n-1 || c==n-2) cout<<n-1<<nl;
            else if(c>=n) cout<<n<<nl;
            else cout<<-1<<nl;
        }
        else{
            cout<<n- max(0LL,(n-c+b-1)/b)<<nl;
        }

    }

}