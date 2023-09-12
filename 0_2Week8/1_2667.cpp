#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int N;
int result=0;
vector<int> danji;

void DFS(int x, int y)
{
    // 0이면 return
    if (!map[x][y])
    {
        return;
    }

    // 1이면 result에 추가, 다시 방문 못하게 0으로 전환
    if (map[x][y])
    {
        result++;
        map[x][y] = 0;
    }

    // 현재에서 4방향을 DFS에 넣음
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (cx < 0 || N < cx || cy < 0 || N < cy)
        {
            continue;
        }
        else
        {
            DFS(cx, cy);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 입력
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    // map[i][j]가 1이면 DFS넣음
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j])  // 1이어야만 danji에 값을 넣음
            {
                DFS(i, j);
                danji.push_back(result);
                result = 0;
            }
        }
    }

    // 정렬해야함
    sort(danji.begin(), danji.end());

    // 출력
    cout << danji.size() << "\n";
    for (int i = 0; i < danji.size(); i++)
    {
        cout << danji[i] << "\n";
    }
    return 0;
}