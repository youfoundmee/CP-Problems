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
        string s;
        cin >> s;
        ll arr[26] = {0};
        fr(i,0,n){
            arr[s[i]-'a']++;
        }
        int count = 0;
        fr(i,0,26){
            
            count+=arr[i]%2;
        }
        if(count>k+1){
            cout<<"NO"<<nl;
        }
        else{
            cout<<"YES"<<nl;
        }

    }

}