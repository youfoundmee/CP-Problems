#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        int horizontal_jumps = (x + k - 1) / k;
        int vertical_jumps = (y + k - 1) / k;
        if(x%2==0 && y%2==0){
            cout << 2 * max(horizontal_jumps, vertical_jumps) -1 << "\n";
        }
else{
        cout <<2* max(horizontal_jumps, vertical_jumps) << "\n";
    }

}
}
