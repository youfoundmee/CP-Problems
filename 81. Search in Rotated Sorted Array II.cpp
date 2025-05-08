#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int x)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = (hi + lo) / 2;
            if (nums[mid] == x)
                return true;
            if (nums[mid] == nums[lo] && nums[lo] == nums[hi])
            {
                lo++;
                hi--;
                continue;
            }
            // Left portion (bigger part)
            if (nums[lo] <= nums[mid])
            {
                if (x > nums[mid] || x < nums[lo])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            // Right portion (smaller part)
            else
            {
                if (x < nums[mid] || x > nums[hi])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    sol.search(nums, target);
    return 0;
}
