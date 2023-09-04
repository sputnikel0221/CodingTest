#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> op;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
            {
                op.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                // stack에 * / 가 같은 레벨이므로 모두 출력
                // 
                while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                //덧셈은 최하위 우선순위기 때문에, 이전의 것들을 다 뽑아냄. 괄호제외.
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == ')')
            {
                // 괄호 사이 요소들 모두 출력 / 괄호 앞도 제거
                // 무조건 출력, 괄호가 먼저다.
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }
    }

    // 남아있는 것들 제거
    while (!op.empty())
    {
        cout << op.top();
        op.pop();
    }

    return 0;
}