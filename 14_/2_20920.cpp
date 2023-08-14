#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, int> wordMap;                     // str, count
    vector<pair<int, pair<int, string>>> wordVec; // (count, (size, str))

    // 중복되는 입력을 하지 않고, count를 계산하여 Map에 저장
    while (N--)
    {
        string s;
        cin >> s;

        if (s.size() < M)
        {
            continue;
        }
        if (wordMap.find(s) == wordMap.end())
        {
            wordMap.insert({s, 0});
        }
        else
        {
            wordMap[s]++; // 값을 수정 count ++
        }
    }

    // 정렬하기 위해 벡터에 넣음
    for (auto w : wordMap)
    {
        wordVec.push_back({w.second, {w.first.size(), w.first}});
    }

    sort(wordVec.begin(), wordVec.end(), [](pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
    {

        if(a.first == b.first && a.second.first == b.second.first)
        {
            return a.second.second < b.second.second;
        }

        return a>b;
    }
    );


    // 출력
    for (auto str : wordVec)
    {
        cout << str.second.second <<"\n";
        //" : " << str.first << "\n";
    }

    return 0;
}