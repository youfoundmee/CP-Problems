#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> diff(n + 1, 0); // Difference array for efficient range updates

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vector<int> results;
        for (int i = 0; i < m; ++i)
        {
            char op;
            int l, r;
            cin >> op >> l >> r;

            // Apply operation to the difference array
            if (op == '+')
            {
                if (l - 1 < n)
                {
                    diff[l - 1] += 1;
                }
                if (r < n)
                {
                    diff[r] -= 1;
                }
            }
            else if (op == '-')
            {
                if (l - 1 < n)
                {
                    diff[l - 1] -= 1;
                }
                if (r < n)
                {
                    diff[r] += 1;
                }
            }

            // Apply the difference array to the original array
            int current_increment = 0;
            int max_val = INT_MIN;
            for (int j = 0; j < n; ++j)
            {
                current_increment += diff[j];
                int updated_value = a[j] + current_increment;
                max_val = max(max_val, updated_value);
            }

            results.push_back(max_val);
        }

        // Reset the difference array
        fill(diff.begin(), diff.end(), 0);

        // Output the results for this test case
        for (const int &result : results)
        {
            cout << result << " ";
        }
        cout << endl;
    }

    return 0;
}
