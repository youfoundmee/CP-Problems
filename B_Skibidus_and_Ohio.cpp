#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        bool found = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                found = true;
                break;
            }
        }

        cout << (found ? 1 : n) << endl;
    }

    
}
