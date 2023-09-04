#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            cout << ' ';
            continue;
        }

        if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (s[i] + 13 > 90)
            {
                char a = s[i] + 13 - 26;
                cout << a;
            }
            else
            {
                char a = s[i] + 13;
                cout << a;
            }
        }

        if ('a' <= s[i] && s[i] <= 'z')
        {
            if (s[i] + 13 > 122)
            {
                char a = s[i] + 13 - 26;
                cout << a;
            }
            else
            {
                char a = s[i] + 13;
                cout << a;
            }
        }
    }

    return 0;
}