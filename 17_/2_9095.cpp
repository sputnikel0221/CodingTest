#include <iostream>
using namespace std;

int dp[12] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int N, T;

    for(int i=4;i<=11;i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << dp[N];
        cout << "\n";
    }

    
    return 0;   
}
