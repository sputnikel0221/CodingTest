#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int dp[100001];
int before[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int S, E;
    cin >> S >> E;

    // 뒤로는 X-1로만 갈 수 있다 - 같은 경우도 제거
    if (E <= S)
    {
        cout << S - E << "\n";

        // 여기서도 경로를 출력, -1밖에 하지 못하므로 내림차순 출력됨
        for(int i=S; i>=E; i--)
        {
            cout << i << " ";
        }
        return 0;
    }

    // min 연산을 위한 초기화
    for(int i=0;i<100001;i++)
    {
        dp[i] = 987654321;
    }

    // 1 S 확정
    dp[S] = 0;
    before[S] = -1;

    // 2 S 이전
    for(int i=S; i>=1; i--)
    {
        dp[i-1] = dp[i] + 1;
        before[i-1] = i;
    }

    // 3 S 이후 - 범위를 E까지만 잡아도 되는 것이, x2를 해봤자 E+1이기 때문
    // E+1은 x2-1의 경우에만 사용되며, 마지막 조건에서 다루게 된다.
    for(int i=S+1; i<=E; i++)
    {
        if(i%2==0)
        {
            if(dp[i-1]+1 <= dp[i/2]+1)
            {
                dp[i] = dp[i-1] + 1;
                before[i] = i-1;
            }
            else
            {
                dp[i] = dp[i/2]+1;
                before[i] = i/2;
            }
        }
        else
        {
            if(dp[i-1]+1 <= dp[(i+1)/2] + 2)
            {
                dp[i] = dp[i-1]+1;
                before[i] = i-1;
            }
            else
            {
                // before이 핵심
                dp[i] = dp[(i+1)/2] + 2;
                before[i] = i+1;
                before[i+1] = (i+1)/2;
            }
        }
    }

    cout << dp[E] << "\n";

    // 출력하기 위해 순서대로 넣고, stack으로 뒤집음
    queue<int> q;
    stack<int> rev;
    q.push(E);
    while(!q.empty())
    {
        int n = q.front();
        if(n == -1)
        {
            break;
        }
        rev.push(n);
        q.pop();
        
        q.push(before[n]);
    }

    while(!rev.empty())
    {
        cout << rev.top() << " ";
        rev.pop();
    }

    return 0;
}