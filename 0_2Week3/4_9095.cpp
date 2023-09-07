#include <iostream>
using namespace std;

int dp[12] = {
    0,
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        for (int i = 4; i <= N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        cout << dp[N] << "\n";
    }

    return 0;
}