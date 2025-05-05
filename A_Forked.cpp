#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> dx = {-1, 1, -1, 1}, dy = {1, 1, -1, -1};
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int xk, yk, xq, yq;
        cin >> xk >> yk >> xq >> yq;
        int ans = 0;
        set<pair<int, int>> st1, st2;
        for (int j = 0; j < 4; j++)
        {
            st1.insert({xk + dx[j] * a, yk + dy[j] * b});
            st2.insert({xq + dx[j] * a, yq + dy[j] * b});
            st1.insert({xk + dx[j] * b, yk + dy[j] * a});
            st2.insert({xq + dx[j] * b, yq + dy[j] * a});
        }

        for (auto x : st1)
            if (st2.find(x) != st2.end())
                ans++;
        cout << ans << '\n';
    }
}