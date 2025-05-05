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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
        string s;
        cin>>s;
        int curr=1;
        int maxr=1;
        fr(i,0,s.size()){
            if(s[i]==s[i+1]){
                curr++;
               
            }
            else{
                if (curr > maxr)
                    maxr = curr;
                curr=1;
            }
        }
        cout<<max(curr,maxr)<<endl;
}