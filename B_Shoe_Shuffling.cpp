#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ll long long
#define nl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        unordered_map<int, int> mp;
        ll n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        bool invalid = false;

        for (auto num : mp)
        {
            if (num.second == 1)
            {
                invalid = true;
                break;
            }
        }

        if (invalid)
        {
            cout << -1 << nl;
            continue;
        }

        vector<int> result;
        int m = 0;  

       
            for (auto &i : mp)
            {
                int a = m;
                m += i.second;
                cout << m << " "; 
                for (int j = a + 1; j < m; j++)
                {
                    cout << j << " "; 
                }
            }
        

        cout << nl;
    }

    
}
