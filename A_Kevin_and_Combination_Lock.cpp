#include <iostream>
#include <string>
using namespace std;

#define nl endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        string str = to_string(x);

        while (str.find("33") != string::npos)
        {
            str.erase(str.find("33"),2);
        }

        long long num = stoll(str);

        if (num % 33 == 0)
        {
            cout << "YES" << nl;
        }
        else
        {
            num -= 33;
            if (num % 33 == 0)
            {
                cout << "YES" << nl;
            }
            else
            {
                if (num < 0 || num%33!=0)
                    cout << "NO" << nl;

            }
        }
    }
}
