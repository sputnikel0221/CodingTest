#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int ans = 0;

int cx[4] = {1, 0, -1, 0};
int cy[4] = {0, -1, 0, 1};

int map[9][9];
int tmp[9][9];

void DFS();

// Wall을 2개 생성
void wall(int cur)
{
    // 벽 3개를 전부 세운다면, DFS 진행
    if (cur == 3)
    { 
        DFS();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp[i][j] == 0)
            {
                tmp[i][j] = 1;
                wall(cur + 1);
                tmp[i][j] = 0; // 이 행위를 함으로써 모든 경우를 탐지
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    // 첫번째 벽을 세우고, 진행
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                copy(&map[0][0], &map[0][0] + 81, &tmp[0][0]); // 복사
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0; // 이 행위를 함으로써 모든 경우를 탐지
            }
        }
    }

    cout << ans;

    return 0;
}

// 2라면 바이러스를 쭉쭉 진행
void DFS()
{
    int spread[9][9];
    copy(&tmp[0][0], &tmp[0][0] + 81, &spread[0][0]);
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (spread[i][j] == 2)
                q.push({i, j});
        }
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + cx[dir];
            int ny = cur.second + cy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (spread[nx][ny] == 0)
            {
                spread[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    // 모든 바이러스가 퍼지고 안전영역을 구함
    int cnt = 0; 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (spread[i][j] == 0)
                cnt++;
        }
    }

    // 최종 ans값 설정
    ans = max(ans, cnt);
}