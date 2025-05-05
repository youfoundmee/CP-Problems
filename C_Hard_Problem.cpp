#include <iostream>
#include <algorithm>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        int row1_seats = min(m, a);
        int row2_seats = min(m, b);
        int remaining_seats = 2 * m - row1_seats - row2_seats;

        int remaining_monkeys = c;
        int max_seated = row1_seats + row2_seats + min(remaining_seats, remaining_monkeys);

        cout << max_seated << endl;
    }

   
}
