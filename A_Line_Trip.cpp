#include <bits/stdc++.h>
using namespace std;
unordered_set<int>us;
int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_set<int> us;
        int n,x,temp2;
        int temp1=0;
        cin>>n >>x;
        for(int i=0;i<n;i++){
            cin>>temp2;
            us.insert(temp2 - temp1);
            temp1=temp2;
        }
        us.insert(2*(x-temp2));
        int max=*max_element(us.begin(),us.end());
        cout<<max<<endl;
    }
}