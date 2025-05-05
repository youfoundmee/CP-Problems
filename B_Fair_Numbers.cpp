#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
typedef unordered_set<int> usi;

bool ok(ll n)
{
    ll temp = n;
    while (temp != 0)
    {
        int digit = temp % 10;
        if (digit != 0 && n % digit != 0)
        {
            return false; 
        }
        temp /= 10; 
    }
    return true; 
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        while (!ok(n))
        {
            n++; 
        }
        cout << n << '\n';
    }
    
}
