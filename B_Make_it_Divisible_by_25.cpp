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
        string s;
        cin >> s;
        ll n=s.length();
        ll ans=n;
       
        fr(i,0,n-1){
            fr(j,i+1,n){
                ll num=(s[i]-'0')*10 + (s[j]-'0');
                if(num%25==0){
                    ans=min(ans,(j-i-1)+(n-1-j));
                }
            }
        
        }
        cout << ans << endl;
    }

}