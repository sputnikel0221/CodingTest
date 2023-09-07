#include <iostream>
#include <cstring>
using namespace std;

long long dp[100001][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));

    int N;
    cin >> N;

    // 첫째 줄에 사자를 배치하는 경우의 수를 9901로 나눈 나머지를 출력하여라.
    dp[1][0] = 1;   // 배치하지 않는 경우도 경우로 친다?
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i=2; i<=N; i++)
    {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }

    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901; 

    return 0;   
}