#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<string, bool>> memo;
    while (N--)
    {
        string s;
        cin >> s;
        memo.push_back({s, true});
    }

    while (M--)
    {
        string s;
        cin >> s;

        vector<string> keyword;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ',')
            {
                tmp += s[i];
            }

            if (s[i] == ',' || i == s.size() - 1)
            {
                keyword.push_back(tmp);
                tmp = "";
            }
        }

        for (auto key : keyword)
        {
            for (auto m : memo)
            {
                cout << key << " " << m.first << "\n";
                if (key == m.first)
                {
                    cout << "gotit\n";
                    m.second = false;
                    cout << m.second;
                }
            }
        }

        int count = 0;
        for (auto m : memo)
        {
            if (m.second == true)
            {
                cout << "count : " << m.first << "\n";
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}