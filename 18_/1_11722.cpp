#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int A[N+1] = {0, };
    for(int i=1;i<=N;i++)
    {
        cin >> A[i];
    }

    int dp[N+1] = {0, };
    dp[1] = 1;
    for(int i=1;i<=N;i++)
    {
        dp[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(A[i] < A[j] && dp[i]<=dp[j])
            {
                dp[i] = dp[j] + 1;  // dp의 최대값 갱신
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if(max < dp[i])
        {
            max = dp[i];
        }
    }
    
    cout << max;

    return 0;   
}