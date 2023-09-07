#include <iostream>
#include <cstring>
using namespace std;

long long dp[901][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    memset(dp, 0, sizeof(dp));

    dp[1][1] = 1;
    dp[2][0] = 1;

    for(int i=3;i<=N;i++)
    {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
    }

    long long result;
    cout << dp[N][0] + dp[N][1];

    return 0;   
}