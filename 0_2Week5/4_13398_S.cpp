#include <iostream>
using namespace std;

int dp[100001][2];

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

        dp[i][0] = arr[i];
        dp[i][1] = arr[i];
    }

    int result = arr[1];
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = dp[i][1] = arr[i];
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);

        result = max(result, max(dp[i][0], dp[i][1]));
    }

    cout << result;

    return 0;
}