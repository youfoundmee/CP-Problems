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
        if(n%2==0){
            cout<<2<<nl;
            cout<<1<<" "<<n<<nl;
            cout<<1<<" "<<n<<nl;
        }
        else{
            cout<<4<<nl;
            cout<<1<<" "<<n<<nl;
            cout<<2<<" "<<n<<nl;
            cout<<1<<" "<<2<<nl;
            cout << 1 << " " << 2 << nl;
        }
    }

}