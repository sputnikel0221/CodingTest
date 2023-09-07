#include <iostream>
using namespace std;

long long dp[201][201] = {0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    dp[0][0]=1;
    for(int i=1;i<=K;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=N;j++) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000000;
    }

    cout << dp[K][N];
    
    return 0;   
}