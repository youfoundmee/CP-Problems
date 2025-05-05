#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int x,k;
        cin>>x >>k;
        if(x<k || x%k!=0){
            cout<<1<<endl;
            cout<<x<<endl;
        }
        else{
            cout<<2<<endl;
            cout<<x-k-1<<" "<<k+1<<endl;
        }
    }
}