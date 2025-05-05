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
        vti v(n), b, c;
        fr(i, 0, n) cin >> v[i];
        sort(all(v));
        
        
            b.push_back(v[0]);

            // THIS ALSO COULD BE APPROACH TO KNOW IF ALL ELEMENTS ARE EQUAL OR NOT  
            // if (all_of(a.begin(), a.end(), [&](int x)
                    //    { return x == a[0]; }))
            // {
                // cout << -1 << endl;
                // continue;

                //THIS IS APPROACH NO.2
            // bool allSame = true;
            // for (int i = 1; i < n; ++i)
            // {
            //     if (a[i] != a[0])
            //     {
            //         allSame = false;
            //         break;
            //     }
            // }

            // if (allSame)
            // {
            //     cout << -1 << endl;
            //     continue; // Skip to the next test case
            // }

        fr(i, 1, n)
        {
            if (v[i] == v[0])
            {
                b.push_back(v[i]);
            }
            else
            {
                c.push_back(v[i]);
            }
        }
        if (c.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << b.size()<<" "<<c.size()<<endl;
            fr(i, 0, b.size()) cout<<b[i]<< " ";
            cout<<endl;
            fr(i, 0, c.size()) cout << c[i] << " ";
        }
        cout << endl;
    }

}
