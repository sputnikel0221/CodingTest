#include <iostream>
#include <cstring>

using namespace std;

int dp[3][100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        memset(dp, 0, sizeof(dp));

        int N;
        cin >> N;

        int arr[3][N + 1];
        memset(arr, 0, sizeof(arr));

        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> arr[i][j];
            }
        }

        // 초기값.
        dp[1][1] = arr[1][1];
        dp[2][1] = arr[2][1]; 

        // j열 각각 값을 구함
        for (int j = 2; j <= N; j++)
        {
            // 바로 전의 대각선이나, 전전의 대각선 값.
            dp[1][j] = max(dp[2][j-1], dp[2][j-2]) + arr[1][j];
            dp[2][j] = max(dp[1][j-1], dp[1][j-2]) + arr[2][j];
        }

        cout << max(dp[1][N], dp[2][N]) << "\n";
    }

    return 0;
}