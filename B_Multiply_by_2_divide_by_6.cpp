#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vti vector<int>
#define vt vector
#define MOD9 1000000009
#define MOD7 1000000007
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a - 1; i >= b; i--)
#define each(a, x)    \
    for (auto &a : x) \
    1
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define ff first
#define ss second
#define nl "\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
       int cnt2=0,cnt3=0;
       while(n%2==0){
        cnt2++;
        n/=2;
       }
       while (n % 3 == 0)
       {
           cnt3++;
           n /= 3;
       }
       if(n!=1) cout<<-1<<nl;
       else if(cnt3>=cnt2){
        cout<<(cnt3-cnt2)+cnt3<<nl;
       }
       else{
        cout<<-1<<nl;
       }
    }

}