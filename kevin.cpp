#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 300005LL
const int mod = 1e9 + 7;
const int INF = 1e15 + 5;
const double LIM = 1e-6;
// for BS: while(r-l>LIM)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
/*
CTRL+CLICK = multi cursor
CTRL+D = next occurrence
CTRL+K = skip occurre
CTRL+SHIFT+K = del entire line
CTRL+SHIFT+UP/DOWN = move selected text or line
CTRL+X = crop
*/

void solve()
{
    /*
    read n, m
    read n ratings, m difficulties

    create an array ahead(m) wich stores how many people are ahead of kevin considering only that problem, that is, if kevin can solve that problem
    than 0 people are ahead of him, else if kevin cannot solve that problem then the number of people ahead of him is going to be given by the number of
    people with rating >= than the difficulty of that problem

    we sort ahead(m) in increasing order

    now to create k groups, for the kth group we need to select the first k ahead elements that hasn't been selected

    our ranking is going to be given by the sum of the maximum ahead in the kth group across all k groups
    */
    int n, m;
    cin >> n >> m;
    vi rat(n), dif(m);
    for (int i = 0; i < n; i++)
    {
        cin >> rat[i];
    }
    int kevin = rat[0];
    for (int i = 0; i < m; i++)
    {
        cin >> dif[i];
    }
    sort(rat.begin(), rat.end());
    vi frente(m);
    for (int i = 0; i < m; i++)
    {
        if (dif[i] <= kevin)
            frente[i] = 0;
        else
        {
            auto l = lower_bound(rat.begin(), rat.end(), dif[i]);
            auto r = rat.end();
            frente[i] = r - l;
        }
    }
    sort(frente.begin(), frente.end());
    for (int k = 1; k <= m; k++)
    {
        int ans = 0;
        for (int i = k - 1; i < m; i += k)
        {
            ans += frente[i] + 1;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int32_t main()
{
// freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}