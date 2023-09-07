#include <iostream>
#include <cstring>

using namespace std;

long long dp[1001][10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    // i는 현재 자릿수, k는 현재 자릿수의 숫자, z는 현재 자릿수 이전의 숫자들
    for (int i = 2; i <= N; i++)
    {
        for (int k = 0; k <= 9; k++)
        {
            for (int z = 0; z <= k; z++)
            {
                dp[i][k] += (dp[i - 1][z])%10007;
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < 10; i++)
    {
        result += dp[N][i];
    }
    cout << result %10007;

    
    return 0;
}