#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001] = {
    0,
};
string result;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    // s1에서 s2가 있는지 찾음 / s2가 찾을 기준이 되고, i 인덱스
    for (int i = 1; i < s2.size(); i++)
    {
        for (int j = 1; j < s1.size(); j++)
        {
            // 현재 글자가 같다면, 각각 이전의 글자를 탐색, 해당 값에 1을 더함
            if (s1[j] == s2[i])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // 현재 글자가 같지 않다면, 둘 중에 max를 가짐.
            // 이 부분이 제일 난해.
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int col = s1.size() - 1;
    int row = s2.size() - 1;

    while (dp[row][col])
    {
        // row와 col을 같다면 다 줄임. 즉 dp값의 시작을 알기 위함.
        if (dp[row][col] == dp[row - 1][col])
        {
            row--;
        }
        else if (dp[row][col] == dp[row][col - 1])
        {
            col--;
        }
        // dp값이 바뀐 시점이 새 글자를 찾은 시점이고, 찾았다면 또 빼고 또 진행.
        else
        {
            result += s1[col];
            row--, col--;
        }
    }

    // LCS알고리즘에 의해, 제일 끝 값이 최대 부분문자열 길이
    cout << dp[s2.size() - 1][s1.size() - 1] << "\n";

    // 출력
    if (result.size() > 0)
    {
        reverse(result.begin(), result.end());
        cout << result << endl;
    }

    return 0;
}