#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t; 

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> result;

           
            for (int i = 1; i <= n; i += 2)
            {
                result.push_back(i); 
            }

            for (int i = 2; i <= n; i += 2)
            {
                result.push_back(i); 
            }

            for (int i = 0; i < n; i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }

    
}
