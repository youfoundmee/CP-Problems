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
        ll n,k;
        cin >> n>> k;
         vector<ll>v(n);
        fr(i,0,n) cin >> v[i];
        int cnt=0;
        if(n==1){
            cout<<(v[0]==k?0:1)<<nl;
            continue;
        }
        fr(i,0,n){
            if(v[i]==k) continue;
            cnt++;
            while(i<n-1 && v[i]==v[i+1]){
                i++;
            }
            bool flag=false;
            while(i<n && __gcd(v[i],k)==k){
                i++;
                flag=true;
            }
            if(i<n && flag==true) cnt++;

        }
        if(cnt>=2) cout<<2<<endl;
        else cout<<cnt<<endl;
    }

}