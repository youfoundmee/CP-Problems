#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vti = vector<int>;

#define fr(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vti v(n);
        fr(i, 0, n)
        {
            cin >> v[i];
        }

        vti ans(n);
        ans[0] = v[0];  // Initialize the first element of ans
        int sum = v[0]; // Initialize sum with the first element

        fr(i, 1, n)
        {
            // If the previous value is odd, just add it to sum and update ans
            if (v[i - 1] % 2 == 1)
            {
                sum += v[i];
                ans[i] = sum; // Store the updated sum
                continue;
            }

            // If the previous value is even, enter the while loop
            while (v[i - 1] % 2 == 0)
            {
                v[i - 1] /= 2; // Divide the previous number by 2
                v[i] *= 2;     // Multiply the current number by 2
            }
            // After modifications, add the current value to sum
            sum += v[i];
            ans[i] = sum; // Store the updated sum
        }

        // Print the ans array
        fr(i, 0, n)
        {
            cout << ans[i] << " ";
        }
        cout << "\n"; // Print a newline after each test case
    }

    return 0;
}
