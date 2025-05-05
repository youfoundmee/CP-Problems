#include <iostream>
#include <string>
using namespace std;

#define inp3(a, b, c) \
    int a, b, c;      \
    cin >> a >> b >> c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        inp3(n, r, b);

        string s = "";
        int grp1 = r / (b + 1);   
        int remain = r % (b + 1); 

        for (int i = 0; i < b + 1; i++)
        {
            if (i < remain)
            {
                s += string(grp1 + 1, 'R'); }
            else
            {
                s += string(grp1, 'R'); 
            }
            if (i < b)
                s += "B"; 
        }

        cout << s << '\n';
    }


}
