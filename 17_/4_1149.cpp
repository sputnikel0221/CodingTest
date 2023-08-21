#include <iostream>
using namespace std;

int dp[1001][3];
int cost[1001][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> cost[i][j];
        }
    }

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for(int i=2;i<=N;i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    int c = min(dp[N][0], dp[N][1]);
    c = min(c, dp[N][2]);

    cout << c;

    return 0;   
}