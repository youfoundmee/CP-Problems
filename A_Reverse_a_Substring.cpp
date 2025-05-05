#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define f1(i, n) for (int i = 1; i <= n; i++)

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool found = false;
        f1(i, s.size() - 1)
        {
            if (s[i - 1] > s[i])
            {
                cout << "YES" << nl;
                cout << i << " " << i + 1 << nl; 
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "NO" << nl;
        }
    }

}
