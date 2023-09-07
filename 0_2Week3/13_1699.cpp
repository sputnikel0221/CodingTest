#include <iostream>
#include <math.h>

using namespace std;

int dp[100001] = {
    0,
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i<=N; i++) 
    {
        dp[i] = i;  // 일단 제곱중 가장 작은 1로 만들 수 있는 값을 집어넣는다.
    }

    for(int i=1; i<=N; i++)
    {
        for(int j = 1; j*j<=i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    cout << dp[N];
    
    return 0;
}