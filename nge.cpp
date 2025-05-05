#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vti vector<ll>
#define vt vector
#define MOD9 1000000009
#define MOD7 1000000007
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a - 1; i >= b; i--)
#define each(a, x)    \
    for (auto &a : x) \
    1
#define all(x) (x).begin(), (x).end()
#define pii pair<ll, ll>
#define ff first
#define ss second
#define nl "\n"



vti NGE(vti a){
    stack<ll>st;
    vti ans(a.size());
    fr(i,0,a.size()){
        while(!st.empty() && a[i]>a[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);

    }
    while(!st.empty()){
        ans[st.top()]=-1;
        st.pop();
    }
    return ans;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vti a(n);
        fr(i, 0, n) cin >> a[i];
        vti ans=NGE(a);
        fr(i, 0, n) cout << a[i] << " " << (ans[i] == -1 ? -1 : a[ans[i]]) << nl;
        cout<<nl;

    }

}


