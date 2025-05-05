#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

const int INF = LLONG_MAX / 2;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return n > 1;
}

int N;
vector<string> board;
vector<vector<string>> solutions;
vector<bool> cols, diag1, diag2;

void placeQueen(int row, int col)
{
    board[row][col] = '1';
    cols[col] = diag1[row - col + N - 1] = diag2[row + col] = true;
}

void removeQueen(int row, int col)
{
    board[row][col] = '0';
    cols[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
}

bool isSafe(int row, int col)
{
    return !cols[col] && !diag1[row - col + N - 1] && !diag2[row + col];
}

void backtrack(int row)
{
    if (row == N)
    {
        solutions.pb(board);
        return;
    }

    for (int col = 0; col < N; ++col)
    {
        if (isSafe(row, col))
        {
            placeQueen(row, col);
            backtrack(row + 1);
            removeQueen(row, col);
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    N = n;
    board = vector<string>(N, string(N, '0'));
    cols = vector<bool>(N, false);
    diag1 = vector<bool>(2 * N - 1, false);
    diag2 = vector<bool>(2 * N - 1, false);
    solutions.clear();

    backtrack(0);
    return solutions;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        auto results = solveNQueens(n);

        cout << "Number of solutions for " << n << "-Queens: " << results.size() << endl;
        for (const auto &board : results)
        {
            for (const auto &row : board)
            {
                cout << row << endl;
            }
            cout << endl;
        }
    }

    return 0;
}