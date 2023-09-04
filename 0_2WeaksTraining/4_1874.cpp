#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    queue<int> q;
    while (N--)
    {
        int n;
        cin >> n;
        q.push(n);
    }

    stack<int> st;
    queue<char> ans;

    int inp = 1;
    while (!q.empty())
    {
        if (st.size() && st.top() == q.front())
        {
            st.pop();
            q.pop();
            ans.push('-');
        }
        else if (inp <= q.front())
        {
            while (inp <= q.front())
            {
                st.push(inp++);
                ans.push('+');
            }
        }
        else
        {
            printf("NO");
            return 0;
        }
    }

    while (ans.size()) printf("%c\n", ans.front()), ans.pop();
    return 0;
}