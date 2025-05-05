#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#include <cstring>

#define ll long long
#define nl endl
#define ld long double
#define gcd(a,b) __gcd<long long>(a,b)
#define lcm(a,b) (a * (b / gcd(a,b)))

#define pb push_back
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define umcc unordered_map<char,char>

#define mii map<int,int>
#define mci map<char,int>
#define mcc map<char,char>
#define mapsi map<string,int>
#define dmp map<int, map<int,int>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvpii vector<vector<pii>>
#define si set<int>
#define usi unordered_set<int>
#define sd set<int, greater<int>>
#define msi multiset<int>
#define msd multiset<int, greater<int>>
#define dq deque<int>

#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#define inp(k) long long k; cin>>k
#define inp2(n,k) long long n, k; cin>>n; cin>>k
#define inp3(a,b,c) long long a, b, c; cin>>a>>b>>c
#define inp4(a,b,c,d) long long a, b, c, d; cin>>a>>b>>c>>d

#define fr(i,a,b) for(long long i=a;i<b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define qsort(a,n) sort(a+0, a+n);
#define revqsort(a,n) sort(a+0, a+n, greater<int>());

#define endl "\n"
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using namespace std;

const int MAX=200000;
const long long int M  = 1000000007;
const long long int Cplus=1e18;
const double Cmin=1e-18;
const int mod=1e9+7;

ll MOD(ll n){
    return (n % M + M) % M;
}
ll mul(ll a, ll b){
    return MOD(MOD(a) * MOD(b));
}
ll add(ll a, ll b){
    return MOD(MOD(a) + MOD(b));
}

ll modPow(ll a, ll b) {
    if (b == 0) return 1LL;
    if (b == 1) return a % M;
    ll res = 1;
    while (b) {
        if (b % 2 == 1) res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}
ll inv(ll x) {
    return modPow(x, M - 2);
}

ll divide(ll a, ll b) {
    return mul(a, inv(b));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    
    while (t--) {
        inp2(n,m);
        ll dif=n-m;
        ll cnt=0;
        if(n==m) {
            cout<<"infinity"<<nl;
            continue;
        }
        if (n <m)
        {
            cout <<0 << nl;
            continue;
        }
        for(int i=1;i*i<=dif;i++){
            if (dif % i == 0 ){
                if(i>m)cnt++;
                if (dif / i != i && dif / i >= m)
                    cnt++;
            }
        }
        cout<<cnt<<nl;

    
    }

}