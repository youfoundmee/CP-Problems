#include <iostream>
#include <vector>
#include <climits>
#define endl "\n"
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);

        for (int i = 0; i < n; i++)
            cin >> v1[i];
        for (int i = 0; i < n; i++)
            cin >> v2[i];

        int cnt = 0;
        int dif = 0;

        for (int i = 0; i < n; i++)
        {
            if (v2[i] >v1[i])
            {
                dif = v2[i] - v1[i];
                cnt++;
            }
        }

        if (cnt >= 2)
        {
            NO;
            continue;
        }
        else if (cnt == 0)
        {
            YES;
            continue;
        }

        int min_diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (v1[i] >= v2[i])
            {
                min_diff = min(min_diff, v1[i] - v2[i]);
            }
        }

        if (min_diff >= dif)
            YES;
        else
            NO;
    }

}
