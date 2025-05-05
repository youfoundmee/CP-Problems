#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define ll long long

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> a(n), b(m);
    ll sum_a = 0, sum_b = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum_a += a[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        sum_b += b[i];
    }

    ll total_beauty = sum_a * sum_b;

    unordered_set<ll> possible_beauties;

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            ll beauty_after_operation = total_beauty - (a[r] * sum_b + sum_a * b[c] - a[r] * b[c]);
            possible_beauties.insert(beauty_after_operation);
        }
    }

    while (q--)
    {
        ll x;
        cin >> x;
        if (possible_beauties.count(x))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    
}
