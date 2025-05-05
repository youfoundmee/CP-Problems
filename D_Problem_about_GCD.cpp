#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r, G;
        cin >> l >> r >> G;

        l = ((l + G - 1) / G); 
        r /= G;                

        bool found = false;

        for (ll i = r - l; i >= 0; i--)
        {
            for (ll j = l; j + i <= r; j++)
            {
                if (__gcd(i + j, j) == 1)
                {
                    cout << j * G << " " << (j + i) * G << endl;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        if (!found)
        {
            cout << "-1 -1" << endl;
        }
    }
}
