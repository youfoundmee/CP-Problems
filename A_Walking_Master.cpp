#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long
#define na cout << "NO" << endl;
#define ha cout << "YES" << endl;
#define pb(x) push_back(x);
#define all(x) x.begin(), x.end()
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
       if(b<=d && a-b>=c-d){
        cout<<(d-b)+(a+d-b-c)<<endl;
       }
       else{
        cout<<-1<<endl;
       }
    }
}