#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define nl endl
#define vi vector<int>
#define vvc vector<vector<char>> 

#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)

using namespace std;

const int MAX = 200000;
const long long int M = 1000000007;
const int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi ans(n + 1, 0);                       
        vvc v(n + 1, vector<char>(n + 1, '0')); 

        f1(i, n)
        {
            int cnt = 0;
            f1(j, n)
            {
                cin >> v[i][j]; 

                if (i < j && v[i][j] == '0')
                    cnt++;
                else if (i > j && v[i][j] == '1')
                    cnt++;
            }

            
            
                ans[cnt+1] = i;
            
        }

        f1(i, n) cout << ans[i] << " ";
        cout << nl;
    }
}
