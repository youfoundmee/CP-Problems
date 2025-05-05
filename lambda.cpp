#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<[&](int x){return x+2;}(2);
   auto sum= [&](int x,int y)
    { return x + y; };
    cout<<sum(2,3);

}


// if (all_of(a.begin(), a.end(), [&](int x){ return x == a[0]; }))
//
// {
// cout << -1 << endl;}

// if (any_of(a.begin(), a.end(), [&](int x){ return x == a[0]; }))
//
// {
// cout << -1 << endl;}

// if (none_of(a.begin(), a.end(), [&](int x){ return x == a[0]; }))
//
// {
// cout << -1 << endl;}