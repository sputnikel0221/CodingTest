#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = {0, -1, 0, 1}; // 위왼아오
int dy[4] = {1, 0, -1, 0};
int map[50][50];
int M, N, K;
int X, Y;
int worm = 0;
void BFS(int x, int y);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cout << "initialize"
             << "\n";
        // 초기화
        cin >> M >> N >> K; // M가로 N세로
        memset(map, 0, sizeof(map));
        worm = 0;

        // 배추 심기
        for (int k = 0; k < K; k++)
        {
            cin >> X >> Y;
            map[Y][X] = 1;
        }

        // BFS
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[j][i] == 1)
                {
                    // cout << "baechu : " << "x :" << i << " y :" << j << "\n";
                    BFS(i, j);
                    worm++;
                }
            }
        }
        cout << worm << "\n";
    }

    return 0;
}

// 해당 값부터 진행
void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    // 해당 좌표에 대한 BFS진행
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        map[y][x] = 0;

        // 4방향에 대해 갈 수 있는 노드를 체크
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (cx < 0 || cx >= N || cy < 0 || cy >= M)
            {
                continue;
            }

            if (map[cy][cx] == 1)
            {
                cout << "mapcxcy : "
                     << "x :" << cx << " y :" << cy << map[cy][cx] << "\n";
                q.push(make_pair(cx, cy));
            }
        }
    }
}
