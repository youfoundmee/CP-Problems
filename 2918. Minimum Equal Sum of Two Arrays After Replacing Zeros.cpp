#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for (int x : nums1)
        {
            sum1 += x;
            if (x == 0)
                zero1++;
        }
        for (int x : nums2)
        {
            sum2 += x;
            if (x == 0)
                zero2++;
        }

        if (zero1 == 0 && zero2 == 0)
            return sum1 == sum2 ? sum1 : -1;
        if (zero2 == 0)
            return (sum1 + zero1) > sum2 ? -1 : sum2;
        if (zero1 == 0)
            return (sum2 + zero2) > sum1 ? -1 : sum1;

        return max(sum1 + zero1, sum2 + zero2);
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {0, 2, 3};
    vector<int> nums2 = {1, 2, 3};
    cout << "Output: " << sol.minSum(nums1, nums2) << "\n"; // Expected: 6

    // Test Case 2
    vector<int> nums3 = {1, 2, 3};
    vector<int> nums4 = {1, 2, 3};
    cout << "Output: " << sol.minSum(nums3, nums4) << "\n"; // Expected: 6

    // Test Case 3
    vector<int> nums5 = {0, 0, 1};
    vector<int> nums6 = {2, 2};
    cout << "Output: " << sol.minSum(nums5, nums6) << "\n"; // Expected: 4

    // Test Case 4
    vector<int> nums7 = {1, 2};
    vector<int> nums8 = {1, 1, 0};
    cout << "Output: " << sol.minSum(nums7, nums8) << "\n"; // Expected: 3

    return 0;
}
