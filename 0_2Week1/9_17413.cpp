#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    stack<char> tmpS;
    string answer = "";

    bool isTag = false;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << ":" << s[i];
        if (s[i] == ' ')
        {
            if (isTag)
            {
                answer += s[i];
            }
            else
            {
                while (!tmpS.empty())
                {
                    answer += tmpS.top();
                    tmpS.pop();
                }
                answer += " ";
            }
        }

        if (s[i] == '<' || s[i] == '>')
        {
            if (!tmpS.empty())
            {
                while (!tmpS.empty())
                {
                    answer += tmpS.top();
                    tmpS.pop();
                }
            }
            isTag = true;
            answer += s[i];

            if (s[i] == '>')
            {
                isTag = false;
            }
        }

        // 글자라면
        if (s[i] != ' ' && s[i] != '<' && s[i] != '>')
        {
            if (isTag)
            {
                answer += s[i];
            }
            else
            {
                tmpS.push(s[i]);
            }
        }

        if (i == s.length() - 1)
        {
            while (!tmpS.empty())
            {
                answer += tmpS.top();
                tmpS.pop();
            }
        }
    }
    cout << answer;
    return 0;
}