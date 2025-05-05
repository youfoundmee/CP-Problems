#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int end = -1;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                end = i;
                break;
            }
        }

        if (end == -1)
            return "";
        return num.substr(0, end + 1);
    }
};

int main()
{
    string input;
    cout << "Enter a number: ";
    cin >> input;

    Solution sol;
    string result = sol.largestOddNumber(input);

    cout << result << endl;

}
