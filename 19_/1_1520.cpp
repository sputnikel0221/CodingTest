#include <iostream>
#include <vector>
using namespace std;

int cx[4] = {1, 0, -1, 0};
int cy[4] = {0, -1, 0, 1};

int DFS(int, int);

int map[501][501];
int d[501][501];    // DP
int M, N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            d[i][j] = -1; // d -1로 초기화
        }
    }

    cout << DFS(0, 0);
    return 0;
}

// 목적지가 아니라면 최종적으로 d[x][y]를 반환한다.
int DFS(int x, int y)
{
    if (x == N - 1 && y == M - 1)
    {
        return 1;
    }

    if (d[x][y] == -1)  // 한번도 방문한 적이 없다면,
    {
        d[x][y] = 0;    // 방문 표시를 한다
        for (int i = 0; i < 4; i++)
        {
            int dx = x + cx[i];
            int dy = y + cy[i];

            if (dx < 0 || dy < 0 || N <= dx || M <= dy)
            {
                continue;
            }
            else
            {
                if (map[dx][dy] < map[x][y]) // 내리막길이라면
                {
                    d[x][y] += DFS(dx, dy); // d(dxdy)값을 d(xy)에 더함
                }
            }
        }
    }
    return d[x][y];
}