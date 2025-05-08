#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl endl
#define gcd(a, b) __gcd<long long>(a, b)
#define vi vector<ll>
#define pb push_back
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

const int MAX = 200000;
const long long int M = 1000000007;

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
        ll k;
        cin >> n >> k;
        vi a(n);

        ll sum = 0, maxi = LLONG_MIN, mini = LLONG_MAX;
        f(i, n)
        {
            cin >> a[i];
            sum += a[i];
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }

        int cnt = 0;
        f(i, n)
        {
            if (a[i] == maxi)
                cnt++;
        }

       
        if ((maxi - mini > k + 1) || (maxi - mini == k + 1 && cnt > 1))
        {
            cout << "Jerry" << nl;
        }
        else
        {
            if (sum % 2)
                cout << "Tom" << nl;
            else
                cout << "Jerry" << nl;
        }
    }

    
}
