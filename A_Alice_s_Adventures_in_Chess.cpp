#include <iostream>
#include <string>
using namespace std;

string will_meet(int n, int a, int b, const string &s)
{
    // Starting position of Alice
    int x = 0, y = 0;

    for (int i = 0; i < 31; ++i)
    {
        // Go through the sequence once
        for (char move : s)
        {
            if (move == 'N')
            {
                y += 1;
            }
            else if (move == 'E')
            {
                x += 1;
            }
            else if (move == 'S')
            {
                y -= 1;
            }
            else if (move == 'W')
            {
                x -= 1;
            }

            // Check if Alice is at the Red Queen's position
            if (x == a && y == b)
            {
                return "YES";
            }
        }
    }

    return "NO";
}

int main()
{
    int t;
    cin >> t; 

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b; // Read n, a, b for each test case
        string s;
        cin >> s; // Read the movement string s

        cout << will_meet(n, a, b, s) << endl; // Check if Alice will meet the Red Queen
    }

    return 0;
}
