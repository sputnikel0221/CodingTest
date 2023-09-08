#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int arr[N + 1] = {
        0,
    };
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];

        for (int k = 0; k < 2; k++)
        {
            dp[i][k] = 1;
        }
    }

    // 정방향으로 증가수열
    for(int i=1; i<N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            if(arr[i] < arr[j])
            {
                dp[j][0] = max(dp[j][0], dp[i][0] + 1);
            }
        }
    }

    // 역방향으로 감소수열
    for(int i=N; i>1; i--)
    {
        for(int j=i-1; j>=1; j--)
        {
            if(arr[i] < arr[j])
            {
                dp[j][1] = max(dp[j][1], dp[i][1] + 1);
            }
        }
    }

    
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result = max(dp[i][0] + dp[i][1], result);
    }
    cout << result - 1; // 중복된 부분 제외

    return 0;
}