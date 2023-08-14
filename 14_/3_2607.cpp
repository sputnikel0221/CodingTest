#include <iostream>
#include <string>
using namespace std;

int count = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int alphabet[26] = {
        0,
    };
    string s;
    cin >> s;
    int slength = s.length();

    for (char c : s)
    {
        alphabet[c - 65]++;
    }

    for (int n = 0; n < N - 1; n++)
    {
        // tmpAlphabet에 값 복사
        int tmpAlphabet[26];
        for (int i = 0; i < 26; i++)
        {
            tmpAlphabet[i] = alphabet[i];
        }

        string str;
        cin >> str;

        int minus = 0;
        int plus = 0;
        bool wrongFlag = false;

        // cout << str << " " << str.length() - slength <<"\n";

        if (slength == str.length() || str.length() - slength == -1 || str.length() - slength == 1)
        {
            // 값 수정
            for (int i = 0; i < str.length(); i++)
            {
                tmpAlphabet[str[i] - 65]--;
            }

            // minus / plus 요소 찾기
            for (int i = 0; i < 26; i++)
            {
                if (tmpAlphabet[i] > 1 || tmpAlphabet[i] < -1)
                {
                    wrongFlag = true;
                    break;
                }

                if (tmpAlphabet[i] == -1)
                {
                    minus++;
                }
                else if (tmpAlphabet[i] == 1)
                {
                    plus++;
                }
            }

            if (wrongFlag)
            {
                continue;
            }

            // 입력값이 더 큰 경우 : 제거
            if (str.length() - slength == 1 && minus == 1 && plus == 0)
            {
                // cout << "(DEL)"  << str << "\n";
                count++;
            }

            // 입력값이 같은 경우 : 완전히 같다
            else if (str.length() - slength == 0 && minus == 0 && plus == 0)
            {

                // cout << "(SAM)" << str << "\n";
                count++;
            }
            // 입력값이 같은 경우 2 : 수정
            else if (str.length() - slength == 0 && minus == 1 && plus == 1)
            {
                // cout << "(MOD)" << str << "\n";
                count++;
            }

            // 입력값이 더 작은 경우 : 추가
            else if (str.length() - slength == -1 && minus == 0 && plus == 1)
            {

                // cout << "(ADD))" << str << "\n";
                count++;
            }
        }
    }
    cout << count;

    return 0;
}