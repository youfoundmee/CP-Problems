#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#include <cstring>

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()

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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        vector<pii> rowSums;

        f(i, n)
        {
            ll rowSum = 0;
            f(j, m)
            {
                cin >> matrix[i][j];
                rowSum += matrix[i][j];
            }
            rowSums.push_back({rowSum, i});
        }

        sort(all(rowSums), greater<pii>());

        ll totalSum = 0,ans=0; 
        f(i, n)
        {
            int rowIndex = rowSums[i].second;

            f(j, m)
            {
                totalSum += matrix[rowIndex][j];
                ans+=totalSum;
            }
        }

        cout << ans<< endl;
    }

    
}
