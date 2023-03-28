#include <iostream>
#include <queue>

#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    int tmp_K = 1;
    int tmp_value;

    queue<int> Josep_input;
    queue<int> Josep_result;

    cin >> N >> K;

    // 일단 input queue에 다 채워 넣는다.
    for (int i = 1; i < N+1; i++)
    {
        Josep_input.push(i);
    }

    // input queue가 다 빌 때까지 뺀다.
    while (!Josep_input.empty())
    {
        if (tmp_K == K)
        {
            // 해당 값을 결과큐에 이동시킨다.
            Josep_result.push(Josep_input.front());
            Josep_input.pop();
            tmp_K = 1;
        }
        else
        {
            // 맨 앞의 값을 맨 뒤에 넣는다.
            tmp_value = Josep_input.front();
            Josep_input.pop();
            Josep_input.push(tmp_value);
            tmp_K++;
        }
    }

    //출력부분도 신경 써야만 한다.
    cout << '<';
    while(!Josep_result.empty()){
        tmp_value = Josep_result.front();
        Josep_result.pop();

        if(Josep_result.empty()){
            cout << tmp_value << ">";
        }
        else{
            cout << tmp_value << ", ";
        }
    }
    
    array<int,3> arr = {0,0,0};
    if(arr.empty()){
        cout << "nice";
    }

    return 0;
}