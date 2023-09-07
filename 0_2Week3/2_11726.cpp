#include <iostream>
using namespace std;

int dp[1001] = {0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=N;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[N];

    return 0;   
}