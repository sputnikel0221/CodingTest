#include <iostream>
#include <cstring>

using namespace std;

int dp[10001][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));

    int N;
    cin >> N;

    int arr[N+1] = {0, };
    
    // 입력과 동시에 초기값 설정
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];

        dp[i][0] = 0;
        dp[i][1] = arr[i];
    }
    dp[1][2] = 0;

    for(int i=2;i<=N;i++)
    {
        // 1 현재 와인을 안마셨을때 최대값
        dp[i][0] = max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][0]); 

        // 2 현재 와인을 마셨을때 최대값
        dp[i][1] = dp[i-1][0] + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }

    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]);

    return 0;   
}