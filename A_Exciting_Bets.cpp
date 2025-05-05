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
        ll a,b;
        cin >>a >>b;
        if(a==b) cout<<"0 0"<<nl;
        else {
            ll excit=abs(a-b);
            ll moves=min(b%excit,excit-b%excit);
            cout<<excit<<" "<<moves<<nl;
           
        }
      
    }

}
// GCD(a,b)=GCD(a−b,b) if a>b
// therefore a-b is always constant ,we have control only on
//b , our goal is to make b as a multiple of a-b 

