#include <iostream>

using namespace std;

int dp[1001] = {0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;


    int arr[N+1] = {0, };
    for(int i=1;i<=N;i++)
    {   
        cin >> arr[i];
        dp[i] = 1;
    }

    
    for(int i=1;i<N;i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[j] = max(dp[i] + 1, dp[j]);
            }
        }
    }

    int result = 0;
    for(int i=1;i<=N;i++)
    {   
        result = max(result, dp[i]);
    }
    cout << result;

    return 0;   
}