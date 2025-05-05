#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD9 1000000009
#define MOD7 1000000007
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n % 2 != 0)
        {
            cout << "YES" << nl;
        }
        else if (n == 2)
        {
            cout << "NO" << nl;
        }
        else
        {
            bool ok = false;
            while (n > 2)
            {
                if (n % 2 != 0)
                {
                    ok = true;
                    break;
                }
                n /= 2;
            }

            if (ok)
            {
                cout << "YES" << nl;
            }
            else
            {
                cout << "NO" << nl;
            }
        }
    }

}
