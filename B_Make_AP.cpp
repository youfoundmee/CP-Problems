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
        ll p,q,r;
        cin >>p >>q >>r;
        bool found=0;
        if((2*q-p)%r==0){
            if ((2 * q - p) / r>0)
            found=true;
        }
         if((2*q-r)%p==0){
            if ((2 * q - r) / p>0)
            found=true;
        }
        if ((r+p)%(2*q)==0){
            found=true;
        }

        if(found)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        

    }

}