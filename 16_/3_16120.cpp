#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> answer;

    for (int i = 0; i < s.size(); i++)
    {
        answer.push(s[i]);
        if (s[i] == 'A' && i + 1 < s.size())
        {
            if (s[i + 1] == 'P') // 즉 A일때, 뒤의 글자가 P라면, 앞이 PP인지 확인
            {
                answer.pop(); // 들어가있는 A를 뺌

                // 앞의 PP를 비교해야하는데 없으면 안됨
                if (answer.size() < 2)
                {
                    cout << "NP";
                    return 0;
                }

                // A가 나오면 무조건 앞의 PP가 나와야만 함
                for (int t = 0; t < 2; t++)
                {
                    if (answer.top() == 'P')
                    {
                        answer.pop();
                    }
                    else
                    {
                        cout << "NP";
                        return 0;
                    }
                }
            }
            else // A다음에 A가 나오는 경우 PPAP문자열이 절대 될 수 없다.
            {
                cout << "NP";
                return 0;
            }
        }
    }

    if (answer.size() != 1 || answer.top() == 'A')
    {
        cout << "NP";
        return 0;
    }
    else
    {
        cout << "PPAP";
    }

    return 0;
}