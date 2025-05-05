#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(c) ((ll)(c).size())
#define ALL(x) x.begin(), x.end()
#define LB(A, x) (ll)(lower_bound(ALL(A), x) - A.begin())
#define BS(A, x) binary_search(ALL(A), x)
#define rep(i, a, b) for (int i = a; i < b; i++)
using vi = vector<int>;
using vvi = vector<vi>;
int n, m, a, d, k;
int fa[200020], fn[200020][21];
int find(int a)
{
    return fa[a] == a ? a : fa[a] = find(fa[a]);
}
int main()
{
    int _;
    _=1;
    while (_--)
    {
        cin >> n >> m;
        rep(i, 0, n)
        {
            memset(fn[i], 0, sizeof(fn[i]));
            fa[i] = i;
        }
        while (m--)
        {
            cin >> a >> d >> k;
            a--;
            fn[a][d] = max(fn[a][d], k);
        }
        rep(i, 0, n) rep(j, 1, 11) if (fn[i][j])
        {
            fa[find(i)] = find(i + j);
            fn[i + j][j] = max(fn[i + j][j], fn[i][j] - 1);
        }
        int ans = 0;
        rep(i, 0, n) ans += (fa[i] == i);
        cout << ans << endl;
    }
}