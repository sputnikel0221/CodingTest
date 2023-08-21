#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    int arr[N + 1] = {
        0,
    };
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int dp[N + 1] = {
        0,
    };
    dp[1] = arr[1];
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
    }

    while(M--)
    {
        int start, end;
        cin >>start>>end;

        cout << dp[end]-dp[start]+arr[start] <<"\n";
    }
    return 0;
}