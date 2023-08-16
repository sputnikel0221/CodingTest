#include <iostream>
#include <vector>
#include <unordered_set>    // 일반 set을 추가하면 안됨.

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_set<string> memo;
    
    while (N--)
    {
        string s;
        cin >> s;
        memo.insert(s);
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
            if(memo.find(key)!=memo.end())
            {
                memo.erase(key);
            }
        }
        
        cout << memo.size() << "\n";
    }

    return 0;
}