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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//to set a bit at a particular position:
    cout<<(9 | (1<<3))<< nl;
       
       //to unset a bit at a particular position:
        cout << (9& ~(1<<3))<< nl;


    //to toggle a bit at a particular position:
    cout << (9 ^ (1 << 3)) << nl;

    // to count the number of set bits in a number:
    int cnt=0;
    rf(i,32,0){
        if(9&(1<<i))cnt++;
    }
    // or
    cout<<__builtin_popcountll(35)<<nl;


    // to convert uppercase to lowercase 
     
    char a='A' | ' ';
    cout<<a<<nl;
// to convert lowercase to uppercase
    char c='c';
    char C=c&'_';
    cout<<C<<nl;    
//to check if a number is a power of 2
int n=16;
if(n&(n-1))cout<<"no"<<nl;
else cout<<"yes"<<nl;    


}
