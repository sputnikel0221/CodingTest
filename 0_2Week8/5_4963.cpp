#include <iostream>
#include <cstring>

using namespace std;

int sum = 0;
int N, M;
bool map[51][51];

int dx[8]={-1,1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

void DFS(int x, int y)
{
    map[x][y] = 0;

    for (int i = 0; i < 8; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (cx < 0 || cx >= N || cy < 0 || cy >= M)
        {
            continue;
        }

        if (map[cx][cy])
        {
            DFS(cx, cy);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        sum = 0;
        memset(map, 0, sizeof(map));

        // M이 가로, N이 세로
        cin >> M >> N;
        if (N == 0 && M == 0)
        {
            return 0;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j])
                {
                    DFS(i, j);
                    sum++;
                }
            }
        }

        cout << sum << "\n";
    }

    return 0;
}