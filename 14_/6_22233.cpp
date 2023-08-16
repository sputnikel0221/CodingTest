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

        // 1 데이터 파싱
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

        // 2 키워드 있는지 검색 및 삭제
        for (auto key : keyword)
        {
            if(memo.find(key)!=memo.end())
            {
                memo.erase(key);
            }
        }
        
        // 3 출력
        cout << memo.size() << "\n";
    }

    return 0;
}