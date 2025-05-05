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
        int n,x;
        cin>>n;
        int max=0;
        vector<int>v(n);
        fr(i,0,n){
            
           cin>>v[i];
            if(v[i]>max) max=v[i];
        }
        fr(i, 0, n)
        {
            cout<<max+1-v[i]<<" ";
        }
        cout<<nl;
}
}