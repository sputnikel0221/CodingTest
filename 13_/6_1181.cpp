#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string beforeSTR = " ";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, string>> sGroup;
    while (N--)
    {
        string s;
        cin >> s;

        //auto it = find(sGroup.begin(), sGroup.end(), make_pair(s.size(), s));
        sGroup.push_back({s.size(), s});
    }



    sort(sGroup.begin(), sGroup.end());
    for (auto element : sGroup)
    {
        if(beforeSTR!=element.second)
        {
            cout << element.second << "\n";
        }
        
        beforeSTR = element.second;  
    }

    return 0;
}