#include "bits/stdc++.h"
using namespace std;

#define fr(i, start, end) for (int i = start; i < end; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    
    cin >> t;
    int matrix[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    while (t--)
    {
        string s;
        int ans = 0;
        
    
        fr(i, 0, 10){
        {
            cin >> s;

            fr(j, 0, 10)
            {

                if (s[j] == 'X')
                {
                    ans += matrix[i][j]; 
            }
        }
       
    }
   
}
cout << ans << endl;
}

}