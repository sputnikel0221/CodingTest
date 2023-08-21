#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int dp[N + 1] = {
        0,
    }; // 횟수 최소값
    int path[N + 1] = {
        0,
    }; // 이전 인덱스값

    dp[1] = 0;

    // dp와 path를 채움, dp[i]와 예상값을 비교하여 더 작은 값을 취하도록 한다.
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        path[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i/2] + 1)
        {
            dp[i] = dp[i/2] + 1;
            path[i] = i/2;
        }
        if (i % 3 == 0 && dp[i] > dp[i/3] + 1)
        {
            dp[i] = dp[i/3] + 1;
            path[i] = i/3;
        }
    }

    cout << dp[N] <<"\n";

    cout << N << " ";
    int idx = N;
    for(int i=0; i<dp[N];i++)
    {
        cout << path[idx] << " ";
        idx =  path[idx];    
    }

    return 0;
}