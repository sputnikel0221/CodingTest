#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> s;
int ans[1000001]; // 오큰수
int seq[1000001]; // 그냥 입력

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 입력
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= seq[i])
        {
            s.pop();    // seq[i]보다 항상 큰 s.top이 남을 수 밖에 없다.
                        // 이게 자신의 가장 첫번째 오큰수가 될 수 있는 이유는, stack때문
        }

        // s.top을 ans[i]로 둔다.
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }

        s.push(seq[i]);
    }

    // 정답 출력
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}