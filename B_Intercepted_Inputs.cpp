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
        ll n,x;
        cin >> n;
        unordered_multiset<ll> s;
        for(int i=0;i<n;i++){
             cin>>x;
             s.insert(x);

    }
    for (int i = 1; i*i <= n; i++)
    {   
        if(i*i==n-2){
            auto it=s.find(i);
            if(it==s.end()){
                continue;
            }
            else{
                s.erase(it);
            }
            auto it1 = s.find(i);
            if(it1==s.end()){
                continue;
            }
            else{
                cout<<i<<" "<<i<<endl;
                break;
            }
        }
        else
        if ((n - 2) %i == 0)
        {
            auto it=s.find(i);
            auto it1=s.find((n-2)/i);
            if(it==s.end() || it1==s.end()){
                continue;
            }
            else{
                cout<<i<<" "<<(n-2)/i<<endl;
                break;
            }



        }
    }
    }
}