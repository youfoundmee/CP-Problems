#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vti vector<int>
#define vt vector
#define MOD9 1000000009
#define MOD7 1000000007
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define rf(i, a, b) for (int i = a - 1; i >= b; i--)
#define each(a, x)    \
    for (auto &a : x) \
    1
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define ff first
#define ss second
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        
            int a,b;
            cin>>a>>b;
            if(a==0 && b%2!=0)
                {cout << "NO" << endl;}
            else if(b==0 && a%2!=0) {cout<<"NO"<<endl;}
            else{
                if ((a*1+b*2)%2!=0){
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
            }


            
            
        
    

}

    }
