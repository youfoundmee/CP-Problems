#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <cstring>

#define ll long long
#define nl endl
#define ld long double
#define gcd(a, b) __gcd<long long>(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))

#define pb push_back
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define umcc unordered_map<char, char>

#define mii map<int, int>
#define mci map<char, int>
#define mcc map<char, char>
#define mapsi map<string, int>
#define dmp map<int, map<int, int>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvpii vector<vector<pii>>
#define si set<int>
#define usi unordered_set<int>
#define sd set<int, greater<int>>
#define msi multiset<int>
#define msd multiset<int, greater<int>>
#define dq deque<int>

#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#define inp(k)   \
    long long k; \
    cin >> k
#define inp2(n, k)  \
    long long n, k; \
    cin >> n;       \
    cin >> k
#define inp3(a, b, c)  \
    long long a, b, c; \
    cin >> a >> b >> c
#define inp4(a, b, c, d)  \
    long long a, b, c, d; \
    cin >> a >> b >> c >> d

#define fr(i, a, b) for (long long i = a; i < b; i++)
#define rf(i, a, b) for (long long i = a; i >= b; i--)
#define qsort(a, n) sort(a + 0, a + n);
#define revqsort(a, n) sort(a + 0, a + n, greater<int>());

#define endl "\n"
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using namespace std;

constexpr int inf = 1E9 + 1;

void solve()
{
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];
    sort(all(b));
    int prev = -1;
    f(i, n)
    {
       auto it=lower_bound(all(b),a[i]+prev);
       if(it!=b.end())
       {
         a[i]=min(a[i],*it);
         
       }
       if(prev<a[i])
       {
           prev=a[i];
       }
       else 
       {
           cout<<"NO"<<endl;
           return;
       }


    }

    YES;
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
        solve();
    }
}