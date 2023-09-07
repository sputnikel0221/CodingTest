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

    // 입력
    int arr[N+1] = {0, };
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
    }
    
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(arr[i] < arr[j])
            {
                // 갱신이 되어야 한다면, 해당 인덱스를 j의 이전 원소라고 표시
                if(dp[i]+1 > dp[j])
                {
                    bt[j] = i;
                }
                // dp 갱신
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }


    // 1 dp로 가장 긴 길이 출력
    int lastIdx=0; // lastIdx는 가장 마지막 = 가장 큰 값의 인덱스를 저장할 변수
    int result = 0;
    for(int i=1;i<=N;i++)
    {
        result = max(result, dp[i]); 
        if(result == dp[i])
        {
            lastIdx = i;
        }
    }
    //cout << lastIdx << "\n";
    // 갱신된게 하나도 없다면, 아무거나 출력하고 종료
    if(lastIdx == 0)
    {
        cout << "1\n";
        cout << arr[1];
        return 0;
    }

    cout << result << "\n";

    // 2 인덱스를 역추적하여 stack에 담음(역추적한 값을 뒤집기 위함)
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

    // 2-2 stack을 출력하여 경로 출력
    while(!back.empty())
    {
        cout << back.top() << " ";
        back.pop();
    }
    

    return 0;   
}