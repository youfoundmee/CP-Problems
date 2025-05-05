#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vti vector<int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vti v(n);
        int dist=k-1;
        int e=0;
        fr(i, 0, n)
        {

            cin >> v[i];}

            fr(i, 0, n)
            {
                if (v[i] % 2 == 0)e++;
                    
                if (v[i] % k == 0) dist=0;
                else
                    dist = min(dist, k - v[i] % k);
            }

            if (k == 4)
            {
                if (e >= 2)
                    cout << 0<< nl;
                else if (e == 0)
                    cout << min(dist, 2) << nl;
                else
                    cout << min(dist, 1) << nl;
            }
            else{
                cout<<dist<<nl;
            }
        }
    }

