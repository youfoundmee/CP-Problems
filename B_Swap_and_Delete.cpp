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
    while (t--)
    {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        int n = s.size();

        fr(i, 0, n)
        {
            if (s[i] == '0')
                cnt0++;
            else
                cnt1++;
        }
        int i;
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                if(cnt1>0) cnt1--;
                else
                    break;
            }
            if (s[i] == '1')
            {
                if (cnt0 > 0)
                    cnt0--;
                else
                    break;
            }
        }
        cout<<n-i<<endl;

    }
}