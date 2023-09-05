#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    if(str=="0")
    {
        cout << 0;
        return 0;
    }

    string result;
    for (long long i = 0; i < str.length(); i++)
    {
        result += to_string((str[i] - '0') / 4);
        result += to_string(((str[i] - '0') % 4) / 2);
        result += to_string((((str[i] - '0') % 4) % 2) / 1);
    }

    for (long long i = 0; i < result.length(); i++)
    {
        if(result[i] != '0')
        {
            cout << result.substr(i, result.length());
            return 0;
        }
    }    
}