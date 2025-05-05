#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s)
{
    int start = 0, end = s.length() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        string S;
        cin >> N >> S;

        if (isPalindrome(S))
        {
            cout << "0" << endl; 
        }
        else if (N == 2)
        {
            cout << "-1" << endl; 
        }
        else
        {
            cout << "1" << endl; 
        }
    }
}
