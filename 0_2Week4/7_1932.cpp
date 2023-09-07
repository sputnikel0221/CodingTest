#include <iostream>
#include <cstring>
using namespace std;

int dp[501][501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    memset(dp, 0, sizeof(dp));

    int tree[N + 1][N + 1];
    memset(tree, 0, sizeof(tree));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> tree[i][j];
        }
    }

    dp[1][1] = tree[1][1];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tree[i][j];
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result = max(result, dp[N][i]);
    }
    cout << result;

    return 0;
}