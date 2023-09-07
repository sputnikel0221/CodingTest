#include <iostream>
#include <cstring>

using namespace std;

int dp[100001][4]; // 주의

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));

    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for (int i = 4; i <= 100000; i++)
    {
        dp[i][1] = ((dp[i - 1][2] + dp[i - 1][3])) % 1000000009;
        dp[i][2] = ((dp[i - 2][1] + dp[i - 2][3])) % 1000000009;
        dp[i][3] = ((dp[i - 3][1] + dp[i - 3][2])) % 1000000009;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        // 오류가 가장 많이 났던 부분.
        // 출력은 dp를 3개 더해야하는데 int로 하면 안되므로, 첫항을 longlong으로 바꾸어
        // longlong값이 나오게 하고, 그 값을 1000000009으로 나머지한 규칙대로 출력
        cout << ((long long)dp[N][1] + dp[N][2] + dp[N][3])%1000000009 << "\n";
    }

    return 0;
}