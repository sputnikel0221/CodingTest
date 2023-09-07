#include <iostream>
using namespace std;

int dp[1001] = {
    0,
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    fill(dp, dp+1001, 999999);

    int arr[N];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = arr[1];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + arr[j]);
        }
    }

    cout << dp[N];

    return 0;
}