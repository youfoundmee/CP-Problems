#include <bits/stdc++.h>
using namespace std;
double eps = 1e-6;
double ans=1;
double multiply(double a,int n){
    for(int i=0;i<n;i++){
        ans*=a;


    }
    return ans;
}

int main(){
    double x;
    int n;
    cin>>x >>n;
    double low=0,high=x,mid;
    while(high-low>eps){
        mid=(high+low)/2;
        if(multiply(mid,n)<x){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    cout<<setprecision(10)<<low<<"\n"<<high<<endl;
}


//time complexity:p*log(N*(10^d))