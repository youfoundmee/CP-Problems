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

        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;

            int column = find(s.begin(), s.end(), '#') - s.begin();

            vec[n - i - 1] = column;
        }

        for (int col : vec)
        {
            cout << col+1 << " ";
        }
        cout << '\n';
    }

}
