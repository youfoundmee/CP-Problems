#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinimumCost(const vector<int> &sequence)
{
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        if (sequence[i] != static_cast<int>(i + 1))
        {
            return i + 1;
        }
    }
    return sequence.size() + 1;
}

void processTestCases()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int &num : arr)
        {
            cin >> num;
        }

        int minCost = n + 1;

        for (int mask = 0; mask < (1 << (n - 1)); ++mask)
        {
            if (__builtin_popcount(mask) != k - 1)
                continue;

            vector<vector<int>> subarrays;
            vector<int> currentSegment;
            currentSegment.push_back(arr[0]);

            for (int j = 0; j < n - 1; ++j)
            {
                if ((mask >> j) & 1)
                {
                    subarrays.push_back(currentSegment);
                    currentSegment.clear();
                }
                currentSegment.push_back(arr[j + 1]);
            }
            subarrays.push_back(currentSegment);

            if (subarrays.size() != k)
                continue;

            vector<int> computedArray;
            for (size_t j = 1; j < subarrays.size(); j += 2)
            {
                computedArray.insert(computedArray.end(), subarrays[j].begin(), subarrays[j].end());
            }
            computedArray.push_back(0);

            minCost = min(minCost, findMinimumCost(computedArray));
        }
        cout << minCost << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    processTestCases();
   
}
