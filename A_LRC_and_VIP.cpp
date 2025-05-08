#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl endl
#define gcd(a, b) __gcd<long long>(a, b)
#define vi vector<ll>
#define pb push_back
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl

const long long int M = 1000000007;

ll MOD(ll n)
{
    return (n % M + M) % M;
}

ll mul(ll a, ll b)
{
    return MOD(MOD(a) * MOD(b));
}

ll add(ll a, ll b)
{
    return MOD(MOD(a) + MOD(b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);

        f(i, n)
        {
            cin >> arr[i];
        }

        // Compute the GCD of all elements
        ll gcd_all = arr[0];
        f(i, n)
        {
            gcd_all = gcd(gcd_all, arr[i]);
        }

        // Check if all elements are equal to gcd_all
        bool all_equal = true;
        f(i, n)
        {
            if (arr[i] != gcd_all)
            {
                all_equal = false;
                break;
            }
        }

        if (all_equal)
        {
            NO;
            continue;
        }

        YES;
        bool used = false;
        f(i, n)
        {
            if (!used && arr[i] != gcd_all)
            {
                cout << "1 ";
                used = true;
            }
            else
            {
                cout << "2 ";
            }
        }
        cout << nl;
    }

}
