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
        cin >> n;
        vti v(n), ans;
        fr(i, 0, n )
        {cin>>v[i];
        }
        ans.push_back(v[0]);
        fr(i,1,n){
            if(v[i-1]>v[i]){
                ans.push_back(v[i]);      
            }
            ans.push_back(v[i]);
              }
            cout<<ans.size()<<nl;
            fr(i,0,ans.size()){
                cout<<ans[i]<<" ";
            }
            cout<<nl;

        }
           
}
