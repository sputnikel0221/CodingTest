#include <iostream>

using namespace std;

int dp[100001];
int S, E;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E;

    // 뒤로는 X-1로만 갈 수 있다 - 같은 경우도 제거
    if (E <= S)
    {
        cout << S - E;
        return 0;
    }

    for(int i=0;i<100001;i++)
    {
        dp[i] = 987654321;
    }

    // 1 S는 확정.
    dp[S] = 0;

    // 2 S 앞의 dp는 확정할 수 있다. (S는 제외)
    for (int i = S; i >= 1; i--)
    {
        dp[i - 1] = dp[i] + 1;
    }

    // 3 S 뒤는 dp는 계산을 통해서 확정한다. (S는 제외)
    for(int i=S+1;i<100001;i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i/2] + 1, dp[i-1] + 1); //dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        else
        {
            dp[i] = min(dp[i-1] + 1, dp[(i+1)/2] + 2);
        }
    }

    cout << dp[E];

    return 0;
}