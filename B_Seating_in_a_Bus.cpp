#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int temp;
        cin >> temp;
        unordered_set<int> us;
        bool possible = true;
        us.insert(temp + 1);
        us.insert(temp - 1);

        for (int i = 1; i < n; i++)
        {
            int next;
            cin >> next;
           
            if (find(us.begin(),us.end(),next)== us.end())
            {
                possible = false;
            }
            else
            {
                us.insert(next + 1);
                us.insert(next - 1);
                us.erase(next);
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            cout << "NO" << endl;
            continue;
        }
    }
}