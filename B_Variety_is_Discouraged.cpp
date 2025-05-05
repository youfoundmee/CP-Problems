#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long
#define nl endl
#define f(i, n) for (int i = 0; i < n; i++)
#define inp(n) \
    ll n;      \
    cin >> n;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        inp(n);
        vector<int> arr(n);
        unordered_map<int, int> freq;

        f(i, n)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        int l = 0, r = 0, best_l = 0, best_r = 0, max_len = 0;
        unordered_map<int, int> window;

        while (r < n)
        {
            window[arr[r]]++;

            while (window[arr[r]] > 1)
            {
                window[arr[l]]--;
                l++;
            }

            if (r - l + 1 > max_len)
            {
                max_len = r - l + 1;
                best_l = l+1;
                best_r = r;
            }

            r++;
        }

        if (max_len == 0)
        {
            cout << "0\n";
        }
        else
        {
            cout << best_l + 1 << " " << best_r + 1 << nl; // Convert 0-based to 1-based index
        }
    }

    return 0;
}
