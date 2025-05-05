#include <iostream>
#include <string>
#include <vector>
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define f(i, n) for (int i = 0; i < n; i++)

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
        string n;
        cin >> n;

        long long sum = 0;
        long long cnt2 = 0, cnt3 = 0;

        for (char c : n)
        {
            int digit = c - '0'; 
            if (digit == 2)
                cnt2++;
            if (digit == 3)
                cnt3++;
            sum += digit;
        }

        bool found = false;

        for (int i = 0; i <= cnt3; i++)
        {
            for (int j = 0; j <= cnt2; j++)
            {
                int temp_sum = sum + j * 2 + i * 6;
                if (temp_sum % 9 == 0)
                {
                    found = true;
                    break;
                }
            }
        }

        if (found)
            YES;
        else
            NO;
    }

}
