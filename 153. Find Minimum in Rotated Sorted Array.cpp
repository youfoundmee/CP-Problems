#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1;
        int mini = INT_MAX;
        while (lo <= hi)
        {
            if (nums[lo] < nums[hi])
            {
                mini = min(mini, nums[lo]);
                break; // Array is already sorted
            }

            int mid = (hi + lo) / 2;
            mini = min(mini, nums[mid]);

            if (nums[mid] >= nums[lo])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return mini;
    }
};

int main()
{
    Solution sol;

    // Example input: rotated sorted array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int result = sol.findMin(nums);
    cout  << result << endl;

    return 0;
}
