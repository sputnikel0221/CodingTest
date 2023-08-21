#include <iostream>
using namespace std;

int dp[301][301];
int stair[301];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&dp[0][0], &dp[300][300], 0);

    int N;
    cin >> N;

    // 계단 value 입력
    for(int i=1;i<=N;i++)
    {
        cin >> stair[i];
    }
    
    dp[1][1] = stair[1]; 
    dp[1][2] = stair[1]; 

    dp[2][1] = stair[2];
    dp[2][2] = stair[1] + stair[2];

    for(int i=3;i<=N;i++)
    {
        dp[i][1] = max(dp[i-2][1]+stair[i], dp[i-2][2]+stair[i]);
        dp[i][2] = dp[i-1][1] + stair[i];
    }

    cout << max(dp[N][1], dp[N][2]);

    return 0;   
}