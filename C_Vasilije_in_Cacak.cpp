#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define ull unsigned long long
// #define vti vector<int>
// #define vt vector
// #define MOD9 1000000009
// #define MOD7 1000000007
// #define fr(i, a, b) for (int i = a; i < b; i++)
// #define rf(i, a, b) for (int i = a - 1; i >= b; i--)
// #define each(a, x)    \
//     for (auto &a : x) \
//     1
// #define all(x) (x).begin(), (x).end()
// #define pii pair<int, int>
// #define ff first
// #define ss second
// #define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n,k,x;
        cin >> n>> k>> x;
       ll total_sum=n*(n+1)/2;
       ll min_sum=k*(k+1)/2;
       ll ans=total_sum-(n-k)*(n-k+1)/2;
       if(min_sum<=x && ans>=x)
       {
           cout<<"YES"<<endl;
       }
       else
       {
           cout<<"NO"<<endl;
       }
    }

}