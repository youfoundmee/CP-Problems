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
        vti v(n);
        unordered_set<int>us;
        cin>>v[0];
        fr(i, 1, n)
        {
            cin >> v[i];
            us.insert(v[i]-v[i-1]);
           

        }
        int min=*min_element(us.begin(),us.end());
        if(min<0) cout<<0<<endl;
        else if(min==0) cout<<1<<endl;
        else cout<<(min/2)+1<<endl;
// we could have done like this too
        // ll diff = INT_MAX;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     if (abs(v[i] - v[i + 1]) < diff)
        //         diff = abs(v[i] - v[i + 1]);
        // };
        // return diff / 2 + 1;
    }
    }
