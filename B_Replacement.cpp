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
        ll n;
        string s,r;
        cin >> n >> s >> r;
        r.pop_back();   
        int cnt1=(count(all(s),'1'))-(count(all(r),'0'));
        int cnt2=(count(all(s),'0'))-(count(all(r),'1'));
        if(cnt2>0 && cnt1>0)
        {
            cout<<"YES"<<nl;
        }
        else
        {
            cout<<"NO"<<nl;
        }
    }

}