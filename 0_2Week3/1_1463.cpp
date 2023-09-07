#include <iostream>
using namespace std;

int dp[1000001]={0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;

    for(int i=4; i<=N; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i%2==0)
        {
            dp[i] = min(dp[i/2]+1, dp[i]);
        }
        if(i%3==0)
        {
            dp[i] = min(dp[i/3]+1, dp[i]);
        }
    }  

    cout << dp[N];

    return 0;   
}