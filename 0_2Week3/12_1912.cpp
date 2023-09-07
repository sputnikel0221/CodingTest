#include <iostream>
using namespace std;

int dp[100001] = {0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int arr[N] = {0, };
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int result = -999999;
    for(int i=1;i<=N;i++)
    {
        if(dp[i] < dp[i-1] + arr[i])
        {
            dp[i] = dp[i-1] + arr[i];
        }
        
        if(dp[i] > result)
        {
            result = dp[i];
        }
    }

    cout << result;
    return 0;   
}