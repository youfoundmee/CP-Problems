#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        int n;
        cin >> n;                                    // Number of impressions
        vector<pair<pair<int, int>, int>> ranges(n); // To store ranges with their indices

        // Step 1: Read the ranges and store them
        for (int i = 0; i < n; i++)
        {
            cin >> ranges[i].first.first >> ranges[i].first.second;
            ranges[i].second = i; // Store the original index
        }

        // Step 2: Sort the ranges based on the starting point, and if equal, by the ending point
        sort(ranges.begin(), ranges.end());

        // Step 3: Initialize result as a binary string of '0's
        string result(n, '0');

        // Step 4: Track the number of overlaps using a sweep line method
        vector<int> active; // To track the active ranges as we sweep through
        for (int i = 0; i < n; i++)
        {
            int l = ranges[i].first.first, r = ranges[i].first.second, idx = ranges[i].second;

            // Remove all ranges that end before the current range starts
            active.erase(remove_if(active.begin(), active.end(), [l](int x)
                                   { return x < l; }),
                         active.end());

            // Now, check if current range [l, r] has a unique value
            bool is_unique = true;
            for (int val = l; val <= r; val++)
            {
                int count = count_if(active.begin(), active.end(), [val](int x)
                                     { return x == val; });
                if (count == 0)
                {
                    is_unique = true;
                    break;
                }
            }

            // Set result for this index
            if (is_unique)
            {
                result[idx] = '1';
            }

            // Add this range to active list
            active.push_back(r);
        }

        // Step 5: Print the result for each test case
        cout << result << endl;
    }
}

int main()
{
    solve();
    return 0;
}
