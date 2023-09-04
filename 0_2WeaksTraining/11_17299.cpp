#include <iostream>
#include <stack>
using namespace std;

int seq[1000001] = {
    0,
};
int ans[1000001] = {
    0,
};
int count[1000001] = {
    0,
};
stack<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // 입력
    for (int i = 0; i < N; i++)
    {
        cin >> seq[i];
        count[seq[i]]++;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        // 사전작업
        while (!s.empty() && count[s.top()] <= count[seq[i]])
        {
            s.pop();
        }

        if(s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }

        s.push(seq[i]);
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    return 0;
}