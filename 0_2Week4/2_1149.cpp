#include <iostream>
using namespace std;

int dp[1001][3] = {0,};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int cost[1001][3];
    for (int n = 1; n <= N; n++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> cost[n][i];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2])+ cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2])+ cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1])+ cost[i][2];
    }
    
    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);

    return 0;
}