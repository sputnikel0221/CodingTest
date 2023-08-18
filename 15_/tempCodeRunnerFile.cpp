#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string b;
    cin >> b;

    int sLen = s.length();
    int bLen = b.length();

    stack<char> answer;

    int combo = 0;
    for (int i = 0; i < sLen; i++)
    {
        answer.push(s[i]);
        if (s[i] == b[combo])
        {
            combo++;
        }
        else
        {
            combo = 0;
            if (s[i] == b[combo])
            {
                combo++;
            }
        }

        if (combo == bLen)
        {
            for (int i = 0; i < bLen; i++)
            {
                answer.pop();
            }

            if (answer.size() == 0 && i == sLen -1)
            {
                cout << "FRULA";
                return 0;
            }

            combo = 0;
            if (answer.size() !=0 && answer.top() == b[combo])
            {
                combo++;
            }
        }
    }

    stack<char> reverseStack;
    int aSize = answer.size();

    while (aSize--)
    {
        reverseStack.push(answer.top());
        answer.pop();
    }

    int rSize = reverseStack.size();
    while (rSize--)
    {
        cout << reverseStack.top();
        reverseStack.pop();
    }

    return 0;
}