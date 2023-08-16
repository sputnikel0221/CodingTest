#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int totalSum = 0;
    string strNum = "";  // 글자로부터 숫자를 만들기 위한 용도
    bool isInMinus = false; // -가 한번 나오면, 그 뒤의 숫자는 모두 -시킨다.

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '+' && s[i] != '-')
        {
            strNum += s[i];

            if (i == s.size() - 1)
            {
                int num = stoi(strNum);
                if (isInMinus)
                {
                    totalSum -= num;
                }
                else
                {
                    totalSum += num;
                }
            }
        }
        
        if(s[i] == '+' || s[i] == '-')
        {
            int num = stoi(strNum); // 여태까지의 문자를 숫자로 변환

            if (s[i] == '+')
            {
                if (isInMinus)
                {
                    totalSum -= num;
                }
                else
                {
                    totalSum += num;
                }
            }
            else if (s[i] == '-')
            {
                if(!isInMinus)
                {
                    totalSum += num;
                }
                else
                {
                    totalSum -= num;
                }
                isInMinus = true;
            }

            strNum = "";
        }
    }
    cout << totalSum;

    return 0;
}