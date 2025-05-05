#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
vector<ll> generate_round_numbers()
{
    vector<ll> round_numbers;
    ll limit = 1e9; 
    for (ll i = 1; i <= limit; i *= 10)
    {
        for (ll j = 1; j <= 9; ++j)
        {
            ll num = i * j;
            if (num <= limit)
                round_numbers.push_back(num);
        }
    }
    return round_numbers;
}
void solve(const vector<ll> &round_numbers)
{
    ll n;
    cin >> n;

    auto it = upper_bound(round_numbers.begin(), round_numbers.end(), n);
    cout << (it - round_numbers.begin()) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> round_numbers = generate_round_numbers();
    ll t;
    cin >> t;
    while (t--)
    {
        solve(round_numbers);
    }

}
