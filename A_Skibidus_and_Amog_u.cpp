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

        int pos = s.rfind("us"); 

        if (pos != string::npos)
        {
            s.replace(pos, 2, "i");
        }

        cout << s << endl;
    }

    
}
