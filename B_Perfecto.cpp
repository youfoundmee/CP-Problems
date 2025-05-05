#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define nl "\n"
#define f1(i, n) for (int i = 1; i <= n; i++)

using namespace std;

// Function to check if a number is a perfect square
bool isSquare(ll n)
{
    ll sq = sqrt(n);
    return sq * sq == n;
}

// Function to check if the sum of first `n` numbers is a perfect square
bool square(int n)
{
    ll sum = 1LL * n * (n + 1) / 2;
    return isSquare(sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        if (square(n))
        {
            cout << -1 << nl; // No valid sequence
        }
        else
        {
            vector<int> v(n);

            // Construct the array in reverse order
            for (int i = 0; i < n; i++)
            {
                v[i] = n - i;
            }

            // Output the array
            f1(i, n) cout << v[i - 1] << " ";
            cout << nl;
        }
    }
}
