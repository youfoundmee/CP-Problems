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
#define pb push_back
#define ff first
#define ss second
#define nl "\n"



vti func(int n){
    if(n==4){
        vti v={2,1,3,4};
        return v;
    }
    if(n==6){
        vti v = { 2 ,4, 5, 1, 3, 6};
        return v;
    }
    int x=log2(n);
    int y=1LL<<x;
    vti ans;
    ans.pb(y);
    ans.pb(y-1);
    ans.pb(y - 2);
    ans.pb(3);
    ans.pb(1);
    ans.pb(2);
    fr(i,4,y-2)ans.pb(i);
    fr(i,y+1,n+1)ans.pb(i);
    reverse(all(ans));
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vti v(n);
        if(n%2!=0){
            v=func(n-1);
           v.pb(n);
           cout<<n<<nl;
           for(auto i:v)cout<<i<<" ";
           cout<<nl;    
        }
        else{
            v=func(n);
            cout<<(1LL<<(int)log2(n)+1)-1<<nl;
            for(auto i:v)cout<<i<<" ";
            cout<<nl;
        }
    }

}