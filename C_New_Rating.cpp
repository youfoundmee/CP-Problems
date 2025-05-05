#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Prefix rating calculation
        vector<int> prefix(n, 0);
        int rating = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > rating)
            {
                rating++;
            }
            else if (a[i] < rating)
            {
                rating--;
            }
            prefix[i] = rating;
        }

        // Suffix rating calculation
        vector<int> suffix(n, 0);
        rating = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > rating)
            {
                rating++;
            }
            else if (a[i] < rating)
            {
                rating--;
            }
            suffix[i] = rating;
        }

        // Now calculate the maximum possible rating by skipping the interval [l, r]
        int max_rating = INT_MIN;

        // Case where we skip from the very first contest to any contest [1, r] or any [l, n]
        max_rating = max(max_rating, suffix[1]);
        max_rating = max(max_rating, prefix[n - 1]);

        // Now consider skipping intervals between [l, r] and combining prefix and suffix results
        for (int i = 0; i < n - 1; i++)
        {
            max_rating = max(max_rating, prefix[i] + suffix[i + 1]);
        }

        cout << max_rating << nl;
    }

    return 0;
}
