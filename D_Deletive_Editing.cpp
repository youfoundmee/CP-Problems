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

    ll n;
    cin >> n;
    while (n--) {
        string s,t;
        cin >>s >>t;
        vti cnt(26,0);
        fr(i,0,t.size()) cnt[t[i] - 'A']++;
        string temp="";
        rf(i,s.size(),0){
            if(cnt[s[i]-'A']>0) 
            temp+=s[i];
            cnt[s[i]-'A']--;
            
        }
        reverse(temp.begin(),temp.end());
        if(temp==t) cout<<"YES"<<nl;
        else cout<<"NO"<<nl;

    }

}