#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#include <cstring>

#define ll long long
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
#define frdec(i,a,b) for(long long i=a;i>=b;i--)
#define qsort(a,n) sort(a+0, a+n);
#define revqsort(a,n) sort(a+0, a+n, greater<int>());

#define nl endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using namespace std;

const int MAX=200000;
const long long int MOD  = 1000000007;
const long long int Cplus=1e18;
const double Cmin=1e-18;
const int mod=1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        //swap two number by xor
        int a=4,b=6;
        a=a^b;
        b=b^a;
        a=a^b;
        cout<<a<<" "<<b<<nl;
        /***given arrat a of n integers,
         * all integers present in even count except one.
         * find that in O(N) and O(1) space complexity
          
         **/ 
int n;
cin>>n;
int ans=0;
fr(i,0,n){
    int x;
    cin>>x;
    ans^=x;
}
cout<<ans<<nl;
    }

}