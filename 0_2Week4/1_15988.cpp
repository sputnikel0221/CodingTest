#include <iostream>
using namespace std;

long long dp[1000001] = {0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1; dp[2] = 2; dp[3] = 4; dp[4] = 7;

    for(int i=5;i<1000001; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000009;
    }

    int N;
    cin >> N;

    while(N--)
    {
        int num;
        cin >> num;

        cout << (dp[num])%1000000009 << "\n";
    }

    return 0;   
}