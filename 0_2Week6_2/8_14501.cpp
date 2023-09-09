#include <iostream>
using namespace std;

int dp[17] = {0, };
int T[17]={0,}, C[17]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++)
    {
        cin >> T[i];
        cin >> C[i];
    }

    for(int i=N+1; i>=1; i--)
    {
        int t=0;
        for(int j=i-1; j>=1;j--)
        {
            t++;
            if(t==T[j])
            {
                dp[i] = max(dp[i], dp[j]+C[j]);
            }
        }
    }

    int result = 0;
    for(int i=1;i<=N+1;i++)
    {
        result = max(result, dp[i]);
    }

    cout << result;

    return 0;   
}