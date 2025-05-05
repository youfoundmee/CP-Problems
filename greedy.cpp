#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> a = {{10, 60}, {20, 100}, {30, 120}};
    sort(a.begin(), a.end(), [](vector<int> &x, vector<int> &y)
         { return (double(x[1]) / x[0]) > (double(y[1]) / y[0]); });
    int capacity;
    cin >> capacity;
    int value = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (capacity >= a[i][0])
        {
            value += a[i][1];
            capacity -= a[i][0];
        }
        else
        {
            value += capacity * (double(a[i][1]) / a[i][0]);
            break;
        }
    }
    cout << value;

    return 0;
}