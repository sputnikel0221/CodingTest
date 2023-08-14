#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int alphabet[26] = {
        0,
    };

    // 입력
    for (char c : s)
    {
        alphabet[c - 65]++;
    }

    // 회문이 가능한지 점검
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] % 2 == 1)
        {
            odd++;
        }
    }

    if (odd > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    // 회문 생성 
    int oddIDX = 0;
    stack<char> half_back;
    string half_front = "";
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] != 0 && alphabet[i] / 2 > 0) // 5/2 = 2 + 1
        {

            int m = alphabet[i] / 2;
            for (int k = 0; k < m; k++)
            {
                alphabet[i] -= 2;

                char a = (char)(i + 65);
                half_front += a; // 될까?
                half_back.push(a);
            }
        }
    }

    // 가운데 홀수글자 끼우기
    if (odd == 1)
    {
        for (int i = 0; i < 26; i++)
        {
            if (alphabet[i] == 1)
            {
            half_front += (char)(i+65);
            }
        }
    }

    // 나머지 반 생성
    while (!half_back.empty())
    {
        half_front += half_back.top();
        half_back.pop();
    }

    cout << half_front;

    return 0;
}