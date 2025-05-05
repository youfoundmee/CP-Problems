#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // 	int t;
    // 	cin>>t;
    // 	while(t--){

    long long n, d;
    cin >> n >> d;

    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int cnt = 0;
    sort(arr, arr + n, greater<int>());
    long long sum = 0;
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        sum += arr[i];
        while (i < j && sum <= d)
        {
            sum += arr[i];
            j--;
        }
        i++;
        if(sum>d){
        
        
            cnt++;
        sum = 0;
    }
    }
    cout << cnt << endl;

    // 	}

}