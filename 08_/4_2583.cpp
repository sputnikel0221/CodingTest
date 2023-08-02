#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
void DFS(int, int);
int map[100][100];
int count = 0;
int sum[5000] = {
    0,
};

int dx[4] = {0, -1, 0, 1}; // 위왼아오
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N; // M이 세로, N이 가로
    cin >> K;

    memset(map, 0, sizeof(map));

    // 사각형 좌표값에 따른 그래프 그리기
    int ax, ay, bx, by;
    for (int k = 0; k < K; k++)
    {
        cin >> ax >> ay;
        cin >> bx >> by;

        for (int x = ax; x < bx; x++)
        {
            for (int y = ay; y < by; y++)
            {
                map[y][x] = 1;

                // cout << "x:" << x << " y:" << y << "\n";
            }
        }
    }

    // DFS
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[j][i] == 0)
            {
                map[j][i] = 1; // visited
                DFS(i, j);
                count++;
            }
        }
    }

    //출력 
    cout << count << "\n";

    // Bubble Sort
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (sum[j] > sum[j + 1])
            {
                int tmp = sum[j + 1];
                sum[j + 1] = sum[j];
                sum[j] = tmp;
            }
        }
    }
    
    for (int i = 0; i < count; i++)
    {
        cout << sum[i] << " ";
    }

    return 0;
}

void DFS(int x, int y)
{
    sum[count]++;

    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (cx < 0 || cy < 0 || cx >= N || cy >= M)
        {
            continue;
        }
        else
        {
            if (map[cy][cx] == 0)
            {
                map[cy][cx] = 1; // visited
                DFS(cx, cy);
            }
        }
    }
}