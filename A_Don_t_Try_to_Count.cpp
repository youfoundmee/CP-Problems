#include "bits/stdc++.h"
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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        int count = 0;
        bool flag = false;

        if (x.find(s) != string::npos)
        {
            flag=1;
        }
        else if(x.length()>s.length()){
            x.append(x);
            count++;
            if (x.find(s) != string::npos)
            {
                flag = true;
                
            }
        }
        else{
        while (x.length() < s.length()+24 )
        {
            x.append(x); 
            count++;

            if (x.find(s) != string::npos)
            {
                flag = true;
                break;

        }
        }
        if (flag)
        {
            cout << count << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }

}
}