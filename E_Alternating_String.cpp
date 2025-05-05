#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int min_operations_to_alternating(string s)
{
    int n = s.size();

    if (n % 2 == 1)
    {
        // Consider the case where we remove one character and compute for both possibilities
        string s1 = s.substr(0, n - 1); // Remove the last character
        string s2 = s.substr(1);        // Remove the first character
        return min(min_operations_to_alternating(s1), min_operations_to_alternating(s2));
    }

    // Length is even
    unordered_map<char, int> even_count, odd_count;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even_count[s[i]]++;
        }
        else
        {
            odd_count[s[i]]++;
        }
    }

    // Find the most frequent characters in even and odd positions
    char most_even = '\0';
    char most_odd = '\0';
    int max_even = 0;
    int max_odd = 0;

    for (auto &kv : even_count)
    {
        if (kv.second > max_even)
        {
            max_even = kv.second;
            most_even = kv.first;
        }
    }

    for (auto &kv : odd_count)
    {
        if (kv.second > max_odd)
        {
            max_odd = kv.second;
            most_odd = kv.first;
        }
    }

    // Calculate the minimum changes needed
    int min_changes = (n / 2 - max_even) + (n / 2 - max_odd);

    // If the most frequent even and odd characters are the same
    if (most_even == most_odd)
    {
        // Find the second most frequent characters
        int second_max_even = 0;
        int second_max_odd = 0;

        for (auto &kv : even_count)
        {
            if (kv.first != most_even && kv.second > second_max_even)
            {
                second_max_even = kv.second;
            }
        }

        for (auto &kv : odd_count)
        {
            if (kv.first != most_odd && kv.second > second_max_odd)
            {
                second_max_odd = kv.second;
            }
        }

        min_changes = min(min_changes, (n / 2 - second_max_even) + (n / 2 - second_max_odd));
    }

    return min_changes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        cout << min_operations_to_alternating(s) << endl;
    }

    return 0;
}
