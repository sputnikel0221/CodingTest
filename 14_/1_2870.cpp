#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<pair<int, string>> num;
    bool enterFlag = false;

    while (N--)
    {
        string s, s_num;
        cin >> s;

        bool isEntered = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (isEntered)
            {
                s_num = "";
                isEntered = false;
            }

            // 숫자면 s_num 문자열에 차곡차곡 쌓음
            if (s[i] - 58 < 0)
            {
                if (s_num == "" && s[i] == '0') // 숫자의 처음인데, 0이 들어온경우
                {
                    // 다음 문자가 숫자인 경우 스킵
                    if (i+1 != s.size() && s[i + 1] - 58 < 0)
                    {
                        continue;
                    }
                }
                // 그게 아닐 경우 더함. 이 경우는 0 홀로 숫자로 오는 경우도 포함.
                s_num += s[i];
            }

            // 다음 문자가 문자라면 숫자가 끝났으므로 vector에 넣음 
            if (s_num != "" && (i == s.size() - 1 || (i + 1 != s.size() && s[i + 1] - 58 > 0)))
            {
                num.push_back({s_num.size(), s_num}); // string to int
                isEntered = true;
            }
        }
    }

    sort(num.begin(), num.end());   // 숫자는 size에 맞게 정렬해야함.

    for (auto n : num)
    {
        // cout << n.second << " : this" "\n";

        for (int i = 0; i < n.first; i++)
        {
            cout << n.second[i];
        }

        cout << "\n";
    }

    return 0;
}