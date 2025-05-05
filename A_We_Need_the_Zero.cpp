#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum = sum ^ arr[i];
        }
        if (n % 2 != 0)
        {
           
            cout << sum << endl;
        }
        else
        {
         if(sum==0) cout<<0<<endl;
         else cout<<-1<<endl;

         
        }
    }
}