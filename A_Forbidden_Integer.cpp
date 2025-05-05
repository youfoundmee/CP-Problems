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
        int n,k,x;
        cin>>n >>k >>x;
        if(x!=1) { cout<<"YES"<<endl;
            cout << n << endl;
            fr(i, 1, n)
            
              cout  << 1 << " ";
        cout<<endl;
        }
        else{
            if(n%2==0 && k>1){
                cout << "YES" << endl;
                cout << n/2 << endl;
                fr(i, 1, n/2)
                {
                    
                    cout << 2 << " ";
                   
            }
            cout << endl;
            }

            else if(n%2!=0 && k>2){
                cout << "YES" << endl;
                cout << (n - 3) / 2 + 1 << endl;
                fr(i, 1, (n - 3) / 2 )
                {
                    
                    cout << 2 << " ";

            }
            cout<<3;
            cout << endl;
            }
            
            else
            {
                cout << "NO" << endl;
            }
        }
            
    }
}
