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

    int arr[N];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
        }
    }

    cout << dp[N];

    return 0;
}