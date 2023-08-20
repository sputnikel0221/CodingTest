#include <iostream>
using namespace std;

int REC(int N);
int dp[1000000+1] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // 초기값
    dp[1] = 0;

    cout << REC(N);

    return 0;   
}

int REC(int N)
{
    int t = 1000000;
    int b = 1000000;
    int o = 1000000;

    if(N==1 || N==0)
    {
        return 0;
    }


    // N에 값이 없다면 부여
    if(dp[N]==0)
    {
        if(N%3==0)
        {
            t = REC(N/3) + 1;
        }

        if(N%2==0)
        {
            b = REC(N/2) + 1;
        }

        o = REC(N-1) + 1;

        dp[N] = min(min(t,o), min(b,o));
    }

    // N값을 리턴
    return dp[N];
}