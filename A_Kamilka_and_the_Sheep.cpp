#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        int n;
        cin >> n; 
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; 
        }

        int maxBeauty = *max_element(a.begin(), a.end());
        int minBeauty = *min_element(a.begin(), a.end());

        cout << (maxBeauty - minBeauty) << endl;
    }

    
}
