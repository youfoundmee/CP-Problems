#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int find_most_frequent(const vector<int> &numbers)
{
    unordered_map<int, int> freq_map;

    // Count frequency of each number
    for (int num : numbers)
    {
        freq_map[num]++;
    }

    int max_freq = 0;
    int result = INT_MAX;

    // Find the number with the highest frequency, tie-breaking on the smallest number
    for (auto &entry : freq_map)
    {
        int num = entry.first;
        int freq = entry.second;

        if (freq > max_freq || (freq == max_freq && num < result))
        {
            max_freq = freq;
            result = num;
        }
    }

    return result;
}

int main()
{
    // Number of test cases
    int t;
    cin >> t;

    // Loop through each test case
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n; // Number of elements in the sequence
        vector<int> numbers(n);

        // Read the numbers into the vector
        for (int j = 0; j < n; ++j)
        {
            cin >> numbers[j];
        }

        // Call the function to find the most frequent number
        cout << find_most_frequent(numbers) << endl;
    }

    return 0;
}
