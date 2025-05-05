#include <iostream>
using namespace std;

#define ll long long
#define nl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if (a == 1 && b == 1)
        {
            cout << 3 << nl;
            continue;
        }

        ll mod = (a - 1) % 4;

        if (mod == 0 && b == a - 1)
        {
            cout << a << nl;
        }
        else if (mod == 0 && (a-1)==(a^b))
        {
            cout << a+2 << nl;
        }
        else if (mod == 1 && b == 1)
        {
            cout << a << nl;
        }
        else if (mod == 1 && b == (a ^ mod)) {
            cout << a + 2 << nl;
        }
        else if (mod == 2 && b == a)
        {
            cout << a << nl;
        }
        else if (mod == 2 && b == 0)
        {
            cout << a+2 << nl;
        }
        else if (mod == 3)
        {
            if (b == 0)
            {
                cout << a << nl;
            }
            else if (a == b)
            {
                cout << a + 2 << nl;
            }
            else
            {
                cout << a + 1 << nl; 
            }
        }
        else
        {
            cout << a + 1 << nl; 
        }
    }

}
