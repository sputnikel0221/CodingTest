#include <iostream>
#include <stack>

using namespace std;

int dp[1001];
int bt[1001] = {0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1로 초기화
    fill(dp, dp+1001, 1);

    int N;
    cin >> N;


    int arr[N+1] = {0, };
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
    }

    int lastIdx=0;
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(arr[i] < arr[j])
            {
                if(dp[i]+1 > dp[j])
                {
                    bt[j] = i;
                    lastIdx = j;
                }
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    int result = 0;
    for(int i=1;i<=N;i++)
    {
        result = max(result, dp[i]); 
    }
    cout << result << "\n";

    stack<int> back;
    
    back.push(arr[lastIdx]);
    while(true)
    {
        int backIdx = bt[lastIdx];
        if(backIdx == 0)
        {
            break;
        }

        back.push(arr[backIdx]);
        lastIdx = backIdx;

        
    }

    while(!back.empty())
    {
        cout << back.top() << " ";
        back.pop();
    }
    

    return 0;   
}