#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdint>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        // Input the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        unordered_map<int, int> freq;
        int max_freq = 0;
        int mode = 0;

        vector<int> b(n);

        // Iterate through the array and calculate mode up to each index
        for (int i = 0; i < n; i++)
        {
            int num = a[i];
            freq[num]++;

            // Update the mode if needed
            if (freq[num] > max_freq)
            {
                max_freq = freq[num];
                mode = num;
            }
            else if (freq[num] == max_freq && num < mode)
            {
                mode = num;
            }

            b[i] = mode; // Store the current mode
        }

        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
