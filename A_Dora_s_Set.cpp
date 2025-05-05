#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to compute GCD
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Function to count valid triplets using combinatorics
int count_valid_triplets(int l, int r)
{
    vector<int> nums(r - l + 1);
    iota(nums.begin(), nums.end(), l);

    int n = nums.size();
    int count = 0;

    // Check all possible triplets using a more efficient method
    for (int i = 0; i < n; ++i)
    {
        int a = nums[i];
        for (int j = i + 1; j < n; ++j)
        {
            int b = nums[j];
            if (gcd(a, b) != 1)
                continue; // Skip non-coprime pairs
            for (int k = j + 1; k < n; ++k)
            {
                int c = nums[k];
                if (gcd(b, c) == 1 && gcd(a, c) == 1)
                {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << count_valid_triplets(l, r) << endl;
    }

    return 0;
}
