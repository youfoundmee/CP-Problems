#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
int main()
{
    cin >> n >> k;
    if (n % 2!=0)
        p = n / 2 + 1;
    else
        p = n / 2;
    if (k > p)
        cout << (k - p) * 2;
    else
        cout << 2 * k - 1;
}