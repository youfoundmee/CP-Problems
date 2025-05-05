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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int countn=0;
        cin>>n;
        vector<int>v(n);
        fr(i,0,n){
            cin>>v[i];
            if(v[i]<0) countn++;
        }
        int ans=0;
        if(countn>n/2) ans=countn-n/2;
        countn-=ans;
        if (countn&1) ans++;
        cout<<ans<<nl;
       
    }
}
//IMPORTANT
// (countn&1) 
// this is bitwise and op , that means if countn is odd 
// then it will return 1 else 0